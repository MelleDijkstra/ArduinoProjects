#define ledPin 5

char command;
String string;
boolean ledShining;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  
  analogWrite(ledPin, 0);
  ledShining = false;
}

void loop() {
  if(Serial.available() > 0) {
    string = "";
  }

  while(Serial.available() > 0) {
    command = ((byte) Serial.read());
    if(command == ':') {
      break;  
    } else {
      string += command;  
    }
    delay(1);
  }

  if(string == "TO") {
    ledOn();
    ledShining = true;
  }

  if((string.toInt() >= 0) && (string.toInt() <= 255)) {
    if(ledShining == true) {
      analogWrite(ledPin, string.toInt());
      Serial.println(string); // debug
      delay(10);  
    }  
  }
}

void ledOn() {
  analogWrite(ledPin, 255);
  delay(10);
}

void ledOff() {
  analogWrite(ledPin, 0);
  delay(10);
}
