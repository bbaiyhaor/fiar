#include "board.h"
#include "fiar.h"

#include <QPainter>
#include <QDebug>
#include <QNetworkInterface>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QHostInfo>

Board::Board(Fiar* kid, QWidget *parent) :
    QDialog(parent)
  , player(-1)
  , ui(new Ui::Board)
  , kid(kid)

{
    ui->setupUi(this);
    for (int i = 1; i <= BOARD_SIZE; i++)
        for (int j = 1; j <= BOARD_SIZE; j++)
            board[i - 1][j - 1] = new QPoint(GRID_SIZE * j, GRID_SIZE * i);
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            boardbool[i][j] = -1;
    ui->AdmitLoser->setEnabled(false);
    ui->Regret->setEnabled(false);
    ui->SaveBoard->setEnabled(false);
    ui->StartGame->setEnabled(false);
    ui->OpenBoard->setEnabled(false);
}

Board::~Board()
{
    delete ui;
}

void Board::paintEvent(QPaintEvent *)
{
    QPainter drawer(this);
    drawer.setBrush(QBrush(Qt::yellow));
    drawer.drawRect(QRect(*board[0][0], QSize((BOARD_SIZE - 1)* GRID_SIZE, (BOARD_SIZE - 1) * GRID_SIZE)));
    drawer.setPen(QPen(QBrush(Qt::black), 2));
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        drawer.drawLine(*board[0][i], *board[BOARD_SIZE - 1][i]);
        drawer.drawLine(*board[i][0], *board[i][BOARD_SIZE - 1]);
    }
}

QPoint Board::calculate(int x, int y)
{
    if ((x <= board[0][0]->x() - GRID_SIZE / 2) ||
        (x >= board[0][BOARD_SIZE - 1]->x() + GRID_SIZE / 2) ||
        (y <= board[0][0]->y() - GRID_SIZE / 2) ||
        (y >= board[BOARD_SIZE - 1][0]->y() + GRID_SIZE / 2))
        return QPoint(-1, -1);
    qDebug() << "calculate: " << x << " " << y << endl;
    x = x - (board[0][0]->x() - GRID_SIZE / 2);
    y = y - (board[0][0]->y() - GRID_SIZE / 2);
    qDebug() << "calculate1: " << x << " " << y << endl;
    x /= GRID_SIZE;
    y /= GRID_SIZE;
    qDebug() << "calculate2: " << x << " " << y << endl;
    if (boardbool[y][x] != -1)
        return QPoint(-1, -1);
    return QPoint(y, x);
}
//  calculate the chess position as (row, col)

bool Board::isWin(int r, int c)
{
    int tot = 0;
    int cc = c - 1;
    while ((cc >= 0) && (boardbool[r][cc] == boardbool[r][c]))
        tot++, cc--;
    cc = c + 1;
    while ((cc < BOARD_SIZE) && (boardbool[r][cc] == boardbool[r][c]))
        tot++, cc++;
    if (tot > 3)
        return true;
    //  horizon
    tot = 0;
    int rr = r - 1;
    while ((rr >= 0) && (boardbool[rr][c] == boardbool[r][c]))
        tot++, rr--;
    rr = r + 1;
    while ((rr < BOARD_SIZE) && (boardbool[rr][c] == boardbool[r][c]))
        tot++, rr++;
    if (tot > 3)
        return true;
    //  vertical
    rr = r - 1;
    cc = c - 1;
    tot = 0;
    while ((rr >= 0) && (cc >= 0) &&
           (boardbool[rr][cc] == boardbool[r][c]))
        rr--, cc--, tot++;
    rr = r + 1;
    cc = c + 1;
    while ((rr < BOARD_SIZE) && (cc < BOARD_SIZE) &&
           (boardbool[rr][cc] == boardbool[r][c]))
        rr++, cc++, tot++;
    if (tot > 3)
        return true;
    //  45 sideling
    rr = r - 1;
    cc = c + 1;
    tot = 0;
    while ((rr >= 0) && (cc < BOARD_SIZE) &&
           (boardbool[rr][cc] == boardbool[r][c]))
        rr--, cc++, tot++;
    rr = r + 1;
    cc = c -1;
    while ((rr < BOARD_SIZE) && (cc >= 0) &&
           (boardbool[rr][cc] == boardbool[r][c]))
        rr++, cc--, tot++;
    if (tot > 3)
        return true;
    //  135 sideling
    return false;
}
//  judge if win

