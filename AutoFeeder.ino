#include <Servo.h>

#define FEED_INTERVAL 10   // hours between feeding time

const byte servoPin = 9;      // pin used to command the servo motor

Servo servo;

unsigned long previousMillis=0;

const long interval = FEED_INTERVAL * 3600000; //hours * milliseconds formula
//const long interval = FEED_INTERVAL * 1000; // seconds * ms formula to test feeding mechanism
/**
   stop the food from flowing
*/
void feederClose() {
  servo.write(180);
  delay(175);
  servo.write(90);
}

/**
   release a ration of food
*/
void feederOpen() {
  servo.write(0);
  delay(175);
  servo.write(90);
}



void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  Serial.println("System initialized");
}

void loop() {
  unsigned long currentMillis = millis();
  Serial.println(currentMillis - previousMillis);
  if(currentMillis - previousMillis >= interval)
  {
    previousMillis=currentMillis;
    
    Serial.println("Feeding the pet :)");
    feederOpen();
    delay(150);
    feederClose();
  }
}
