#include "radio.h"
#include "ui_radio.h"

Radio::Radio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Radio),
    player(new QMediaPlayer),
    btnState(true)
{
    ui->setupUi(this);

    setWindowFlags(Qt::CustomizeWindowHint);

    player->setMedia(QUrl("http://sc7.spacialnet.com:22018"));
    player->setVolume(100);

    // INIT
    ui->cmd->setIcon(QIcon("dar_stop.png"));
    ui->cmd->setIconSize(QSize(75,60));
    ui->cmd->setFixedSize(75,60);
    ui->txt->setPalette(palette());
    ui->cmd->setStyleSheet("QToolButton {border: 0px solid #8f8f91;border-radius: 0px;}");


    //connect
    connect(ui->cmd,SIGNAL(clicked()),SLOT(slotPlayPause()));
    connect(&timer,SIGNAL(timeout()),SLOT(slotTitle()));
    connect(ui->volume,SIGNAL(valueChanged(int)),player,SLOT(setVolume(int)));
}

Radio::~Radio()
{
    delete ui;
}

void Radio::mouseMoveEvent(QMouseEvent *pe)
{
    //перетаскивание окна
        if(ui->wgt1->geometry().contains(mPos) || ui->wgt2->geometry().contains(mPos))
            move(pe->globalPos() - mPos);
}

void Radio::keyPressEvent(QKeyEvent *pe)
{
    switch(pe->key())
    {
    case Qt::Key_F12:
        close();
        break;
    }
}

void Radio::slotPlayPause()
{
    if(btnState)
    {
        player->setMedia(QUrl("http://sc7.spacialnet.com:22018"));
        player->play();
        ui->cmd->setIcon(QIcon("dar_play.png"));
        btnState = false;
        ui->txt->setText(player->metaData("Title").toString());
        timer.start(1000);
    }
    else
    {
        player->stop();
        ui->cmd->setIcon(QIcon("dar_stop.png"));
        btnState = true;
        timer.stop();
    }
}

void Radio::slotTitle()
{
    if(title != ui->txt->text())
    {
        title = player->metaData("Title").toString();
        ui->txt->setText(title);
    }
}


void Radio::mousePressEvent(QMouseEvent *pe)
{
    mPos = pe->pos();
}
