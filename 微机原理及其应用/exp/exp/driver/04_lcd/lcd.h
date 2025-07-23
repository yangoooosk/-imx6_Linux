/*
 *	lcd.h  ---	Primary header file for 
 *				LCD Device Driver with Framebuffer
 *	(C)opyright 2004 Bit 920 Labs
 *
 *	Written by: Ye Nan <bye200009123@163.com>
 *	Created on: Sat. Mar 6 22:03:45 GMT +8:00 2004
 */


#ifndef __FB_LCD_H
#define __FB_LCD_H

#include <linux/fb.h>

// Define common data types
#ifndef __AES_TYPE_DEF__
#define __AES_TYPE_DEF__

typedef unsigned char	ByteType;
typedef unsigned short	WordType;
typedef unsigned long	DWordType;

#endif	// __AES_TYPE_DEF__

// Define color types
typedef unsigned long	ColorType;

#define SYS_BLACK		0x00000000
#define SYS_WHITE		0xffffffff

// Define default dash space
#define DEFAULT_DASH	2

// Framebuffer device display information
unsigned int fb_bpp;
unsigned int fb_width;
unsigned int fb_height;
unsigned int fb_pixel_size;
unsigned int fb_line_size;
unsigned int fb_buffer_size;

// Define macro of display information
#define BPP				fb_bpp
#define SCREEN_WIDTH	fb_width
#define SCREEN_HEIGHT	fb_height
#define PIXEL_SIZE		fb_pixel_size
#define LINE_SIZE		fb_line_size
#define BUFFER_SIZE		fb_buffer_size



/* * * * * * * * * * * * * * * * * * * *
 *
 * Framebuffer device display functions
 *
 * * * * * * * * * * * * * * * * * * * */

// Framebuffer initialization.
// Failed return 0, succeed return 1.
int fb_Init(void);

// Framebuffer release
void fb_Release(void);

// Assert device is opened
int fb_AssertDevice(int dev);

// Make up System Palette
void fb_MakePalette(struct fb_cmap *map);

// Save System Palette
int fb_SavePalette(struct fb_cmap * map);

// Update System Palette
int fb_UpdatePalette(struct fb_cmap map);

// Make up a color fits for 8-bit display according to RGB factors specified
ColorType fb_MakeColor_8(ByteType red, ByteType green, ByteType blue);

// Make up a color fits for 16-bit display according to RGB factors specified
ColorType fb_MakeColor_16(ByteType red, ByteType green, ByteType blue);

// Retrieve base address of frame buffer
void * fb_GetFrameAddr();

// Retrieve screen width
unsigned int fb_GetScreenWidth();

// Retrieve screen height
unsigned int fb_GetScreenHeight();

// Retrieve screen bits_per_pixel
unsigned int fb_GetScreenBpp();

// Retrieve screen colors
unsigned int fb_GetScreenColors();

// Clear screen with specified color
void fb_Clear(ColorType color);

// Put a color pixel on the screen
void fb_PutPixel(short x, short y, ColorType color/*, int xorm */);

// Retrieve the color of specified pixel
ColorType fb_GetPixel(short x, short y);

// Draw a horizontal line on the screen
void fb_DrawLine_H(short x1, short x2, short y, ColorType color/*, int xorm */);

// Draw a vertical line on the screen
void fb_DrawLine_V(short x, short y1, short y2, ColorType color/*, int xorm */);

// Draw a common line on the screen
void fb_DrawLine(short x1, short y1, short x2, short y2, ColorType color/*, int xorm */);

// Draw a horizontal dashed line on the screen
void fb_DrawDashed_H(short x1, short x2, short y, short spaceWidth, ColorType color);

// Draw a vertical dashed line on the screen
void fb_DrawDashed_V(short x, short y1, short y2, short spaceWidth, ColorType color);
	
// Draw a rectangle frame on the screen
void fb_DrawRect(short x1, short y1, short x2, short y2, ColorType color);
                                                                                                                                                                                                                                                                                                                                                            
// Draw a rectangle frame on the screen
void fb_FillRect(short x1, short y1, short x2, short y2, ColorType color);

// Draw a specified character with 16 x 8 dot matrix code on the screen
void fb_Text_8x16(short x, short y, unsigned char * dotCodes, ColorType color);

// Draw a specified character with 16 x 16 dot matrix code on the screen
void fb_Text_16x16(int x, int y, unsigned char * dotCodes, ColorType color);

// Draw a ellipse, center at point (x, y), 
// a specifies x_axis radius, b specifies y_axis radius
void fb_DrawEllipse(short x, short y, short a, short b, ColorType color);

// Draw a ellipse, center at point (x, y), 
// a specifies x_axis radius, b specifies y_axis radius
void fb_FillEllipse(short x, short y, short a, short b, ColorType color);

#endif	// __FB_LCD_H
