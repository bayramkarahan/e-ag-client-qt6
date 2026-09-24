#ifndef STREAMPLAYER_H
#define STREAMPLAYER_H

#include "../common/StreamSettings.h"
#include "../stream/receiverpipeline.h"


class StreamPlayer : public QObject
{
    Q_OBJECT

public:
    explicit StreamPlayer(QObject *parent = nullptr);

    bool open(StreamSettings &settings);
    bool start();
    void stop();    bool prepareSource(StreamSettings &settings);

private:
    ReceiverPipeline m_receiver;

    StreamSettings m_settings;
};

#endif // STREAMPLAYER_H
