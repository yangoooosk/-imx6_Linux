#include "itms.h"
#include "ui_itms.h"

#define  UARTDevice "/dev/ttyS2"

#define x1  274
#define y1  344
#define x2  274
#define y2  67
#define x3  87
#define y3  67
#define x4  87
#define y4  209
#define x5  462
#define y5  209
#define x6  462
#define y6  344

#define busStationX1    274
#define busStationY1    280
#define busStationX2    274
#define busStationY2    120
#define busStationX3    150
#define busStationY3    209
#define busStationX4    376
#define busStationY4    209

#define sidewalkX1  274
#define sidewalkY1  269
#define sidewalkX2  274
#define sidewalkY2  110
#define sidewalkX3  167
#define sidewalkY3  209
#define sidewalkX4  367
#define sidewalkY4  209

char stationName[8][50] = {
    "下一站知春路站",
    "知春路站到了",
    "下一站海淀黄庄",
    "海淀黄庄到了",
    "下一站中关村南",
    "中关村南到了",
    "下一站北京大学",
    "北京大学到了"
                        };

unsigned char wakeup[] = {0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x03,0xfd,0xd4,0x14,0x01,0x17,0x00}; //唤醒
unsigned char getUID[] = {0x00, 0x00, 0xFF, 0x04, 0xFC, 0xD4, 0x4A, 0x01, 0x00, 0xE1, 0x00}; //获取UID

ITMS::ITMS(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ITMS)
{
    ui->setupUi(this);

    COMDevice = com_init((char*)UARTDevice,B115200);
    if(COMDevice <0)
        return;

    mem_fd = open("/dev/mem", O_RDWR);
    cpldLed = (unsigned char*)mmap(NULL,(size_t)0x04,PROT_READ | PROT_WRITE | PROT_EXEC,MAP_SHARED,mem_fd,(off_t)(0x8000000));
    if(cpldLed == MAP_FAILED)
        return;

    cpldMotor = (unsigned char*)mmap(NULL,(size_t)0x04,PROT_READ | PROT_WRITE | PROT_EXEC,MAP_SHARED,mem_fd,(off_t)(0x8000000));
    if(cpldMotor == MAP_FAILED)
        return;

    busx = x1;
    busy = y1;
    stationNum = 0;
    busdir = 0;
    ui->stationNameLabel->setText(tr(stationName[stationNum]));

     nmatrix.rotate(90);
    ui->lightNorth->setPixmap(QPixmap(":/new/prefix1/img/greenLightOn.png").transformed(nmatrix,Qt::FastTransformation).scaled(QSize(ui->lightNorth->geometry().width(),ui->lightNorth->geometry().height())));
    smatrix.rotate(270);
    ui->lightSouth->setPixmap(QPixmap(":/new/prefix1/img/greenLightOn.png").transformed(smatrix,Qt::FastTransformation).scaled(QSize(ui->lightSouth->geometry().width(),ui->lightSouth->geometry().height())));
    ui->lightWest->setStyleSheet("border-image: url(:/new/prefix1/img/redLightOn.png);");
    ematrix.rotate(180);
    ui->lightEast->setPixmap(QPixmap(":/new/prefix1/img/redLightOn.png").transformed(ematrix,Qt::FastTransformation).scaled(QSize(ui->lightEast->geometry().width(),ui->lightEast->geometry().height())));

//    ui->stopTimeBox->setStyleSheet("QComboBox{color:green;}"
//                                   "QComboBox{ background-color:rgb(232, 232, 232);}");

    ui->itmsButton->setStyleSheet("border-image: url(:/new/prefix1/img/itmsStart.png);");

    *(cpldLed+(0xe8<<1)) = ~(0x20 | 0x01);
    *(cpldMotor+(0xe2<<1)) = 0;

    ledflag = 0;
    norSouthPass = true;
    eastWestPass = true;
    startflag = false;
    irda = false;
    irdaflag = false;
    work = false;
    nfcflag = false;
    busCycleNum = 0;

    total = 0;
    busTotal = 0;
    getOnPeopleNum = 0;
    getOffPeopleNum = 0;
    str1=QString::number(total);
    str2=QString::number(busTotal);
    str3=QString::number(getOnPeopleNum);
    str4=QString::number(getOffPeopleNum);
    ui->totality->setText(str1);
    ui->busTotal->setText(str2);
    ui->getOnPeopleNum->setText(str3);
    ui->getOffPeopleNum->setText(str4);

    bustimer=new QTimer(this);
    norSouthLedTimer=new QTimer(this);
    eastWestLedTimer=new QTimer(this);
    arrivalTime = new QTimer(this);
    comPoll = new QTimer(this);
   // comPoll->start(1);
    bustimer->setInterval(6);
    norSouthLedTimer->setInterval(6000);
    eastWestLedTimer->setInterval(8000);

    norSouthLedTimer->stop();
    eastWestLedTimer->stop();
    bustimer->stop();

    movingTrajectory = 0;
    swipeState = false;

    itmscom = new itmsComThread();
    itmscom->start();

    connect(bustimer,SIGNAL(timeout()),this,SLOT(bustimeoutSlot()));
    connect(norSouthLedTimer,SIGNAL(timeout()),this,SLOT(norsouthtimeoutSlot()));
    connect(eastWestLedTimer,SIGNAL(timeout()),this,SLOT(eastwesttimeoutSlot()));
    connect(arrivalTime,SIGNAL(timeout()),this,SLOT(arrivalTimeSlot()));
    connect(this,SIGNAL(busPass()),this,SLOT(stopBusPass()));
    connect(comPoll,SIGNAL(timeout()),this,SLOT(comPollSlot()));
    connect(this,SIGNAL(setShowData()),this,SLOT(setShowDataSlot()));
    connect(itmscom,SIGNAL(comDataSignals()),this,SLOT(comDataSlot()));


    QPalette palette;
   palette.setBrush(QPalette::Background,QBrush(QImage(":/new/prefix1/img/itmsgreen.png").scaled(this->geometry().width(),this->geometry().height())));
    this->setPalette(palette);
    this->setAutoFillBackground(true);
   this->show();
}

