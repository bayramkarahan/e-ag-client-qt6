#include "receiverpipeline.h"

#include "../decoder/audioopusdecoder.h"
#include "../decoder/h264depacketizer.h"

#include "../decoder/h264decoder.h"
#include "../decoder/CpuVideoDecoder.h"

#include "../decoder/AbstractVideoDecoder.h"
#include "../decoder/videodecoderfactory.h"

#include "../player/audioplayback.h"

#include "../preview/videopreview.h"
#include "../preview/openglvideopreview.h"

#include "../sync/mastertime.h"
#include "../sync/mediaclock.h"
#include "../sync/videoscheduler.h"
#include "../sync/audioscheduler.h"

ReceiverPipeline::ReceiverPipeline(QObject *parent)
    : QObject(parent)
{
}

bool ReceiverPipeline::open(const StreamSettings &settings)
{
    m_settings = settings;

    return true;
}
bool ReceiverPipeline::start()
{
    qDebug() << "RUNNING AS RECEIVER";

    m_clock = new MediaClock;

   /* m_renderer = new VideoRenderer;

    if (m_settings.previewMode != PreviewMode::None)
    {
        m_renderer->resize(960, 540);
        m_renderer->show();
    }*/

    m_openglrenderer = new OpenGLVideoRenderer;

        if (m_settings.previewMode != PreviewMode::None)
        {
            m_openglrenderer->resize(m_settings.video.width, m_settings.video.height);
            m_openglrenderer->show();
        }


    m_openglpreview = new OpenGLVideoPreview(m_openglrenderer);
    m_openglpreview->setMediaClock(m_clock);

    m_playback = new AudioPlayback;
    if (!m_playback->open(m_settings.audioSampleRate,
                          m_settings.audioChannels))
        return false;

    m_playback->setClock(m_clock);

    // RTSP
    m_rtspSource = new RtspSource(this);

    connect(m_rtspSource,
            &RtspSource::connected,
            []()
            {
                qDebug() << "RTSP Connected";
            });

    connect(m_rtspSource,
            &RtspSource::disconnected,
            []()
            {
                qDebug() << "RTSP Disconnected";
            });

    connect(m_rtspSource,
            &RtspSource::errorOccurred,
            [](const QString &err)
            {
                qCritical() << err;
            });

    ///video

   // m_videoDecoder = new H264Decoder(this);


//m_videoDecoder = VideoDecoderFactory::create(this);
//m_videoDecoder =new CpuVideoDecoder(this);

    m_videoDecoder = VideoDecoderFactory::create(this);

    /*if (!m_videoDecoder)
        return false;*/
    if(!m_videoDecoder->start())
        return -1;

    m_videoDecoder->setSettings(m_settings);
     //-------------------------------------
    // SCHEDULERS
    //-------------------------------------
    /// video
    m_videoScheduler = new VideoScheduler(m_clock);
    m_videoScheduler->open(m_settings.video);

     connect(m_rtspSource,
             &RtspSource::videoPacket,
             m_videoDecoder,
             &AbstractVideoDecoder::decode,
             Qt::QueuedConnection);

     connect(m_videoDecoder,
             &AbstractVideoDecoder::frameReady,
             m_videoScheduler,
             &VideoScheduler::enqueue,
             Qt::QueuedConnection);

     connect(m_videoScheduler,
             &VideoScheduler::frameReady,
             m_openglpreview,
             &OpenGLVideoPreview::onFrame,
             Qt::QueuedConnection);
    /* connect(m_rtspSource,
             &RtspSource::videoExtraData,
             m_videoDecoder,
             &AbstractVideoDecoder::setExtraData);*/
    /* connect(m_rtspSource,
             &RtspSource::videoExtraData,
             m_videoDecoder,
             &AbstractVideoDecoder::configure);*/
    /*connect(m_rtspSource,
            &RtspSource::videoPacket,
            m_videoDecoder,
            &H264Decoder::decode,
            Qt::QueuedConnection);*/

   /* connect(m_videoDecoder,
            &H264Decoder::frameReady,
            m_openglpreview,
            &OpenGLVideoPreview::onFrame,
            Qt::QueuedConnection);*/
   /* connect(m_videoDecoder,
            &H264Decoder::frameReady,
            m_videoScheduler,
            &VideoScheduler::enqueue,
            Qt::QueuedConnection);*/



    m_audioDecoder = new AudioOpusDecoder(this);

    if (!m_audioDecoder->open(m_settings.audioSampleRate,
                              m_settings.audioChannels))
        return false;


    ///ses
    m_audioScheduler = new AudioScheduler(m_clock);
    m_audioScheduler->open(m_settings.video);
    connect(m_rtspSource,
            &RtspSource::audioPacket,
            m_audioDecoder,
            &AudioOpusDecoder::decode,
            Qt::QueuedConnection);

    /*connect(m_audioDecoder,
             &AudioOpusDecoder::frameReady,
            m_playback,
            &AudioPlayback::onFrame,
            Qt::QueuedConnection);*/

    connect(m_audioDecoder,
            &AudioOpusDecoder::frameReady,
            m_audioScheduler,
            &AudioScheduler::enqueue,
            Qt::QueuedConnection);

    connect(m_audioScheduler,
            &AudioScheduler::frameReady,
            m_playback,
            &AudioPlayback::onFrame,
            Qt::QueuedConnection);


    m_rtspSource->open("rtsp://192.168.1.103:8554/stream",m_settings);
    m_rtspSource->start();

    return true;
}


void ReceiverPipeline::stop()
{

}
bool ReceiverPipeline::createObjects()
{

}
