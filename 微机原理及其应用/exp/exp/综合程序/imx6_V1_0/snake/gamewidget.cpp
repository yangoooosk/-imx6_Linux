#include "gamewidget.h"
#include "ui_gamewidget.h"

#include <stdio.h>
#define ROW 13
#define COL 16
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define XOffset 100
#define YOffset 50
#define GridLength 25

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget)
{
    ui->setupUi(this);

    QPalette palette;
   palette.setBrush(QPalette::Background,QBrush(QImage(":/new/prefix1/img/green.jpg").scaled(this->geometry().width(),this->geometry().height())));
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    QPixmap gameoverpix(QPixmap(":/new/prefix1/img/gameover.png"));
    ui->gameoverlabel->setPixmap(gameoverpix);
    ui->gameoverlabel->hide();

    //设置分数等级为0
    score=0;
    level=0;
    //显示分数等级标签区
    str1=QString::number(score);
    str2=QString::number(level);
    ui->scoreshow->setText(str1);
    ui->levelshow->setText(str2);

    foodcount=0;
     //设置随机数
    int i=1;
    QTime t;
    t= QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);
    snake[0][0]=qrand()%COL;
    snake[0][1]=qrand()%ROW;
    foodx=qrand()%COL;
    foody=qrand()%ROW;
    direction=qrand()%4;
    while(i)
    {
        if(snake[0][0]==foodx&&snake[0][1]==foody)
        {
            foodx=qrand()%COL;
            foody=qrand()%ROW;
            i=1;
        }
        else
            i=0;
    }
    timer=new QTimer(this);
    timer->setInterval(500);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeoutSlot()));

    //设置键盘操作
    connect(this,SIGNAL(UpSignal()),ui->upbtn,SLOT(click()));
    connect(this,SIGNAL(DownSignal()),ui->downbtn,SLOT(click()));
    connect(this,SIGNAL(LeftSignal()),ui->leftbtn,SLOT(click()));
    connect(this,SIGNAL(RightSignal()),ui->rightbtn,SLOT(click()));

    work = false;
}

GameWidget::~GameWidget()
{
    delete ui;
    delete timer;
}

void GameWidget::on_upbtn_clicked()
{
    if(direction==DOWN)
        return;
    else
    {
    direction=UP;
    }
}

void GameWidget::on_leftbtn_clicked()
{
    if(direction==RIGHT)
        return;
    else
    {
    direction=LEFT;
    }
}

void GameWidget::on_rightbtn_clicked()
{
    if(direction==LEFT)
        return;
    else
    {
    direction=RIGHT;
    }
}

void GameWidget::on_downbtn_clicked()
{
    if(direction==UP)
        return;
    else
    {
   direction=DOWN;
    }
}

void GameWidget::snakeSwitchSlot(int n)
{
    if(n==0)
    {
        if(work == true)
            timer->start();
    }
    else
    {
        if(work == true)
            timer->stop();
    }
}

void GameWidget::on_pausebtn_clicked()
{
    work = false;
    timer->stop();
}

void GameWidget::on_startbtn_clicked()
{
    ui->gameoverlabel->hide();
    if(work == true)
    {
        QTime t;
       int i;
       t= QTime::currentTime();
       qsrand(t.msec()+t.second()*1000);
       snake[0][0]=qrand()%COL;
       snake[0][1]=qrand()%ROW;
       direction=qrand()%4;
       foodx=qrand()%COL;
       foody=qrand()%ROW;
       while(i)
       {
           if(snake[0][0]==foodx&&snake[0][1]==foody)
           {
               foodx=qrand()%COL;
               foody=qrand()%ROW;
               i=1;
           }
           else
               i=0;
       }
       foodcount=0;
       score=0;
       level=0;

       str1=QString::number(score);
       str2=QString::number(level);
       ui->scoreshow->setText(str1);
      ui-> levelshow->setText(str2);
    }
    work = true;
    timer->start();
}


