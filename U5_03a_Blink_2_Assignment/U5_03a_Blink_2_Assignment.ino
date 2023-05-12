
/*
Part 1:
  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  delay(250);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(250);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  delay(250);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  delay(250);
  digitalWrite(9, LOW);

Part 2 Below:
*/

void setup() {
  Serial.begin(9600);
}

void blinkWave(int timeOn, int timeOff)
{
  digitalWrite(13, HIGH);
  delay(timeOn);
  digitalWrite(13, LOW);
  delay(timeOff);
  digitalWrite(12, HIGH);
  delay(timeOn);
  digitalWrite(12, LOW);
  delay(timeOff);
  digitalWrite(11, HIGH);
  delay(timeOn);
  digitalWrite(11, LOW);
  delay(timeOff);
  digitalWrite(10, HIGH);
  delay(timeOn);
  digitalWrite(10, LOW);
  delay(timeOff);
  digitalWrite(9, HIGH);
  delay(timeOn);
  digitalWrite(9, LOW);
  delay(timeOff);
}

void loop() {
  blinkWave(1000, 1000);
  blinkWave(100, 100);
  blinkWave(5000, 500);
}