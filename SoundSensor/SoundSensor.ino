/*
  This is the code to make a LED blink with sound.
  You have to set the threshold so it' sensible enough to make the led blink.
  
  You connect an LED to PIN13 and the Sound Sensor to Analog Pin 0
 */
 
int led1 = 10;
int led2 = 9;
int led3 = 8;

int volume;
 
void setup() {       
  Serial.begin(9600); // For debugging
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}
 
void loop() {
  
  volume = analogRead(A3); // Reads the value from the Analog PIN A0
  
  //Debug mode
  Serial.println(volume);
  delay(100);
  
  digitalWrite(led1, (volume >= 20) ? HIGH : LOW);
  digitalWrite(led2, (volume >= 25) ? HIGH : LOW);
  digitalWrite(led3, (volume >= 30) ? HIGH : LOW);
  
}
