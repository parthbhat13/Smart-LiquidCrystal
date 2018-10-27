/*
  Functions In Version 1.0

  -- InitDisp      --> This Helps to Define If Its i2C Disp Or A normal
  -- FlashString    --> This is if you want to Flash a String On the LCD
  -- FlashLogo      --> This is if you want to Flash a logo on the lcd
  -- AltStr       --> This is if you want to flash an alternate String
  -- AltLogo        --> This is if you want to flash an alternate Logo
  -- ClrRow         --> This Helps to just clear the Specific Row Insted Of The Whole Lcd
  -- DispWait       --> This Displays a Please Wait Message With Dots ("Please Wait...");
  -- FlashBackLight --> This Helps to Just Flash The Backlight Of The Display

  Copyright (c) 2018 Parth Yatin Temkar

  Permission is hereby granted, free of charge, to any person obtaining
  a copy of this software and associated documentation files (the
  "Software"), to deal in the Software without restriction, including
  without limitation the rights to use, copy, modify, merge, publish,
  distribute, sublicense, and/or sell copies of the Software, and to
  permit persons to whom the Software is furnished to do so, subject to
  the following conditions:

  The above copyright notice and this permission notice shall be
  included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

  Author: Parth Yatin Temkar
  Date Of Creation: 22nd September 2018
  Version: 1.2

*/

#ifndef SmartDisplay_h
#define SmartDisplay_h

#include "Arduino.h"
#include <LiquidCrystal.h>

#define DEFAULT_FLASH 		500				//The default waiting time before every flash in ms
#define DEFAULT_ALTERNATE 	1500			//The default waiting time for alternate string flashing in ms
#define DEFAULT_INTRO		1500			//The default waiting time for every intro line in ms
#define DEFAULT_WAIT		500				//The default waiting time for the display wait in ms

#define BUFF_SIZE	100
#define NUM_SIZE	100

extern LiquidCrystal lcd;
class SmartDisplay {
  public:
    SmartDisplay(uint8_t mode);

    //Char
    void Flash(uint8_t col, uint8_t row, char* data, bool onoff, unsigned long delay);
    void Flash(uint8_t col, uint8_t row, char* data, unsigned long delay);
    void Flash(uint8_t col, uint8_t row, char* data, bool onoff);
    void Flash(uint8_t col, uint8_t row, char* data);

    //Long
    void Flash(uint8_t col, uint8_t row, long data, bool onoff, unsigned long delay);
    void Flash(uint8_t col, uint8_t row, long data, unsigned long delay);
    void Flash(uint8_t col, uint8_t row, long data, bool onoff);
    void Flash(uint8_t col, uint8_t row, long data);

    //Unsigned Long
    void Flash(uint8_t col, uint8_t row, unsigned long data, bool onoff, unsigned long delay);
    void Flash(uint8_t col, uint8_t row, unsigned long data, unsigned long delay);
    void Flash(uint8_t col, uint8_t row, unsigned long data, bool onoff);
    void Flash(uint8_t col, uint8_t row, unsigned long data);


    //Float
    void Flash(uint8_t col, uint8_t row, float data, bool onoff, unsigned long delay);
    void Flash(uint8_t col, uint8_t row, float data, unsigned long delay);
    void Flash(uint8_t col, uint8_t row, float data, bool onoff);
    void Flash(uint8_t col, uint8_t row, float data);

    //Int
    void Flash(uint8_t col, uint8_t row, int data, bool onoff, unsigned long delay);
    void Flash(uint8_t col, uint8_t row, int data, unsigned long delay);
    void Flash(uint8_t col, uint8_t row, int data, bool onoff);
    void Flash(uint8_t col, uint8_t row, int data);

    //Flash Logo Single
    void FlashLogo(uint8_t col, uint8_t row, byte logo, bool onoff, unsigned long delay);
    void FlashLogo(uint8_t col, uint8_t row, byte logo, unsigned long delay);
    void FlashLogo(uint8_t col, uint8_t row, byte logo, bool onoff);
    void FlashLogo(uint8_t col, uint8_t row, byte logo);
	
	//Flash Logo Dual
	void FlashLogo(uint8_t col, uint8_t row, byte logoone, byte logotwo, bool onoff, unsigned long delay);
    void FlashLogo(uint8_t col, uint8_t row, byte logoone, byte logotwo, unsigned long delay);
    void FlashLogo(uint8_t col, uint8_t row, byte logoone, byte logotwo, bool onoff);
    void FlashLogo(uint8_t col, uint8_t row, byte logoone, byte logotwo);

    //One: Char Two: Char
    void Alt(uint8_t col, uint8_t row, char* one, char* two, unsigned long delay);
    void Alt(uint8_t col, uint8_t row, char* one, char* two);

    //One: Char Two:Long
    void Alt(uint8_t col, uint8_t row, char* one, long two, unsigned long delay);
    void Alt(uint8_t col, uint8_t row, char* one, long two);

    //One: long Two: Char
    void Alt(uint8_t col, uint8_t row, long one, char* two, unsigned long delay);
    void Alt(uint8_t col, uint8_t row, long one, char* two);

    //One: Char Two:unsigned Long
    void Alt(uint8_t col, uint8_t row, char* one, unsigned long two, unsigned long delay);
    void Alt(uint8_t col, uint8_t row, char* one, unsigned long two);

    //One: unsigned Long  Two:char
    void Alt(uint8_t col, uint8_t row, unsigned long one, char* two, unsigned long delay);
    void Alt(uint8_t col, uint8_t row, unsigned long one, char* two);


    //One: Char Two: Float
    void Alt(uint8_t col, uint8_t row, char* one, float two, unsigned long delay);
    void Alt(uint8_t col, uint8_t row, char* one, float two);

    //One: Float  Two:char
    void Alt(uint8_t col, uint8_t row, float one, char* two, unsigned long delay);
    void Alt(uint8_t col, uint8_t row, float one, char* two);

    //One: Char Two: Int
    void Alt(uint8_t col, uint8_t row, char* one, int two, unsigned long delay);
    void Alt(uint8_t col, uint8_t row, char* one, int two);

    //One: Int  Two:char
    void Alt(uint8_t col, uint8_t row, int one, char* two, unsigned long delay);
    void Alt(uint8_t col, uint8_t row, int one, char* two);

    //Alternate Logo
    void AltLogo(uint8_t col, uint8_t row, byte one, byte two, unsigned long delay);
    void AltLogo(uint8_t col, uint8_t row, byte one, byte two);

  private:
    unsigned long _Laststringflash;
    bool _Flashstringstate;

    unsigned long _Lastlogoflash;
    bool _Flashlogostate;

    unsigned long _Lastaltstr;
    bool _Altstrstate;

    unsigned long _Lastaltlogo;
    bool _Altlogostate;


};

void ClearRow(uint8_t nrow);
void DispWait(uint8_t col, uint8_t row, char* data, uint8_t count, uint16_t Delay);
void DispWait(uint8_t col, uint8_t row, char* data, uint8_t count);

void DispIntro(uint8_t col, uint8_t row, char* data, bool cleardisp, uint8_t wait);
void DispIntro(uint8_t col, uint8_t row, char* data, bool cleardisp);
void DispIntro(uint8_t col, uint8_t row, char* data, uint8_t wait);
void DispIntro(uint8_t col, uint8_t row, char* data);

void ftoa(double n, char *res, int afterpoint);
int intToStr(int x, char str[], int d);
void rever(char *str, int len);

#endif
