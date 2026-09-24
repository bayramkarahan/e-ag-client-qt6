#pragma once

#include "streamenums.h"

struct StreamSettings
{
    //----------------------------------------------------
    // Genel
    //----------------------------------------------------

    StreamMode mode = StreamMode::Sender;

    //----------------------------------------------------
    // Capture
    //----------------------------------------------------

    CaptureMode captureMode = CaptureMode::AudioVideo;

    VideoCaptureSettings video;

    //----------------------------------------------------
    // Preview
    //----------------------------------------------------

    PreviewMode previewMode = PreviewMode::Normal;

    //----------------------------------------------------
    // Network
    //----------------------------------------------------

    QHostAddress videoAddress = QHostAddress("239.10.10.10");
    quint16 videoPort = 5004;

    QHostAddress audioAddress = videoAddress;
    quint16 audioPort = videoPort+2;

    //----------------------------------------------------
    // Codec
    //----------------------------------------------------
    QString serverAddress = "127.0.0.1";
    int videoBitrate = 4000;

    int audioBitrate = 64000;

    int audioSampleRate = 48000;
    int audioFrameSample = 960;
    int audioChannels = 2;

    int multicastTtl = 1;

    QString networkInterface;

};
