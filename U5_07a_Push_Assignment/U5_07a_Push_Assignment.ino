const int Pull_Up = 2;
const int Pull_Down = 4;
int brightness = 0;
int fadeAmount = 5;

const int LED1 = 13;
const int LED2 = 12;

void setup() {
  Serial.begin(9600);
  pinMode(Pull_Up, INPUT_PULLUP);
  pinMode(Pull_Down, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  int Button_State_Up = digitalRead(Pull_Up);
  int Button_State_Down = digitalRead(Pull_Down);
  
  Serial.println(Button_State_Up);
  Serial.println(Button_State_Down);

  if (Button_State_Up == 0) {
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }
  if (Button_State_Down == 1) {
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }
  delay(50);
}

void loop() {
  analogWrite(LED1, brightness);
  if (brightness >= 255) {
    amount = -5;
  } else if (brightness <= 0) {
    amount = 5;
  }
  delay(25);
}
