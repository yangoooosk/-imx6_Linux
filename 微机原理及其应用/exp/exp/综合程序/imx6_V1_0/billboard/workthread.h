#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include <QThread>
#include <QWidget>

struct typFNT_GB16                 // 汉字字模数据结构
{
       char Index[4];               // 汉字内码索引
       char Msk[32];                       // 点阵码数据
};

class workThread: public QThread
{
    Q_OBJECT

    public:
        explicit workThread(QObject *parent = 0);
        ~workThread();
//public:
  //  workThread();
 //   ~workThread();

protected:
    void run();
protected:
    int mem_fd;
    unsigned short *cpld;
    typFNT_GB16 *GB_16_Th;
    bool work_Th;
    long wtime_Th;
    int charsize_Th;

public slots:
    void PreferencesTh(typFNT_GB16 *GB_16,int charsize,bool work);
    void workSetStart(long wtime,bool work);
    void workSetStop(bool work);
};

#endif // WORKTHREAD_H