void GameWidget::timeoutSlot()
{
    //判断是否知道食物
   if(snake[0][0]==foodx&&snake[0][1]==foody)
    {
        //如果吃到食物，食物坐标更新
       int i=0;
        foodcount++;
        score++;
        str1=QString::number(score);
       ui-> scoreshow->setText(str1);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx=qrand()%COL;
        foody=qrand()%ROW;
        while(i<=foodcount)
        {
            i++;
            //判断食物是否出现在蛇身上，如果出现在蛇身上重新产生食物
            if(snake[i][0]==foodx&&snake[i][1]==foody)
            {
                foodx=qrand()%COL;
                foody=qrand()%ROW;
                i=0;
            }
        }
        switch(score)
        {
        case 10:timer->setInterval(350);level++;break;
        case 20:timer->setInterval(250);level++;break;
        case 30:timer->setInterval(150);level++;break;
        }
        str2=QString::number(level);
        ui->levelshow->setText(str2);
    }
    memcpy(snake1,snake,sizeof(snake));
    //实现蛇的游动
    for(int i=foodcount;i>=1;i--)
    {
        snake[i][0]=snake[i-1][0];
        snake[i][1]=snake[i-1][1];
    }

    switch(direction)
    {
    case UP:snake[0][1]--;break;
    case DOWN:snake[0][1]++;break;
    case LEFT:snake[0][0]--;break;
    case RIGHT:snake[0][0]++;break;
    }
    //判断蛇是否撞到自身
    for(int i=1;i<=foodcount;i++)
    {
        if(snake[0][0]==snake[i][0]&&snake[0][1]==snake[i][1])
        {
          //  sound1->play();
            memcpy(snake,snake1,sizeof(snake));
            timer->stop();
           // if(QMessageBox::question(this,"提示","游戏结束,是否重新游戏",QMessageBox::Yes,QMessageBox::No)==QMessageBox::Yes)
            //   {
           /*     QTime t;
                int i;
                t= QTime::currentTime();
                qsrand(t.msec()+t.second()*1000);
                snake[0][0]=qrand()%COL;
                snake[0][1]=qrand()%ROW;
                direction=qrand()%4;
                foodx=qrand()%COL;
                foody=qrand()%ROW;
                while(i)
                {
                    if(snake[0][0]==foodx&&snake[0][1]==foody)
                    {
                        foodx=qrand()%COL;
                        foody=qrand()%ROW;
                        i=1;
                    }
                    else
                        i=0;
                }
                foodcount=0;
                score=0;
                level=0;

                str1=QString::number(score);
                str2=QString::number(level);
                ui->scoreshow->setText(str1);
               ui-> levelshow->setText(str2);
               */
                ui->gameoverlabel->show();
             //  }
          //  return;
        }
    }
    //判断蛇是否撞到墙体
    if(snake[0][0]<0||snake[0][0]>=COL||snake[0][1]<0||snake[0][1]>=ROW)
    {
      //  sound1->play();
        memcpy(snake,snake1,sizeof(snake));
       timer->stop();
     //  if(QMessageBox::question(this,"提示","游戏结束,是否重新游戏",QMessageBox::Yes,QMessageBox::No)==QMessageBox::Yes)
      //    {
    /*       QTime t;
           int i;
           t= QTime::currentTime();
           qsrand(t.msec()+t.second()*1000);
           snake[0][0]=qrand()%COL;
           snake[0][1]=qrand()%ROW;
           direction=qrand()%4;
           foodx=qrand()%COL;
           foody=qrand()%ROW;
           while(i)
           {
               if(snake[0][0]==foodx&&snake[0][1]==foody)
               {
                   foodx=qrand()%COL;
                   foody=qrand()%ROW;
                   i=1;
               }
               else
                   i=0;
           }
           foodcount=0;
           score=0;
           level=0;

           str1=QString::number(score);
           str2=QString::number(level);
           ui->scoreshow->setText(str1);
          ui-> levelshow->setText(str2);
*/
         ui->gameoverlabel->show();
      //    }
     //  else
      //  {
       //    delete this;
       //    return ;
     //   }

    }
    this->update();
}

