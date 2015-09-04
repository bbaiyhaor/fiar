#include "fiar.h"
#include <QPainter>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QDateTime>

void Fiar::initMyServer()
{
    qDebug() << "server creation" << endl;
    this->myServer = new Server(this);
    ui->CreateServer->setEnabled(false);
    ui->JoinRoom->setEnabled(false);
    ui->AdmitLoser->setEnabled(false);
    ui->Regret->setEnabled(false);
    ui->SaveBoard->setEnabled(false);
    ui->StartGame->setEnabled(true);
    ui->OpenBoard->setEnabled(false);
    player = 0;
    //  current player is server

    connect(myServer, SIGNAL(startGame()), this, SLOT(startGame()));
    //  connect start game signal and slot
    connect(myServer, SIGNAL(updateFiarMove(QString,int)),
            this, SLOT(updateChess(QString,int)));
    //  connect move signal and slot
    connect(myServer, SIGNAL(updateFiarAdmit(QString)), this, SLOT(updateAdmit(QString)));
    //  connect admit defeat signal and slot
    connect(myServer, SIGNAL(gameOver()), this, SLOT(slotGameOver()));
    //  connect quit game (reason: net break) signal and slot
    connect(myServer, SIGNAL(updateFiarRegret(QString)), this, SLOT(updateRegret(QString)));
    //  connect regret chess signal and slot
    connect(myServer, SIGNAL(updateFiarBoard(QString)), this, SLOT(updateBoard(QString)));
    connect(myServer, SIGNAL(updateFiarContinue(QString)), this, SLOT(updateContinue(QString)));
    //  connect open board signal and slot
}
//  initial server

void Fiar::initMyClient(QString ip, int port)
{
    myClient = new Client(ip, port, this);
    if (myClient->serverIP == 0)
        return;
    ui->CreateServer->setEnabled(false);
    ui->JoinRoom->setEnabled(false);
    ui->AdmitLoser->setEnabled(false);
    ui->Regret->setEnabled(false);
    ui->SaveBoard->setEnabled(false);
    ui->StartGame->setEnabled(true);
    ui->OpenBoard->setEnabled(false);
    player = 1;
    //  current player is client

    connect(myClient, SIGNAL(startGame()), this, SLOT(startGame()));
    //  connect start game signal and slot
    connect(myClient, SIGNAL(updateFiarMove(QString,int)),
            this, SLOT(updateChess(QString,int)));
    //  connect move signal and slot
    connect(myClient, SIGNAL(updateFiarAdmit(QString)), this, SLOT(updateAdmit(QString)));
    //  connect admit defeat signal and slot
    connect(myClient, SIGNAL(gameOver()), this, SLOT(slotGameOver()));
    //  connect quit game (reason: net break) signal and slot
    connect(myClient, SIGNAL(updateFiarRegret(QString)), this, SLOT(updateRegret(QString)));
    //  connect regret chess signal and slot
    connect(myClient, SIGNAL(updateFiarBoard(QString)), this, SLOT(updateBoard(QString)));
    connect(myClient, SIGNAL(updateFiarContinue(QString)), this, SLOT(updateContinue(QString)));
    //  connect open board signal and slot
}
// initial client

void Fiar::updateChess(QString msg, int)
{
    int len = msg.length();
    if (len > 2)
    {
        QStringList xy = msg.split(",");
        int cx = xy.at(0).toInt();
        int cy = xy.at(1).toInt();
        boardbool[cx][cy] = player ^ 1;
        update();
        if (isWin(cx, cy))
        {
            emit signalWin(player ^ 1);
            return;
        }
    }
    canChess ^= 1;
    initTime();
    //  turn to me and begin to start
}
//  update rival place

void Fiar::playerReady(int player)
{
    if (! player)
        myServer->gameReady(player);
    else if (player == 1)
    {
        QString msg = "gameReady(" + QString::number(player) + ")";
        write(msg);
    }
    else
        qDebug() << "error in Fiar::playerReady" << endl;
}
//  player is ready

