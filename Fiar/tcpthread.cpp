#include "tcpthread.h"

#include "server.h"

#include <QDebug>

TcpThread::TcpThread(int socketDescriptor, Server* owner, QObject *parent) :
    QThread(parent)
  , socketDescriptor(socketDescriptor)
  , owner(owner)
{
}

void TcpThread::run()
{
    qDebug() << "thread start to run" << endl;
    tcpClient = new TcpSocket(this);
    if (! tcpClient->setSocketDescriptor(socketDescriptor))
    {
        qDebug() << "TcpThread run error" << endl;
        emit error(tcpClient->error());
        return;
    }
    connect(tcpClient, SIGNAL(updateClients(QString,int)), owner, SLOT(updateClients(QString,int)));
    //  socket inform server
    connect(owner, SIGNAL(write(const char*)), tcpClient, SLOT(difThrWrite(const char*)));
    connect(owner, SIGNAL(write(const char*,qint64)), tcpClient, SLOT(difThrWrite(const char*, qint64)));
    connect(owner, SIGNAL(write(QByteArray)), tcpClient, SLOT(difThrWrite(QByteArray)));
    //  server write to socket

    this->exec();
    tcpClient->deleteLater();
    //delete socket object
}

void TcpThread::slotDisconnected()
{
    qDebug() << socketDescriptor << " Disconnected.";
    emit socketDisconnected(this->socketDescriptor);
    exit(0);
    //exit event loop
}
//  the thread is over