void GameWidget::paintEvent(QPaintEvent *)
{
    //画方格
    QPainter painter(this);
    for(int i=YOffset;i<YOffset+ROW*GridLength;i+=GridLength)
        for(int j=XOffset;j<XOffset+COL*GridLength;j+=GridLength)
        painter.drawRect(j,i,GridLength,GridLength);
    //画食物
    painter.drawImage(XOffset+foodx*GridLength,YOffset+foody*GridLength,QImage(":/new/prefix1/img/apple.png").scaled(QSize(GridLength,GridLength)));
    //画蛇头

    switch(direction)
    {
    case UP:painter.drawImage(XOffset+snake[0][0]*GridLength,YOffset+snake[0][1]*GridLength,QImage(":/new/prefix1/img/headup.png").scaled(QSize(GridLength,GridLength)));break;//蛇头向上
    case DOWN:painter.drawImage(XOffset+snake[0][0]*GridLength,YOffset+snake[0][1]*GridLength,QImage(":/new/prefix1/img/headdown.png").scaled(QSize(GridLength,GridLength)));break;//蛇头向下
    case LEFT:painter.drawImage(XOffset+snake[0][0]*GridLength,YOffset+snake[0][1]*GridLength,QImage(":/new/prefix1/img/headleft.png").scaled(QSize(GridLength,GridLength)));break;//蛇头向下
    case RIGHT:painter.drawImage(XOffset+snake[0][0]*GridLength,YOffset+snake[0][1]*GridLength,QImage(":/new/prefix1/img/headright.png").scaled(QSize(GridLength,GridLength)));break;//蛇头向下
    }


    //画蛇身
    for(int i=1;i<=foodcount;i++)
    {
        if(i!=foodcount)
        {
        if((snake[i][0]==snake[i-1][0]&&snake[i][1]==snake[i-1][1]-1&&
           snake[i][0]==snake[i+1][0]-1&&snake[i][1]==snake[i+1][1])||
           (snake[i][0]==snake[i-1][0]-1&&snake[i][1]==snake[i-1][1]&&
            snake[i][0]==snake[i+1][0]&&snake[i][1]==snake[i+1][1]-1))
         painter.drawImage(XOffset+snake[i][0]*GridLength,YOffset+snake[i][1]*GridLength,QImage(":/new/prefix1/img/tl_corner.png").scaled(QSize(GridLength,GridLength)));
        else if((snake[i][0]==snake[i-1][0]-1&&snake[i][1]==snake[i-1][1]&&
                 snake[i][0]==snake[i+1][0]&&snake[i][1]==snake[i+1][1]+1)||
                 (snake[i][0]==snake[i-1][0]&&snake[i][1]==snake[i-1][1]+1&&
                  snake[i][0]==snake[i+1][0]-1&&snake[i][1]==snake[i+1][1]))
         painter.drawImage(XOffset+snake[i][0]*GridLength,YOffset+snake[i][1]*GridLength,QImage(":/new/prefix1/img/bl_corner.png").scaled(QSize(GridLength,GridLength)));
        else if((snake[i][0]==snake[i-1][0]+1&&snake[i][1]==snake[i-1][1]&&
                 snake[i][0]==snake[i+1][0]&&snake[i][1]==snake[i+1][1]-1)||
                 (snake[i][0]==snake[i-1][0]&&snake[i][1]==snake[i-1][1]-1&&
                  snake[i][0]==snake[i+1][0]+1&&snake[i][1]==snake[i+1][1]))
         painter.drawImage(XOffset+snake[i][0]*GridLength,YOffset+snake[i][1]*GridLength,QImage(":/new/prefix1/img/tr_corner.png").scaled(QSize(GridLength,GridLength)));
        else if((snake[i][0]==snake[i-1][0]&&snake[i][1]==snake[i-1][1]+1&&
                 snake[i][0]==snake[i+1][0]+1&&snake[i][1]==snake[i+1][1])||
                 (snake[i][0]==snake[i-1][0]+1&&snake[i][1]==snake[i-1][1]&&
                  snake[i][0]==snake[i+1][0]&&snake[i][1]==snake[i+1][1]+1))
         painter.drawImage(XOffset+snake[i][0]*GridLength,YOffset+snake[i][1]*GridLength,QImage(":/new/prefix1/img/br_corner.png").scaled(QSize(GridLength,GridLength)));
        else if(snake[i][1]==snake[i-1][1]&&snake[i][0]!=snake[i-1][0])
       painter.drawImage(XOffset+snake[i][0]*GridLength,YOffset+snake[i][1]*GridLength,QImage(":/new/prefix1/img/h_body.png").scaled(QSize(GridLength,GridLength)));
        else if(snake[i][0]==snake[i-1][0]&&snake[i][1]!=snake[i-1][1])
         painter.drawImage(XOffset+snake[i][0]*GridLength,YOffset+snake[i][1]*GridLength,QImage(":/new/prefix1/img/v_body.png").scaled(QSize(GridLength,GridLength)));
        }
        else
        {
            //画蛇尾
            if(snake[i][0]==snake[i-1][0]+1&&snake[i][1]==snake[i-1][1])
                painter.drawImage(XOffset+snake[i][0]*GridLength,YOffset+snake[i][1]*GridLength,QImage(":/new/prefix1/img/tailleft.png").scaled(QSize(GridLength,GridLength)));
            else if(snake[i][0]==snake[i-1][0]-1&&snake[i][1]==snake[i-1][1])
                painter.drawImage(XOffset+snake[i][0]*GridLength,YOffset+snake[i][1]*GridLength,QImage(":/new/prefix1/img/tailright.png").scaled(QSize(GridLength,GridLength)));
            else if(snake[i][0]==snake[i-1][0]&&snake[i][1]==snake[i-1][1]-1)
                painter.drawImage(XOffset+snake[i][0]*GridLength,YOffset+snake[i][1]*GridLength,QImage(":/new/prefix1/img/taildown.png").scaled(QSize(GridLength,GridLength)));
             else if(snake[i][0]==snake[i-1][0]&&snake[i][1]==snake[i-1][1]+1)
                painter.drawImage(XOffset+snake[i][0]*GridLength,YOffset+snake[i][1]*GridLength,QImage(":/new/prefix1/img/tail.png").scaled(QSize(GridLength,GridLength)));
        }
    }
}

void GameWidget::getKeySlot(unsigned long n)
{
  if(n==56)
  {
      //if(direction==DOWN)
          //return ;
     // else
      //direction=UP;
      emit UpSignal();
  }
  else if(n==16777330)
  {
      /*if(direction==UP)
          return;
      else
      direction=DOWN;*/
      emit DownSignal();
  }
  else if(n==16777216)
  {
      /*if(direction==RIGHT)
          return;
      else
      direction=LEFT;*/
      emit LeftSignal();
  }
  else if(n==16777328)
  {
      /*if(direction==LEFT)
          return;
      else
      direction=RIGHT;*/
      emit RightSignal();
  }
}


