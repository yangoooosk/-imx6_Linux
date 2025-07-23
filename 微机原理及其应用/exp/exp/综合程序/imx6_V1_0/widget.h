#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPoint>
#include <QMouseEvent>
#include <QMovie>
#include<QImage>
#include "configure.h"
#include "./camera/camera.h"
#include "./led/led.h"
#include "./billboard/billboard.h"
#include "./snake/gamewidget.h"
#include "./itms/itms.h"
#include "trackingcar/trackingcar.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    void keyPressEvent(QKeyEvent *k);
    //=============================================================
protected slots:
     void mousePressEvent(QMouseEvent *event);
     void mouseReleaseEvent(QMouseEvent *event);
private slots:
     void on_homePageButton_clicked();
     void on_cameraPageButton_clicked();
     void on_billboardPageButton_clicked();
     void on_snakePageButton_clicked();
     void on_itmsPageButton_clicked();
     void on_trackingCarPageButton_clicked();

     void on_homePageButton1_clicked();
     void on_ledPageButton_clicked();
     void on_billboardPageButton1_clicked();
     void on_snakePageButton1_clicked();
     void on_itmsPageButton1_clicked();
     void on_trackingCarPageButton1_clicked();

     void on_homePageButton2_clicked();

     void on_ledPageButton1_clicked();

     void on_cameraPageButton1_clicked();

     void on_snakePageButton2_clicked();

     void on_itmsPageButton2_clicked();

     void on_trackingCarPageButton2_clicked();

     void on_homePageButton3_clicked();

     void on_ledPageButton2_clicked();

     void on_cameraPageButton2_clicked();

     void on_billboardPageButton2_clicked();

     void on_itmsPageButton3_clicked();

     void on_trackingCarPageButton3_clicked();

     void on_homePageButton4_clicked();

     void on_ledPageButton3_clicked();

     void on_cameraPageButton3_clicked();

     void on_billboardPageButton3_clicked();

     void on_snakePageButton3_clicked();

     void on_trackingCarPageButton4_clicked();

     void on_homePageButton5_clicked();

     void on_ledPageButton4_clicked();

     void on_cameraPageButton4_clicked();

     void on_billboardPageButton4_clicked();

     void on_snakePageButton4_clicked();

     void on_itmsPageButton4_clicked();

private:
     bool m_f_PressMouse;
     QPoint m_StartDragPos;
     int pagenum; //当前页面
     unsigned char pagesize;        //总共页面数
private:
     void TransitionInterface(bool LeftScroll);
  //=================================================================
 private:
     camera *cam;
     Led *led;
     billboard *board;
     GameWidget *snake;
     ITMS *itms;
     trackingCar *trackingcar;

signals:
    void billboardPressEvent(QPoint a);
    void SwitchSignal(int a);
    void getKeySignal(unsigned long n);
};

#endif // WIDGET_H
