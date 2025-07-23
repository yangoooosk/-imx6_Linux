/*
 *	lcd.c  ---	Primary C source file for 
 *				LCD Device Driver with Framebuffer
 *	(C)opyright 2004 Bit 920 Labs
 *
 *	Written by: Ye Nan <bye200009123@163.com>
 *	Created on: Sat. Mar 6 22:03:45 GMT +8:00 2004
 */

#ifndef __FB_LCD_C
#define __FB_LCD_C

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
#include <time.h>
#include "lcd.h"

int current_vt;
struct termios term;

extern ColorType fb_GetPixel(short , short );
// Framebuffer device routine
int fb_con = 0;				/* framebuffer device handle */
void * frame_base = 0;			/* lcd framebuffer base address */

// Framebuffer initialization.
// Failed return -1, succeed return 0.
int fb_Init(void)
{
	struct fb_fix_screeninfo finfo;		/* fixed screen information */
	struct fb_var_screeninfo vinfo;		/* variable screen information */
	struct termios current;	

	unsigned short red[256], green[256], blue[256];
	struct fb_cmap new_map = {0, 256, red, green, blue, NULL};		/* new system palette */
	
	tcgetattr(0, &term);
	current = term;

	current.c_lflag &= ~ICANON;
	current.c_lflag &= ~ECHO;
	current.c_cc[VMIN] = 1;
	current.c_cc[VTIME] = 0;  
    
	// Open framebuffer device
	fb_con = open("/dev/fb0", O_RDWR, 0);  
	if (fb_con < 0) 
	{
		printf("Can't open /dev/fb0.\n");
		return -1;
	}

	// Get fixed screen information
	if (ioctl(fb_con, FBIOGET_FSCREENINFO, &finfo) < 0)
	{
		printf("Can't get FSCREENINFO.\n");
		close(fb_con);

		return -1;
	}
	// Get variable screen information
	if (ioctl(fb_con, FBIOGET_VSCREENINFO, &vinfo) < 0)
	{
      	printf("Can't get VSCREENINFO.\n");
		close(fb_con);

	    return -1;
   	}

	// Palette opertion
	srand(time(0));
	// Make up a new palette
	fb_MakePalette(&new_map);

	// Apply new framebuffer palette
	if (finfo.visual == FB_VISUAL_DIRECTCOLOR || vinfo.bits_per_pixel == 8)
	{
		if (ioctl(fb_con, FBIOPUTCMAP, &new_map) < 0)
		{
			printf("Error putting Colormap.\n");
			return -1;
		}
	}

	// Configure framebuffer color settings
	switch (vinfo.bits_per_pixel)
	{
		case 8:
			fb_pixel_size = 1;
			break;

		case 16:
			fb_pixel_size = 2;
			vinfo.red.offset = 11;
			vinfo.red.length = 5;
			vinfo.green.offset = 5;
			vinfo.green.length = 6;
			vinfo.blue.offset = 0;
			vinfo.blue.length = 5;
			break;
		case 32:
			fb_pixel_size = 4;
			vinfo.red.offset = 24;
			vinfo.red.length = 8;
			vinfo.green.offset = 16;
			vinfo.green.length = 8;
			vinfo.blue.offset = 8;
			vinfo.blue.length = 8;
			vinfo.transp.offset = 0;
			vinfo.transp.length = 8;
			break;

		default:
			fprintf(stderr, "Current color depth is NOT surpported.\n");
			fb_pixel_size = 1;
			break;
	}
	// Apply new settings to the framebuffer
	if (ioctl(fb_con, FBIOPUT_VSCREENINFO, &vinfo) < 0)
	{
		fprintf(stderr, "Couldn't set ideal mode at FBIOPUT_VSCREENINFO");
		return -1;
	}

	// Retrieve screen size information
	if (ioctl(fb_con, FBIOGET_VSCREENINFO, &vinfo) < 0)
	{
		fprintf(stderr, "ioctl FBIOGET_VSCREENINFO");
		return -1;
	}
	fb_width = vinfo.xres_virtual;
	//fb_height = vinfo.yres_virtual/2;
	fb_height = vinfo.yres_virtual;//for UP-CUP4412 Linux-3.5 kernel
	fb_bpp = vinfo.bits_per_pixel;
	fb_line_size = finfo.line_length;
	fb_buffer_size = finfo.smem_len;
	
	// Map frame buffer to a vitual memory area
	frame_base = mmap(NULL, BUFFER_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fb_con, 0);
	if (frame_base == MAP_FAILED)
    	{        
        	fprintf(stderr, "Can't mmap.\n");
		close(fb_con);
	 	return -1;    
	}
    	printf("\nVideo memory address = 0x%x\n",frame_base);
	printf("Video visible resolution: x_res = %ld, y_res = %ld\n", SCREEN_WIDTH, SCREEN_HEIGHT);

	// Clear screen
	fb_Clear(SYS_BLACK);

	return 0;
}

