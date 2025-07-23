#ifndef BILLBOARD_H
#define BILLBOARD_H

#include <QWidget>
#include <QFileDialog>
#include <QDebug>
#include <QFile>
#include <QTimer>
#include <QMouseEvent>
#include <QMovie>
//#include "mythread.h"
#include "workthread.h"

namespace Ui {
class billboard;
}

class billboard : public QWidget
{
    Q_OBJECT

public:
    explicit billboard(QWidget *parent = 0);
    ~billboard();

private slots:
    void openFileButton_clicked();

    void on_startButton_clicked();

    void on_checkBox_stateChanged();

    void on_checkBox_3_stateChanged();

    void on_checkBox_5_stateChanged();

    void on_checkBox_7_stateChanged();

private:
    Ui::billboard *ui;

public:
    bool fre;
    workThread *workthread;

    typFNT_GB16 *GB_16;
    long wtime;
    int charsize;
     bool buttonflag;

private:

protected slots:
     void buttonPressEventSlot(QPoint a);

signals:
       void Preferences(typFNT_GB16 *GB_16,int charsize,bool work);
       void workSet(long wtime,bool work);
       void stopShow(bool work);
        void openfilebuttonsignal();
};

#endif // BILLBOARD_H