ITMS::~ITMS()
{
    delete ui;
    munmap(cpldLed,0x04);
    munmap(cpldMotor,0x04);
    ::close(mem_fd);
    ::close(COMDevice);

    delete[] itmscom;
    delete[] bustimer;
    delete[] norSouthLedTimer;
    delete[] eastWestLedTimer;
    delete[] arrivalTime;
    delete[] comPoll;
}

int ITMS::com_init(char *DEVICE,speed_t speed)
{
    struct termios options;
    int COMDevice;
    COMDevice = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);// | O_NONBLOCK
    if(COMDevice < 0)
    {
         printf("open com device failure");
         return COMDevice;
    }
    tcgetattr(COMDevice,&options);
    cfsetispeed(&options,speed);//波特率
    cfsetospeed(&options,speed);
    options.c_cflag |= (CLOCAL|CREAD);
    options.c_cflag |= CS8;
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    options.c_oflag &= ~OPOST;
    options.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    options.c_cc[VTIME] = 0;//设置超时
    options.c_cc[VMIN] = 1;//最少读1个数据
    tcsetattr(COMDevice,TCSANOW,&options);

    return COMDevice;
}

void ITMS::setShowDataSlot()
{
    str1=QString::number(total);
    str2=QString::number(busTotal);
    str3=QString::number(getOnPeopleNum);
    str4=QString::number(getOffPeopleNum);
    ui->totality->setText(str1);
    ui->busTotal->setText(str2);
    ui->getOnPeopleNum->setText(str3);
    ui->getOffPeopleNum->setText(str4);
}

int ITMS::foreachdata(unsigned long uid)
{
    int i=0;
    for(i=0;i<100;i++)
    {
        if(cardMessage[i].uid == uid)
        {
            return i;
        }
    }
    for(i=0;i<100;i++)
    {
        if(cardMessage[i].uid == 0)
        {
            return i;
        }
    }
    return 0;
}