// Framebuffer release
void fb_Release(void)
{
	fb_AssertDevice(fb_con);

	// release the vitual memeory area of frame buffer
   	munmap(frame_base, BUFFER_SIZE);

	// close framebuffer device
	if(fb_con)
     		close(fb_con);

//        tcsetattr(0, TCSANOW, &term);

	return;
}

// Assert device is opened
int fb_AssertDevice(int dev)
{
	if (dev == 0)
	{
		printf("Device is NOT opened.\n");
		return -1;
	}

	return 0;
}

// Make up System Palette
void fb_MakePalette(struct fb_cmap *map)
{
	int rs, gs, bs, i;
	int r = 8, g = 8, b = 4;

	if (map == NULL)
		return;

	rs = 256 / (r - 1);
	gs = 256 / (g - 1);
	bs = 256 / (b - 1);
	
	for (i = 0; i < 256; i++)
	{
		map->red[i]   = (rs * ((i / (g * b)) % r)) * 255;
		map->green[i] = (gs * ((i / b) % g)) * 255;
		map->blue[i]  = (bs * ((i) % b)) * 255;
	}

	return;
}

// Save System Palette
int fb_SavePalette(struct fb_cmap * map)
{
	fb_AssertDevice(fb_con);

	if (BPP == 8)
	{
		if (ioctl(fb_con, FBIOGETCMAP, map) < 0) 
		{
			printf("Save system palette failed.\n");
			return -1;
		}
	}

	return 0;
}

// Update System Palette
int fb_UpdatePalette(struct fb_cmap map)
{
	fb_AssertDevice(fb_con);

	if (BPP == 8)
	{
		if(ioctl(fb_con, FBIOPUTCMAP, &map) < 0)
		{
			printf("Update system palette failed.\n");
			return -1;
		}
	}

	return 0;
}

// Make up a color fits for 8-bit display according to RGB factors specified
ColorType fb_MakeColor_8(ByteType red, ByteType green, ByteType blue)
{
	ColorType color;

	// Adjust RGB factors to fit 16 bit display
	red >>= 5;
	green >>= 5;
	blue >>=6;

	red &= 7;
	green &= 7;
	blue &= 3;

		
	// Use RGB factors to make up the display color
	color = (red << 5 | green << 2 | blue);

    return color;
}

// Make up a color fits for 16-bit display according to RGB factors specified
ColorType fb_MakeColor_16(ByteType red, ByteType green, ByteType blue)
{
	ColorType color;

	// Adjust RGB factors to fit 16 bit display
	red >>= 3;
	green >>= 2;
	blue >>= 3;
		
	// Use RGB factors to make up the display color
	color = (red << 11 | green << 5 | blue);

    return color;
}

// Retrieve base address of frame buffer
void * fb_GetFrameAddr()
{
	return frame_base;
}

// Retrieve screen width
unsigned int fb_GetScreenWidth()
{
	return SCREEN_WIDTH;
}

