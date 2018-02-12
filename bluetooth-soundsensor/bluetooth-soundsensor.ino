int volume;

void setup() {
  Serial.begin(9600);
}

void loop()
{
  Serial.flush();
  volume = analogRead(A0);
  Serial.println(volume);
  delay(500);
}
