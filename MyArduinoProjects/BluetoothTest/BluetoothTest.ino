#include <Servo.h>

Servo theServo;

int pos = 0;

int ledPin = 13;
int state = 0;
int flag = 0;

void setup() {
  // use led as output and set it to low when beginning
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);
  digitalWrite(8,HIGH);
  Serial.begin(9600);  

  // setup Servo
  theServo.attach(9);
}

void loop() {
  
  if(Serial.available() > 0) {
    state = (int)Serial.read();
    Serial.print("State: ");
    state = constrain(state, 5, 175);
    Serial.println(state);
    flag = 0;
  }

  theServo.write(state);
  
  if(state == '0') {
    digitalWrite(ledPin,LOW);
    if(flag == 0) {
      Serial.println("LED: off");
    }
  } else if(state == '1') {
    digitalWrite(ledPin,HIGH);
    if(flag == 0) {
      Serial.println("LED: on");
      flag = 1;
    }
  }
}