// Retrieve screen height
unsigned int fb_GetScreenHeight()
{
	return SCREEN_HEIGHT;
}

// Retrieve screen bpp(bits per pixel)
unsigned int fb_GetScreenBpp()
{
	return BPP;
}

// Retrieve screen colors
unsigned int fb_GetScreenColors()
{
	return (1 << BPP);
}

// Clear screen with specified color
void fb_Clear(ColorType color)
{
	switch (BPP)
	{
		case 8:
			memset((ByteType *)frame_base, (color & 0xff), BUFFER_SIZE);
			break;

		case 16:
			memset((WordType *)frame_base, (color & 0xffff), BUFFER_SIZE);
			break;
	
		case 32:
			memset((DWordType *)frame_base, (color & 0xffffffff), BUFFER_SIZE);
			break;
		default:
			break;
	}
}

// Put a color pixel on the screen
void fb_PutPixel(short x, short y, ColorType color/*, int xorm */)
{
	void * currPoint;

	if (x < 0 || x >= SCREEN_WIDTH ||
		y < 0 || y >= SCREEN_HEIGHT)
	{
#ifdef ERR_DEBUG
		printf("DEBUG_INFO: Pixel out of screen range.\n");
		printf("DEBUG_INFO: x = %d, y = %d\n", x, y);
#endif
		return;
	}

	// Calculate address of specified point
	currPoint = (ByteType *)frame_base + y * LINE_SIZE + x * PIXEL_SIZE;

#ifdef DEBUG
		printf("DEBUG_INFO: x = %d, y= %d, currPoint = 0x%x\n", x, y, currPoint);
#endif

	switch (BPP)
	{
		case 8:
			*((ByteType *)currPoint) = (color & 0xff);
			break;
			
		case 16:
			*((WordType *)currPoint) = (color & 0xffff);
			break;
		case 32:
			*((DWordType *)currPoint) = (color & 0xffffffff);
			break;
		default:
			break;
	}
	return;
}

//Retrieve the color of specified pixel
ColorType fb_GetPixel(short x, short y)
{
	void * currPoint;
	ColorType color;

	if (x < 0 || x >= SCREEN_WIDTH ||
		y < 0 || y >= SCREEN_HEIGHT)
	{
#ifdef ERR_DEBUG
		printf("DEBUG_INFO: Pixel out of screen range.\n");
		printf("DEBUG_INFO: x = %d, y = %d\n", x, y);
#endif
		return 0;
	}

	// Calculate address of specified point
	currPoint = (ByteType *)frame_base + y * LINE_SIZE + x * PIXEL_SIZE;

#ifdef DEBUG
		printf("DEBUG_INFO: x = %d, y= %d, currPoint = 0x%x\n", x, y, currPoint);
#endif

	switch (BPP)
	{
		case 8:
			color = *((ByteType *)currPoint);
			break;

		case 16:
			color = *((WordType *)currPoint);
			break;
		case 32:
			color = *((DWordType *)currPoint);
			break;
	}
	
	return color;
}


// Draw a horizontal line on the screen
void fb_DrawLine_H(short x1, short x2, short y, ColorType color)
{
	long startOffset = 0;

	x1 = (x1 < 0) ? 0 : x1; 
	x2 = (x2 < 0) ? 0 : x2;
	x1 = (x1 >= SCREEN_WIDTH) ? SCREEN_WIDTH - 1 : x1;
	x2 = (x2 >= SCREEN_WIDTH) ? SCREEN_WIDTH - 1 : x2;

	if (y < 0 || y >= SCREEN_HEIGHT)
	{
#ifdef ERR_DEBUG
		printf("DEBUG_INFO: Pixel out of screen range.\n");
		printf("DEBUG_INFO: x1 = %d, x2 = %d, y = %d\n", x1, x2, y);
#endif

		return; 
	}

	if (x1 > x2)
	{
		short tmp;

		tmp = x1;
		x1 = x2;
		x2 = tmp;
	}

	// Directly access memory instead of call putpixel function 
	// to make more effective performance of drawing a line
	startOffset = y * LINE_SIZE + x1 * PIXEL_SIZE;

#ifdef DEBUG
		printf("DEBUG_INFO: x1 = %d, x2 = %d, y = %d, startOffset = 0x%x\n", x1, x2, y, startOffset);
#endif

	switch (BPP)
	{
		case 8:
			memset((ByteType *)((ByteType *)frame_base + startOffset), (color & 0xff), (x2 - x1 + 1) * PIXEL_SIZE);
			break;

		case 16:
			memset((WordType *)((ByteType *)frame_base + startOffset), (color & 0xffff), (x2 - x1 + 1) * PIXEL_SIZE);
		
		case 32:
			memset((DWordType *)((ByteType *)frame_base + startOffset), (color & 0xffffffff), (x2 - x1 + 1) * PIXEL_SIZE);
		break;
	}

	return;
}

