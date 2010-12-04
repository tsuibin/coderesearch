#ifndef MP3PLAYER_H
#define MP3PLAYER_H

#include <QWidget>

#include <phonon/audiooutput.h>
#include <phonon/mediaobject.h>

namespace Ui {
    class Mp3Player;
}

class Mp3Player : public QWidget
{
    Q_OBJECT

public:
    explicit Mp3Player(QWidget *parent = 0);
    ~Mp3Player();

private:
    Ui::Mp3Player *ui;

    Phonon::MediaObject *mediaObject;
    Phonon::AudioOutput *audioOutput;


private slots:
    void on_pB_stop_clicked();
    void on_pB_pause_clicked();
    void on_pB_play_clicked();
};

#endif // MP3PLAYER_H
