#include <QApplication>
#include <QDebug>
#include "common/StreamSettings.h"
#include "common/commandlineparser.h"
#include "stream/rstpreceiverstream.h"
#include "stream/rtpreceiverstream.h"

#include "preview/openglvaapizerocopypreview.h"
#include "preview/openglvideopreview.h"
#include "preview/videopreview.h"
#include "preview/AbstractVideoPreview.h"
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
    //settings.receivermode=ReceiverMode::Multicast;
    settings.receivermode=ReceiverMode::Unicast;
    settings.serverAddress="192.168.1.104";
    settings.audio.source=AudioSource::None;
    settings.video.source=VideoSource::ScreenPipeWire;
    //settings.video.device="/dev/video2";
    //settings.previewMode = PreviewMode::Remote;
    //settings.videoAddress=QHostAddress("239.10.10.10");
    settings.videoPort=5004;
    settings.audio.sampleRate=48000;
    settings.audio.channels=2;
    settings.audio.frameSample=960;
    settings.audio.bitrate=20000;
    settings.audioAddress=settings.videoAddress;
    settings.audioPort=settings.videoPort+2;

    settings.video.screenIndex = 0;
    settings.video.bitrate=100;
    settings.video.fps    = 5;
    settings.video.width  = 160;
    settings.video.height = 90;
    settings.previewMode=PreviewMode::MultiPreview;

    //settings.video.timeMode = TimeMode::FramePts;

    ///if (!CommandLineParser::parse(app, settings))
       /// return -1;


    if(settings.receivermode==ReceiverMode::Unicast)
    {
        qDebug()<<"ReceiverMode::Unicast";
        RstpReceiverStream *rstp= new RstpReceiverStream;
        if (!rstp->open(settings)) return -1;
        rstp->start(settings.serverAddress);

        RstpReceiverStream *rstp1= new RstpReceiverStream;
        if (!rstp1->open(settings)) return -1;
        rstp1->start(settings.serverAddress);
        RstpReceiverStream *rstp2= new RstpReceiverStream;
        if (!rstp2->open(settings)) return -1;
        rstp2->start(settings.serverAddress);
        RstpReceiverStream *rstp3= new RstpReceiverStream;
        if (!rstp3->open(settings)) return -1;
        rstp3->start(settings.serverAddress);
        RstpReceiverStream *rstp4= new RstpReceiverStream;
        if (!rstp4->open(settings)) return -1;
        rstp4->start(settings.serverAddress);
    }
    if(settings.receivermode==ReceiverMode::Multicast)
    {
        qDebug()<<"ReceiverMode::Multicast";
        RtpReceiverStream *rtp= new RtpReceiverStream;
        if (!rtp->open(settings)) return -1;

        rtp->start();
    }


    return app.exec();
}