// Draw a vertical line on the screen
void fb_DrawLine_V(short x, short y1, short y2, ColorType color)
{
	short currLine;
	void * currPoint;

	y1 = (y1 < 0) ? 0 : y1;
	y2 = (y2 < 0) ? 0 : y2;

	y1 = (y1 >= SCREEN_HEIGHT) ? SCREEN_HEIGHT - 1 : y1;
	y2 = (y2 >= SCREEN_HEIGHT) ? SCREEN_HEIGHT - 1 : y2;

	if (x < 0 || x >= SCREEN_WIDTH)
	{
#ifdef ERR_DEBUG
		printf("DEBUG_INFO: Pixel out of screen range.\n");
		printf("DEBUG_INFO: x = %d, y1 = %d, y2 = %d\n", x, y1, y2);
#endif

		return;
	}

	if (y1 > y2)
	{
		short tmp;

		tmp = y1;
		y1 = y2;
		y2 = tmp;
	}

	// Directly access memory instead of call putpixel function 
	// to make more effective performance of drawing a line
	currPoint = (ByteType *)frame_base + y1 * LINE_SIZE + x * PIXEL_SIZE;

#ifdef DEBUG
		printf("DEBUG_INFO: x = %d, y1 = %d, y2 = %d, currPoint = 0x%x\n", x, y1, y2, currPoint);
#endif

	for (currLine = y1; currLine <= y2; currLine++) 
	{
		switch (BPP)
		{
			case 8:
				*((ByteType *)currPoint) = (color & 0xff);
				break;

			case 16:
				*((WordType *)currPoint) = (color & 0xffff);
				break;
			case 32:
				*((DWordType *)currPoint) = (color & 0xffffffff);
				break;
			default:
				break;
		}

		currPoint = currPoint + LINE_SIZE;
	}	

  	return;
}

// Draw a common line on the screen
void fb_DrawLine(short x1, short y1, short x2, short y2, ColorType color/*, int xorm */)
{
	int i = 0;
	int d = 0;

	if(abs(y2 - y1) > abs(x2 - x1))
	{
		d = (y2 > y1) ? 1 : -1;

		for(i = y1; i != y2; i += d)
		{
			fb_PutPixel(x1 + (i - y1) * ( x2 - x1) / (y2 - y1), i, color);
		}
	}
	else
	{
		d = (x2 > x1) ? 1 : -1;

		for(i = x1; i != x2; i += d)
		{
			fb_PutPixel(i, y1 + (i - x1) * (y2 - y1) / (x2 - x1), color);
		}        
	}
}

