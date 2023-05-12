const int BUTTON1_P = 6;
const int BUTTON2_P = 5;
const int BUTTON3_P = 4;
const int BUTTON4_P = 3;
const int BUTTON5_P = 2;
const int GLED_P = 13;
const int RLED_P = 12;
const int ALARM_P = 8;


class LEDBlinker {
  public:
    LEDBlinker(int ledpin, int onInterval, int offInterval) {
      pin = ledpin;
      state = LOW;
      prevTime = 0;
      onInt = onInterval;
      offInt = offInterval;
      blinking = true;
      pinMode(pin, OUTPUT);
    }


    void update() {
      unsigned long currentTime = millis();
      if (blinking == false) {
        return;
      }
      if ((state == HIGH) && (currentTime - prevTime >= onInt)) {
        prevTime = currentTime;
        state = LOW;

        digitalWrite(pin, state);
      }
      else if ((state == LOW) && (currentTime - prevTime >= offInt)) {
        prevTime = currentTime;
        state = HIGH;

        digitalWrite(pin, state);
    }
    }

    void turnOff() {
      blinking = false;
      digitalWrite(pin, LOW);
    }
    void turnOn() {
      blinking = true;
    }
    void turnOnNoBlink() {
      blinking = false;
      digitalWrite(pin, HIGH);
    }

  private:
    int pin;     
    int onInt;   
    int offInt;  
    int state;  
    bool blinking;
    unsigned long prevTime;
};


class PushButton {
  public:
    PushButton(int bpin, bool bpullup) {
      pin = bpin;
      initTime = millis();
      pullup = bpullup;
      pinMode(pin, INPUT_PULLUP);
      buttonState = HIGH;
      pushed = false;
    }

    void update() {
      unsigned long currentTime = millis();
      int newButtonState = digitalRead(pin);

      if (currentTime - initTime < 500) {
        return;
      }

      if (newButtonState != buttonState) {
        buttonState = newButtonState;
        if (down()) {
          pushed = true;
        }
      }
    }

    bool up() {
      if (pullup) {
        return buttonState == HIGH;
      }
      else {
        return buttonState == LOW;
      }
    }
    
    bool down() {
      if (pullup) {
        return buttonState == LOW;
      }
      else {
        return buttonState == HIGH;
      }
    }

    bool newPush() {
      if (pushed) {
        pushed = false;
        return true;
      }
      return false;
    }

  private:
    int pin;          
    bool pullup;
    bool pushed;
    int initTime;     
    int buttonState;  
};

class alarm {
  public:
    alarm(int pin) {
      buzz = pin;
      fadeAmount = -20;
      prevTime = 0;
      frequency = 2000;
      timeUpdate = 50;
      buzzs = true;
    }

    void update() {
    unsigned long currentTime = millis();
      if (buzzs == false) {
        noTone(buzz);
        return;
      }

      if (currentTime-prevTime>timeUpdate) {
        prevTime=currentTime;

        if (frequency>=3000 || frequency<=2000) {
          fadeAmount=-fadeAmount;
        }
        frequency=frequency+fadeAmount;
        
      }
      tone(buzz,frequency);
    }
    void turnOff() {
      buzzs = false;
      return;
    }
    void turnOn() {
      buzzs = true;
      return;
    }

  private:
    int buzz;
    int fadeAmount;
    int prevTime;
    int frequency;
    int timeUpdate;
    bool buzzs;
};

//////////////////////////////////////////////////////////
// Code below this point is working and has been tested //
//////////////////////////////////////////////////////////

//
// The Combination Lock.  This class contains the PushButtons,
// LEDs and Alarm which form part of the lock.
//   - This code is working and complete for 3 buttons and
//   - an input key of 3 pushes
//
class ComboLock {
  public:

    ComboLock()
      : b1(BUTTON1_P, true), b2(BUTTON2_P, true), b3(BUTTON3_P, true), b4(BUTTON4_P, true), b5(BUTTON5_P, true),
        redLED(RLED_P, 500, 500), greenLED(GLED_P, 500, 500),
        alarm(ALARM_P)
    {
      open = true;
      allowNext = false;

      setLockMode(SETKEYMODE);
    }

    // set the lock key for each button position
    void setKey(int pos, int val)
    {
      if (pos >= 0 && pos < LEN)
        key[pos] = val;
    }

