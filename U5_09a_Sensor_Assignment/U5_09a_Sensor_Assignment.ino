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
  
  void setBlinkSpeed(int speed) {
    delay(speed);
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

/*void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  
  float voltage = sensorValue * (5.0 / 1023);
  
  Serial.print("analog: ");
  Serial.print(sensorValue);
  Serial.print("/");
  Serial.println(voltage);
  
  delay(100);
}*/

void setup() {
  
}

LEDBlinker led(13, 500, 500);
void loop() {
  led.startBlink();
  led.update();
  int s = analogRead(A0);
  led.setBlinkSpeed(s);
}