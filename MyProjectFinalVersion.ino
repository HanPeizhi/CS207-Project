/*
 * Peizhi Han
 * CS207 Project
 *
 * The project was to make a wake-up machine, 
 * and the purpose of making this machine was 
 * because the traditional alarm clock was annoying, 
 * so our team used water to awake the user. 
 * Its name is water alarm clock. 
 *
 *
 * servo  1 
 * HDT    1 
 * lcd    6  
 * tone   1 
 * Potentiometer 0
 * RTC    2
 *
 * Total 11
 */


//#include "DHT.h"
#include "dht11.h" 
#include <LiquidCrystal.h>
#include <Wire.h>
#include "RTClib.h"
#include <Servo.h> 

//DHT
dht11 DHT11;
#define DHT11PIN 10


//Tone
#define NOTE_C4  262
#define melody NOTE_C4

//RTC
RTC_DS1307 RTC;
//LCD
LiquidCrystal lcd(12,11,5,4,3,2);  //Define the pin

//Time & Date
String time="Time: ";
String date="Date: ";
String sd, me, hr, dy, mh, yr;

//Tone
const int beep = 13;
// notes in the melody:
#define NOTE_C4  262
#define melody NOTE_C4

//Open water
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
int openWater = true;
int pos = 0;

void setup () { 
  Serial.begin(9600);
  //pinMode(13, OUTPUT); //tone

  myservo.attach(7);  // attaches the servo on pin 9 to the servo object
  myservo.write(90);

     // LCD
    lcd.begin(16,2); //Set the number of LCD displays. 16 X 2:16 grid 2 lines.
    //lcd.print("hello,Han!"); //Show hello, Han! On the LCD
    
    Wire.begin();
    RTC.begin();
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }


}

void loop () {
    int chk = DHT11.read(DHT11PIN);

    
    switch (chk){ // check the DHT work condition
      case DHTLIB_OK: 
                Serial.println("OK"); 
                break;
      case DHTLIB_ERROR_CHECKSUM: 
                Serial.println("Checksum e rror"); 
                break;
      case DHTLIB_ERROR_TIMEOUT: 
                Serial.println("Time out error"); 
                break;
      default: 
                Serial.println("Unknown error"); 
                break;
    }

    
    Serial.print("Temperature (oC): ");
    Serial.println((float)DHT11.temperature, 1);

    
    DateTime now = RTC.now(); //get the time

    // print out the time
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println(); 
    delay(1000);
    

    // Fix the zero string in LCD
    if(now.second() < 10) sd = "0";
    else sd ="";
    if(now.minute() < 10) me = "0";
    else me ="";
    if(now.hour() < 10) hr = "0";
    else hr ="";

    if(now.day() < 10) dy = "0";
    else dy ="";
    if(now.month() < 10) mh = "0";
    else mh ="";
    if(now.year() < 10) yr = "0";
    else yr ="";

    // Set the flashing cursor to column 0, line 1 (Note: counting from 0, 
    // line 0 shows the first line and line 1 shows the second line.)
    //lcd.setCursor(0,0); //lcd.print(time + hr + now.hour() + ":" + me +  now.minute() + ":" + sd + now.second());  
    //After power on, the screen shows the time
    lcd.setCursor(0,0);        
    lcd.print(date + yr + now.year() + "/" + mh + now.month() + "/" + dy + now.day());  //After power on, the screen shows the time
    lcd.setCursor(0,1);
    lcd.print(hr + now.hour() + ":" + me +  now.minute() + ":" + sd + now.second() + " " + DHT11.temperature + "C " + DHT11.humidity +"%");
    
    if(now.hour() == 6 && openWater){ // set hour here it is 6am
      if(now.minute() == 0){          // set one minute for working
        tone(beep, melody);
      }
      else{
        noTone(beep);
      }
      
      if ((now.minute() == 1 ) ){     // after one minute release the cup
        Serial.println("Open water NOW!"); 
        for(pos = 90; pos>=1; pos-=1){     // goes from 90 degrees to 0 degrees 
          myservo.write(pos);              // tell servo to go to position in variable 'pos' 
          delay(15);                       // waits 15ms for the servo to reach the position 
         }
         myservo.write(90); 
         openWater = false;
      }
    }
    else if (now.hour() == 6){
      openWater = true;
    }
    
    
}
