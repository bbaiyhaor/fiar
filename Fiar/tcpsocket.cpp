#include "tcpsocket.h"
#include "tcpthread.h"

TcpSocket::TcpSocket(TcpThread* owner, QObject *parent) :
    QTcpSocket(parent)
  , owner(owner)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(dataRecieved()));
    connect(this, SIGNAL(disconnected()), owner, SLOT(slotDisconnected()));
    //  connect the essential signal to essential slot
}

void TcpSocket::dataRecieved()
{
    while (bytesAvailable() > 0)
    {
        QByteArray datagram;
        datagram.resize(this->bytesAvailable());
        qDebug() << "server receive byte: " <<
        this->read(datagram.data(), datagram.size())
        << " " << datagram << endl;
        QString msg = datagram.data();
        emit updateClients(msg, msg.length());
        //  when socket get news emit the signal to inform server
    }
}
//  get news from clients


