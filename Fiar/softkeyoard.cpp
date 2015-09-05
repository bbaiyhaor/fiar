#include "softkeyoard.h"

#include <QPushButton>
#include <QString>
#include <QGridLayout>
#include <QDebug>

SoftKeyoard::SoftKeyoard(QWidget *parent) :
    QDialog(parent)
{
    QGridLayout* myGrid = new QGridLayout(this);
    mapper = new QSignalMapper(this);
    QPushButton *dot = new QPushButton(".");
    connect(dot, SIGNAL(clicked()), this, SLOT(slotDot()));
    QPushButton *ok = new QPushButton("ok");
    connect(ok , SIGNAL(clicked()), this, SLOT(slotOk()));
    QPushButton *cancel = new QPushButton("del");
    connect(cancel, SIGNAL(clicked()), this, SLOT(slotDel()));
    QPushButton *number = new QPushButton[10];
    for (int i = 0; i < 10; i++)
    {
        number[i].setText(QString::number(i));
        connect(&number[i], SIGNAL(clicked()), mapper, SLOT(map()));
        mapper->setMapping(&number[i], i);
    }
    connect(mapper, SIGNAL(mapped(int)), this, SLOT(keyPress(int)));
    for (int i = 0; i < 5; i++)
        myGrid->addWidget(&number[i], 0, i << 1, 2, 2);
    for (int i = 6; i < 10; i++)
        myGrid->addWidget(&number[i], 3, (i - 6) << 1, 2, 2);
    myGrid->addWidget(dot, 6, 0, 2, 2);
    myGrid->addWidget(ok, 6, 4, 2, 2);
    myGrid->addWidget(cancel, 6, 8, 2, 2);
    myEdit = new QLineEdit(this);
    myGrid->addWidget(myEdit, 9, 0, 15, 15);
}

void SoftKeyoard::keyPress(int v)
{
    QString text = myEdit->text() + QString::number(v);
    myEdit->setText(text);
}

void SoftKeyoard::slotDot()
{
    QString text = myEdit->text() + ".";
    myEdit->setText(text);
}

void SoftKeyoard::slotOk()
{
    emit IPAdress(myEdit->text());
    close();
}

void SoftKeyoard::slotDel()
{
    QString text = myEdit->text();
    if (text.length() > 0)
        text.replace(text.length() - 1, 1, "");
    myEdit->setText(text);
}