// Draw a horizontal dashed line on the screen
void fb_DrawDashed_H(short x1, short x2, short y, short spaceWidth, ColorType color)
{
	short i;
	short dashCount;	/* dashed width counter */
	short isSpace;		/* sign for put a pixel or not */

	if (x1 > x2)
	{
		short tmp;

		tmp = x1;
		x1 = x2;
		x2 = tmp;
	}

	if (spaceWidth < 0 || spaceWidth > (x2 - x1))
	{
#ifdef ERR_DEBUG
		printf("DEBUG_INFO: spaceWidth out of range.\n");
		printf("DEBUG_INFO: spaceWidth = %d\n", spaceWidth);
#endif
		spaceWidth = DEFAULT_DASH;

#ifdef ERR_DEBUG
		printf("DEBUG_INFO: Set to DEFAULT_DASH.\n");
		printf("DEBUG_INFO: spaceWidth = %d\n", spaceWidth);
#endif
	}

	dashCount = 0;
	isSpace = 0;
	for (i = x1; i <= x2; i++)
	{
		// to put a pixel with a specified color according isSpace sign
		if (!isSpace)
		{
			fb_PutPixel(i, y, color);
			dashCount++;
		}
		else
			dashCount++;

		if (dashCount == spaceWidth)
		{
			dashCount = 0;
			isSpace ^= 1;
		}
	}

	return;
}

// Draw a vertical dashed line on the screen
void fb_DrawDashed_V(short x, short y1, short y2, short spaceWidth, ColorType color)
{
	short i;
	short dashCount;	/* dashed width counter */
	short isSpace;		/* sign for put a pixel or not */

	if (y1 > y2)
	{
		short tmp;

		tmp = y1;
		y1 = y2;
		y2 = tmp;
	}

	if (spaceWidth < 0 || spaceWidth > (y2 - y1))
	{
#ifdef ERR_DEBUG
		printf("DEBUG_INFO: spaceWidth out of range.\n");
		printf("DEBUG_INFO: spaceWidth = %d\n", spaceWidth);
#endif
		spaceWidth = DEFAULT_DASH;

#ifdef ERR_DEBUG
		printf("DEBUG_INFO: Set to DEFAULT_DASH.\n");
		printf("DEBUG_INFO: spaceWidth = %d\n", spaceWidth);
#endif
	}

	dashCount = 0;
	isSpace = 0;
	for (i = y1; i <= y2; i++)
	{
		// To put a pixel with a specified color according isSpace sign
		if (!isSpace)
		{
			fb_PutPixel(x, i, color);
			dashCount++;
		}
		else
			dashCount++;

		if (dashCount == spaceWidth)
		{
			dashCount = 0;
			isSpace ^= 1;
		}
	}

	return;
}
	
// Draw a rectangle frame on the screen
void fb_DrawRect(short x1, short y1, short x2, short y2, ColorType color)
{
	// Draw horitontal frame
	fb_DrawLine_H(x1, x2, y1, color);
	fb_DrawLine_H(x1, x2, y2, color);
	// Draw vertical frame
	fb_DrawLine_V(x1, y1 + 1, y2 - 1, color);
	fb_DrawLine_V(x2, y1 + 1, y2 - 1, color);

	return;
}
                                                                                                                                                                                                                                                                                                                                                            
