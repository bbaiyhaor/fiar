#ifndef SERVER_H
#define SERVER_H

#include "tcpsocket.h"
#include "tcpthread.h"

#include <QTcpServer>
#include <QList>
#include <QString>

class Server : public QTcpServer
{
    Q_OBJECT

    friend class Fiar;
public:
    int port;
    QList<TcpThread*> tcpClientThreads;
private:
    int playerTotal;
private:
    bool isMove(QString, int);
    bool isRegret(QString, int);
    bool isAdmitLoser(QString, int);
    bool isStart(QString, int);
    bool isOpen(QString, int);
    bool isContinue(QString, int);
    void move(int x, int y);
    void startgame();
public:
    explicit Server(QObject *parent = 0, int = 1234);
    void gameReady(int);

signals:
    void updateFiarMove(QString, int);
    void startGame();
    void write(const char * data, qint64 maxSize);
    void write(const char * data);
    void write(const QByteArray & byteArray);
    void updateFiarAdmit(QString);
    void updateFiarRegret(QString);
    void updateFiarBoard(QString);
    void gameOver();
    void updateFiarContinue(QString);
public slots:
    void updateClients(QString, int);
    void slotDisconnected(int);
protected:
    void incomingConnection(int socketDescriptor);
};

#endif // SERVER_H
