
/*
  LiquidCrystal Library - Hello World
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch prints "Hello World!" to the LCD
 and shows the time.
 
  The circuit:
 * LCD RS pin to digital pin 13
 * LCD Enable pin to digital pin 12
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 
 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

 // include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

#include <SoftwareSerial.h>
SoftwareSerial cell(7, 6); // RX, TX

long duration, inches, cm;

char df;
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

int sensorValue1 = 0;        // value read from the pot
int sensorValue2 = 0;        // value read from the pot
int sensorValue3 = 0;        // value read from the pot
int sensorValue4 = 0;        // value read from the pot


void setup() {
  // set up the LCD's number of columns and rows: 
  Serial.begin(9600); 
         
  pinMode (5,OUTPUT);//attach pin 2 to vcc
  pinMode (2,OUTPUT);//attach pin 2 to vcc
  cell.begin(9600);

digitalWrite(5,0);
digitalWrite(2,0);
lcd.begin(16,2);
lcd.print("Door Control       ");
}

long ll;
char lf;


void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  // print the number of seconds since reset:



 while (cell.available()) {
    // get the new byte:
    
    char inChar = (char)cell.read();
lcd.setCursor(15,0);
lcd.print(inChar);
    // add it to the inputString:
    
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == 'a') {   
       lcd.setCursor(0,1);
lcd.print("Door Open   ");
digitalWrite(2,1);
delay(2000);
digitalWrite(2,0);
     }


  if (inChar == 'b') {
    lcd.setCursor(0,1);
lcd.print("Door Close   ");
digitalWrite(2,1);
delay(2000);
digitalWrite(2,0);
     }

    if (inChar == 'c') {
            lcd.setCursor(0,1);
lcd.print("Door Open   ");
digitalWrite(2,1);
     }


  if (inChar == 'd') {
          lcd.setCursor(0,1);
lcd.print("Door Close   ");
digitalWrite(2,0);
     }




    
  }


 
 
 }

