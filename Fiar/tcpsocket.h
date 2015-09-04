#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QTcpSocket>
#include <QString>

class TcpThread;

class TcpSocket : public QTcpSocket
{
    Q_OBJECT
private:
    TcpThread* owner;
public:
    explicit TcpSocket(TcpThread* owner, QObject *parent = 0);

signals:
    void updateClients(QString, int);
public slots:
    void dataRecieved();
    qint64 difThrWrite(const char * data, qint64 maxSize)
    {
        return this->write(data, maxSize);
    }
    qint64 difThrWrite(const char * data)
    {
        return this->write(data);
    }
    qint64 difThrWrite(const QByteArray & byteArray)
    {
        return this->write(byteArray);
    }
};

#endif // TCPSOCKET_H
