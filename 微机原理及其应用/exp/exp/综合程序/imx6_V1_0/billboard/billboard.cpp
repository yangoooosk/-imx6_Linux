#include "billboard.h"
#include "ui_billboard.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/mman.h>

billboard::billboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::billboard)
{
    ui->setupUi(this);
  //  ui->fileTextEdit->setReadOnly(true);
    ui->fileNameTextEdit->setReadOnly(true);
    fre = false;
    workthread = new workThread();
    workthread->start();
    buttonflag = false;
    connect(this, SIGNAL(Preferences(typFNT_GB16*,int,bool)), this->workthread, SLOT(PreferencesTh(typFNT_GB16*,int,bool)));// Qt::DirectConnection
    connect(this, SIGNAL(workSet(long,bool)), this->workthread, SLOT(workSetStart(long,bool)));
    connect(this,SIGNAL(stopShow(bool)),this->workthread,SLOT(workSetStop(bool)));
    connect(this,SIGNAL(openfilebuttonsignal()),this,SLOT(openFileButton_clicked()));

    QPalette palette;
   palette.setBrush(QPalette::Background,QBrush(QImage(":/new/prefix1/img/billboardgreen.PNG").scaled(this->geometry().width(),this->geometry().height())));
    this->setPalette(palette);
    this->setAutoFillBackground(true);
    this->show();

    ui->startButton->setStyleSheet("background-color:rgb(195, 195, 195)");
   // ui->timeComboBox->setStyleSheet("QComboBox{color:black;}"
 //                              "QComboBox{ background-color:rgb(195, 195, 195);}");
    ui->startButton->setText(tr("开始"));
}

billboard::~billboard()
{
    delete ui;
}

void billboard::buttonPressEventSlot(QPoint a)
{
   // printf("x=%d,y=%d\n",a.x(),a.y());
    if((a.x()>=520 && a.x()<=711) && (a.y()>=40 && a.y()<=151))
    {
        emit openfilebuttonsignal();
    }
}

void billboard::openFileButton_clicked()
{
    QFile file;
    QString fileName;
    QString str;
    int size;

    QFileDialog fileDialog;

     fileName = fileDialog.getOpenFileName(this, tr("打开文件"), "/home/adfonts",  tr("txtfile(*.txt);;Allfile(*.*)"));
    //fileName = QFileDialog::getOpenFileName(this, tr("打开文件"), " ",  tr("txtfile(*.txt);;Allfile(*.*)"));
  //  ui->fileTextEdit->clear();
  //  ui->fileTextEdit->setText(fileName);
    if(!fileName.isEmpty())
    {
    file.setFileName(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug()<<"Can't open the file!";
        fileDialog.close();
        file.close();
    }
    else
    {
        if(fre == true)
            delete[] GB_16;
        FILE *fd;
        size = file.size();
        file.close();

        char *ptr;
        fd=fopen(fileName.toLatin1().data(),"r");
        ptr = new char[size+1];
        fread(ptr,size+1,1,fd);

        int i,j;
        QStringList list;
        str = QString(QLatin1String(ptr));
        QStringList strlist=str.split(";");
        charsize = strlist.size();

        for(i=0;i<strlist.size();i++)
        {
            if(strlist.at(i).size()>160)
                list.append(strlist.at(i).split(","));
           else
                charsize--;
        }
        //printf("charsize=%d\n",charsize);
       // qDebug()<<list;
        bool ok;
        char name[1000]="";
        GB_16 = new typFNT_GB16[charsize+1];

        for(i=0;i<charsize;i++)
        {
            if(i==0)
            {
                memcpy(GB_16[i].Index,list.at(i*33).toLatin1().data(),4);
                GB_16[i].Index[3] = '\n';
            }
            else
            {
                memcpy(GB_16[i].Index,&list.at(i*33).toLatin1().data()[2],3);
                GB_16[i].Index[3] = '\n';
            }
            if( GB_16[i].Index[0] == 0x20 &&  GB_16[i].Index[1] == 0x00)
            {
                name[i*3] = 0x20;
                name[i*3+1] = 0x20;
                name[i*3+2] = 0x20;
            }
            else
            {
                name[i*3] = GB_16[i].Index[0];
                name[i*3+1] = GB_16[i].Index[1];
                name[i*3+2] = GB_16[i].Index[2];
            }
            for(j=0;j<32;j++)
                GB_16[i].Msk[j] = list.at(i*33+1+j).toInt(&ok,16);
        }
         name[i*3] = '\n';
         //printf("%x:%x:%x:%x:%x:%x:%x:%x:%x\n",name[0],name[1],name[2],name[3],name[4],name[5],name[6],name[7],name[8]);
        ui->fileNameTextEdit->clear();
        ui->fileNameTextEdit->setStyleSheet("color:blue");
        ui->fileNameTextEdit->setFont(QFont("Timers" , 16 ,  QFont::Bold));
        ui->fileNameTextEdit->setAlignment(Qt::AlignHCenter);
         ui->fileNameTextEdit->append(tr(name));
         fre = true;
          ui->startButton->setText(tr("开始"));
          buttonflag = false;
    //   ui->fileNameTextEdit->appendPlainText(tr(list.at(1*33).toLatin1().data()));
       // printf("size=%x,%x,%x,%x,%x\n",list.at(33).toLatin1().data()[0],list.at(33).toLatin1().data()[1],list.at(33).toLatin1().data()[2],list.at(33).toLatin1().data()[3],list.at(33).toLatin1().data()[4]);

        delete[] ptr;
        fclose(fd);
       emit  Preferences(GB_16,charsize,false);
    }
    }
}


