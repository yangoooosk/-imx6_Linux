#ifndef  ITMSCOMHREAD_H
#define ITMSCOMHREAD_H

#include <QThread>
#include <QWidget>
#include <termios.h>

class itmsComThread: public QThread
{
    Q_OBJECT

    public:
        explicit itmsComThread(QObject *parent = 0);
        ~itmsComThread();

protected:
    void run();
protected:
    int irdaDevice;

 protected:
     int com_init(char *DEVICE,speed_t speed);


signals:
    void comDataSignals();
};

#endif // ITMSCOMHREAD_H
