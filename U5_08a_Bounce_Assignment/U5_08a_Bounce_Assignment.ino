/*class LEDBlinker {
  public:
    LEDBlinker(int ledpin, int onInterval, int offInterval)
    {
      pin = ledpin;
      state = LOW;
      previousTime = 0;
      onInt = onInterval;
      offInt = offInterval;
      blinker = false;
      pinMode(pin, OUTPUT);
    }
    void update()
    {
      if (blinker == false) {
        return;
      }
      unsigned long currentTime = millis();
      if ((state == HIGH) && (currentTime - previousTime >= onInt)) {
        previousTime = currentTime;
        state = LOW;
        digitalWrite(pin, state);
      }
      else if ((state == LOW) && (currentTime - previousTime >= offInt)) {
        previousTime = currentTime;
        state = HIGH;
        digitalWrite(pin,state);
      }
    }
    
    void turnOff()
    {
      state = LOW;
      digitalWrite(pin, state);
      blinker = false;
    }
    
    void turnOn()
    {
      blinker = true;
    }
    
    bool isBlinking() {
      if (blinker == true) {
        return true;
      } if (blinker == false) {
        return false;
      }
    }
  
  private:
    int pin;
    int onInt;
    int offInt;
    int state;
    unsigned long previousTime;
    bool blinker;
};

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
          pushed = true;
        }
      }
    }
    
    bool down() {
      if (pullup) {
        return buttonState == 0;
      } else {
        return buttonState == 1;
      }
    }
    
    bool up() {
      if (pullup) {
        return buttonState == 1;
      } else {
        return buttonState == 0;
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

void setup() {
  Serial.begin(9600);
}

LEDBlinker led(13, 500, 500);
PushButton pullUpButton(2, true);
PushButton pullDownButton(3, false);

void loop() {
  led.update();
  pullUpButton.update();
  pullDownButton.update();
 
  if (pullUpButton.newPush() || pullDownButton.newPush()) {
    if (led.isBlinking())
      led.turnOff();
    else
      led.turnOn();
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
      blinker = false;
      pinMode(pin, OUTPUT);
    }
    void update()
    {
      if (blinker == false) {
        return;
      }
      unsigned long currentTime = millis();
      if ((state == HIGH) && (currentTime - previousTime >= onInt)) {
        previousTime = currentTime;
        state = LOW;
        digitalWrite(pin, state);
      }
      else if ((state == LOW) && (currentTime - previousTime >= offInt)) {
        previousTime = currentTime;
        state = HIGH;
        digitalWrite(pin,state);
      }
    }
    
    void turnOff()
    {
      state = LOW;
      digitalWrite(pin, state);
      blinker = false;
    }
    
    void turnOn()
    {
      blinker = true;
    }
    
    bool isBlinking() {
      if (blinker == true) {
        return true;
      } if (blinker == false) {
        return false;
      }
    }
  
  private:
    int pin;
    int onInt;
    int offInt;
    int state;
    unsigned long previousTime;
    bool blinker;
};

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

void setup() {
  Serial.begin(9600);
}

LEDBlinker led(13, 500, 500);
PushButton pullUpButton(2, true);
PushButton pullDownButton(3, false);

void loop() {
  led.update();
  pullUpButton.update();
  if (pullUpButton.newPush() || pullDownButton.newPush()) {
    if (led.isBlinking())
      led.turnOff();
    else
      led.turnOn();
  }
  pullDownButton.update();

}

