#include <QtGui>
#include "akaplayer.h"

AKAPlayer::AKAPlayer()
{
    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    mediaObject = new Phonon::MediaObject(this);

   // mediaObject->setTickInterval(1000);
//    connect(mediaObject, SIGNAL(stateChanged(Phonon::State,Phonon::State)),
//            this, SLOT(stateChanged(Phonon::State,Phonon::State)));

    Phonon::createPath(mediaObject, audioOutput);
    Phonon::MediaSource source("/home/tsuibin/Music/show.mp3");

    mediaObject->setCurrentSource(source);
    mediaObject->play();

//    QPushButton *play,*pause,*stop;

//    play = new QPushButton(this);
//    play->setGeometry(0,0,50,20);
//    play->setText("play");
//    pause = new QPushButton(this);
//    pause->setGeometry(60,0,50,30);
//    pause->setText("pause");

//    stop = new QPushButton(this);
//    stop->setGeometry(100,0,50,30);
//    stop->setText("stop");

//    connect(play, SIGNAL(clicked()), mediaObject, SLOT(play()));
//    connect(pause, SIGNAL(clicked()), mediaObject, SLOT(pause()) );
//    connect(stop, SIGNAL(clicked()), mediaObject, SLOT(stop()));

}

void AKAPlayer::stateChanged(Phonon::State newState, Phonon::State /* oldState */)
{
    switch (newState) {
        case Phonon::ErrorState:
                QMessageBox::warning(this, tr("Error"),
                mediaObject->errorString());
            break;
        case Phonon::PlayingState:break;
        case Phonon::StoppedState:break;
        case Phonon::PausedState:break;

        case Phonon::BufferingState:break;
        default:
            ;
    }
}