void Fiar::startGame()
{
    eventFlag = true;
    canChess = 0;
    if (! player)
        initTime();
}
//  start game

void Fiar::timeout()
{
    canChess ^= 1;
    endTime();
    write("Point(,)");
}
//  submit control and stop time

void Fiar::initTime()
{
    qDebug() << "initTime" << endl;
    ui->AdmitLoser->setEnabled(true);
    ui->Regret->setEnabled(true);
    ui->SaveBoard->setEnabled(true);
    ui->OpenBoard->setEnabled(true);
    timer->start(LIMITTIME);
    idTimer = startTimer(INTERVAL);
    limiTime = 20;
    emit leftTime(20);
    emit totalTime(totTime);
}
//  timer work

void Fiar::endTime()
{
    qDebug() << "endTime" << endl;
    ui->AdmitLoser->setEnabled(false);
    ui->Regret->setEnabled(false);
    ui->SaveBoard->setEnabled(false);
    ui->OpenBoard->setEnabled(false);
    if (idTimer != -1)
        killTimer(idTimer);
    idTimer = -1;
    timer->stop();
    ui->LeftTime->display(-1);
}
//  timer stop

void Fiar::Win(int who)
{
    QMessageBox::StandardButton reply;
    QString info = "<h2>you have ";
    if (who == player)
        info += "won</h2>";
    else
        info += "lost</h2>";
    reply = QMessageBox::question(this, "game over",
        info + "<h3>start(Yes)|quit(No)</h3>");
    if (reply == QMessageBox::Yes)
    {
        clearGame();
        playerReady(player);
    }
    else
        this->close();
}
//  game result

void Fiar::slotAdmitLosed()
{
    canChess ^= 1;
    endTime();
    write("admit");
}
//  ask the rival for admitting defeat

void Fiar::updateAdmit(QString msg)
{ 
    if ((! msg.contains("yes")) && (! msg.contains("no")))
    {
        QMessageBox::StandardButton reply;
        QString info = "<h2>the rival want to admit defeat\
            do you agree? </h2>";
        reply = QMessageBox::question(this, "ask for ending",
            info);
        if (reply == QMessageBox::Yes)
        {
            write("admityes");
            emit signalWin(player);
        }
        else
            write("admitno");
    }
    else if (msg.contains("yes"))
    {
        emit signalWin(player ^ 1);
    }
    else if (msg.contains("no"))
    {
        QMessageBox::information(this, "notice", "you must going on");
        canChess ^= 1;
        initTime();
    }
    else
        qDebug() << "error in update admit" << endl;
}
//  deal with things about admit defeat

void Fiar::slotGameOver()
{
    QMessageBox::information(this, "game over",
        "<h2>becasue the other player \
        quit the game, you have to quit game</h2>");
    this->close();
}
//  quit game

void Fiar::slotRegretRequest()
{
    qDebug() << "slotregret: " << me.size() << " " << have;
    if ((! me.size()) || (have > 1))
        return;
    canChess ^= 1;
    endTime();
    QPoint last = *me.top();
    write("regret(" + QString::number(last.x())
          + "," + QString::number(+ last.y()) + ")");
}
//  take back