void ITMS::comPollSlot()
{
    unsigned char c,i,re;
    unsigned long uid;
    int placeNum;
   // qDebug()<<"11111111111111111";
        re = read(COMDevice,&c,1);
        if(re==1)
        {
            for(i=0;i<24;i++)
            {
                uartdata[i]=uartdata[i+1];
            }
            uartdata[24] = c;
            //=======================================================

            if(uartdata[24-3] == 0xd5 && uartdata[24-2] == 0x15)  // D5  15表示正确执行并完毕
            {
                write(COMDevice,getUID,sizeof(getUID));
            }
            /*else if(uartdata[15]==0x00 && uartdata[16]==0x00 && uartdata[17]==0xFF && uartdata[18]==0x00 && uartdata[19]==0xff
                    && uartdata[20]==0x00 && uartdata[21]==0x00 && uartdata[22] == 0x00 && uartdata[23] == 0xFF)
            {
                datalength = uartdata[24];
            }*/
            else if(uartdata[0]==0x00 && uartdata[1]==0x00 && uartdata[2]==0xFF && uartdata[3]==0x00 && uartdata[4]==0xff
                    && uartdata[5]==0x00 && uartdata[6]==0x00 && uartdata[7] == 0x00 && uartdata[8] == 0xFF && uartdata[12] == 0x4b && uartdata[18] == 0x04 && uartdata[24] == 0x00 )
            {
                uid = uartdata[19]<<24 | uartdata[20]<<16 | uartdata[21]<<8 | uartdata[22];
                if(swipeState == true)
                {
                    placeNum = foreachdata(uid);
                    if(cardMessage[placeNum].uid != uid)
                    {
                        cardMessage[placeNum].uid = uid;
                        cardMessage[placeNum].cycleNum = busCycleNum;
                        cardMessage[placeNum].site = stationNum;
                        cardMessage[placeNum].state = cardMessage[placeNum].state ? false : true;
                        total++;
                        busTotal++;
                        getOnPeopleNum ++;
                        emit setShowData();
              //          printf("num=%d,site=%d,state=%d,uid=0x%x\n", placeNum,cardMessage[placeNum].site,cardMessage[placeNum].state,cardMessage[placeNum].uid);
                    }
                    else if(cardMessage[placeNum].uid == uid)
                    {
                            if(cardMessage[placeNum].site != stationNum || cardMessage[placeNum].cycleNum != busCycleNum)
                            {
                                cardMessage[placeNum].cycleNum = busCycleNum;
                                cardMessage[placeNum].site = stationNum;
                                cardMessage[placeNum].state = cardMessage[placeNum].state ? false:true;
                                if(cardMessage[placeNum].state == true)
                                {
                                    total++;
                                    busTotal++;
                                    getOnPeopleNum ++;
                                }
                                else
                                {
                                    busTotal--;
                                    getOffPeopleNum ++;
                                }
                                emit setShowData();
                         //       printf("num=%d,site=%d,state=%d,uid=0x%x\n", placeNum,cardMessage[placeNum].site,cardMessage[placeNum].state,cardMessage[placeNum].uid);
                            }
                    }
                }
                write(COMDevice,getUID,sizeof(getUID));
            }
        }
}

void ITMS::comDataSlot()
{
        if((busx == sidewalkX1 && (busy>=sidewalkY2 && busy <= sidewalkY1)) || ((busx >= sidewalkX3 && busx<=sidewalkX4) && busy == sidewalkY3) ||
                (busx == busStationX1 && busy==busStationY1-1) || (busx == busStationX2 && busy==busStationY2-1) ||
                (busx == busStationX3+1 && busy==busStationY3) || (busx == busStationX4+1 && busy==busStationY4) )
        {
        }
        else
        {
            irdaflag = true;
            irda = irda ? false : true;
            if(irda == true)
            {
                busCycleNum++;
                emit busPass();
                ui->irdaLabel->setText(tr("临时停车！"));
                comPoll->start(1);
                nfcflag = true;
                *(cpldMotor+(0xe2<<1)) = 0;
            }
            else
            {
                comPoll->stop();
                nfcflag = false;
                ui->irdaLabel->clear();
                arrivalTime->start(1);
                *(cpldMotor+(0xe2<<1)) = busdir;
            }
        }
}

void ITMS::itmsSwitchSlot(int n)
{
    if(n==1)
    {
        if(startflag == true)
        {
            if(nfcflag == true)
            {
                work = true;
                bustimer->stop();
                if(irda == true)
                    comPoll->start(1);
                else
                    arrivalTimeSlot();
            }
            else
            {
                bustimer->start();
                comPoll->stop();
            }
        }
    }
    else
    {
        bustimer->stop();
        comPoll->stop();
        arrivalTime->stop();
    }
}

