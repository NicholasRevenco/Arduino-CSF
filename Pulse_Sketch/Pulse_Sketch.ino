/*

*/

/*const int PWN_PIN = 11;

void setup() {
  pinMode(PWN_PIN, OUTPUT);
}

int brightness = 0;
const int fadeAmount = 5;

void loop() {
  analogWrite(PWN_PIN, brightness);
  
  brightness = (brightness + fadeAmount) % 256;
  
  delay(50);
}*/

/*const int PWN_PIN = 11;

void setup() {
  pinMode(PWN_PIN, OUTPUT);
}

int brightness = 0;
const int fadeAmount = 5;

void loop() {
  
  for (int i = 0; i < 255; i = i+5) {
    brightness = (brightness + fadeAmount);
    analogWrite(PWN_PIN, brightness);
    delay(25);
  }
  for (int i = 0; i < 255; i = i+5) {
    brightness = (brightness - fadeAmount);
    analogWrite(PWN_PIN, brightness);
    delay(25);
  }
}*/

const int PWN_PIN = 11;
int amount = 5;

void setup() {
  pinMode(PWN_PIN, OUTPUT);
}

int brightness = 0;
const int fadeAmount = 5;

void loop() {
  analogWrite(PWN_PIN, brightness);
  if (brightness >= 255) {
    amount = -5;
  } else if (brightness <= 0) {
    amount = 5;
  }
  brightness = brightness + amount;
  delay(25);
}

