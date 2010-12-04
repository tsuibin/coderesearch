#include "mp3player.h"
#include "ui_mp3player.h"

Mp3Player::Mp3Player(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mp3Player)
{
    ui->setupUi(this);

    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    mediaObject = new Phonon::MediaObject(this);

    Phonon::createPath(mediaObject, audioOutput);

    Phonon::MediaSource source("/home/tsuibin/Music/show.mp3");

    mediaObject->setCurrentSource(source);

    //mediaObject->play();




}

Mp3Player::~Mp3Player()
{
    delete ui;
}

void Mp3Player::on_pB_play_clicked()
{
    mediaObject->play();
}

void Mp3Player::on_pB_pause_clicked()
{
    mediaObject->pause();
}

void Mp3Player::on_pB_stop_clicked()
{
    mediaObject->stop();
}
