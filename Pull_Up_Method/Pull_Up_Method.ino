/*

*/

const int BUTTON = 3;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(BUTTON);
  
  Serial.println(buttonState);
  delay(50);
}
