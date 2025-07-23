#include "trackingcar.h"
#include "ui_trackingcar.h"



trackingCar::trackingCar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::trackingCar)
{
    ui->setupUi(this);


        startflag = false;
        work = false;

        trackcarthread = new trackCarThread();
        trackcarthread->start();

        tubenixiethread = new tubeNixieThread();
        tubenixiethread->start();

        trackingcomthread = new trackingComThread();
        trackingcomthread->start();

        gauge=new myGauge(ui->fm);
        gauge->setAnimating(true);
        ui->gridLayout->addWidget(gauge);

         gauge1=new myGauge1(ui->fm1);
         ui->gridLayout1->addWidget(gauge1);
         gauge->setVisible(false);
         gauge1->setVisible(false);

        connect(this,SIGNAL(startSignal(bool)),trackcarthread,SLOT(startSlot(bool)));
        connect(trackcarthread,SIGNAL(sindraw(unsigned char*)),this,SLOT(timerUpDate(unsigned char*)));
        connect(this,SIGNAL(drawingFinish(bool)),trackcarthread,SLOT(drawingFinishSlot(bool)));
        connect(trackingcomthread,SIGNAL(comDataShowSignals(unsigned char*)),tubenixiethread,SLOT(tubeDataSlot(unsigned char *)));
        connect(trackingcomthread,SIGNAL(comDataSignals(unsigned char *)),this,SLOT(comDataSlot(unsigned char *)));
        connect(this,SIGNAL(trackcarWorkSignal(bool)),trackingcomthread,SLOT(trackcarWorkSlot(bool)));

        QPalette palette;
       palette.setBrush(QPalette::Background,QBrush(QImage(":/new/prefix1/img/trackbusgreen.PNG").scaled(this->geometry().width(),this->geometry().height())));
        this->setPalette(palette);
        this->setAutoFillBackground(true);
       this->show();
}

trackingCar::~trackingCar()
{
    delete ui;
}

void trackingCar::trackcarSwitchSlot(int n)
{
    if(n == 2)
    {
        gauge->setVisible(true);
        gauge1->setVisible(true);
        if(startflag == true)
        {
            emit startSignal(true);
        }
    }
    else
    {
        gauge->setVisible(false);
        gauge1->setVisible(false);
        if(startflag == true)
        {
            emit startSignal(false);
        }
    }
}

void trackingCar::comDataSlot(unsigned char *ch)
{
   // emit tubeDataSignal(da);
   // qDebug()<<ch[0]<<ch[1]<<ch[2]<<ch[3];
    gauge->setValue(ch[3]*2);
    if((ch[2]>>7)  == 1)
        gauge1->setValue((ch[2]&0x7f)*1.8*-1);
    else
        gauge1->setValue(ch[2]*1.8);
    if((ch[1]&0x10) > 0)
        ui->led0Label->setStyleSheet("border-image: url(:/new/prefix1/img/trackbusDirLeftOn.png);");
    else
        ui->led0Label->setStyleSheet("border-image: url(:/new/prefix1/img/trackbusDirLeftOff.png);");

    if((ch[1]&0x20) > 0)
        ui->led1Label->setStyleSheet("border-image: url(:/new/prefix1/img/trackbusDirRightOn.png);");
    else
        ui->led1Label->setStyleSheet("border-image: url(:/new/prefix1/img/trackbusDirRightOff.png);");
}

/* 定时时间到 */
void trackingCar::timerUpDate(unsigned char*s)
{
    memcpy(buf,s,100);
    update(); 
    work = true;
}

/* 重绘事件函数 */
void trackingCar::paintEvent(QPaintEvent *)
{
    if(work == true)
    {
        QPainter painter(this);
        QPoint beginPoint;
        QPoint endPoint;
        QPen pen(Qt::black,40,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
        painter.setPen(pen); //使用画笔

       for( int i=0; i<47; i++ ) {
        beginPoint.setX( buf[i]+280 );
        beginPoint.setY( i*10);

        endPoint.setX( buf[i+1]+280 );
        endPoint.setY( i*10+1);

        painter.drawLine( beginPoint, endPoint );
            }

        work = false;
        emit drawingFinish(true);
    }

}

void trackingCar::on_startButton_clicked()
{
    startflag = startflag ? false : true;
    if(startflag == true)
    {
        trackcarWorkSignal(true);
       // ui->startButton->setText(tr("停止"));
        ui->startButton->setStyleSheet("border-image: url(:/new/prefix1/img/trackbusStart.png);");
    }
    else
    {
        trackcarWorkSignal(false);
      //   ui->startButton->setText(tr("开始"));
         ui->startButton->setStyleSheet("border-image: url(:/new/prefix1/img/trackbusStop.png);");
    }
    emit startSignal(startflag);
}
