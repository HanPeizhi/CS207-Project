# My Project: Wake-up Machine
This is my arduino uno and some modules related to a project.

[YouTube](https://www.youtube.com/watch?v=ZoMZ0CTlgw8)

</br>
</br>
The project was to make a wake-up machine, and the purpose of making this machine was because the traditional alarm clock was annoying, so our team used water to awake the user. Its name is water alarm clock. 
</br>
</br>
![Alt text](https://github.com/HanPeizhi/CS207-Project/blob/master/pictures/project.jpg)

Repository Contents:
============
Here I provide a map of all thr top-level contents:
- /ProjectWriteup - project paper/write-up
- /codeLib - Any libraries that are needed to build your software for you device 
- /example - Example files that can be run on your hardware
- /other - Proposal and useless somethings
- /picture - This is where the image files for this readme are! Yay! Yay! hah
- /LICENCE - The license file.
- /hardware - All the design files 
- /README.de - The file you're reading now! xD





The first step: Prepare materials
============
Materials Required List:
- 1 x Arduino UNO
- 1 x Bread-board
- 1 x Servo
- 1 x Cup and water
- 1 x TRC (Clock module) 
- 1 x Piezo buzzer
- 1 x LED Strip
- 2 x Potentiometers
- as much wires as your need


The second step: set up the board
============
The circuit diagram is as follows：
![Alt text](https://github.com/HanPeizhi/CS207-Project/blob/master/pictures/ApendixA.JPG)
</br>


The third step: download the libraries
============
Download the libraries from:
</br>
https://github.com/HanPeizhi/CS207-Project/tree/master/code
</br>
</br>
There are two folders:
- Dht11
- RTC
</br>
Download these two whole folders, and add under your path: ..\Arduino\libraries
</br>


The fourth step: download the example code
============
The Complete demo code can download from here:
</br>
https://github.com/HanPeizhi/CS207-Project/tree/master/example
</br>
Then Upload to you arduino.
</br>


The fifth step: fix the servo and cup
============
I gripped the servo with an iron clip and then nailed the iron shelf to the wall with a spike:
</br>
![Alt text](https://github.com/HanPeizhi/CS207-Project/blob/master/pictures/fixed%20servo.jpg)
</br>
</br>
I used a nail to pocke a hole in the bottom edge of the paper cup. Then we nailed two tacks on the wall.
</br>
![Alt text](https://github.com/HanPeizhi/CS207-Project/blob/master/pictures/fixed%20cup.jpg)
</br>
</br>
Here I put the servo on the edge of the mouth of the paper cup, so the servo can jam and release the paper cup when the servo turns:
</br>
![Alt text](https://github.com/HanPeizhi/CS207-Project/blob/master/pictures/fixed%20cup%26servo.jpg)
</br>

The sixth step: Complete project map
===========
I fixed the Arduino on the wall with just a few studs:
</br>
![Alt text](https://github.com/HanPeizhi/CS207-Project/blob/master/pictures/fixed%20UNO.jpg)
I simply glued the breadboard can stick the breadboard on the wall. 
</br>
If you do not like sticky glue on the wall, we also use tacks to support the breadboard on the wall:
</br>
![Alt text](https://github.com/HanPeizhi/CS207-Project/blob/master/pictures/fixed%20e-watch.jpg)

Team
===========
The build team consist of:
- Peizhi Han -- I did everything. </br>


### Link for existing projects
<p>
  1. https://create.arduino.cc/projecthub/mitov/fanduino-cool-automatic-arduino-fan-75e9f2
  </br>
  2. https://www.adafruit.com/product/3216
  </br>
  3. https://learn.adafruit.com/tri-layer-mini-round-robot-chassis-kit/assemble-the-chassis?view=all
</P>

### Link for library
<p>
  1. DHT11: https://github.com/adafruit/DHT-sensor-library
  </br>
            https://github.com/nicolsc/arduino-libs/tree/master/DHT11
            </br>
  2. RTC: https://github.com/adafruit/RTClib
  </br>
          https://www.elecrow.com/wiki/index.php?title=File:RTC.zip
  </br>
  3. Adafruit_Sensor(DHT11 lib needed): https://github.com/adafruit/Adafruit_Sensor
  
</p>

### Link for cites
<p>
  1. LCD: https://www.arduino.cc/en/Tutorial/HelloWorld?from=Tutorial.LiquidCrystal
  </br>
  2. RTC: https://www.elecrow.com/wiki/index.php?title=Tiny_RTC
  </br>
  3. HDT11: https://playground.arduino.cc/Main/DHT11Lib
</>
