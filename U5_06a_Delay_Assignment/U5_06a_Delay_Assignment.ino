/*const int LED = 13;

int ledState = LOW;

unsigned long previousTime = 0;

const int interval = 1000;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  unsigned long currentTime = millis();
  
  if (currentTime - previousTime >= interval) {
    previousTime = currentTime;
    
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    
    digitalWrite(LED, ledState);
  }
}*/

/*const int LED1 = 13;

int ledState1 = LOW;

unsigned long previousTime1 = 0;

const int timeOnInt1 = 1000;
const int timeOffInt1 = 1000;


void setup() {
  pinMode(LED1, OUTPUT);
}

void loop() {
  unsigned long currentTime1 = millis();
  
  if (ledState1 == HIGH && currentTime1 - previousTime1 >= timeOnInt1) {
    previousTime1 = currentTime1;
    ledState1 = LOW;
    digitalWrite(LED1, ledState1);
  } else if (ledState1 == LOW && currentTime1 - previousTime1 >= timeOffInt1) {
    previousTime1 = currentTime1;
    ledState1 = HIGH;
    digitalWrite(LED1, ledState1);
  }
}*/

/*const int LED1 = 13;
const int LED2 = 12;

int ledState1 = LOW;
int ledState2 = LOW;

unsigned long previousTime1 = 0;
unsigned long previousTime2 = 0;

const int timeOnInt1 = 1000;
const int timeOffInt1 = 500;
const int timeOnInt2 = 200;
const int timeOffInt2 = 200;


void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  unsigned long currentTime1 = millis();
  unsigned long currentTime2 = millis();
  
  if (ledState1 == HIGH && currentTime1 - previousTime1 >= timeOnInt1) {
    previousTime1 = currentTime1;
    ledState1 = LOW;
    digitalWrite(LED1, ledState1);
  } else if (ledState1 == LOW && currentTime1 - previousTime1 >= timeOffInt1) {
    previousTime1 = currentTime1;
    ledState1 = HIGH;
    digitalWrite(LED1, ledState1);
  }
  if (ledState2 == HIGH && currentTime2 - previousTime2 >= timeOnInt2) {
    previousTime2 = currentTime2;
    ledState2 = LOW;
    digitalWrite(LED2, ledState2);
  } else if (ledState2 == LOW && currentTime2 - previousTime2 >= timeOffInt2) {
    previousTime2 = currentTime2;
    ledState2 = HIGH;
    digitalWrite(LED2, ledState2);
  }
}*/

class LEDBlinker {
  public:
    LEDBlinker(int ledpin, int onInterval, int offInterval)
    {
      pin = ledpin;
      state = LOW;
      previousTime = 0;
      onInt = onInterval;
      offInt = offInterval;
      pinMode(pin, OUTPUT);
    }

    void stopBlink() 
    {
      blinking = false;
      pinMode(pin, LOW);
    }
    void startBlink()
    {
      blinking = true;
      pinMode(pin, HIGH);
    }

    // call to check if LED needs to turn on or off
    void update()
    {
      if (blinking == false) {
        return false;
        
      }
      unsigned long currentTime = millis();

      if ((state == HIGH) && (currentTime - previousTime >= onInt)) {
        // save the last time you blinked the LED
        previousTime = currentTime;
        state = LOW;

        // set the LED with the ledState of the variable:
        digitalWrite(pin, state);
      }
      else if ((state == LOW) && (currentTime - previousTime >= offInt)) {
        previousTime = currentTime;
        state = HIGH;

        // set the LED with the ledState of the variable:
        digitalWrite(pin, state);
      }
    }

  // state of object
  private:
    int pin;     // the pin of this LED
    int onInt;   // the time this LED should be on
    int offInt;  // the time this LED should be off
    int state;   // the state HIGH/LOW or the LED
    unsigned long previousTime;  // the time this LED last switched state
    bool blinking = true;
};




void setup() {
  Serial.begin(9600);
}

const int LEDPIN1 = 13;
const int LEDPIN2 = 12;
const int LEDPIN3 = 11;
const int LEDPIN4 = 10;
const int LEDPIN5 = 9;

// create LEDBlinkers
LEDBlinker led1(LEDPIN1, 1000, 1000);
LEDBlinker led2(LEDPIN2, 800, 800);
LEDBlinker led3(LEDPIN3, 600, 600);
LEDBlinker led4(LEDPIN4, 400, 400);
LEDBlinker led5(LEDPIN5, 200, 200);


void loop() {
  led1.update();
  led2.update();
  led3.update();
  led4.update();
  led5.update();
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '1') {
      led1.startBlink();
      led2.startBlink();
      led3.startBlink();
      led4.startBlink();
      led5.startBlink();
    } else if (c == '0'){
      led1.stopBlink();
      led2.stopBlink();
      led3.stopBlink();
      led4.stopBlink();
      led5.stopBlink();
    }
  }
}
