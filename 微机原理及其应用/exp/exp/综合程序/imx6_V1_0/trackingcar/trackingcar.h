#ifndef TRACKINGCAR_H
#define TRACKINGCAR_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QImage>
#include <QPixmap>
#include <QPainter>
#include <QPalette>
#include <QDebug>
#include <QFont>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/mman.h>
#include <sys/ioctl.h>
#include <termios.h>
#include "trackcarthread.h"
#include "tubeNixieThread.h"
#include "mygauge.h"
#include "mygauge1.h"

namespace Ui {
class trackingCar;
}

class trackingCar : public QWidget
{
    Q_OBJECT

public:
    explicit trackingCar(QWidget *parent = 0);
    ~trackingCar();

private:
    Ui::trackingCar *ui;

private:
    bool startflag;
    bool work;
    unsigned char buf[300];
    trackCarThread *trackcarthread;
    tubeNixieThread *tubenixiethread;
    trackingComThread *trackingcomthread;
    myGauge *gauge;
    myGauge1 *gauge1;

signals:
    void startSignal(bool sta);
    void drawingFinish(bool e);
    void tubeDataSignal(double n);
    void trackcarWorkSignal(bool b);

private:
    void paintEvent(QPaintEvent *);

public slots:
    void timerUpDate(unsigned char *s);
    void comDataSlot(unsigned char *ch);
    void trackcarSwitchSlot(int n);
private slots:
    void on_startButton_clicked();
};

#endif // TRACKINGCAR_H
