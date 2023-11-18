# Control the Servo Angle using HC-05 Bluetooth module. 

Use the HC05 Bluetooth module to connect Arduino to the mobile phone. Then, send serial data from this app ranges from 0 to 180 which is to be received by the Arduino then sent to the SG-90 servo motor and moves to this desired angle based on the value sent from the mobile app via Bluetooth technology. 

Bonus: send the serial data from the keypad module along with the Bluetooth based app. 
Hint: keypad sends char data, you shall cast them to integer to be send to the servo.write function of the servo. 

