#ifndef BOARD_H
#define BOARD_H

#include "ui_board.h"

#include <QDialog>

#include <QStack>
#include <QPoint>

const int BOARD_SIZE = 15;
const int GRID_SIZE = 40;

class Fiar;

class Board : public QDialog
{
    Q_OBJECT

    friend class Fiar;
public:
    QPoint* board[BOARD_SIZE][BOARD_SIZE];
    int boardbool[BOARD_SIZE][BOARD_SIZE];
    QStack<QPoint*> me;
    int player;
public:
    void paintEvent(QPaintEvent *);
    QPoint calculate(int, int);
    bool isWin(int r, int c);
public:
    explicit Board(Fiar*, QWidget *parent = 0);
    ~Board();

signals:
    void initMyClient(QString, int);
    void gameReady(int);
    void admitLosed();
    void regretRequest();
    void saveBoard();
    void openBoard();
private slots:
    void on_CreateServer_clicked();

    void on_JoinRoom_clicked();

    void on_StartGame_clicked();

    void on_Regret_clicked();

    void on_SaveBoard_clicked();

    void on_AdmitLoser_clicked();

    void on_OpenBoard_clicked();

private:
    Ui::Board *ui;
    Fiar* kid;
};

#endif // BOARD_H