// Draw a rectangle frame on the screen
void fb_FillRect(short x1, short y1, short x2, short y2, ColorType color)
{
	short currLine;
	unsigned long startOffset;

	if (x1 < 0 || x1 >= SCREEN_WIDTH || 
		x2 < 0 || x2 >= SCREEN_WIDTH ||
		y1 < 0 || y1 >= SCREEN_HEIGHT ||
		y2 < 0 || y2 >= SCREEN_HEIGHT)
	{
#ifdef ERR_DEBUG
		printf("DEBUG_INFO: Pixel out of screen range.\n");
		printf("DEBUG_INFO: x1 = %d, y1 = %d, x2 = %d, y2 = %d\n", x1, y1, x2, y2);
#endif

		x1 = (x1 < 0) ? 0 : x1;
		x2 = (x2 < 0) ? 0 : x2;
		y1 = (y1 < 0) ? 0 : y1;
		y2 = (y2 < 0) ? 0 : y2;

		x1 = (x1 >= SCREEN_WIDTH) ? SCREEN_WIDTH - 1 : x1;
		x2 = (x2 >= SCREEN_WIDTH) ? SCREEN_WIDTH - 1 : x2;
		y1 = (y1 >= SCREEN_HEIGHT) ? SCREEN_HEIGHT - 1 : y1;
		y2 = (y2 >= SCREEN_HEIGHT) ? SCREEN_HEIGHT - 1 : y2;
	}

	if (x1 > x2)
	{
		short tmp;

		tmp = x1;
		x1 = x2;
		x2 = tmp;
	}

	if (y1 > y2)
	{
		short tmp;

		tmp = y1;
		y1 = y2;
		y2 = tmp;
	}

	startOffset = y1 * LINE_SIZE + x1 * PIXEL_SIZE;

#ifdef DEBUG
	printf("DEBUG_INFO: x1 = %d, y1 = %d, x2 = %d, y2= %d, color = 0x%x\n", x1, y1, x2, y2, color);
#endif

	// Directly access memory instead of call putpixel function 
	// to make more effective performance of drawing a line
	for (currLine = y1; currLine <= y2; currLine++)
	{
		switch (BPP)
		{
			case 8:
				memset((ByteType *)((ByteType *)frame_base + startOffset), (color & 0xff), (x2 - x1 + 1) * PIXEL_SIZE);
				break;

			case 16:
				memset((WordType *)((ByteType *)frame_base + startOffset), (color & 0xffff), (x2 - x1 + 1) * PIXEL_SIZE);
				break;
			case 32:
				memset((DWordType *)((ByteType *)frame_base + startOffset), (color & 0xffffffff), (x2 - x1 + 1) * PIXEL_SIZE);
				break;
			default:
				break;	
		}
		// Make a LINE_SIZE increment to the startOffset,
		// in order to move point to the start position of next line
		startOffset += SCREEN_WIDTH * PIXEL_SIZE;
	}

	return;
}

// Draw a specified character with 16 x 8 dot matrix code on the screen
void fb_Text_8x16(short x, short y, unsigned char * dotCodes, ColorType color)
{
	int i, j;

	if (x < 0 || x >= SCREEN_WIDTH ||
		y < 0 || y >= SCREEN_HEIGHT)
	{
#ifdef ERR_DEBUG
		printf("DEBUG_INFO: Pixel out of screen range.\n");
		printf("DEBUG_INFO: x = %d, y = %d\n", x, y);
#endif
		return;
	}

	if (dotCodes == NULL)
	{
#ifdef ERR_DEBUG
		printf("DEBUG_INFO: Dot codes NULL.\n");
#endif
		return;
	}

	for (i = 0; i < 16; i++)
	{
		x += 8;
		
		for (j = 0; j < 8; j++)
		{
			x--;

			if ((dotCodes[i] >> j) & 0x1)
			{
				fb_PutPixel(x, y, color);
			}
		}

		y++;
	}

	return;
}

// Draw a specified character with 16 x 16 dot matrix code on the screen
void fb_Text_16x16(int x, int y, unsigned char * dotCodes, ColorType color)
{
	int i, j, k;

	if (x < 0 || x >= SCREEN_WIDTH ||
		y < 0 || y >= SCREEN_HEIGHT)
	{
#ifdef ERR_DEBUG
		printf("DEBUG_INFO: Pixel out of screen range.\n");
		printf("DEBUG_INFO: x = %d, y = %d\n", x, y);
#endif
		return;
	}

	if (dotCodes == NULL)
	{
#ifdef ERR_DEBUG
		printf("DEBUG_INFO: Dot codes NULL.\n");
#endif
		return;
	}

	for(i = 0; i < 16; i++)
	{
		for (j = 0; j < 2; j++)
		{
			x += 8 * ( j + 1);

			for (k = 0; k < 8; k++)
			{
				x--;

				if ((dotCodes[2 * i + j] >> k) & 0x1)
				{
					fb_PutPixel(x, y, color);
				}
			}
		}

		x -= 8;
		++y;
	}

	return;
}

