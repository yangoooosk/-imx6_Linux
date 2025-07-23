#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QPalette>
#include <QIcon>
#include <QPushButton>
#include <QPainter>
#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QMessageBox>
#include <QKeyEvent>
#include <QLabel>
#include <QFont>
#include <QPixmap>

namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = 0);
    ~GameWidget();

private:
    Ui::GameWidget *ui;

    void paintEvent(QPaintEvent *);
private:
    int direction;
    int snake[100][2];
    int snake1[100][2];
    int foodcount;
    QTimer *timer;
    int foodx,foody;
    int score;
    int level;
    QString str1,str2;
    bool work;
signals:
    void UpSignal();
    void DownSignal();
    void LeftSignal();
    void RightSignal();
public slots:
    void timeoutSlot();
    void snakeSwitchSlot(int n);
    void getKeySlot(unsigned long n);
private slots:
    void on_upbtn_clicked();
    void on_leftbtn_clicked();
    void on_rightbtn_clicked();
    void on_downbtn_clicked();
    void on_startbtn_clicked();
    void on_pausebtn_clicked();

};

#endif // GAMEWIDGET_H
