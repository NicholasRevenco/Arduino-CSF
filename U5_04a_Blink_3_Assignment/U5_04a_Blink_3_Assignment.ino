/*

*/

int goStop = 0;
int speed = 100;

void setup() {
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();
    if (c == ' ') {
      goStop++;
      if (goStop % 2 == 0){
        Serial.println("Lights turned on.");
      } else {
        Serial.println("Lights turned off.");
      }
    } else if (c == '0') {
        speed = 1000;
        Serial.println("Speed set to: 1000.");
    } else if (c == '1') {
        speed = 900;
        Serial.println("Speed set to: 900.");
    } else if (c == '2') {
        speed = 800;
        Serial.println("Speed set to: 800.");
    } else if (c == '3') {
        speed = 700;
        Serial.println("Speed set to: 700.");
    } else if (c == '4') {
        speed = 600;
        Serial.println("Speed set to: 600.");
    } else if (c == '5') {
        speed = 500;
        Serial.println("Speed set to: 500.");
    } else if (c == '6') {
        speed = 400;
        Serial.println("Speed set to: 400.");
    } else if (c == '7') {
        speed = 300;
        Serial.println("Speed set to: 300.");
    } else if (c == '8') {
        speed = 200;
        Serial.println("Speed set to: 200.");
    } else if (c == '9') {
        speed = 100;
        Serial.println("Speed set to: 100.");
    } 
  }
  if (goStop % 2 == 0) {
    blinkWave(speed, 0, 0);
    blinkWave(speed, 0, 1);
  }
}


void blinkWave(int timeOn, int timeOff, int direction){
  if (direction == 0) {
    for (int i = 13; i > 9; i--) {
      digitalWrite(i, HIGH);
      delay(timeOn);
      digitalWrite(i, LOW);
      delay(timeOff);
    }
  } else {
    for (int i = 9; i < 13; i++) {
      digitalWrite(i, HIGH);
      delay(timeOn);
      digitalWrite(i, LOW);
      delay(timeOff);
    }
  }
}