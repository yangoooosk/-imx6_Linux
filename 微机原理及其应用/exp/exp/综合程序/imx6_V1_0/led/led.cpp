#include "led.h"
#include "ui_led.h"

Led::Led(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Led)
{
    ui->setupUi(this);

    ledfd = open(ledDEVICE,O_RDWR,0777);
    if(ledfd<0)
    {
        perror("open led fail");
    }

    led1 = false;
    led2 = false;
    led3 = false;
    led4 = false;


    ioctl(ledfd,OffLED,LED1);
    ioctl(ledfd,OffLED,LED2);
    ioctl(ledfd,OffLED,LED3);
    ioctl(ledfd,OffLED,LED4);
    ui->led1Button->setStyleSheet("border-image: url(:/new/prefix1/img/ledoff.PNG);");
    ui->led2Button->setStyleSheet("border-image:url(:/new/prefix1/img/ledoff.PNG);");
    ui->led3Button->setStyleSheet("border-image:url(:/new/prefix1/img/ledoff.PNG);");
    ui->led4Button->setStyleSheet("border-image:url(:/new/prefix1/img/ledoff.PNG);");

    QPalette palette;
   palette.setBrush(QPalette::Background,QBrush(QImage(":/new/prefix1/img/ledgreen.png").scaled(this->geometry().width(),this->geometry().height())));
    this->setPalette(palette);
    this->setAutoFillBackground(true);
   this->show();

}

Led::~Led()
{
    delete ui;
    ::close(ledfd);
}

void Led::on_led1Button_clicked()
{
    led1 = led1 ? false : true;
    if(led1 == true)
    {
        ioctl(ledfd,OnLED,LED1);
        ui->led1Button->setStyleSheet("border-image:url(:/new/prefix1/img/ledon.PNG);");
    }
    else
    {
        ioctl(ledfd,OffLED,LED1);
        ui->led1Button->setStyleSheet("border-image:url(:/new/prefix1/img/ledoff.PNG);");
    }
}

void Led::on_led2Button_clicked()
{
    led2 = led2 ? false : true;
    if(led2 == true)
    {
        ioctl(ledfd,OnLED,LED2);
        ui->led2Button->setStyleSheet("border-image:url(:/new/prefix1/img/ledon.PNG);");
    }
    else
    {
        ioctl(ledfd,OffLED,LED2);
        ui->led2Button->setStyleSheet("border-image:url(:/new/prefix1/img/ledoff.PNG);");
    }
}

void Led::on_led3Button_clicked()
{
     led3 = led3 ? false : true;
     if(led3 == true)
     {
         ioctl(ledfd,OnLED,LED3);
         ui->led3Button->setStyleSheet("border-image:url(:/new/prefix1/img/ledon.PNG);");
     }
     else
     {
         ioctl(ledfd,OffLED,LED3);
         ui->led3Button->setStyleSheet("border-image:url(:/new/prefix1/img/ledoff.PNG);");
     }
}

void Led::on_led4Button_clicked()
{
    led4 = led4 ? false : true;
    if(led4 == true)
    {
        ioctl(ledfd,OnLED,LED4);
        ui->led4Button->setStyleSheet("border-image:url(:/new/prefix1/img/ledon.PNG);");
    }
    else
    {
        ioctl(ledfd,OffLED,LED4);
        ui->led4Button->setStyleSheet("border-image:url(:/new/prefix1/img/ledoff.PNG);");
    }
}