    // set the input for each button
    void setInput(int pos, int val)
    {
      if (pos >= 0 && pos < LEN)
        input[pos] = val;
    }

    // check if the lock matches the input - and set the open state
    void check()
    {
      for (int i = 0; i < LEN; i++) {
        if (key[i] != input[i]) {
          open = false;
          return;
        }
      }
      open = true;
    }

    bool isOpen() {
      return open;
    }

    // lock and reset the input
    void lock()
    {
      open = false;
      for (int i = 0; i < LEN; i++)
        input[i] = 0;
    }


    void setLockMode(int newMode)
    {
      mode = newMode;
      inPos = 0;
      allowNext = false;

      if (newMode == SETKEYMODE) {
        alarm.turnOff();
        redLED.turnOn();
        greenLED.turnOff();
      }
      else if (newMode == INPUTMODE) {
        lock();
        alarm.turnOff();
        redLED.turnOff();
        greenLED.turnOff();
      }
      else if (newMode == ENDMODE) {
        check();
        if (isOpen()) {
          greenLED.turnOnNoBlink();
        }
        else {
          alarm.turnOn();
          redLED.turnOnNoBlink();
        }
      }
    }

    // call repeatedly in loop() to operate the lock
    //  manages the lock modes
    //    SETKEYMODE - accept button input to set the key for the lock
    //    INPUTMODE - accept button input to unlock the lock
    //    ENDMODE - wait for a button input after INPUTMODE
    void update()
    {
      b1.update();
      b2.update();
      b3.update();
      b4.update();
      b5.update();
      redLED.update();
      greenLED.update();
      alarm.update();

      // Get the button input to set the combo key
      if (mode == SETKEYMODE) {

        getButtonInput(key);

        // got all inputs - combo is set
        if (inPos >= LEN) {
          printCombo();
          setLockMode(INPUTMODE);
        }
      }

      // Get the button input to unlock
      else if (mode == INPUTMODE) {

        getButtonInput(input);

        // got all inputs - check
        if (inPos >= LEN) {
          printInput();
          setLockMode(ENDMODE);
        }
      }

      // wait for a button press to reset lock
      else if (mode == ENDMODE) {
        if (b1.up() && b2.up() && b3.up() && b4.up() && b5.up())
          allowNext = true;

        // if any button is pressed - reset the lock and go to input mode
        if (allowNext && (b1.down() || b2.down() || b3.down() || b4.down() || b5.down()))
          setLockMode(INPUTMODE);
      }
    }

  private:
    static const int LEN = 5;

    int key[LEN] = {0};    // lock key

    int input[LEN] = {0};  // user input

    static const int SETKEYMODE = 1;
    static const int INPUTMODE = 2;
    static const int ENDMODE = 3;

    int mode;

    bool open;
    int inPos;
    bool allowNext;

    // the buttons
    PushButton b1;
    PushButton b2;
    PushButton b3;
    PushButton b4;
    PushButton b5;
    // the status LED's
    LEDBlinker redLED;
    LEDBlinker greenLED;

    alarm alarm;

    /////  helper methods - used internally

    // handles button presses, making sure the input is reliable
    void getButtonInput(int buff[])
    {
      // don't allow a button press until all buttons are up
      if (b1.up() && b2.up() && b3.up() && b4.up() && b5.up())
        allowNext = true;

      if (allowNext) {
        if (b1.down()) {
          buff[inPos] = 1;
          inPos++;
          allowNext = false;
        }
        if (b2.down()) {
          buff[inPos] = 2;
          inPos++;
          allowNext = false;
        }
        if (b3.down()) {
          buff[inPos] = 3;
          inPos++;
          allowNext = false;
        }
        if (b4.down()) {
          buff[inPos] = 4;
          inPos++;
          allowNext = false;
        }
        if (b5.down()) {
          buff[inPos] = 5;
          inPos++;
          allowNext = false;
        }
    }
    }

    void printCombo()
    {
      Serial.print("Combo: ");
      for (int i = 0; i < LEN; i++)
        Serial.print(key[i]);
      Serial.println();
    }

    void printInput()
    {
      Serial.print("Input: ");
      for (int i = 0; i < LEN; i++)
        Serial.print(input[i]);
      Serial.println();
    }
};


void setup()
{
  Serial.begin(9600);
}


// create the lock
ComboLock combo;

void loop()
{
  combo.update();
}