void ITMS::on_itmsButton_clicked()
{
    if(startflag == false)
    {
        //ui->itmsButton->setText(tr("停止"));
        ui->itmsButton->setStyleSheet("border-image: url(:/new/prefix1/img/itmsStop.png);");
        startflag = true;
        busx = x1;
        busy = y1;

       ui->lightNorth->setPixmap(QPixmap(":/new/prefix1/img/greenLightOn.png").transformed(nmatrix,Qt::FastTransformation).scaled(QSize(ui->lightNorth->geometry().width(),ui->lightNorth->geometry().height())));
       ui->lightSouth->setPixmap(QPixmap(":/new/prefix1/img/greenLightOn.png").transformed(smatrix,Qt::FastTransformation).scaled(QSize(ui->lightSouth->geometry().width(),ui->lightSouth->geometry().height())));
       ui->lightWest->setStyleSheet("border-image: url(:/new/prefix1/img/redLightOn.png);");
       ui->lightEast->setPixmap(QPixmap(":/new/prefix1/img/redLightOn.png").transformed(ematrix,Qt::FastTransformation).scaled(QSize(ui->lightEast->geometry().width(),ui->lightEast->geometry().height())));

        *(cpldLed+(0xe8<<1)) = ~(0x20 | 0x01);
        *(cpldMotor+(0xe2<<1)) = 0;
        norSouthPass = true;
        eastWestPass = true;
        irda = false;
        irdaflag = false;
        movingTrajectory = 0;
        ledflag = 0;
        bustimer->start();
        norSouthLedTimer->start();
        eastWestLedTimer->start();
        arrivalTime->stop();
        busCycleNum = 0;
        stationNum = 0;
        total = 0;
        busTotal = 0;
        getOnPeopleNum = 0;
        getOffPeopleNum = 0;
        emit setShowData();
        ui->stationNameLabel->setText(tr(stationName[stationNum]));
        cardMessage = new typCardMessage[100];
        int i=0;
        for(i=0;i<100;i++)
        {
            cardMessage[i].site = 0;
            cardMessage[i].state = 0;
            cardMessage[i].cycleNum = 0;
            cardMessage[i].uid = 0;
        }
    }
    else if(startflag == true)
    {
      //  ui->itmsButton->setText(tr("开始"));
        ui->itmsButton->setStyleSheet("border-image: url(:/new/prefix1/img/itmsStart.png);");
        startflag = false;
        swipeState = false;

        *(cpldMotor+(0xe2<<1)) = 0;
        bustimer->stop();
        norSouthLedTimer->stop();
        eastWestLedTimer->stop();
        arrivalTime->stop();
        delete[] cardMessage;
    }
}

void ITMS::arrivalTimeSlot()
{
        arrivalTime->stop();
        bustimer->start();
        comPoll->stop();
        nfcflag = false;
        swipeState = false;
        if(irdaflag == false)
        {
            stationNum++;
            if(stationNum == 8)
                    stationNum = 0;
            ui->stationNameLabel->setText(tr(stationName[stationNum]));
        }
        irdaflag = false;
}
/*
void ITMS::stopBusPass()
{
    int tab,bustime=0;
    tab = ui->stopTimeBox->currentIndex();
    if(tab == 0)
        bustime=2000;
    else if(tab == 1)
         bustime=3000;
    else if(tab == 2)
         bustime=5000;
    else if(tab == 3)
         bustime=7000;
    else if(tab == 4)
         bustime=10000;
    else if(tab == 5)
         bustime=15000;
    else if(tab == 6)
         bustime=20000;

    write(COMDevice,wakeup,sizeof(wakeup));
    getOffPeopleNum = 0;
    getOnPeopleNum = 0;
    emit setShowData();
    swipeState = true;
    bustimer->stop();
    comPoll->start(1);
    nfcflag = true;
    if(irdaflag == false)
    {
        busCycleNum ++;
        stationNum++;
        ui->stationNameLabel->setText(tr(stationName[stationNum]));
        arrivalTime->start(bustime);
    }

}
*/
//qi add-->
void ITMS::stopBusPass()
{
    int bustime=0;
    if(ui->checkBox->isChecked()==true)
    {
        bustime=2000;
    }
    else if(ui->checkBox_2->isChecked()==true)
    {
       bustime=3000;
    }
    else if(ui->checkBox_3->isChecked()==true)
    {
       bustime=5000;
    }
    else if(ui->checkBox_4->isChecked()==true)
    {
       bustime=7000;
    }
    write(COMDevice,wakeup,sizeof(wakeup));
    getOffPeopleNum = 0;
    getOnPeopleNum = 0;
    emit setShowData();
    swipeState = true;
    bustimer->stop();
    comPoll->start(1);
    nfcflag = true;
    if(irdaflag == false)
    {
        busCycleNum ++;
        stationNum++;
        ui->stationNameLabel->setText(tr(stationName[stationNum]));
        arrivalTime->start(bustime);
    }
}
//<--qi add