// Draw a ellipse, center at point (x, y), 
// a specifies x_axis radius, b specifies y_axis radius
void fb_DrawEllipse(short x, short y, short a, short b, ColorType color)
{
	int wx, wy;
	int thresh;
	int asq = a * a;
	int bsq = b * b;
	int xa, ya;
	
	if (a < 0 || b < 0)
	{
#ifdef ERR_DEBUG
		printf("DEBUG_INFO: Radius invalid.\n");
		printf("DEBUG_INFO: a = %d, b = %d\n", a, b);
#endif
		return;
	}

	fb_PutPixel(x, y + b, color);
	fb_PutPixel(x, y - b, color);

	wx = 0;
	wy = b;
	xa = 0;
	ya = asq * 2 * b;
	thresh = asq / 4 - asq * b;

	// Draw upper half of ellipse
	while(1)
	{
		thresh += xa + bsq;

		if (thresh >= 0)
		{
			ya -= asq * 2;
			thresh -= ya;
			wy--;
		}

		xa += bsq * 2;
		wx++;

		if (xa >= ya)
			break;


		fb_PutPixel(x + wx, y - wy, color);
		fb_PutPixel(x - wx, y - wy, color);
		fb_PutPixel(x + wx, y + wy, color);
		fb_PutPixel(x - wx, y + wy, color);
	}

	fb_PutPixel(x + a, y, color);
	fb_PutPixel(x - a, y, color);

	wx = a;
	wy = 0;
	xa = (bsq * a) << 1;

	ya = 0;
	thresh = (bsq >> 2) - bsq * a;

	// Draw lower half of ellipse
	while(1)
	{
		thresh += ya + asq;

		if (thresh >= 0)
		{
			xa -= bsq + bsq;
			thresh = thresh - xa;
			wx--;
		}

		ya += asq + asq;
		wy++;

		if (ya > xa)
			break;

		fb_PutPixel(x + wx, y - wy, color);
		fb_PutPixel(x - wx, y - wy, color);
		fb_PutPixel(x + wx, y + wy, color);
		fb_PutPixel(x - wx, y + wy, color);
	}

}

// Draw a ellipse, center at point (x, y), 
// a specifies x_axis radius, b specifies y_axis radius
void fb_FillEllipse(short x, short y, short a, short b, ColorType color)
{
	int wx, wy;
	int thresh;
	int asq = a * a;
	int bsq = b * b;
	int xa, ya;

	if (a < 0 || b < 0)
	{
#ifdef ERR_DEBUG
		printf("DEBUG_INFO: Radius invalid.\n");
		printf("DEBUG_INFO: a = %d, b = %d\n", a, b);
#endif
		return;
	}

	fb_PutPixel(x, y + b, color);
	fb_PutPixel(x, y - b, color);

	wx = 0;
	wy = b;
	xa = 0;
	ya = asq * 2 * b;
	thresh = asq / 4 - asq * b;

	// Fill upper half of ellipse
	while(1)
	{
		thresh += xa + bsq;

		if (thresh >= 0)
		{
			ya -= asq * 2;
			thresh -= ya;
			wy--;
		}

		xa += bsq * 2;
		wx++;

		if (xa >= ya)
			break;

		fb_DrawLine_H(x - wx, x + wx, y - wy, color);
		fb_DrawLine_H(x - wx, x + wx, y + wy, color);
	}

	fb_DrawLine_H(x - a, x + a, y, color);

	wx = a;
	wy = 0;
	xa = (bsq * a) << 1;

	ya = 0;
	thresh = (bsq >> 2) - bsq * a;

	// Fill lower half of ellipse
	while(1)
	{
		thresh += ya + asq;

		if (thresh >= 0)
		{
			xa -= bsq + bsq;
			thresh = thresh - xa;
			wx--;
		}

		ya += asq + asq;
		wy++;

		if (ya > xa)
			break;

		fb_DrawLine_H(x - wx, x + wx, y - wy, color);
		fb_DrawLine_H(x - wx, x + wx, y + wy, color);
	}
}

#endif	// __FB_LCD_C
