// THIS SKETCH DOESN'T WORK PROPERLY

const int switchPin = 8;
unsigned long previousTime = 0;

int switchState = 0;
int prevSwitchState =0;

int led = 2;

long interval = 1000;

void setup() {
  Serial.begin(9600);
  
  // loop through leds and set them up
  for(int x = 2; x < 8 ;x++) {
    pinMode(x,OUTPUT);
    char str[50];
    sprintf(str,"Led %i set up",x);
    Serial.println(str);
  }
  // set up the switch (tilt switch)
  pinMode(switchPin,INPUT);
}

void loop() {
  unsigned long currentTime = millis();

  if(currentTime - previousTime > interval) {
    previousTime = currentTime;

    digitalWrite(led,HIGH);
    led++;

    if(led == 7) {
        
    }
  } else {
    String firstPart = "Not yet time: cur(";
    String secondPart = ") previous(";
    String thirdPart = ") dif(";
    String fourthPart = ")";
    String str = firstPart+currentTime+secondPart+previousTime+thirdPart+(currentTime - previousTime)+fourthPart;
    Serial.println(str);  
  }

  switchState = digitalRead(switchPin);
  Serial.println(switchState);

  if(switchState != prevSwitchState) {
    //Serial.println("Hourglass is reset");
    for(int x = 2; x < 8;x++) {
      digitalWrite(x,LOW);
    }

    led = 2;
    previousTime = currentTime;
  }

  prevSwitchState = switchState;
  // delay to let the arduino think a bit
  delay(1000);
}
