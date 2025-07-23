#include "workthread.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/mman.h>

workThread::workThread(QObject *parent) :
    QThread(parent)
{
        mem_fd = open("/dev/mem", O_RDWR);
        cpld = (unsigned short*)mmap(NULL,(size_t)0x20,PROT_READ | PROT_WRITE | PROT_EXEC,MAP_SHARED,mem_fd,(off_t)(0x8000000));
        if(cpld == MAP_FAILED)
            return;

        work_Th = false;
        charsize_Th = 0;
        wtime_Th = 0;
}

workThread::~workThread()
{
    munmap(cpld,0x20);
    ::close(mem_fd);
}

void workThread::run()
{
    int i,j,z;
    while(1)
    {
            usleep(1);
            for(z=0;z<charsize_Th-1;z++)
            {
                if(work_Th == false)
                    break;
                for(j=0;j<16;j++)
                {
                    if(work_Th == false)
                        break;
                    for(i=0;i<16;i++)
                    {
                        if(work_Th == false)
                            break;
                        if(i < 16-j)
                            *(cpld+((0xc0+i)<<1)) = ((GB_16_Th[z].Msk[(i+j)*2]<<8) + (GB_16_Th[z].Msk[(i+j)*2+1]));   //数码管
                        else
                            *(cpld+((0xc0+i)<<1)) = ((GB_16_Th[z+1].Msk[(i-(16-j))*2]<<8) + (GB_16_Th[z+1].Msk[(i-(16-j))*2+1]));   //数码管
                    }
                    usleep(wtime_Th);
                }
            }
    }
}

void workThread::PreferencesTh(typFNT_GB16 *GB_16,int charsize,bool work)
{
    GB_16_Th = GB_16;
    charsize_Th = charsize;
    work_Th = work;
  //  printf("size=%d,work=%d\n",charsize_Th,work_Th);
}

void workThread::workSetStart(long wtime,bool work)
{
    wtime_Th = wtime;
    work_Th = work;
   // printf("wtime=%d,work=%d\n",wtime_Th,work_Th);
}

void workThread::workSetStop(bool work)
{
    work_Th = work;
}
