#include "radio.h"
#include "ui_radio.h"

Radio::Radio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Radio),
    player(new QMediaPlayer),
    btnState(true)
{
    ui->setupUi(this);

    player->setMedia(QUrl("http://sc7.spacialnet.com:22018"));
    player->setVolume(100);

    //connect
    connect(ui->cmd,SIGNAL(clicked()),SLOT(slotPlayPause()));
    connect(&timer,SIGNAL(timeout()),SLOT(slotTitle()));
    connect(ui->volume,SIGNAL(valueChanged(int)),player,SLOT(setVolume(int)));
}

Radio::~Radio()
{
    delete ui;
}

void Radio::slotPlayPause()
{
    if(btnState)
    {
        player->setMedia(QUrl("http://sc7.spacialnet.com:22018"));
        player->play();
        ui->cmd->setText("Stop");
        btnState = false;
        ui->txt->setText(player->metaData("Title").toString());
        timer.start(1000);
    }
    else
    {
        player->stop();
        ui->cmd->setText("Play");
        btnState = true;
        timer.stop();
    }
}

void Radio::slotTitle()
{
    ui->txt->setText(player->metaData("Title").toString());
}
