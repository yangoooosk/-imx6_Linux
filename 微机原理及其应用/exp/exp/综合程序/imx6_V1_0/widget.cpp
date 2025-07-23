#include "widget.h"
#include "ui_widget.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    pagesize = ui->stackedWidget->count();
    pagenum = ui->stackedWidget->currentIndex();

    cam = new camera(this);
    ui->cameraGridLayout->addWidget(cam);

    led = new Led(this);
    ui->ledGridLayout->addWidget(led);

    board = new billboard(this);
    ui->billboardGridLayout->addWidget(board);

    snake = new GameWidget(this);
    ui->snakeGridLayout->addWidget(snake);

    itms = new ITMS(this);
    ui->itmsGridLayout->addWidget(itms);

    trackingcar = new trackingCar(this);
    ui->trackingCarGridLayout->addWidget(trackingcar);

    connect(this,SIGNAL(billboardPressEvent(QPoint)),this->board,SLOT(buttonPressEventSlot(QPoint)));

    connect(this,SIGNAL(getKeySignal(ulong)),snake,SLOT(getKeySlot(ulong)));

    connect(this,SIGNAL(SwitchSignal(int)),cam,SLOT(cameraSwitchSlot(int)));
    connect(this,SIGNAL(SwitchSignal(int)),trackingcar,SLOT(trackcarSwitchSlot(int)));
    connect(this,SIGNAL(SwitchSignal(int)),snake,SLOT(snakeSwitchSlot(int)));
    connect(this,SIGNAL(SwitchSignal(int)),itms,SLOT(itmsSwitchSlot(int)));

    QPalette palette;
   palette.setBrush(QPalette::Background,QBrush(QImage(":/new/prefix1/img/homegreen.jpg").scaled(this->geometry().width(),this->geometry().height())));
    this->setPalette(palette);
    this->setAutoFillBackground(true);
   this->show();
}

Widget::~Widget()
{
    delete ui;
    delete cam;
    delete led;
    delete board;
    delete snake;
}
void Widget::keyPressEvent(QKeyEvent *k)
{
  unsigned long key = k->key();
 // printf("key=%d\n",key);
  emit getKeySignal(key);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
        m_StartDragPos = event->pos();
        m_f_PressMouse = true;
        if(ui->stackedWidget->currentIndex() == 6)
            emit billboardPressEvent(m_StartDragPos);
     //   printf("x=%d,y=%d\n",m_StartDragPos.x(),m_StartDragPos.y());
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if(m_f_PressMouse)
    {
        QPoint end_pos = event->pos();
        if(qAbs(end_pos.x() - m_StartDragPos.x()) >= 250)
        {
            if(end_pos.x() < m_StartDragPos.x()) //向左滑动，右面页面展开
            {
                 TransitionInterface(true);
              //  printf("start:%d\n",qAbs(end_pos.x() - m_StartDragPos.x()));
            }
            else if(end_pos.x() > m_StartDragPos.x()) //向右滑动，左面页面展开
            {
                TransitionInterface(false);
            //    printf("end:%d\n",qAbs(end_pos.x() - m_StartDragPos.x()));
            }
        }
    }
    m_f_PressMouse = false;
}

void Widget::TransitionInterface(bool LeftScroll)
{
        if(LeftScroll == true)  //向左滑动，右面页面展开
        {
            pagenum++;
            if(pagenum>=pagesize)
                pagenum = 0;
                   emit SwitchSignal(pagenum);
            ui->stackedWidget->setCurrentIndex(pagenum);
        }
        else if(LeftScroll == false)  //向右滑动，左面页面展开
        {
            pagenum--;
            if(pagenum<0)
                pagenum = pagesize-1;
            ui->stackedWidget->setCurrentIndex(pagenum);
                   emit SwitchSignal(pagenum);
        }
}

//===============LED===========================
void Widget::on_homePageButton_clicked()
{
    pagenum = 3;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_cameraPageButton_clicked()
{
    pagenum = 5;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_billboardPageButton_clicked()
{
    pagenum = 6;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_snakePageButton_clicked()
{

    pagenum = 0;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_itmsPageButton_clicked()
{

    pagenum = 1;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_trackingCarPageButton_clicked()
{
    pagenum = 2;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

//====================摄像头===================
void Widget::on_homePageButton1_clicked()
{
    pagenum = 3;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_ledPageButton_clicked()
{
    pagenum = 4;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_billboardPageButton1_clicked()
{
    pagenum = 6;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_snakePageButton1_clicked()
{
    pagenum = 0;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_itmsPageButton1_clicked()
{
    pagenum = 1;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_trackingCarPageButton1_clicked()
{
    pagenum = 2;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

//=============广告牌================
void Widget::on_homePageButton2_clicked()
{
    pagenum = 3;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_ledPageButton1_clicked()
{
    pagenum = 4;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_cameraPageButton1_clicked()
{
    pagenum = 5;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_snakePageButton2_clicked()
{
    pagenum = 0;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_itmsPageButton2_clicked()
{
    pagenum = 1;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_trackingCarPageButton2_clicked()
{
    pagenum = 2;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

//===================贪吃蛇====================
void Widget::on_homePageButton3_clicked()
{
    pagenum = 3;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_ledPageButton2_clicked()
{
    pagenum = 4;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_cameraPageButton2_clicked()
{
    pagenum = 5;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_billboardPageButton2_clicked()
{
    pagenum = 6;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_itmsPageButton3_clicked()
{
    pagenum = 1;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_trackingCarPageButton3_clicked()
{
    pagenum = 2;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

//===============智能公交==================

void Widget::on_homePageButton4_clicked()
{
    pagenum = 3;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_ledPageButton3_clicked()
{
    pagenum = 4;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_cameraPageButton3_clicked()
{
    pagenum = 5;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_billboardPageButton3_clicked()
{
    pagenum = 6;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_snakePageButton3_clicked()
{
    pagenum = 0;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_trackingCarPageButton4_clicked()
{
    pagenum = 2;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

//=========================循迹小车=============================

void Widget::on_homePageButton5_clicked()
{
    pagenum = 3;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_ledPageButton4_clicked()
{
    pagenum = 4;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_cameraPageButton4_clicked()
{
    pagenum = 5;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_billboardPageButton4_clicked()
{
    pagenum = 6;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_snakePageButton4_clicked()
{
    pagenum = 0;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}

void Widget::on_itmsPageButton4_clicked()
{
    pagenum = 1;
    emit SwitchSignal(pagenum);
    ui->stackedWidget->setCurrentIndex(pagenum);
}
