# soundartslab_workshop_2025
repo for arduino and raspberry pi code for sound arts lab workshop 2025 Struer Denmark


# first things to do! 

download arduino program here for mac/windows/linux: 
https://www.arduino.cc/en/software/

Plug in USB Cable into Arduino slot 

1. open up arduino app
2. Tools -> Manage Libraries... search 'Adafruit Motor' and install library called, "Adafruit Motor Shield V2 Library"
3. open Arduino 
4. Port -> Board -> Arduino Uno 
5. Port -> something like "/dev/cu.usbmodem... " (NOT the /dev/cu.BLUETOOTH)



# Raspberry Pi setup 


<img src="./images/Rpi4_pinout.png" alt="Description" width="400"/></img>

1. connect GPIO 2 (SDA) to Adafruit shield pin labeled "SDA" 
2. connect GPIO 3 (SCL) to Adafruit shield pin labeled "SCL" 
3. connect GPIO 6 to Adafruit shield pin labeled 'GND' 
4. connect GPIO 4 (5V) to Adafruit shield pin labeled '5V' 

