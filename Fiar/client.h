#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QHostAddress>
#include <QTcpSocket>
#include <QString>

class Client : public QObject
{
    Q_OBJECT

    friend class Fiar;
private:
    int port;
    QHostAddress *serverIP;
    QTcpSocket *moveSocket;
private:
    void updateMove(QString, int);
    bool isMove(QString, int);
    bool isRegret(QString, int);
    bool isAdmitLoser(QString, int);
    bool isStart(QString, int);
    bool isOpen(QString, int);
    bool isContinue(QString, int);
    void write(QString qdata)
    {
        qDebug() << "write to server: "
                 << qdata << " " << qdata.length() << endl;
        moveSocket->write(qdata.toLatin1());
    }
public:
    explicit Client(QString ip, int port, QObject *parent = 0);

signals:
    void startGame();
    void updateFiarMove(QString, int);
    void updateFiarAdmit(QString);
    void gameOver();
    void updateFiarRegret(QString);
    void updateFiarBoard(QString);
    void updateFiarContinue(QString);
public slots:
    void dataReceived();
    void slotDisconnected();
};

#endif // CLIENT_H