void ITMS::norsouthtimeoutSlot()
{
    if(ledflag == 0)
    {
       ui->lightNorth->setPixmap(QPixmap(":/new/prefix1/img/yellowLightOn.png").transformed(nmatrix,Qt::FastTransformation).scaled(QSize(ui->lightNorth->geometry().width(),ui->lightNorth->geometry().height())));
       ui->lightSouth->setPixmap(QPixmap(":/new/prefix1/img/yellowLightOn.png").transformed(smatrix,Qt::FastTransformation).scaled(QSize(ui->lightSouth->geometry().width(),ui->lightSouth->geometry().height())));

        *(cpldLed+(0xe8<<1)) = ~(0x10 | 0x01);
    }
    else if(ledflag == 1)
    {
       ui->lightWest->setStyleSheet("border-image: url(:/new/prefix1/img/yellowLightOn.png);");
       ui->lightEast->setPixmap(QPixmap(":/new/prefix1/img/yellowLightOn.png").transformed(ematrix,Qt::FastTransformation).scaled(QSize(ui->lightEast->geometry().width(),ui->lightEast->geometry().height())));


       *(cpldLed+(0xe8<<1)) = ~(0x02 | 0x08);
    }

    norSouthLedTimer->stop();

}

void ITMS::eastwesttimeoutSlot()
{
    if(ledflag == 0)
    {
       ui->lightNorth->setPixmap(QPixmap(":/new/prefix1/img/redLightOn.png").transformed(nmatrix,Qt::FastTransformation).scaled(QSize(ui->lightNorth->geometry().width(),ui->lightNorth->geometry().height())));
       ui->lightSouth->setPixmap(QPixmap(":/new/prefix1/img/redLightOn.png").transformed(smatrix,Qt::FastTransformation).scaled(QSize(ui->lightSouth->geometry().width(),ui->lightSouth->geometry().height())));
       ui->lightWest->setStyleSheet("border-image: url(:/new/prefix1/img/greenLightOn.png);");
       ui->lightEast->setPixmap(QPixmap(":/new/prefix1/img/greenLightOn.png").transformed(ematrix,Qt::FastTransformation).scaled(QSize(ui->lightEast->geometry().width(),ui->lightEast->geometry().height())));


        *(cpldLed+(0xe8<<1)) = ~(0x04 | 0x08);

        ledflag = 1;
        norSouthLedTimer->start();
        norSouthPass = false;
        eastWestPass = true;
    }
    else if(ledflag == 1)
    {
       ui->lightNorth->setPixmap(QPixmap(":/new/prefix1/img/greenLightOn.png").transformed(nmatrix,Qt::FastTransformation).scaled(QSize(ui->lightNorth->geometry().width(),ui->lightNorth->geometry().height())));
       ui->lightSouth->setPixmap(QPixmap(":/new/prefix1/img/greenLightOn.png").transformed(smatrix,Qt::FastTransformation).scaled(QSize(ui->lightSouth->geometry().width(),ui->lightSouth->geometry().height())));
       ui->lightWest->setStyleSheet("border-image: url(:/new/prefix1/img/redLightOn.png);");
       ui->lightEast->setPixmap(QPixmap(":/new/prefix1/img/redLightOn.png").transformed(ematrix,Qt::FastTransformation).scaled(QSize(ui->lightEast->geometry().width(),ui->lightEast->geometry().height())));


        *(cpldLed+(0xe8<<1)) = ~(0x20 | 0x01);

        ledflag = 0;
        norSouthLedTimer->start();
        norSouthPass = true;
        eastWestPass = false;
    }
    //eastWestLedTimer->stop();
}

void ITMS::paintEvent(QPaintEvent *)
{
    if(work == true)
    {
        QPainter painter(this);
        switch(movingTrajectory)
        {
            case 0:
               painter.drawImage(busx,busy,QImage(":/new/prefix1/img/busNorth.png").scaled(QSize(25,50)));
                break;
            case 1:
               painter.drawImage(busx,busy,QImage(":/new/prefix1/img/busWest.png").scaled(QSize(50,25)));
                break;
            case 2:
                painter.drawImage(busx,busy,QImage(":/new/prefix1/img/busSouth.png").scaled(QSize(25,50)));
                break;
            case 3:
                painter.drawImage(busx,busy,QImage(":/new/prefix1/img/busEast.png").scaled(QSize(50,25)));
                break;
            case 4:
                painter.drawImage(busx,busy,QImage(":/new/prefix1/img/busSouth.png").scaled(QSize(25,50)));
                break;
            case 5:
                painter.drawImage(busx,busy,QImage(":/new/prefix1/img/busWest.png").scaled(QSize(50,25)));
                break;

        }
        work = false;
    }
}



