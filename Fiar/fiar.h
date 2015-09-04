#ifndef FIAR_H
#define FIAR_H

#include "board.h"
#include "server.h"
#include "client.h"
#include <QMouseEvent>
#include <QTimer>

const int INTERVAL = 1000;
const int LIMITTIME = 20000;

class Fiar : public Board
{
    Q_OBJECT
    friend class Board;
private:
    Server* myServer;
    Client* myClient;
    bool eventFlag;
    int canChess, have;
    QTimer* timer;
    int totTime, limiTime, idTimer;
private slots:
    void initMyServer();
    void initMyClient(QString ip, int port);
    void updateChess(QString, int);
    void playerReady(int);
    void startGame();
    void timeout();
    void Win(int);
    void slotAdmitLosed();
    void updateAdmit(QString);
    void slotGameOver();
    void slotRegretRequest();
    void updateRegret(QString);
    void slotRegret(QPoint);
    void slotSaveBoard();
    void slotOpenBoard();
    void updateBoard(QString);
    void updateContinue(QString);
signals:
    void leftTime(int);
    void totalTime(int);
    void signalWin(int);
    void signalRegret(QPoint);
public:
    void initTime();
    void endTime();
    void clearGame();
    void write(QString);
public:
    Fiar();
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void timerEvent(QTimerEvent *);
};

#endif // FIAR_H
