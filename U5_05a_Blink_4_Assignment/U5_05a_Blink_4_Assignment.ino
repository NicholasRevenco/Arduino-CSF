/*

*/

const int NUMLEDS = 5;
const int LEDPINS[] = { 12, 10, 5, 4, 3 };

int goStop = 0;
int speed = 100;
int c  = 9;

void setup() {
  Serial.begin(9600);
  for (int a = 0; a < NUMLEDS; a++) {
    pinMode(LEDPINS[a], OUTPUT);
  }
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
    for (int i = 0; i < NUMLEDS-1; i++) {
      digitalWrite(LEDPINS[i], HIGH);
      delay(timeOn);
      digitalWrite(LEDPINS[i], LOW);
      delay(timeOff);
    }
  } else {
    for (int i = NUMLEDS-1; i > 0; i--) {
      digitalWrite(LEDPINS[i], HIGH);
      delay(timeOn);
      digitalWrite(LEDPINS[i], LOW);
      delay(timeOff);
    }
  }
}

