QT += gui widgets core network multimedia openglwidgets

# sudo apt install libqt6opengl6-dev
# sudo apt install vainfo
# sudo usermod -aG render etapadmin
# sudo apt install intel-media-va-driver
# sudo apt install libva-dev
# sudo apt install libdrm-dev
CONFIG += c++17 console
CONFIG -= app_bundle
CONFIG += link_pkgconfig

LIBS += -lEGL

PKGCONFIG += x264
PKGCONFIG += opus
PKGCONFIG += libva
PKGCONFIG += libdrm

TEMPLATE = app
TARGET=streamplayer

SOURCES += \
    common/camerainforeader.cpp \
    common/commandlineparser.cpp \
    common/mediafileinforeader.cpp \
    converter/videoconverter.cpp \
    decoder/CpuVideoDecoder.cpp \
    decoder/audioopusdecoder.cpp \
    decoder/h264decoder.cpp \
    decoder/h264depacketizer.cpp \
    decoder/vaapivideodecoder.cpp \
    decoder/vaapizerocopydecoder.cpp \
    decoder/videodecoderfactory.cpp \
    main.cpp \
    network/rtpjitterbuffer.cpp \
    player/audioplayback.cpp \
    player/audioprocessor.cpp \
    player/rtpaudioplayback.cpp \
    player/rtpaudioprocessor.cpp \
    preview/openglvaapizerocopypreview.cpp \
    preview/openglvideopreview.cpp \
    preview/videopreview.cpp \
    receiver/rtpreceiver.cpp \
    receiver/rtpsource.cpp \
    receiver/rtpworker.cpp \
    receiver/rtspsource.cpp \
    receiver/rtspworker.cpp \
    session/sessiondescription.cpp \
    stream/rstpreceiverstream.cpp \
    stream/rtpreceiverstream.cpp \
    rstp-sync/audioscheduler.cpp \
    rstp-sync/mediaclock.cpp \
    rtp-sync/rtpaudioscheduler.cpp \
    rtp-sync/rtpmediaclock.cpp \
    rtp-sync/rtpvideoscheduler.cpp \
    rstp-sync/videoscheduler.cpp \
    udpmesageservice/controlchannel.cpp \
    udpmesageservice/controlclient.cpp \
    udpmesageservice/controlmessage.cpp \
    udpmesageservice/controlserver.cpp


HEADERS += \
    audio/audioframe.h \
    common/EncodedPacket.h \
    common/MediaBuffer.h \
    common/MediaClock.h \
    common/MediaFrame.h \
    common/MediaPacket.h \
    common/StreamSettings.h \
    common/VideoBuffer.h \
    common/camerainforeader.h \
    common/commandlineparser.h \
    common/hardwareframe.h \
    common/mediafileinforeader.h \
    common/streamenums.h \
    common/vaapihardwareframe.h \
    converter/videoconverter.h \
    decoder/AbstractVideoDecoder.h \
    decoder/CpuVideoDecoder.h \
    decoder/audioopusdecoder.h \
    decoder/h264decoder.h \
    decoder/h264depacketizer.h \
    decoder/vaapivideodecoder.h \
    decoder/vaapizerocopydecoder.h \
    decoder/videodecoderfactory.h \
    network/rtpjitterbuffer.h \
    network/rtppacket.h \
    player/audioplayback.h \
    player/audioprocessor.h \
    player/rtpaudioplayback.h \
    player/rtpaudioprocessor.h \
    preview/AbstractVideoPreview.h \
    preview/openglvaapizerocopypreview.h \
    preview/openglvideopreview.h \
    preview/videopreview.h \
    receiver/rtpreceiver.h \
    receiver/rtpsource.h \
    receiver/rtpworker.h \
    receiver/rtspsource.h \
    receiver/rtspworker.h \
    session/sessiondescription.h \
    stream/rstpreceiverstream.h \
    stream/rtpreceiverstream.h \
    rstp-sync/audioscheduler.h \
    rstp-sync/mediaclock.h \
    rtp-sync/rtpaudioscheduler.h \
    rtp-sync/rtpmediaclock.h \
    rtp-sync/rtpvideoscheduler.h \
    rstp-sync/videoscheduler.h \
    udpmesageservice/controlchannel.h \
    udpmesageservice/controlclient.h \
    udpmesageservice/controlmessage.h \
    udpmesageservice/controlserver.h

INCLUDEPATH += \
    /usr/include \
    /usr/include/x86_64-linux-gnu

LIBS += \
    -lavdevice \
    -lavformat \
    -lavcodec \
    -lavutil \
    -lswscale \
    -lswresample


    #INCLUDEPATH += /usr/include/pipewire-0.3
    LIBS += -lpipewire-0.3
    PKGCONFIG += libpipewire-0.3

    INCLUDEPATH += \
        /usr/include/pipewire-0.3 \
        /usr/include/spa-0.2

target.path = /usr/bin
INSTALLS += target
