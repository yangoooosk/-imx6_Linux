#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "led_control.h"

// 你需要根据你的驱动程序修改这些值
#define LED_ON_COMMAND  1  // 假设 1 是打开 LED 的命令
#define LED_OFF_COMMAND 0  // 假设 0 是关闭 LED 的命令
#define NUM_LEDS        4  // LED 的数量

int blink_led(const char* device_file) {
    int fd;
    int ret;

    fd = open(device_file, O_RDWR);
    if (fd < 0) {
        perror("open device");
        return -1;
    }
    for(int sb=2;sb!=0;sb--)
    {
        for (int i = 0; i < NUM_LEDS; i++) {
            // 亮半秒
            ret = ioctl(fd, LED_ON_COMMAND, i); // 控制第 i 个 LED
            if (ret < 0) {
                perror("ioctl");
                close(fd);
                return -1;
            }
        }
    usleep(500000);

    for (int i = 0; i < NUM_LEDS; i++) {
        // 灭四分之一秒
        ret = ioctl(fd, LED_OFF_COMMAND, i); // 控制第 i 个 LED
        if (ret < 0) {
            perror("ioctl");
            close(fd);
            return -1;
        }
    }
    usleep(250000);

    for (int i = 0; i < NUM_LEDS; i++) {
        // 亮半秒
        ret = ioctl(fd, LED_ON_COMMAND, i); // 控制第 i 个 LED
        if (ret < 0) {
            perror("ioctl");
            close(fd);
            return -1;
        }
    }
    usleep(500000);

    for (int i = 0; i < NUM_LEDS; i++) {
        // 灭四分之一秒
        ret = ioctl(fd, LED_OFF_COMMAND, i); // 控制第 i 个 LED
        if (ret < 0) {
            perror("ioctl");
            close(fd);
            return -1;
        }
    }
    usleep(250000);
    }
    close(fd);
    return 0;
}
