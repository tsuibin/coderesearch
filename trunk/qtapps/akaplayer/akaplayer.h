
#ifndef AKAPLAYER_H
#define AKAPLAYER_H

#include <QMainWindow>
#include <phonon/audiooutput.h>
#include <phonon/mediaobject.h>
#include <QList>
#include <QDebug>


class AKAPlayer : public QMainWindow
{
    Q_OBJECT

public:
    AKAPlayer();

private slots:
    void stateChanged(Phonon::State newState, Phonon::State oldState);
private:

    Phonon::MediaObject *mediaObject;
    Phonon::AudioOutput *audioOutput;

};

#endif //AKAPLAYER_H
