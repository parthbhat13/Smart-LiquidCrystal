/*
   SmartDisplay Library --> Flash Logo Example

   Demostrates the use of Smart Display Librarie's , Logo Flashing.
   This library is tested and used with the LiquidCrystal Library from the arduino, it is necessary
   to import the liquidcrystal library for the Smart Display Library to work.
   The Smart Display Library can work with all the displays/Lcd supported by the LiquidCrystal library.

   The Sketch demostrates the use of FlashingText and shows some basic Functions and object decleration.

   The Circuit:
    # LCD RS Pin  --> D12
    # LCD EN Pin  --> D11
    # LCD D4 Pin  --> D5
    # LCD D5 Pin  --> D4
    # LCD D6 Pin  --> D3
    # LCD D7 Pin  --> D2
    # LCD RW Pin  --> GND
    # 10K Resistor: Ends to +5v And Ground
    # Wiper To LCD VO Pin

    Here is the function prototype

    FlashLogo(uint8_t col, uint8_t row, byte data, bool onoff, unsigned long delay);

    # uint8_t col           --> Set The Column On The Lcd.
    # uint8_t row           --> Set The Row On The Lcd.
    # byte data            --> Provide The Required Data, This will the Byte Of the Special Char You created
    # bool onoff            --> If set to True, The Text Flashes / If False it remains still. If Not Used, it flashes the test bydefault
    # unsigned long delay   --> Used to Set The Delay Between Flashes. If Left Blank The Default Delay Is Used.(1500)

    Author: Parth Yatin Temkar
    Date Of Creation: 24Th September 2018
*/

// Include The LiquidCrystal  Library First
#include <LiquidCrystal.h>
#include <SmartDisplay.h>

//Lcd Pinouts decleration
#define RS  12
#define EN  11
#define D4  5
#define D5  4
#define D6  3
#define D7  2

// Initialize The Lcd
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

//Create The Smart Library Object
//  Select The Mode
//  Mode 1 --> FlashText
//  Mode 2 --> FlashLogo
//  Mode 3 --> Alternate String Flashing
//  Mode 4 --> Alternate Logo Flashing

SmartDisplay GsmTowerAnt = SmartDisplay(2);    //Selected The Logo Flashing Mode
SmartDisplay GsmTowerSig = SmartDisplay(2);    //Selected The Logo Flashing Mode

//Create The Custom Character
byte SigChar[8] = {1, 1, 5, 5, 21, 21, 21, 21};
byte AntChar[8] = {31, 21, 21, 14, 4, 4, 4, 4};

void setup() {
  //Setup The LCD's number of rows and columns
  lcd.begin(16, 2);

  //Create The Character
  lcd.createChar(0, AntChar);
  lcd.createChar(1, SigChar);
}

void loop() {
  //Call The Function To Run
  //You can leave the true and delay if you want it to run in default mode

  //Show The Antena, You can even use lcd.write(); to show the custom char in non flashing 
  GsmTowerAnt.FlashLogo(0, 0, 0, false); //We Keep The Tower Static
  GsmTowerSig.FlashLogo(0, 0, 1, true, 100); //We Flash The Signal Char

  /* Put Your Code Down Here If Needed, Don't use delay, orelse it will 
   *  effect the Smart Display Library
   */
}
