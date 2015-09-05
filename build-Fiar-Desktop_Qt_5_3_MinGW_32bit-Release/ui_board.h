/********************************************************************************
** Form generated from reading UI file 'board.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOARD_H
#define UI_BOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Board
{
public:
    QPushButton *CreateServer;
    QPushButton *JoinRoom;
    QPushButton *StartGame;
    QPushButton *Regret;
    QPushButton *SaveBoard;
    QPushButton *AdmitLoser;
    QLCDNumber *LeftTime;
    QLCDNumber *TotalTime;
    QLabel *label;
    QLabel *label_2;
    QPushButton *OpenBoard;

    void setupUi(QDialog *Board)
    {
        if (Board->objectName().isEmpty())
            Board->setObjectName(QStringLiteral("Board"));
        Board->resize(800, 640);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Board->sizePolicy().hasHeightForWidth());
        Board->setSizePolicy(sizePolicy);
        CreateServer = new QPushButton(Board);
        CreateServer->setObjectName(QStringLiteral("CreateServer"));
        CreateServer->setGeometry(QRect(700, 60, 75, 40));
        JoinRoom = new QPushButton(Board);
        JoinRoom->setObjectName(QStringLiteral("JoinRoom"));
        JoinRoom->setGeometry(QRect(700, 110, 75, 40));
        StartGame = new QPushButton(Board);
        StartGame->setObjectName(QStringLiteral("StartGame"));
        StartGame->setGeometry(QRect(700, 210, 75, 40));
        Regret = new QPushButton(Board);
        Regret->setObjectName(QStringLiteral("Regret"));
        Regret->setGeometry(QRect(700, 260, 75, 40));
        SaveBoard = new QPushButton(Board);
        SaveBoard->setObjectName(QStringLiteral("SaveBoard"));
        SaveBoard->setGeometry(QRect(700, 310, 75, 40));
        AdmitLoser = new QPushButton(Board);
        AdmitLoser->setObjectName(QStringLiteral("AdmitLoser"));
        AdmitLoser->setGeometry(QRect(700, 360, 75, 40));
        LeftTime = new QLCDNumber(Board);
        LeftTime->setObjectName(QStringLiteral("LeftTime"));
        LeftTime->setGeometry(QRect(700, 430, 75, 51));
        TotalTime = new QLCDNumber(Board);
        TotalTime->setObjectName(QStringLiteral("TotalTime"));
        TotalTime->setGeometry(QRect(700, 510, 75, 51));
        label = new QLabel(Board);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(710, 410, 61, 16));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Board);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(710, 490, 54, 12));
        label_2->setAlignment(Qt::AlignCenter);
        OpenBoard = new QPushButton(Board);
        OpenBoard->setObjectName(QStringLiteral("OpenBoard"));
        OpenBoard->setGeometry(QRect(700, 160, 75, 40));

        retranslateUi(Board);

        QMetaObject::connectSlotsByName(Board);
    } // setupUi

    void retranslateUi(QDialog *Board)
    {
        Board->setWindowTitle(QApplication::translate("Board", "Board", 0));
        CreateServer->setText(QApplication::translate("Board", "\345\210\233\345\273\272\346\210\277\351\227\264", 0));
        JoinRoom->setText(QApplication::translate("Board", "\345\212\240\345\205\245\346\210\277\351\227\264", 0));
        StartGame->setText(QApplication::translate("Board", "\345\274\200\345\247\213\346\270\270\346\210\217", 0));
        Regret->setText(QApplication::translate("Board", "\346\202\224\346\243\213", 0));
        SaveBoard->setText(QApplication::translate("Board", "\344\277\235\345\255\230\346\243\213\345\261\200", 0));
        AdmitLoser->setText(QApplication::translate("Board", "\350\256\244\350\276\223", 0));
        label->setText(QApplication::translate("Board", "\346\227\266\351\231\220", 0));
        label_2->setText(QApplication::translate("Board", "\346\200\273\346\227\266\351\227\264", 0));
        OpenBoard->setText(QApplication::translate("Board", "\346\211\223\345\274\200\346\256\213\345\261\200", 0));
    } // retranslateUi

};

namespace Ui {
    class Board: public Ui_Board {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOARD_H
