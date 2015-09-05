#include "server.h"
#include <QMessageBox>

bool Server::isMove(QString msg, int)
{
    if (msg.contains("Point"))
        return true;
    return false;
}

bool Server::isRegret(QString msg, int)
{
    if (msg.contains("regret"))
        return true;
    return false;
}

bool Server::isAdmitLoser(QString msg, int)
{
    if (msg.contains("admit"))
        return true;
    return false;
}

bool Server::isStart(QString msg, int)
{
    if (msg.contains("gameReady"))
        return true;
    return false;
}

bool Server::isOpen(QString msg, int)
{
    if (msg.contains("open"))
        return true;
    return false;
}

bool Server::isContinue(QString msg, int)
{
    if (msg.contains("continue"))
        return true;
    return false;
}

void Server::move(int x, int y)
{
    QString msg = "Point(" + QString::number(x)
            + "," + QString::number(y) + ")";
    emit write(msg.toLatin1());
}
// inform client where to place

void Server::startgame()
{
    qDebug() << "startgame" << endl;
    emit write("startGame");
    emit startGame();
}

Server::Server(QObject *parent, int port) :
    QTcpServer(parent)
  , port(port)
  , playerTotal(0)
{
    listen(QHostAddress::Any, port);
}

void Server::updateClients(QString msg, int length)
{
    if (isStart(msg, length))
    {
        msg.replace("gameReady(", "");
        msg.replace(")", "");
        gameReady(msg.toInt());
    }
    else if (isMove(msg, length))
    {
        msg.replace("Point(", "");
        msg.replace(")", "");
        emit updateFiarMove(msg, length);
    }
    else if (isRegret(msg, length))
    {
        emit updateFiarRegret(msg);
    }
    else if (isAdmitLoser(msg, length))
    {
        emit updateFiarAdmit(msg);
    }
    else if (isOpen(msg, length))
    {
        qDebug() << "open " << msg;
        emit updateFiarBoard(msg);
    }
    else if (isContinue(msg, length))
    {
        msg.replace("continue","");
        qDebug() << "CONTINUE " << msg << endl;
        emit updateFiarContinue(msg);
    }
}
//  deal with the news from clients

void Server::slotDisconnected(int descriptor)
{
    qDebug() << "client " << descriptor << " break up" << endl;
    for (int i = 0; i < tcpClientThreads.count(); i++)
    {
        TcpThread *item = tcpClientThreads.at(i);
        if (item->socketDescriptor == descriptor)
        {
            tcpClientThreads.removeAt(i);
            emit gameOver();
            return;
        }
    }
}
//  remove the finished thread

void Server::gameReady(int player)
{
    if ((! player) || (player == 1))
        playerTotal++;
    else
        qDebug() << "error in server::gameReady" << endl;
    if (! (playerTotal % 2))
        startgame();
}
//  players is ready for beginning

void Server::incomingConnection(int socketDescriptor)
{
    qDebug() << "new connection start" << endl;
    TcpThread *thread = new TcpThread(socketDescriptor, this, 0);
    connect(thread, SIGNAL(socketDisconnected(int)), this, SLOT(slotDisconnected(int)));
    //  when thread is finished, remove it out of list
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    //  when thread is finished, delete it later
    tcpClientThreads.append(thread);
    thread->start();
}
//  for each socket, create a new thread to administrate it
