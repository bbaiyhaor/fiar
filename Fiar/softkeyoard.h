#ifndef SOFTKEYOARD_H
#define SOFTKEYOARD_H

#include <QDialog>
#include <QSignalMapper>
#include <QLineEdit>

class SoftKeyoard : public QDialog
{
    Q_OBJECT
public:
    QSignalMapper* mapper;
    QLineEdit* myEdit;
public:
    explicit SoftKeyoard(QWidget *parent = 0);
signals:
    void IPAdress(QString);
public slots:
    void keyPress(int);
    void slotDot();
    void slotOk();
    void slotDel();
};

#endif // SOFTKEYOARD_H
