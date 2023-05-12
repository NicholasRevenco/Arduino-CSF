/*
  void setup() {
  Serial.begin(9600);
  }

  void loop() {
  pinMode(11, OUTPUT);
  tone(11, 2000);
  }
*/

class PushButton {
  public:
    PushButton(int whichPin, bool pullUp) {
      pin = whichPin;
      pullup = pullUp;
      initTime = 0;
      if (pullup) {
        buttonState = 1;
      } else if (pullup == false) {
        buttonState = 0;
      }
      if (pullup) {
        pinMode(pin, INPUT_PULLUP);
      } else if (pullup == false) {
        pinMode(pin, INPUT);
      }
      pushed = true;
    }

    void update() {
      int bs = digitalRead(pin);
      if (bs != buttonState) {
        buttonState = bs;
        if (down()) {
          Serial.println("down");
          pushed = true;
        }
      }
    }

    bool down() {
      if (pullup) {
        buttonState = 0;
      } else {
        buttonState = 1;
      }
    }

    bool up() {
      if (pullup) {
        buttonState = 1;
      } else {
        buttonState = 0;
      }
    }

    bool newPush() {
      if (pushed) {
        pushed = false;
        return true;
      } else {
        return false;
      }
    }

  private:
    int pin;
    bool pullup;
    int initTime;
    int buttonState;
    bool pushed;
};

class Alarm {
  public:
    Alarm(int pin1) {
      pinMode(pin1, OUTPUT);
      pin = pin1;
      currentTime = millis();
      off = 0;
    }

    void update() {
      if (off == 0) {
        tone(pin, start);
        if (currentTime % 50 < 5) {
          start = start + interval;
          if (start >= 3000) {
            interval = -20;
            start = 2980;
          } else if (start <= 2000) {
            interval = 20;
            start = 2020;
          }
          //Serial.println(start);
        }
      }
    }

    // turn the alarm on
    void turnOn() {
      off == 0;
    }

    // turn the alarm off
    void turnOff() {
      off = 1;
      tone(pin, 0);
    }

  private:
    int pin;
    int start = 2000;
    int interval = 20;
    unsigned int currentTime;
    int off = 0;
};

void setup() {
  Serial.begin(9600);
}

int check = 3;
Alarm alarm(11);
PushButton button(2, false);

void loop() {
  alarm.update();
  button.update();
  //Serial.println(check);
  if (button.newPush()) {
    check++;
    if (check % 2 == 0) {
      alarm.turnOn();
      Serial.println("hello234");
    } else {
      alarm.turnOff();
      Serial.println("Hello");
    }
  }
}