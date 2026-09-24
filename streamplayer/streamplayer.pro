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
TARGET=streamplayer

TEMPLATE = app

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
    player/audioplayback.cpp \
    player/audioprocessor.cpp \
    player/rtspsource.cpp \
    player/rtspworker.cpp \
    renderer/openglvaapizerocopyrenderer.cpp \
    renderer/openglvideorenderer.cpp \
    renderer/videorenderer.cpp \
    stream/receiverstream.cpp \
    sync/audioscheduler.cpp \
    sync/mastertime.cpp \
    sync/mediaclock.cpp \
    sync/videoscheduler.cpp \
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
    common/VideoCaptureSettings.h \
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
    network/rtppacket.h \
    player/audioplayback.h \
    player/audioprocessor.h \
    player/rtspsource.h \
    player/rtspworker.h \
    renderer/AbstractVideoRenderer.h \
    renderer/openglvaapizerocopyrenderer.h \
    renderer/openglvideorenderer.h \
    renderer/videorenderer.h \
    stream/receiverstream.h \
    sync/audioscheduler.h \
    sync/mastertime.h \
    sync/mediaclock.h \
    sync/videoscheduler.h \
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