void ITMS::bustimeoutSlot()
{
   // QPainter painter(this);
    if(busx == x1 && busy == y1)
        movingTrajectory = 0;
    else if(busy == y2 && busx == x2)
        movingTrajectory = 1;
    if(busx == x3 && busy == y3)
        movingTrajectory = 2;
    if(busy == y4 && busx == x4)
        movingTrajectory = 3;
    if(busx == x5 && busy == y5)
        movingTrajectory = 4;
    if(busy == y6 && busx == x6)
        movingTrajectory = 5;

    switch(movingTrajectory)
    {
        case 0:

            if(busx == sidewalkX1 && busy== sidewalkY1)
            {
                if(norSouthPass == 1)
                {
                    busy--;
                    *(cpldMotor+(0xe2<<1)) = 3;
                    busdir = 3;
                }
                else
                    *(cpldMotor+(0xe2<<1)) = 0;
            }
            else
            {
                if((busx == busStationX1 && busy == busStationY1) || (busx == busStationX2 && busy == busStationY2))
                {
                    bustimer->stop();
                    *(cpldMotor+(0xe2<<1)) = 0;
                    busy--;
                    emit busPass();
                }
                else
                {
                    busy--;
                    *(cpldMotor+(0xe2<<1)) = 3;
                    busdir = 3;
                }
            }
            break;
        case 1:
                busx--;
                *(cpldMotor+(0xe2<<1)) = 3;
                busdir = 3;
            break;
        case 2:
            busy++;
            *(cpldMotor+(0xe2<<1)) = 2;
            busdir = 2;
            break;
        case 3:

            if(busx == sidewalkX3 && busy == sidewalkY3)
            {
                if(eastWestPass == 1)
                {
                    busx++;
                    *(cpldMotor+(0xe2<<1)) = 2;
                    busdir = 2;
                }
                else
                    *(cpldMotor+(0xe2<<1)) = 0;
            }
            else
            {
                if((busx == busStationX3 && busy == busStationY3) || (busx == busStationX4 && busy == busStationY4))
                {
                    bustimer->stop();
                    *(cpldMotor+(0xe2<<1)) = 0;
                    busx++;
                    emit busPass();
                }
                else
                {
                    busx++;
                    *(cpldMotor+(0xe2<<1)) = 2;
                    busdir = 2;
                }
            }

            break;
        case 4:
            busy++;
            *(cpldMotor+(0xe2<<1)) = 2;
            busdir = 2;
            break;
        case 5:
                busx--;
                *(cpldMotor+(0xe2<<1)) = 3;
                busdir = 3;
            break;

    }
    this->update();
    work = true;
}
//qi add 2019.10.18
void ITMS::on_checkBox_stateChanged()
{
    if(ui->checkBox->isChecked()==true)
    {
        ui->checkBox_2->setEnabled(false);
        ui->checkBox_3->setEnabled(false);
        ui->checkBox_4->setEnabled(false);
    }else
    {
        ui->checkBox_2->setEnabled(true);
        ui->checkBox_3->setEnabled(true);
        ui->checkBox_4->setEnabled(true);
    }
}

void ITMS::on_checkBox_2_stateChanged()
{
    if(ui->checkBox_2->isChecked()==true)
    {
        ui->checkBox->setEnabled(false);
        ui->checkBox_3->setEnabled(false);
        ui->checkBox_4->setEnabled(false);
    }else
    {
        ui->checkBox->setEnabled(true);
        ui->checkBox_3->setEnabled(true);
        ui->checkBox_4->setEnabled(true);
    }
}

void ITMS::on_checkBox_3_stateChanged()
{
    if(ui->checkBox_3->isChecked()==true)
    {
        ui->checkBox->setEnabled(false);
        ui->checkBox_2->setEnabled(false);
        ui->checkBox_4->setEnabled(false);
    }else
    {
        ui->checkBox->setEnabled(true);
        ui->checkBox_2->setEnabled(true);
        ui->checkBox_4->setEnabled(true);
    }
}

void ITMS::on_checkBox_4_stateChanged()
{
    if(ui->checkBox_4->isChecked()==true)
    {
        ui->checkBox->setEnabled(false);
        ui->checkBox_2->setEnabled(false);
        ui->checkBox_3->setEnabled(false);
    }else
    {
        ui->checkBox->setEnabled(true);
        ui->checkBox_2->setEnabled(true);
        ui->checkBox_3->setEnabled(true);
    }
}
