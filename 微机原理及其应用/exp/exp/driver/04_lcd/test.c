/*
 *	test.c  ---	Primary header file for 
 *	LCD Device Driver with Framebuffer
 *	(C)opyright 2004 Bit 920 Labs
 *
 *	Written by: Tangliting <dawn@bit.edu.cn>
 *	Created on: Sat. Mar 7 14:33:45 GMT +8:00 2004
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <linux/fb.h>
#include <linux/kd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <termios.h>
#include <sys/time.h>
#include <sys/ioctl.h>

#include "lcd.h"
#include "ascii.lib"

FILE *hzkFile = NULL;

void DrawCharEN(short x, short y, unsigned char c, ColorType color)
{
	unsigned char codes[16];
	short i;

	for (i = 0; i < 16; i++)
		codes[i] = ascii_codes[c][i];
	
	fb_Text_8x16(x, y, codes, color);
}

void DrawCharCHS(int x, int y, unsigned char c[2], ColorType color)
{
	unsigned char codes[32];
	short i;
	unsigned char ch, cl;
	unsigned long offset;

	if (hzkFile == NULL)
	{
		printf("No Chinese Character Library opened.\n");

		exit(1);
	}

	ch = c[0];
	cl = c[1];

	offset = ((ch - 0xa1) * 94L + (cl - 0xa1)) * 32L;

	fseek(hzkFile, offset, SEEK_SET);
	fread(codes, 32, 1, hzkFile);	

	fb_Text_16x16(x, y, codes, color);
}

int  main()
{
    	short x, y;
	short i;
	ColorType color = SYS_WHITE;
	short colorPage;
	short endFlag;
	unsigned char * ascTxt = "UP-IMX6DL";
	unsigned char * chsTxt = "嵌入式开发板";
	unsigned char bufferTxt[2];
	
	short x_max, y_max;
	ColorType color_max;

    	if (fb_Init() == -1)
	{
		printf("Initialize Framebuffer LCD failed.\n");
		exit(1);
	}
    
    	x_max = fb_GetScreenWidth() - 1;
    	y_max = fb_GetScreenHeight() - 1;
    	//color_max = fb_GetScreenColors() - 1;
    	color_max = fb_GetScreenBpp() - 1; 
	
	// Test Pixel functions
 	printf("Test PutPixel:\t\t");
	for(y = 0; y <= y_max; y += 10)
	{
		for (x = 0; x <= x_max; x += 10)
		{
			fb_PutPixel(x, y, color);
		}
	}
    	printf("Press any key to continue...\n");
	getchar();

	// Test Draw Lines functions
	printf("Test DrawLine_H blue:\t");
	fb_Clear(SYS_BLACK);
	for(y = 0; y <= y_max; y += 10)
	{
		fb_DrawLine_H(0, x_max,  y, color);
	}
    	
	printf("Press any key to continue...\n");
	getchar();
	
	printf("Test DrawLine_V: green\t");
	for(x = 0; x <= x_max; x += 10)
	{
		fb_DrawLine_V(x, 0, y_max, color);
	}
    	printf("Press any key to continue...\n");
	getchar();
	
	// Test Draw Dashed Lines functions
	printf("Test DrawDashed_H red:\t");
	fb_Clear(SYS_BLACK);
	for(y = 0; y <= y_max; y += 10)
	{
		fb_DrawDashed_H(0, x_max, y, 2, color);
	}
    	printf("Press any key to continue...\n");
	getchar();
	printf("Test DrawDashed_V:\t");
	for(x = 0; x <= x_max; x += 10)
	{
		fb_DrawDashed_V(x, 0, y_max, 2, color);
	}
    	
	printf("Press any key to continue...\n");
	getchar();

	// Test Rectangle functions
	printf("Test DrawRect:\t\t");
	fb_Clear(SYS_BLACK);
	for(y = 0; y <= y_max; y += 20)
	{
		for (x = 0; x <= x_max; x += 20)
		{
			fb_DrawRect(x, y, x + 10, y + 10, color);
		}
	}
	printf("Press any key to continue...\n");
	getchar();
	
	printf("Test fillRect:\t\t");
	fb_Clear(SYS_BLACK);
	for(y = 0; y <= y_max; y += 20)
	{
		for (x = 0; x <= x_max; x += 20)
		{
			fb_FillRect(x, y, x + 10, y + 10, color);
		}
	}
	printf("Press any key to continue...\n");
	getchar();


	// Test Ellipse functions
	printf("Test DrawEllipse:\t");
	fb_Clear(SYS_BLACK);
	for(y = 0; y <= y_max; y += 20)
	{
		for (x = 0; x <= x_max; x += 20)
		{
			fb_DrawEllipse(x + 10, y + 10, 5, 5, color);
		}
	}
	printf("Press any key to continue...\n");
	getchar();
	printf("Test FillEllipse:\t");
	fb_Clear(SYS_BLACK);
	for(y = 0; y <= y_max; y += 20)
	{
		for (x = 0; x <= x_max; x += 20)
		{
			fb_FillEllipse(x + 10, y + 10, 5, 5, color);
		}
	}
	printf("Press any key to continue...\n");
	getchar();

	// Test Text functions
	printf("Test text_16x8:\t\t");
	fb_Clear(SYS_BLACK);
	x = 10, y = 10;
	for (i = 0; i < strlen(ascTxt); i++)
	{
		DrawCharEN(x, y, ascTxt[i], color);
		x += 8;
	}
	printf("Press any key to continue...\n");
	getchar();
	printf("Test text_16x16:\t");
	hzkFile = fopen("./hz16", "rb");
	x = 10, y = 40;
	for (i = 0; i < strlen(chsTxt); i += 2)
	{
		bufferTxt[0] = chsTxt[i];
		bufferTxt[1] = chsTxt[i + 1];
		DrawCharCHS(x, y, bufferTxt, color);
		x += 16;
	}
	fclose(hzkFile);
	printf("Press any key to continue...\n");
	getchar();

	printf("\nFinished Test. Press any key to exit.\n");
	getchar();

    fb_Release();
}

