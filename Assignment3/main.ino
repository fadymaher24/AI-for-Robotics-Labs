

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>
#include <RemoteXY.h>
#include <Servo.h>
#include <Keypad.h>

Servo myServo;
int servoPin = 38;
int servoPosition = 90; // Initialize servo position

const int numRows = 4;
const int numCols = 3;

char keys[numRows][numCols] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[numRows] = {31, 33, 35, 37};
byte colPins[numCols] = {39, 41, 43};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, numRows, numCols);

// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX 68
#define REMOTEXY_SERIAL_TX 69
#define REMOTEXY_SERIAL_SPEED 9600

// RemoteXY configurate 
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,1,0,0,0,33,0,16,200,1,4,0,23,29,18,54,2,26,129,0,
  10,3,41,6,17,83,101,114,118,111,32,80,111,115,105,116,105,111,110,0 };

struct {
  int8_t slider; 
  uint8_t connect_flag;  // =1 if wire connected, else =0 
} RemoteXY;
#pragma pack(pop)

void setup() {
  RemoteXY_Init();
  Serial.begin(9600);
  myServo.attach(servoPin);
  myServo.write(servoPosition);

  // TODO your setup code
}

void loop() {
  RemoteXY_Handler();

  // Check for keypad input
  char key = keypad.getKey();
  if (key != NO_KEY) {
    Serial.print("Key pressed: ");
    Serial.println(key);

    if (key == '1') {
      moveServo(20);
    } else if (key == '2') {
      moveServo(-20);
    }
  }

  // Debug statement for slider value
  Serial.print("Slider value: ");
  Serial.println(RemoteXY.slider);
  myServo.write(RemoteXY.slider*2);
}

void moveServo(int angleIncrement) {
  int newAngle = servoPosition + angleIncrement;

  if (newAngle >= 0 && newAngle <= 180) {
    myServo.write(newAngle);
    servoPosition = newAngle;
    Serial.print("Servo moved to: ");
    Serial.println(servoPosition);
  }
}


