/*

*/

const int BUTTON = 2;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT);
}

void loop() {
  int buttonState = digitalRead(BUTTON);
  
  Serial.println(buttonState);
  delay(50);
}