/*
void billboard::on_startButton_clicked()
{
    int tab;  
    buttonflag = buttonflag ? false : true;
    if(buttonflag == true)
    {
            tab = ui->timeComboBox->currentIndex();
            if(tab == 0)
                wtime=100000;
            else if(tab == 1)
                 wtime=200000;
            else if(tab == 2)
                 wtime=500000;
            else if(tab == 3)
                 wtime=700000;
            else if(tab == 4)
                 wtime=1000000;
            else if(tab == 5)
                 wtime=1500000;
            else if(tab == 6)
                 wtime=2000000;
            if(ui->fileNameTextEdit->toPlainText() != "")
                ui->startButton->setText(tr("停止"));
            else
                buttonflag = false;
            emit workSet(wtime,true);
     }
    else
    {
        ui->startButton->setText(tr("开始"));
        stopShow(false);
    }
}
*/
//qi add-2019.10.17
void billboard::on_startButton_clicked()
{
    buttonflag = buttonflag ? false : true;
    if(buttonflag == true)
    {
        if(ui->checkBox->isChecked()==true)
        {
            wtime=100000;
        }
        else if(ui->checkBox_3->isChecked()==true)
        {
           wtime=500000;
        }
        else if(ui->checkBox_5->isChecked()==true)
        {
           wtime=1000000;
        }
        else if(ui->checkBox_7->isChecked()==true)
        {
           wtime=2000000;
        }
        if(ui->fileNameTextEdit->toPlainText() != "")
            ui->startButton->setText(tr("停止"));
        else
            buttonflag = false;
        emit workSet(wtime,true);
    }
    else
    {
        ui->startButton->setText(tr("开始"));
        stopShow(false);
    }

}

void billboard::on_checkBox_stateChanged()
{
    if(ui->checkBox->isChecked()==true)
    {
          ui->checkBox_3->setEnabled(false);
          ui->checkBox_5->setEnabled(false);
          ui->checkBox_7->setEnabled(false);
    }else
    {
        ui->checkBox_3->setEnabled(true);
        ui->checkBox_5->setEnabled(true);
        ui->checkBox_7->setEnabled(true);
    }

}

void billboard::on_checkBox_3_stateChanged()
{
    if(ui->checkBox_3->isChecked()==true)
    {
        ui->checkBox->setEnabled(false);
        ui->checkBox_5->setEnabled(false);
        ui->checkBox_7->setEnabled(false);
    }else
    {
        ui->checkBox->setEnabled(true);
        ui->checkBox_5->setEnabled(true);
        ui->checkBox_7->setEnabled(true);
    }
}

void billboard::on_checkBox_5_stateChanged()
{
    if(ui->checkBox_5->isChecked()==true)
    {
        ui->checkBox->setEnabled(false);
        ui->checkBox_3->setEnabled(false);
        ui->checkBox_7->setEnabled(false);
    }else
    {
        ui->checkBox->setEnabled(true);
        ui->checkBox_3->setEnabled(true);
        ui->checkBox_7->setEnabled(true);
    }
}

void billboard::on_checkBox_7_stateChanged()
{
    if(ui->checkBox_7->isChecked()==true)
    {
        ui->checkBox->setEnabled(false);
        ui->checkBox_3->setEnabled(false);
        ui->checkBox_5->setEnabled(false);
    }else
    {
        ui->checkBox->setEnabled(true);
        ui->checkBox_3->setEnabled(true);
        ui->checkBox_5->setEnabled(true);
    }
}
