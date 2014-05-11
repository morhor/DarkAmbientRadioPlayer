#ifndef RADIO_H
#define RADIO_H

#include <QWidget>
#include <QMediaPlayer>
#include <QTimer>
#include <QDebug>

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
    bool btnState;
public:
    Radio(QWidget *parent = 0);
    ~Radio();
public slots:
    void slotPlayPause();
    void slotTitle();
};

#endif // RADIO_H