void Board::on_CreateServer_clicked()
{
    QString hostname = QHostInfo::localHostName(), ipAddress;
    QHostInfo hostInfo = QHostInfo::fromName(hostname);
    QList<QHostAddress> listAddress = hostInfo.addresses();
    if (! listAddress.isEmpty())
    {
        for (int i = 0; i < listAddress.count(); i++)
        {
            QHostAddress address = listAddress.at(i);
            if (address.protocol() == QAbstractSocket::IPv4Protocol
                    && address != QHostAddress(QHostAddress::LocalHost))
            {
                ipAddress = address.toString();
                qDebug() << "ip " << ipAddress << endl;
            }
        }
    }
    QDialog request(this);
    QLabel hostLabel("主机名: ");
    QLineEdit LineEditLocalHostName(hostname);
    LineEditLocalHostName.setReadOnly(true);
    QLabel ipLabel("IP 地址: ");
    QLineEdit LineEditAddress(ipAddress);
    LineEditAddress.setReadOnly(true);
    QPushButton detailBtn("创建");
    QGridLayout mainLayout(&request);
    mainLayout.addWidget(&hostLabel, 0, 0);
    mainLayout.addWidget(&LineEditLocalHostName, 0, 1);
    mainLayout.addWidget(&ipLabel, 1, 0);
    mainLayout.addWidget(&LineEditAddress, 1, 1);
    mainLayout.addWidget(&detailBtn, 2, 0, 1, 2);
    connect(&detailBtn, SIGNAL(clicked()), this->kid, SLOT(initMyServer()));
    connect(&detailBtn, SIGNAL(clicked()), &request, SLOT(close()));
    request.exec();
}
//  create host

void Board::on_JoinRoom_clicked()
{
    QDialog request(this);
    QLabel portLabel("端口: ");
    QLineEdit LineEditLocalHostName;
    QLabel ipLabel("IP 地址: ");
    QLineEdit LineEditAddress;
    QPushButton detailBtn("加入");
    QGridLayout mainLayout(&request);
    mainLayout.addWidget(&portLabel, 0, 0);
    mainLayout.addWidget(&LineEditLocalHostName, 0, 1);
    mainLayout.addWidget(&ipLabel, 1, 0);
    mainLayout.addWidget(&LineEditAddress, 1, 1);
    mainLayout.addWidget(&detailBtn, 2, 0, 1, 2);
    connect(this, SIGNAL(initMyClient(QString,int)), this->kid, SLOT(initMyClient(QString,int)));
    connect(&detailBtn, SIGNAL(clicked()), &request, SLOT(close()));
    request.exec();
    QString ip, port;
    port = LineEditLocalHostName.text();
    ip = LineEditAddress.text();
    emit initMyClient(ip, port.toInt());
}
//  join room

void Board::on_StartGame_clicked()
{
    if (player != -1)
    {
        ui->StartGame->setText(QString("已准备"));
        ui->StartGame->setEnabled(false);
        emit gameReady(player);
    }
}
//  start game

void Board::on_Regret_clicked()
{
    emit regretRequest();
}

void Board::on_SaveBoard_clicked()
{
    emit saveBoard();
}

void Board::on_AdmitLoser_clicked()
{
    emit admitLosed();
}
//  admit losed

void Board::on_OpenBoard_clicked()
{
    emit openBoard();
}