void Fiar::updateRegret(QString msg)
{
    qDebug() << "updateregret"<< msg;
    if ((! msg.contains("yes")) && (! msg.contains("no")))
    {
        QMessageBox::StandardButton reply;
        QString info = "<h2>the rival want to take one step back\
            do you agree? </h2>";
        reply = QMessageBox::question(this, "ask for back",
            info);
        if (reply == QMessageBox::Yes)
        {
            QPoint last = *me.pop();
            qDebug() << "upyes: " << last.x() << " " << last.y();
            emit signalRegret(last);
            msg.replace("regret(", "");
            msg.replace(")", "");
            QStringList xy = msg.split(",");
            int cx = xy.at(0).toInt();
            int cy = xy.at(1).toInt();
            qDebug() << "upyesoop: "<< cx << " " << cy << endl;
            emit signalRegret(QPoint(cx, cy));
            write("regretyes(" + QString::number(last.x()) + ","
                  + QString::number(last.y()) + ")");
        }
        else
            write("regretno");
    }
    else if (msg.contains("yes"))
    {
        have++;
        if (have > 1)
            ui->Regret->setEnabled(false);
        QPoint last = *me.pop();
        qDebug() << last.x() << " regret " << last.y();
        emit signalRegret(last);
        msg.replace("regretyes(", "");
        msg.replace(")", "");
        QStringList xy = msg.split(",");
        int cx = xy.at(0).toInt();
        int cy = xy.at(1).toInt();
        qDebug() << cx << " regret " << cy;
        emit signalRegret(QPoint(cx, cy));
        canChess ^= 1;
        initTime();
    }
    else if (msg.contains("no"))
    {
        QMessageBox::information(this, "notice", "you must going on");
        canChess ^= 1;
        initTime();
    }
    else
        qDebug() << "error in updateregret" << endl;
}
//  deal with things about regret request

void Fiar::slotRegret(QPoint pos)
{
    boardbool[pos.x()][pos.y()] = -1;
    update();
}
//  back board

void Fiar::slotSaveBoard()
{
    endTime();
    QString dir = QFileDialog::getExistingDirectory(this, "Open Directory"
        , "E:/", QFileDialog::ShowDirsOnly);
    QString name = dir + "/" + QDateTime::currentDateTime().toString("yyyyMMddhhmmss") + ".fiar";
    qDebug() << "name: " << name << endl;
    QFile myboard(name);
    myboard.open(QFile::WriteOnly);
    QTextStream fileStream(&myboard);
    fileStream.setCodec("UTF-8");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
            fileStream << boardbool[i][j] << " ";
        fileStream << endl;
    }
    myboard.close();
    initTime();
}
//  save board

void Fiar::slotOpenBoard()
{
    canChess ^= 1;
    endTime();
    write("open");
}
//  open board request

void Fiar::updateBoard(QString msg)
{
    if ((! msg.contains("yes")) && (! msg.contains("no")))
    {
        QMessageBox::StandardButton reply;
        QString info = "<h2>the rival want to continue last game\
            do you agree? </h2>";
        reply = QMessageBox::question(this, "ask for open",
            info);
        if (reply == QMessageBox::Yes)
        {
            write("openyes");
        }
        else
            write("openno");
    }
    else if (msg.contains("yes"))
    {
        QString name = QFileDialog::getOpenFileName(this, "open file",
            "E:/", "Text files(*.fiar)");
        qDebug() << "name::: " << name << endl;
        QFile file(name);
        file.open(QFile::ReadOnly);
        QTextStream fileStream(&file);
        fileStream.setCodec("UTF-8");
        QString omsg = "continue";
        for (int i = 0; i < BOARD_SIZE; i++)
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                fileStream >> boardbool[i][j];
                omsg += QString::number(boardbool[i][j] + 1);
            }
        file.close();
        write(omsg);
        me.clear();
        update();
    }
    else if (msg.contains("no"))
    {
        QMessageBox::information(this, "notice", "you must going on");
        canChess ^= 1;
        initTime();
    }
    else
        qDebug() << "bug in open" << endl;
}
//  request about open board

void Fiar::updateContinue(QString msg)
{
    qDebug() << "continue update: " << msg << endl;
    int l = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            boardbool[i][j] = msg[l++].toLatin1() - '0' - 1;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
            if (boardbool[i][j] != -1)
            qDebug() << i << " " << j << " " << boardbool[i][j] << " ";
    }
    me.clear();
    update();
    canChess ^= 1;
    initTime();
}
//  continue last game

