#ifndef ITMS_H
#define ITMS_H

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
#include "itmsComThread.h"


struct typCardMessage
{
       unsigned char site;
       bool state;
       unsigned long cycleNum;
       unsigned long uid;
};

namespace Ui {
class ITMS;
}

class ITMS : public QWidget
{
    Q_OBJECT

public:
    explicit ITMS(QWidget *parent = 0);
    ~ITMS();

private:
    Ui::ITMS *ui;

public:
    QTimer *bustimer;
    QTimer *norSouthLedTimer;
    QTimer *eastWestLedTimer;
    QTimer *arrivalTime;
    QTimer *comPoll;
    int ledflag;
    bool norSouthPass;
    bool eastWestPass;
    bool startflag;
    bool swipeState;
    QMatrix nmatrix;
    QMatrix smatrix;
    QMatrix ematrix;

protected:
    int mem_fd;
    unsigned char *cpldLed;
    unsigned char *cpldMotor;
    int stationNum;
    int COMDevice;
    unsigned char uartdata[25];
    int busx;
    int busy;
    int total;
    int busTotal;
    int getOnPeopleNum;
    int getOffPeopleNum;
    bool irda;
    bool irdaflag;
    bool work;
    bool nfcflag;
    int busdir;

    unsigned long busCycleNum;
    QString str1,str2,str3,str4;
    typCardMessage *cardMessage;
    itmsComThread *itmscom;


protected:
    int com_init(char *DEVICE,speed_t speed);
    void paintEvent(QPaintEvent *);
    int foreachdata(unsigned long uid);

signals:
       void busPass();
       void setShowData();

private:
    int movingTrajectory;
  //  QImage image;
   // QMatrix matrix;

public slots:
    void bustimeoutSlot();
    void norsouthtimeoutSlot();
    void eastwesttimeoutSlot();
    void arrivalTimeSlot();
    void stopBusPass();
    void comPollSlot();
    void setShowDataSlot();
    void comDataSlot();
    void itmsSwitchSlot(int n);
private slots:
    void on_itmsButton_clicked();
    void on_checkBox_stateChanged();
    void on_checkBox_2_stateChanged();
    void on_checkBox_3_stateChanged();
    void on_checkBox_4_stateChanged();
};

#endif // ITMS_H
