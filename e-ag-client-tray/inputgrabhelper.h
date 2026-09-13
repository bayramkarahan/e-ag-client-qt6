#ifndef INPUTGRABHELPER_H
#define INPUTGRABHELPER_H

#include <QObject>
#include <QDebug>
#include <QGuiApplication>

#include <QTextStream>

#include <X11/Xlib.h>

class InputGrabHelper : public QObject
{
    Q_OBJECT

public:
    explicit InputGrabHelper(QObject *parent = nullptr);
    ~InputGrabHelper();
    bool grabKeyboard();
    void ungrabKeyboard();

    bool grabMouse();
    void ungrabMouse();

    bool grabAll();
    void ungrabAll();

private:
    Display *dpy = nullptr;
    Window root = 0;
};

#endif
