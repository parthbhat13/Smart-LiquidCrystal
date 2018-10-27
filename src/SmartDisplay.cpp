/*
  This is very basic library, It is intended to do the following Things

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

#include "Arduino.h"
#include "SmartDisplay.h"

SmartDisplay::SmartDisplay(uint8_t mode) {
  if (mode == 1) {
    //When 1 is selected its The Flash Text Mode
    //Initialize the variables here

    _Laststringflash = 0;
    _Flashstringstate = false;
  }

  else if (mode == 2) {
    //When 2 is selected its Flash Logo Mode
    //Initialize The Variables

    _Lastlogoflash = 0;
    _Flashlogostate = false;
  }

  else if (mode == 3) {
    //When 3 is selected its Alternate String Mode
    //Initialize the variables

    _Lastaltstr = 0;
    _Altstrstate = false;
  }
  else if (mode == 4) {
    //When 4 is selected Alternate Logo Mode
    //Initialize The Variables

    _Lastaltlogo = 0;
    _Altlogostate = false;
  }
}

// ================================= FLASH TEXT START ================================= //

void SmartDisplay::Flash(uint8_t col, uint8_t row, char* data, bool onoff, unsigned long delay) {

  //Check if its said as On/Off Flash Mode
  if (onoff) {
    unsigned long currentTime = millis();

    if (currentTime - _Laststringflash >= delay) {
      _Laststringflash = currentTime;
      _Flashstringstate = !_Flashstringstate;

      if (_Flashstringstate) {
        lcd.setCursor(col, row);
        lcd.print(data);
      }
      else {
        lcd.setCursor(col, row);
        for (int i = 0; i < strlen(data); i++) {
          lcd.print(" ");
        }
      }
    }
  }
  else {
    lcd.setCursor(col, row);
    lcd.print(data);
  }


}


void SmartDisplay::Flash(uint8_t col, uint8_t row, char* data, unsigned long delay) {

  unsigned long currentTime = millis();

  if (currentTime - _Laststringflash >= delay) {
    _Laststringflash = currentTime;
    _Flashstringstate = !_Flashstringstate;

    if (_Flashstringstate) {
      lcd.setCursor(col, row);
      lcd.print(data);
    }
    else {
      lcd.setCursor(col, row);
      for (int i = 0; i < strlen(data); i++) {
        lcd.print(" ");
      }
    }
  }



}


void SmartDisplay::Flash(uint8_t col, uint8_t row, char* data, bool onoff) {

  //Check if its said as On/Off Flash Mode
  if (onoff) {
    unsigned long currentTime = millis();

    if (currentTime - _Laststringflash >= DEFAULT_FLASH) {
      _Laststringflash = currentTime;
      _Flashstringstate = !_Flashstringstate;

      if (_Flashstringstate) {
        lcd.setCursor(col, row);
        lcd.print(data);
      }
      else {
        lcd.setCursor(col, row);
        for (int i = 0; i < strlen(data); i++) {
          lcd.print(" ");
        }
      }
    }
  }
  else {
    lcd.setCursor(col, row);
    lcd.print(data);
  }


}


void SmartDisplay::Flash(uint8_t col, uint8_t row, char* data) {

  unsigned long currentTime = millis();

  if (currentTime - _Laststringflash >= DEFAULT_FLASH) {
    _Laststringflash = currentTime;
    _Flashstringstate = !_Flashstringstate;

    if (_Flashstringstate) {
      lcd.setCursor(col, row);
      lcd.print(data);
    }
    else {
      lcd.setCursor(col, row);
      for (int i = 0; i < strlen(data); i++) {
        lcd.print(" ");
      }
    }
  }
}


// ================================= FLASH TEXT STOP ================================= //



// ================================= FLASH LONG START ================================= //

void SmartDisplay::Flash(uint8_t col, uint8_t row, long data, bool onoff, unsigned long delay) {
  //Check if the onoff is selected

  if (onoff) {
    unsigned long currentTime = millis();
    char buff[BUFF_SIZE];
    if (currentTime - _Laststringflash >= delay) {
      _Laststringflash = currentTime;
      _Flashstringstate = !_Flashstringstate;

      if (_Flashstringstate) {
        lcd.setCursor(col, row);
        lcd.print(data);
      }
      else {
        lcd.setCursor(col, row);
        ltoa(data, buff, NUM_SIZE);
        for (int i = 0; i < strlen(data); i++) {
          lcd.print(" ");
        }
      }
    }
  }
  else {
    lcd.setCursor(col, row);
    lcd.print(data);
  }

}

void SmartDisplay::Flash(uint8_t col, uint8_t row, long data, unsigned long delay) {

  unsigned long currentTime = millis();
  char buff[BUFF_SIZE];
  if (currentTime - _Laststringflash >= delay) {
    _Laststringflash = currentTime;
    _Flashstringstate = !_Flashstringstate;

    if (_Flashstringstate) {
      lcd.setCursor(col, row);
      lcd.print(data);
    }
    else {
      lcd.setCursor(col, row);
      ltoa(data, buff, NUM_SIZE);
      for (int i = 0; i < strlen(data); i++) {
        lcd.print(" ");
      }
    }
  }

}

void SmartDisplay::Flash(uint8_t col, uint8_t row, long data, bool onoff) {
  //Check if the onoff is selected

  if (onoff) {
    unsigned long currentTime = millis();
    char buff[BUFF_SIZE];
    if (currentTime - _Laststringflash >= DEFAULT_FLASH) {
      _Laststringflash = currentTime;
      _Flashstringstate = !_Flashstringstate;

      if (_Flashstringstate) {
        lcd.setCursor(col, row);
        lcd.print(data);
      }
      else {
        lcd.setCursor(col, row);
        ltoa(data, buff, NUM_SIZE);
        for (int i = 0; i < strlen(data); i++) {
          lcd.print(" ");
        }
      }
    }
  }
  else {
    lcd.setCursor(col, row);
    lcd.print(data);
  }

}

void SmartDisplay::Flash(uint8_t col, uint8_t row, long data) {



  unsigned long currentTime = millis();
  char buf[BUFF_SIZE];
  if (currentTime - _Laststringflash >= DEFAULT_FLASH) {
    _Laststringflash = currentTime;
    _Flashstringstate = !_Flashstringstate;

    if (_Flashstringstate) {
      lcd.setCursor(col, row);
      lcd.print(data);
    }
    else {
      lcd.setCursor(col, row);
      ltoa(data, buf, NUM_SIZE);
      for (int i = 0; i < strlen(data); i++) {
        lcd.print(" ");
      }
    }
  }
}




// ================================= FLASH LONG STOP ================================= //


// ================================= FLASH UNSIGNED LONG START ================================= //

void SmartDisplay::Flash(uint8_t col, uint8_t row, unsigned long data, bool onoff, unsigned long delay) {
  //Check if the onoff is selected

  if (onoff) {
    unsigned long currentTime = millis();
    char buff[BUFF_SIZE];
    if (currentTime - _Laststringflash >= delay) {
      _Laststringflash = currentTime;
      _Flashstringstate = !_Flashstringstate;

      if (_Flashstringstate) {
        lcd.setCursor(col, row);
        lcd.print(data);
      }
      else {
        lcd.setCursor(col, row);
        ltoa(data, buff, NUM_SIZE);
        for (int i = 0; i < strlen(data); i++) {
          lcd.print(" ");
        }
      }
    }
  }
  else {
    lcd.setCursor(col, row);
    lcd.print(data);
  }

}


void SmartDisplay::Flash(uint8_t col, uint8_t row, unsigned long data, unsigned long delay) {

  unsigned long currentTime = millis();
  char buff[BUFF_SIZE];
  if (currentTime - _Laststringflash >= delay) {
    _Laststringflash = currentTime;
    _Flashstringstate = !_Flashstringstate;

    if (_Flashstringstate) {
      lcd.setCursor(col, row);
      lcd.print(data);
    }
    else {
      lcd.setCursor(col, row);
      ltoa(data, buff, NUM_SIZE);
      for (int i = 0; i < strlen(data); i++) {
        lcd.print(" ");
      }
    }
  }

}

void SmartDisplay::Flash(uint8_t col, uint8_t row, unsigned long data, bool onoff) {
  //Check if the onoff is selected

  if (onoff) {
    unsigned long currentTime = millis();
    char buff[BUFF_SIZE];
    if (currentTime - _Laststringflash >= delay) {
      _Laststringflash = currentTime;
      _Flashstringstate = !_Flashstringstate;

      if (_Flashstringstate) {
        lcd.setCursor(col, row);
        lcd.print(data);
      }
      else {
        lcd.setCursor(col, row);
        ltoa(data, buff, NUM_SIZE);
        for (int i = 0; i < strlen(data); i++) {
          lcd.print(" ");
        }
      }
    }
  }
  else {
    lcd.setCursor(col, row);
    lcd.print(data);
  }

}

void SmartDisplay::Flash(uint8_t col, uint8_t row, unsigned long data) {
  unsigned long currentTime = millis();
  char buff[BUFF_SIZE];
  if (currentTime - _Laststringflash >= delay) {
    _Laststringflash = currentTime;
    _Flashstringstate = !_Flashstringstate;

    if (_Flashstringstate) {
      lcd.setCursor(col, row);
      lcd.print(data);
    }
    else {
      lcd.setCursor(col, row);
      ltoa(data, buff, NUM_SIZE);
      for (int i = 0; i < strlen(data); i++) {
        lcd.print(" ");
      }
    }
  }
}

// ================================= FLASH UNSIGNED LONG STOP ================================= //


// ================================= FLASH FLOAT START ================================= //

void SmartDisplay::Flash(uint8_t col, uint8_t row, float data, bool onoff, unsigned long delay) {
  //Check if the onoff is selected

  if (onoff) {
    unsigned long currentTime = millis();
    char buff[BUFF_SIZE];
    if (currentTime - _Laststringflash >= delay) {
      _Laststringflash = currentTime;
      _Flashstringstate = !_Flashstringstate;

      if (_Flashstringstate) {
        lcd.setCursor(col, row);
        lcd.print(data);
      }
      else {
        lcd.setCursor(col, row);
        ftoa(data, buff, NUM_SIZE);
        for (int i = 0; i < strlen(buff); i++) {
          lcd.print(" ");
        }
      }
    }
  }
  else {
    lcd.setCursor(col, row);
    lcd.print(data);
  }

}

void SmartDisplay::Flash(uint8_t col, uint8_t row, float data, unsigned long delay) {

  unsigned long currentTime = millis();
  char buff[BUFF_SIZE];
  if (currentTime - _Laststringflash >= delay) {
    _Laststringflash = currentTime;
    _Flashstringstate = !_Flashstringstate;

    if (_Flashstringstate) {
      lcd.setCursor(col, row);
      lcd.print(data);
    }
    else {
      lcd.setCursor(col, row);
      ftoa(data, buff, NUM_SIZE);
      for (int i = 0; i < strlen(buff); i++) {
        lcd.print(" ");
      }
    }
  }

}

void SmartDisplay::Flash(uint8_t col, uint8_t row, float data, bool onoff) {
  //Check if the onoff is selected

  if (onoff) {
    unsigned long currentTime = millis();
    char buff[BUFF_SIZE];
    if (currentTime - _Laststringflash >= DEFAULT_FLASH) {
      _Laststringflash = currentTime;
      _Flashstringstate = !_Flashstringstate;

      if (_Flashstringstate) {
        lcd.setCursor(col, row);
        lcd.print(data);
      }
      else {
        lcd.setCursor(col, row);
        ftoa(data, buff, NUM_SIZE);
        for (int i = 0; i < strlen(buff); i++) {
          lcd.print(" ");
        }
      }
    }
  }
  else {
    lcd.setCursor(col, row);
    lcd.print(data);
  }

}

void SmartDisplay::Flash(uint8_t col, uint8_t row, float data) {
  //Check if the onoff is selected
  char buf[BUFF_SIZE];
  unsigned long currentTime = millis();

  if (currentTime - _Laststringflash >= DEFAULT_FLASH) {
    _Laststringflash = currentTime;
    _Flashstringstate = !_Flashstringstate;

    if (_Flashstringstate) {
      lcd.setCursor(col, row);
      lcd.print(data);
    }
    else {
      lcd.setCursor(col, row);
      ftoa(data, buf, NUM_SIZE);
      for (int i = 0; i < strlen(buf); i++) {
        lcd.print(" ");
      }
    }
  }


}

// ================================= FLASH FLOAT STOP ================================= //

// ================================= FLASH INT START ================================= //

void SmartDisplay::Flash(uint8_t col, uint8_t row, int data, bool onoff, unsigned long delay) {
  //Check if the onoff is selected

  if (onoff) {
    unsigned long currentTime = millis();
    char buff[BUFF_SIZE];
    if (currentTime - _Laststringflash >= delay) {
      _Laststringflash = currentTime;
      _Flashstringstate = !_Flashstringstate;

      if (_Flashstringstate) {
        lcd.setCursor(col, row);
        lcd.print(data);
      }
      else {
        lcd.setCursor(col, row);
        intToStr(data, buff, NUM_SIZE);
        for (int i = 0; i < strlen(buff); i++) {
          lcd.print(" ");
        }
      }
    }
  }
  else {
    lcd.setCursor(col, row);
    lcd.print(data);
  }

}

void SmartDisplay::Flash(uint8_t col, uint8_t row, int data, unsigned long delay) {

  unsigned long currentTime = millis();
  char buff[BUFF_SIZE];
  if (currentTime - _Laststringflash >= delay) {
    _Laststringflash = currentTime;
    _Flashstringstate = !_Flashstringstate;

    if (_Flashstringstate) {
      lcd.setCursor(col, row);
      lcd.print(data);
    }
    else {
      lcd.setCursor(col, row);
      intToStr(data, buff, NUM_SIZE);
      for (int i = 0; i < strlen(buff); i++) {
        lcd.print(" ");
      }
    }
  }

}

void SmartDisplay::Flash(uint8_t col, uint8_t row, int data, bool onoff) {
  //Check if the onoff is selected

  if (onoff) {
    unsigned long currentTime = millis();
    char buff[BUFF_SIZE];
    if (currentTime - _Laststringflash >= DEFAULT_FLASH) {
      _Laststringflash = currentTime;
      _Flashstringstate = !_Flashstringstate;

      if (_Flashstringstate) {
        lcd.setCursor(col, row);
        lcd.print(data);
      }
      else {
        lcd.setCursor(col, row);
        intToStr(data, buff, NUM_SIZE);
        for (int i = 0; i < strlen(buff); i++) {
          lcd.print(" ");
        }
      }
    }
  }
  else {
    lcd.setCursor(col, row);
    lcd.print(data);
  }

}

void SmartDisplay::Flash(uint8_t col, uint8_t row, int data) {
  char buff[BUFF_SIZE];
  unsigned long currentTime = millis();

  if (currentTime - _Laststringflash >= DEFAULT_FLASH) {
    _Laststringflash = currentTime;
    _Flashstringstate = !_Flashstringstate;

    if (_Flashstringstate) {
      lcd.setCursor(col, row);
      lcd.print(data);
    }
    else {
      lcd.setCursor(col, row);
      intToStr(data, buff, NUM_SIZE);
      for (int i = 0; i < strlen(buff); i++) {
        lcd.print(" ");
      }
    }
  }
}

// ================================= FLASH INT STOP ================================= //

// ================================= FLASH LOGO START ================================= //

void SmartDisplay::FlashLogo(uint8_t col, uint8_t row, byte logo, bool onoff, unsigned long delay) {
  //Check If Its set To On/Off

  if (onoff) {
    unsigned long currentTime = millis();

    if (currentTime - _Lastlogoflash >= delay) {
      _Lastlogoflash = currentTime;
      _Flashlogostate = !_Flashlogostate;

      if (_Flashlogostate) {
        lcd.setCursor(col, row);
        lcd.write((byte)logo);
      }
      else {
        lcd.setCursor(col, row);
        lcd.print(" ");
      }
    }
  }
  else {
    lcd.setCursor(col, row);
    lcd.write((byte)logo);
  }
}

void SmartDisplay::FlashLogo(uint8_t col, uint8_t row, byte logo, unsigned long delay) {

  unsigned long currentTime = millis();

  if (currentTime - _Lastlogoflash >= delay) {
    _Lastlogoflash = currentTime;
    _Flashlogostate = !_Flashlogostate;

    if (_Flashlogostate) {
      lcd.setCursor(col, row);
      lcd.write((byte)logo);
    }
    else {
      lcd.setCursor(col, row);
      lcd.print(" ");
    }
  }

}


void SmartDisplay::FlashLogo(uint8_t col, uint8_t row, byte logo, bool onoff) {
  //Check If Its set To On/Off

  if (onoff) {
    unsigned long currentTime = millis();

    if (currentTime - _Lastlogoflash >= DEFAULT_FLASH) {
      _Lastlogoflash = currentTime;
      _Flashlogostate = !_Flashlogostate;

      if (_Flashlogostate) {
        lcd.setCursor(col, row);
        lcd.write((byte)logo);
      }
      else {
        lcd.setCursor(col, row);
        lcd.print(" ");
      }
    }
  }
  else {
    lcd.setCursor(col, row);
    lcd.write((byte)logo);
  }
}


void SmartDisplay::FlashLogo(uint8_t col, uint8_t row, byte logo) {

  unsigned long currentTime = millis();

  if (currentTime - _Lastlogoflash >= DEFAULT_FLASH) {
    _Lastlogoflash = currentTime;
    _Flashlogostate = !_Flashlogostate;

    if (_Flashlogostate) {
      lcd.setCursor(col, row);
      lcd.write((byte)logo);
    }
    else {
      lcd.setCursor(col, row);
      lcd.print(" ");
    }
  }

}

// ================================= FLASH LOGO STOP ================================= //

// ================================= FLASH LOGO DUAL START ================================= //

void SmartDisplay::FlashLogo(uint8_t col, uint8_t row, byte logoone, byte logotwo, bool onoff, unsigned long delay) {
  //Check If Its set To On/Off

  if (onoff) {
    unsigned long currentTime = millis();

    if (currentTime - _Lastlogoflash >= delay) {
      _Lastlogoflash = currentTime;
      _Flashlogostate = !_Flashlogostate;

      if (_Flashlogostate) {
        lcd.setCursor(col, row);
        lcd.write((byte)logoone);
		lcd.setCursor(col+1,row);
		lcd.write((byte)logotwo);
      }
      else {
        lcd.setCursor(col, row);
        lcd.print(" ");
		lcd.setCursor(col+1,row);
		lcd.print(" ");
      }
    }
  }
  else {
    lcd.setCursor(col, row);
    lcd.write((byte)logoone);
	lcd.setCursor(col+1,row);
	lcd.write((byte)logotwo);
  }
}

void SmartDisplay::FlashLogo(uint8_t col, uint8_t row, byte logo, unsigned long delay) {

  unsigned long currentTime = millis();

  if (currentTime - _Lastlogoflash >= delay) {
    _Lastlogoflash = currentTime;
    _Flashlogostate = !_Flashlogostate;

    if (_Flashlogostate) {
		lcd.setCursor(col, row);
		lcd.write((byte)logoone);
		lcd.setCursor(col+1,row);
		lcd.write((byte)logotwo);
    }
    else {
      lcd.setCursor(col, row);
      lcd.print(" ");
	  lcd.setCursor(col+1,row);
	  lcd.print(" ");
    }
  }

}


void SmartDisplay::FlashLogo(uint8_t col, uint8_t row, byte logo, bool onoff) {
  //Check If Its set To On/Off

  if (onoff) {
    unsigned long currentTime = millis();

    if (currentTime - _Lastlogoflash >= DEFAULT_FLASH) {
      _Lastlogoflash = currentTime;
      _Flashlogostate = !_Flashlogostate;

      if (_Flashlogostate) {
        lcd.setCursor(col, row);
        lcd.write((byte)logoone);
		lcd.setCursor(col+1,row);
		lcd.write((byte)logotwo)
      }
      else {
        lcd.setCursor(col, row);
        lcd.print(" ");
		lcd.setCursor(col+1,row);
		lcd.print(" ");
      }
    }
  }
  else {
    lcd.setCursor(col, row);
    lcd.write((byte)logoone);
	lcd.setCursor(col+1,row);
	lcd.write((byte)logotwo);
  }
}


void SmartDisplay::FlashLogo(uint8_t col, uint8_t row, byte logo) {

  unsigned long currentTime = millis();

  if (currentTime - _Lastlogoflash >= DEFAULT_FLASH) {
    _Lastlogoflash = currentTime;
    _Flashlogostate = !_Flashlogostate;

    if (_Flashlogostate) {
      lcd.setCursor(col, row);
      lcd.write((byte)logoone);
	  lcd.setCursor(col+1,row);
	  lcd.write((byte)logotwo);
    }
    else {
      lcd.setCursor(col, row);
      lcd.print(" ");
	  lcd.setCursor(col+1,row);
	  lcd.print(" ");
    }
  }

}

// ================================= FLASH LOGO STOP ================================= //

// ================================= ALTERNATE TEXT START ================================= //

void SmartDisplay::Alt(uint8_t col, uint8_t row, char* one, char* two, unsigned long delay) {
  //Start The Timer

  unsigned long currentTime = millis();

  if (currentTime - _Lastaltstr >= delay) {
    _Lastaltstr = currentTime;
    _Altstrstate = !_Altstrstate;

    if (_Altstrstate) {
      lcd.setCursor(col, row);
      lcd.print(one);
    }
    else {
      lcd.setCursor(col, row);
      lcd.print(two);
    }
  }
}

void SmartDisplay::Alt(uint8_t col, uint8_t row, char* one, char* two) {
  //Start The Timer

  unsigned long currentTime = millis();

  if (currentTime - _Lastaltstr >= DEFAULT_ALTERNATE) {
    _Lastaltstr = currentTime;
    _Altstrstate = !_Altstrstate;

    if (_Altstrstate) {
      lcd.setCursor(col, row);
      lcd.print(one);
    }
    else {
      lcd.setCursor(col, row);
      lcd.print(two);
    }
  }
}

// ================================= ALTERNATE TEXT STOP ================================= //


// ================================= ALTERNATE LONG START ================================= //

//One: Char Two: Long
void SmartDisplay::Alt(uint8_t col, uint8_t row, char* one, long two, unsigned long delay) {
  //Start The Timer

  unsigned long currentTime = millis();

  if (currentTime - _Lastaltstr >= delay) {
    _Lastaltstr = currentTime;
    _Altstrstate = !_Altstrstate;

    if (_Altstrstate) {
      lcd.setCursor(col, row);
      lcd.print(one);
    }
    else {
      lcd.setCursor(col, row);
      lcd.print(two);
    }
  }
}

void SmartDisplay::Alt(uint8_t col, uint8_t row, char* one, long two) {
  //Start The Timer

  unsigned long currentTime = millis();

  if (currentTime - _Lastaltstr >= DEFAULT_ALTERNATE) {
    _Lastaltstr = currentTime;
    _Altstrstate = !_Altstrstate;

    if (_Altstrstate) {
      lcd.setCursor(col, row);
      lcd.print(one);
    }
    else {
      lcd.setCursor(col, row);
      lcd.print(two);
    }
  }
}


//One: Long Two: Char
void SmartDisplay::Alt(uint8_t col, uint8_t row, long one, char* two, unsigned long delay) {
  //Start The Timer

  unsigned long currentTime = millis();

  if (currentTime - _Lastaltstr >= delay) {
    _Lastaltstr = currentTime;
    _Altstrstate = !_Altstrstate;

    if (_Altstrstate) {
      lcd.setCursor(col, row);
      lcd.print(one);
    }
    else {
      lcd.setCursor(col, row);
      lcd.print(two);
    }
  }
}

void SmartDisplay::Alt(uint8_t col, uint8_t row, long one, char* two) {
  //Start The Timer

  unsigned long currentTime = millis();

  if (currentTime - _Lastaltstr >= DEFAULT_ALTERNATE) {
    _Lastaltstr = currentTime;
    _Altstrstate = !_Altstrstate;

    if (_Altstrstate) {
      lcd.setCursor(col, row);
      lcd.print(one);
    }
    else {
      lcd.setCursor(col, row);
      lcd.print(two);
    }
  }
}

// ================================= ALTERNATE LONG STOP ================================= //

// ================================= ALTERNATE UNSIGNED LONG START ================================= //

//One: Char Two: unsigned Long
void SmartDisplay::Alt(uint8_t col, uint8_t row, char* one, unsigned long  two, unsigned long delay) {
  //Start The Timer

  unsigned long currentTime = millis();

  if (currentTime - _Lastaltstr >= delay) {
    _Lastaltstr = currentTime;
    _Altstrstate = !_Altstrstate;

    if (_Altstrstate) {
      lcd.setCursor(col, row);
      lcd.print(one);
    }
    else {
      lcd.setCursor(col, row);
      lcd.print(two);
    }
  }
}

void SmartDisplay::Alt(uint8_t col, uint8_t row, char* one, unsigned long two) {
  //Start The Timer

  unsigned long currentTime = millis();

  if (currentTime - _Lastaltstr >= DEFAULT_ALTERNATE) {
    _Lastaltstr = currentTime;
    _Altstrstate = !_Altstrstate;

    if (_Altstrstate) {
      lcd.setCursor(col, row);
      lcd.print(one);
    }
    else {
      lcd.setCursor(col, row);
      lcd.print(two);
    }
  }
}

//One: unsigned long Two: char

void SmartDisplay::Alt(uint8_t col, uint8_t row, unsigned long one, char* two, unsigned long delay) {
  //Start The Timer

  unsigned long currentTime = millis();

  if (currentTime - _Lastaltstr >= delay) {
    _Lastaltstr = currentTime;
    _Altstrstate = !_Altstrstate;

    if (_Altstrstate) {
      lcd.setCursor(col, row);
      lcd.print(one);
    }
    else {
      lcd.setCursor(col, row);
      lcd.print(two);
    }
  }
}

void SmartDisplay::Alt(uint8_t col, uint8_t row, unsigned long one, char* two) {
  //Start The Timer

  unsigned long currentTime = millis();

  if (currentTime - _Lastaltstr >= DEFAULT_ALTERNATE) {
    _Lastaltstr = currentTime;
    _Altstrstate = !_Altstrstate;

    if (_Altstrstate) {
      lcd.setCursor(col, row);
      lcd.print(one);
    }
    else {
      lcd.setCursor(col, row);
      lcd.print(two);
    }
  }
}

// ================================= ALTERNATE UNSIGNED LONG STOP ================================= //


// ================================= ALTERNATE FLOAT START ================================= //

//One: char	Two: Float
void SmartDisplay::Alt(uint8_t col, uint8_t row, char* one, float two, unsigned long delay) {
  //Start The Timer

  unsigned long currentTime = millis();

  if (currentTime - _Lastaltstr >= delay) {
    _Lastaltstr = currentTime;
    _Altstrstate = !_Altstrstate;

    if (_Altstrstate) {
      lcd.setCursor(col, row);
      lcd.print(one);
    }
    else {
      lcd.setCursor(col, row);
      lcd.print(two);
    }
  }
}

void SmartDisplay::Alt(uint8_t col, uint8_t row, char* one, float two) {
  //Start The Timer

  unsigned long currentTime = millis();

  if (currentTime - _Lastaltstr >= DEFAULT_ALTERNATE) {
    _Lastaltstr = currentTime;
    _Altstrstate = !_Altstrstate;

    if (_Altstrstate) {
      lcd.setCursor(col, row);
      lcd.print(one);
    }
    else {
      lcd.setCursor(col, row);
      lcd.print(two);
    }
  }
}

//One: float Two: char

void SmartDisplay::Alt(uint8_t col, uint8_t row, float one, char* two, unsigned long delay) {
  //Start The Timer

  unsigned long currentTime = millis();

  if (currentTime - _Lastaltstr >= delay) {
    _Lastaltstr = currentTime;
    _Altstrstate = !_Altstrstate;

    if (_Altstrstate) {
      lcd.setCursor(col, row);
      lcd.print(one);
    }
    else {
      lcd.setCursor(col, row);
      lcd.print(two);
    }
  }
}

void SmartDisplay::Alt(uint8_t col, uint8_t row, float one, char* two) {
  //Start The Timer

  unsigned long currentTime = millis();

  if (currentTime - _Lastaltstr >= DEFAULT_ALTERNATE) {
    _Lastaltstr = currentTime;
    _Altstrstate = !_Altstrstate;

    if (_Altstrstate) {
      lcd.setCursor(col, row);
      lcd.print(one);
    }
    else {
      lcd.setCursor(col, row);
      lcd.print(two);
    }
  }
}



// ================================= ALTERNATE FLOAT STOP ================================= //

// ================================= ALTERNATE INT START ================================= //

//One: char Two: int
void SmartDisplay::Alt(uint8_t col, uint8_t row, char* one, int two, unsigned long delay) {
  //Start The Timer

  unsigned long currentTime = millis();

  if (currentTime - _Lastaltstr >= delay) {
    _Lastaltstr = currentTime;
    _Altstrstate = !_Altstrstate;

    if (_Altstrstate) {
      lcd.setCursor(col, row);
      lcd.print(one);
    }
    else {
      lcd.setCursor(col, row);
      lcd.print(two);
    }
  }
}

void SmartDisplay::Alt(uint8_t col, uint8_t row, char* one, int two) {
  //Start The Timer

  unsigned long currentTime = millis();

  if (currentTime - _Lastaltstr >= DEFAULT_ALTERNATE) {
    _Lastaltstr = currentTime;
    _Altstrstate = !_Altstrstate;

    if (_Altstrstate) {
      lcd.setCursor(col, row);
      lcd.print(one);
    }
    else {
      lcd.setCursor(col, row);
      lcd.print(two);
    }
  }
}

//One: int Two: char
void SmartDisplay::Alt(uint8_t col, uint8_t row, int one, char* two, unsigned long delay) {
  //Start The Timer

  unsigned long currentTime = millis();

  if (currentTime - _Lastaltstr >= delay) {
    _Lastaltstr = currentTime;
    _Altstrstate = !_Altstrstate;

    if (_Altstrstate) {
      lcd.setCursor(col, row);
      lcd.print(one);
    }
    else {
      lcd.setCursor(col, row);
      lcd.print(two);
    }
  }
}

void SmartDisplay::Alt(uint8_t col, uint8_t row, int one, char* two) {
  //Start The Timer

  unsigned long currentTime = millis();

  if (currentTime - _Lastaltstr >= DEFAULT_ALTERNATE) {
    _Lastaltstr = currentTime;
    _Altstrstate = !_Altstrstate;

    if (_Altstrstate) {
      lcd.setCursor(col, row);
      lcd.print(one);
    }
    else {
      lcd.setCursor(col, row);
      lcd.print(two);
    }
  }
}

// ================================= ALTERNATE INT STOP ================================= //

// ================================= ALTERNATE LOGO START ================================= //

void SmartDisplay::AltLogo(uint8_t col, uint8_t row, byte one, byte two, unsigned long delay) {
  //Start The Timer

  unsigned long currentTime = millis();

  if (currentTime - _Lastaltlogo >= delay) {
    _Lastaltlogo = currentTime;
    _Altlogostate = !_Altlogostate;

    if (_Altlogostate) {
      lcd.setCursor(col, row);
      lcd.write((byte)one);
    }
    else {
      lcd.setCursor(col, row);
      lcd.write((byte)two);
    }
  }
}

void SmartDisplay::AltLogo(uint8_t col, uint8_t row, byte one, byte two) {
  //Start The Timer

  unsigned long currentTime = millis();

  if (currentTime - _Lastaltlogo >= DEFAULT_ALTERNATE) {
    _Lastaltlogo = currentTime;
    _Altlogostate = !_Altlogostate;

    if (_Altlogostate) {
      lcd.setCursor(col, row);
      lcd.write((byte)one);
    }
    else {
      lcd.setCursor(col, row);
      lcd.write((byte)two);
    }
  }
}

// ================================= ALTERNATE LOGO STOP ================================= //


// ================================= CLEAR ROW FUNCTION START ================================= //
void ClearRow(uint8_t nrow) {
  lcd.setCursor(0, nrow);
  for (uint8_t i = 0; i < 20; i++) {
    lcd.print(" ");
  }
}
// ================================= CLEAR ROW FUNCTION STOP ================================= //


// ================================= DISP WAIT FUNCTION START ================================= //

void DispWait(uint8_t col, uint8_t row, char* data, uint8_t count, uint16_t Delay) {
  lcd.setCursor(col, row);
  lcd.print(data);

  for (uint8_t i = 0; i <= count; i++) {
    lcd.print(".");
    delay(Delay);
  }
}

void DispWait(uint8_t col, uint8_t row, char* data, uint8_t count) {
  lcd.setCursor(col, row);
  lcd.print(data);

  for (uint8_t i = 0; i <= count; i++) {
    lcd.print(".");
    delay(DEFAULT_WAIT);
  }
}

// ================================= DISP WAIT FUNCTION STOP ================================= //

// ================================= DISP INTRO FUNCTION START ================================= //


void DispIntro(uint8_t col, uint8_t row, char* data, uint8_t wait) {
  lcd.setCursor(col, row);
  lcd.print(data);
  delay(wait);
  lcd.clear();
}

void DispIntro(uint8_t col, uint8_t row, char* data) {
  lcd.setCursor(col, row);
  lcd.print(data);
  delay(DEFAULT_WAIT);
  lcd.clear();
}

// ================================= DISP INTRO FUNCTION STOP ================================= //


// Converts a floating point number to string.
void ftoa(double n, char *res, int afterpoint) {
  // Extract integer part
  int ipart = (int)n;
  // Extract floating part
  double fpart = n - (float)ipart;
  // convert integer part to string
  int i = intToStr(ipart, res, 0);
  // check for display option after point
  if (afterpoint != 0)  {
    res[i] = '.';  // add dot
    // Get the value of fraction part upto given no.
    // of points after dot. The third parameter is needed
    // to handle cases like 233.007
    fpart = fpart * pow(10, afterpoint);
    intToStr((int)fpart, res + i + 1, afterpoint);
  }
}

// Converts a given integer x to string str[].  d is the number
// of digits required in output. If d is more than the number
// of digits in x, then 0s are added at the beginning.
int intToStr(int x, char str[], int d) {
  int i = 0;
  while (x) {
    str[i++] = (x % 10) + '0';
    x = x / 10;
  }
  // If number of digits required is more, then
  // add 0s at the beginning
  while (i < d)
    str[i++] = '0';

  rever(str, i);
  str[i] = '\0';
  return i;
}

void rever(char *str, int len) {
  int i = 0, j = len - 1, temp;
  while (i < j) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++; j--;
  }
}