void Fiar::clearGame()
{
    qDebug() << "clearGame" << endl;
    eventFlag = false;
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            boardbool[i][j] = -1;
    totTime = 0;
    me.clear();
    endTime();
    if (! player)
        myServer->playerTotal = 0;
}
//  clear information and play again

void Fiar::write(QString msg)
{
    qDebug() << "write to other msg:" << msg << " " << msg.length() << endl;
/*    auto byteArr = msg.toLatin1();
    const char* charArr = byteArr;
    for (int i = 0; i < msg.length(); i++)
        qDebug() << QString("%1, %2, %3").arg(i).arg((int)msg.at(i).toLatin1()).arg((int)charArr[i]);
*/
    if (! player)
//        emit myServer->write(byteArr.data(), byteArr.size());
//        emit myServer->write(charArr, msg.length());
        emit myServer->write(msg.toLatin1());
    else
        myClient->write(msg);
}
//  sent message to the rival

Fiar::Fiar():
    Board(this)
  , have(0)
  , timer(new QTimer(this))
  , totTime(0)

  , idTimer(-1)
{
    eventFlag = false;
    connect(this, SIGNAL(gameReady(int)), this, SLOT(playerReady(int)));
    //  relate to game begining
    connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
    //  relate to 20s time out
    connect(this, SIGNAL(leftTime(int)), ui->LeftTime, SLOT(display(int)));
    //  relate to 20s time left
    connect(this, SIGNAL(totalTime(int)), ui->TotalTime, SLOT(display(int)));
    //  relate to player's game time
    connect(this, SIGNAL(signalWin(int)), this, SLOT(Win(int)));
    //  relate to victory judgment
    connect(this, SIGNAL(admitLosed()), this, SLOT(slotAdmitLosed()));
    //  relate to admitting defeat
    connect(this, SIGNAL(regretRequest()), this, SLOT(slotRegretRequest()));
    connect(this, SIGNAL(signalRegret(QPoint)), this, SLOT(slotRegret(QPoint)));
    //  relate to take back
    connect(this, SIGNAL(saveBoard()), this, SLOT(slotSaveBoard()));
    //  relate to save board
    connect(this, SIGNAL(openBoard()), this, SLOT(slotOpenBoard()));
    //  relate to open board
}

void Fiar::paintEvent(QPaintEvent *e)
{
    Board::paintEvent(e);
    if (eventFlag == false)
        return;
    QPainter drawer(this);
    drawer.setBrush(QBrush(Qt::white));
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            if (boardbool[i][j] == 1)
                drawer.drawEllipse(*board[i][j], GRID_SIZE >> 1, GRID_SIZE >> 1);
    drawer.setBrush(QBrush(Qt::black));
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            if (boardbool[i][j] == 0)
                drawer.drawEllipse(*board[i][j], GRID_SIZE >> 1, GRID_SIZE >> 1);
}

void Fiar::mousePressEvent(QMouseEvent *e)
{
    if (canChess != player)
        return;
    QPoint pos = calculate(e->x(), e->y());
    if (pos.x() == -1)
        return;
    if (player == 1)
    {
        QString msg = "Point(" + QString::number(pos.x())
                + "," + QString::number(pos.y()) + ")";
        write(msg);
        //  sent to server
    }
    else
        myServer->move(pos.x(), pos.y());
        //  sent to client
    boardbool[pos.x()][pos.y()] = player;
    QPoint* mepos = new QPoint(pos);
    me.push(mepos);
    canChess ^= 1;
    have = 0;
    ui->Regret->setEnabled(true);
    //  turn the rival
    endTime();
    //  timer stop
    update();
    if (isWin(pos.x(), pos.y()))
        emit signalWin(player);
}

void Fiar::timerEvent(QTimerEvent *)
{
    limiTime--;
    totTime++;
    emit leftTime(limiTime);
    emit totalTime(totTime);
}


