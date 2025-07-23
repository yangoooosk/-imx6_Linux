#include "camera.h"
#include "ui_camera.h"
#include <stdlib.h>

camera::camera(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::camera)
{
    ui->setupUi(this);
    cameraflag = false;
    camerathread = new cameraThread();
    ui->startButton->setStyleSheet("border-image:url(:/new/prefix1/img/play.png);");
    connect(camerathread, SIGNAL(errorshow()), this, SLOT(errorshowslot()));

    connect(this,SIGNAL(Show_complete(bool)),camerathread,SLOT(startCapture(bool)));
    connect(camerathread,SIGNAL(Collect_complete(unsigned char*)),this,SLOT(videoDisplay(unsigned char*)));
    camerathread->start();

    QPalette palette;
   palette.setBrush(QPalette::Background,QBrush(QImage(":/new/prefix1/img/caremagreen.png").scaled(this->geometry().width(),this->geometry().height())));
    this->setPalette(palette);
    this->setAutoFillBackground(true);
   this->show();
}

camera::~camera()
{
    delete ui;
}

void camera::errorshowslot()
{
    ui->cameraLabel->setText(tr("摄像头初始化失败，请检查是否插好，并重新启动！"));
}

void camera::videoDisplay(unsigned char *pp)
{
    QImage frame = QImage(pp,IMAGE_WIDTH,IMAGE_HEIGHT,QImage::Format_RGB888).mirrored(false, true);
    ui->cameraLabel->setPixmap(QPixmap::fromImage(frame));
}

void camera::on_startButton_clicked()
{
    cameraflag = cameraflag ? false : true;
    if(cameraflag == true)
    {
         //ui->startButton->setText(tr("暂停"));
        ui->startButton->setStyleSheet("border-image:url(:/new/prefix1/img/Pause.png);");
        emit this->Show_complete(true);

    }
    else
    {
     //  ui->startButton->setText(tr("播放"));

       ui->startButton->setStyleSheet("border-image:url(:/new/prefix1/img/play.png);");
       emit this->Show_complete(false);
    }
}

void camera::cameraSwitchSlot(int n)
{
    if(n==5)
    {
        if(cameraflag == true)
        {
            emit this->Show_complete(true);
        }
    }
    else
    {
        if(cameraflag == true)
        {
          emit this->Show_complete(false);
        }
    }
}
