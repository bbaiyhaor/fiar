#ifndef TCPTHREAD_H
#define TCPTHREAD_H

#include "tcpsocket.h"

#include <QThread>

class Server;

class TcpThread : public QThread
{
    Q_OBJECT

    friend class Server;
private:
    int socketDescriptor;
    Server* owner;
    TcpSocket* tcpClient;
public:
    explicit TcpThread(int socketDescriptor, Server* owner, QObject *parent = 0);
    void run();

signals:
    void socketDisconnected(int);
    void error(QTcpSocket::SocketError socketError);
public slots:
    void slotDisconnected();
};

#endif // TCPTHREAD_H
