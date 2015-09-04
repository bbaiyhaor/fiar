#include "client.h"

#include <QMessageBox>
#include <QString>

void Client::updateMove(QString msg, int length)
{
    if (isStart(msg, length))
    {
        emit startGame();
    }
    else if (isMove(msg, length))
    {
        msg.replace("Point(", "");
        msg.replace(")", "");
        emit updateFiarMove(msg, length);
    }
    else if (isRegret(msg, length))
    {
        qDebug() << "client regret" << endl;
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

bool Client::isMove(QString msg, int)
{
    if (msg.contains("Point"))
        return true;
    return false;
}

bool Client::isRegret(QString msg, int)
{
    if (msg.contains("regret"))
        return true;
    return false;
}

bool Client::isAdmitLoser(QString msg, int)
{
    if (msg.contains("admit"))
        return true;
    return false;
}

bool Client::isStart(QString msg, int)
{
    if (msg.contains("startGame"))
        return true;
    return false;
}

bool Client::isOpen(QString msg, int)
{
    if (msg.contains("open"))
        return true;
    return false;
}

bool Client::isContinue(QString msg, int)
{
    if (msg.contains("continue"))
        return true;
    return false;
}

Client::Client(QString ip, int port, QObject *parent):
    QObject(parent)
  , port(port)
  , serverIP(0)
{
    serverIP = new QHostAddress;
    if (! serverIP->setAddress(ip))
    {
        QMessageBox::information(0, "错误信息", "ip有误");
        delete serverIP;
        serverIP = 0;
        return;
    }
    moveSocket = new QTcpSocket(this);
    moveSocket->connectToHost(*serverIP, port);
    connect(moveSocket, SIGNAL(readyRead()), this, SLOT(dataReceived()));
    connect(moveSocket, SIGNAL(disconnected()), this, SLOT(slotDisconnected()));
    qDebug() << "client created" << endl;
}

void Client::dataReceived()
{
    while (moveSocket->bytesAvailable() > 0)
    {
      /*  qint64 length = moveSocket->bytesAvailable();
        char buf[length+1];
        buf[length] = '\0';
        int effLen = moveSocket->read(buf, length);
        for (int i = 0; i < length; ++i)
            qDebug() << QString("buf[%1] = %2").arg(i).arg((int)buf[i]);
        qDebug() << "Client::dataRecieved bytes: " << effLen << buf   << endl;
        QString msg = buf;
        qDebug() << "madan: " << msg << endl;
there is a bug which I cannot solve
*/
        QByteArray datagram;
        datagram.resize(moveSocket->bytesAvailable());
        qDebug() << "client receive byte: " <<
            moveSocket->read(datagram.data(), datagram.size())
            << " " << datagram << endl;
        QString msg = datagram.data();
        updateMove(msg, msg.length());
    }
}

void Client::slotDisconnected()
{
    qDebug() << "server quit" << endl;
    emit gameOver();
}
