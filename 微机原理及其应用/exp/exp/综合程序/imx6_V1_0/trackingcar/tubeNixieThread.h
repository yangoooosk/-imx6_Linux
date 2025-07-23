#ifndef  TUBENIXIETHREAD_H
#define TUBENIXIETHREAD_H

#include <QThread>
#include <QWidget>
#include <termios.h>

class tubeNixieThread: public QThread
{
    Q_OBJECT

    public:
        explicit tubeNixieThread(QObject *parent = 0);
        ~tubeNixieThread();

protected:
    void run();
protected:
    int mem_fd;
    unsigned char *cpld;
    int speed;
    int angle;
    int direction;



public slots:
    void tubeDataSlot(unsigned char *ch);
};

//==========================================================================================

class trackingComThread: public QThread
{
    Q_OBJECT

    public:
        explicit trackingComThread(QObject *parent = 0);
        ~trackingComThread();

protected:
    void run();
protected:
    int mem_fd;
    int trackDevice;

 protected:
     int com_init(char *DEVICE,speed_t speed);


signals:
    void comDataSignals(unsigned char *ch);
    void comDataShowSignals(unsigned char *ch);

public slots:
    void trackcarWorkSlot(bool b);
};

#endif // WORKTHREAD_H
