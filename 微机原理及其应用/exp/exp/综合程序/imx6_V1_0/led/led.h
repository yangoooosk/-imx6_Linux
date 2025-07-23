#ifndef LED_H
#define LED_H

#include <QWidget>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <getopt.h>

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <malloc.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

namespace Ui {
class Led;
}

#define LED1  0
#define LED2  1
#define LED3  2
#define LED4  3
#define OnLED    1
#define OffLED  0
#define ledDEVICE "/dev/ledtest"
class Led : public QWidget
{
    Q_OBJECT

public:
    explicit Led(QWidget *parent = 0);
    ~Led();

private slots:
    void on_led1Button_clicked();

    void on_led2Button_clicked();

    void on_led3Button_clicked();

    void on_led4Button_clicked();

public:
    int ledfd;

    bool led1;
    bool led2;
    bool led3;
    bool led4;

private:
    Ui::Led *ui;
};

#endif // LED_H
