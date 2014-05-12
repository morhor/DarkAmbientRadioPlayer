#ifndef RADIO_H
#define RADIO_H

#include <QWidget>
#include <QMediaPlayer>
#include <QTimer>
#include <QDebug>
#include <QPalette>
#include <QString>
#include <QToolBox>
#include <QMouseEvent>
#include <QPoint>
#include <QKeyEvent>

namespace Ui {
class Radio;
}

class Radio : public QWidget
{
    Q_OBJECT
private:
    Ui::Radio *ui;
    QMediaPlayer * player;
    QTimer timer;
    QString title;
    bool btnState;
    QPoint mPos;
public:
    Radio(QWidget *parent = 0);
    ~Radio();
protected:
protected:
    virtual void mousePressEvent(QMouseEvent* pe);
    virtual void mouseMoveEvent(QMouseEvent *pe);
    virtual void keyPressEvent(QKeyEvent *pe);
public slots:
    void slotPlayPause();
    void slotTitle();
};

#endif // RADIO_H
