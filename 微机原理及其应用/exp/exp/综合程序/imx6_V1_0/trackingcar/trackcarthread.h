#ifndef TRACKCARHREAD_H
#define TRACKCARHREAD_H

#include <QThread>
#include <QWidget>

class trackCarThread: public QThread
{
    Q_OBJECT

    public:
        explicit trackCarThread(QObject *parent = 0);
        ~trackCarThread();

protected:
    void run();
protected:
    bool startflag;
    bool success;

signals:
    void sindraw(unsigned char *s);


public slots:
    void startSlot(bool work);
    void drawingFinishSlot(bool e);
};

#endif // WORKTHREAD_H
