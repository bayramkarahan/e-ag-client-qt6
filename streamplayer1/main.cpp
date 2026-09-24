#include <QApplication>
#include <QDebug>
#include "common/StreamSettings.h"
#include "common/commandlineparser.h"
#include "stream/receiverstream.h"

#include "renderer/openglvaapizerocopyrenderer.h"
#include "renderer/openglvideorenderer.h"
#include "renderer/videorenderer.h"
#include "renderer/AbstractVideoRenderer.h"
/*
 * *********use********
./mediastreamer --mode sender --source file --file abc.mp4
./mediastreamer --mode sender --source camera --device /dev/video0
./mediastreamer --mode sender --source screen --screen 0
./mediastreamer --mode receiver
*/

int main(int argc, char *argv[])
{
    qputenv("QT_XCB_GL_INTEGRATION", "xcb_egl");
    QApplication app(argc, argv);

    StreamSettings settings;
    settings.mode=StreamMode::Receiver;
    //settings.video.source = CaptureSource::Camera;
    //settings.video.fileName="selcuk.mp4";
    if (!CommandLineParser::parse(app, settings))
        return -1;

    //qDebug()<<"settings.captureMode"<<int(settings.captureMode);
    //return 0;

    //settings.video.device="/dev/video2";
    //settings.captureMode = CaptureMode::AudioVideo;
    //settings.previewMode = PreviewMode::Remote;
    //settings.videoAddress=QHostAddress("239.10.10.10");
    //settings.videoPort=5004;



    settings.audioSampleRate=48000;
    settings.audioChannels=2;
    settings.audioFrameSample=960;
    settings.audioBitrate=20000;
    settings.videoBitrate=4000;

    settings.audioAddress=settings.videoAddress;
    settings.audioPort=settings.videoPort+2;
    settings.video.screenIndex = 0;
    //settings.video.fps    = 5;
    //settings.video.width  = 160;
    //settings.video.height = 90;
    //settings.video.timeMode = TimeMode::MasterClock;

    ReceiverStream *rs= new ReceiverStream;
    if (!rs->open(settings)) return -1;

    rs->start("192.168.1.103");
    //rs->m_openglrenderer->show();

    return app.exec();
}
