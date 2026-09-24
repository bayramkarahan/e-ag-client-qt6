#include "streamplayer.h"

StreamPlayer::StreamPlayer(QObject *parent)
    : QObject(parent)
{
}

bool StreamPlayer::open(StreamSettings &settings)
{
    //

    if (settings.mode == StreamMode::Receiver)
    {  m_settings = settings;
        if (settings.video.source == CaptureSource::MediaFile){
            m_settings.video.timeMode = TimeMode::FramePts;
          }

        qDebug()<<"m_settings.video.timeMode"<<int(m_settings.video.timeMode);
        qDebug()<<"CaptureSource::MediaFile"<<int(CaptureSource::MediaFile);
        qDebug()<<"settings.video.source"<<int(settings.video.source);




        return m_receiver.open(m_settings);
    }
    return true;
}

bool StreamPlayer::start()
{

    return m_receiver.start();
}


void StreamPlayer::stop()
{

        m_receiver.stop();
}
