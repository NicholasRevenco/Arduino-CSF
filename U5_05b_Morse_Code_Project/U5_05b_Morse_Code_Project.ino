void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

const int var = 500;

char inputString[256];
bool getSerialInput()
{
  if (Serial.available())
  {
    size_t size = Serial.readBytesUntil('\n', inputString, 255);
    inputString[size] = 0;
    return true;
  }
  else
  {
    return false;
  }
}

void morseDot()
{
  digitalWrite(13, HIGH);
  delay(var);
  digitalWrite(13, LOW);
}

void morseDash()
{
  digitalWrite(13, HIGH);
  delay(var*3);
  digitalWrite(13, LOW);
}

void morsePause()
{
  delay(var*4);
}

void betweenLetter()
{
  delay(var*3);
}


void morseCharacter(char ch)
{
  Serial.println(ch);
}

void loop() 
{
  bool gotString = getSerialInput();

  if (gotString)
  {
    Serial.print("string: "); Serial.println(inputString);
    

    for (int i = 0; i < strlen(inputString); i ++)
    {
      morseCharacter(inputString[i]);
      if (inputString[i] == 'a') {
        morseDot();
        delay(var);
        morseDash();
      } else if (inputString[i] == 'b') {
        morseDash();
        delay(var);
        morseDot();
        delay(var);
        morseDot();
        delay(var);
        morseDot();
      } else if (inputString[i] == 'c') {
        morseDash();
        delay(var);
        morseDot();
        delay(var);
        morseDash();
        delay(var);
        morseDot();
      } else if (inputString[i] == 'd') {
        morseDash();
        delay(var);
        morseDot();
        delay(var);
        morseDot();
      } else if (inputString[i] == 'e') {
        morseDot();
      } else if (inputString[i] == 'f') {
        morseDot();
        delay(var);
        morseDot();
        delay(var);
        morseDash();
        delay(var);
        morseDot();
      } else if (inputString[i] == 'g') {
        morseDash();
        delay(var);
        morseDash();
        delay(var);
        morseDot();
      } else if (inputString[i] == 'h') {
        morseDot();
        delay(var);
        morseDot();
        delay(var);
        morseDot();
        delay(var);
        morseDot();
      } else if (inputString[i] == 'i') {
        morseDot();
        delay(var);
        morseDot();
      } else if (inputString[i] == 'j') {
        morseDot();
        delay(var);
        morseDash();
        delay(var);
        morseDash();
        delay(var);
        morseDash();
      } else if (inputString[i] == 'k') {
        morseDash();
        delay(var);
        morseDot();
        delay(var);
        morseDash();
      } else if (inputString[i] == 'l') {
        morseDot();
        delay(var);
        morseDash();
        delay(var);
        morseDot();
        delay(var);
        morseDot();
      } else if (inputString[i] == 'm') {
        morseDash();
        delay(var);
        morseDash();
      } else if (inputString[i] == 'n') {
        morseDash();
        delay(var);
        morseDot();
      } else if (inputString[i] == 'o') {
        morseDash();
        delay(var);
        morseDash();
        delay(var);
        morseDash();
      } else if (inputString[i] == 'p') {
        morseDot();
        delay(var);
        morseDash();
        delay(var);
        morseDash();
        delay(var);
        morseDot();
      } else if (inputString[i] == 'q') {
        morseDash();
        delay(var);
        morseDash();
        delay(var);
        morseDot();
        delay(var);
        morseDash();
      } else if (inputString[i] == 'r') {
        morseDot();
        morseDash();
        morseDot();
      } else if (inputString[i] == 's') {
        morseDot();
        delay(var);
        morseDot();
        delay(var);
        morseDot();
      } else if (inputString[i] == 't') {
        morseDash();
      } else if (inputString[i] == 'u') {
        morseDot();
        delay(var);
        morseDot();
        delay(var);
        morseDash();
      } else if (inputString[i] == 'v') {
        morseDot();
        delay(var);
        morseDot();
        delay(var);
        morseDot();
        delay(var);
        morseDash();
      } else if (inputString[i] == 'x') {
        morseDash();
        delay(var);
        morseDot();
        delay(var);
        morseDot();
        delay(var);
        morseDash();
      } else if (inputString[i] == 'y') {
        morseDash();
        delay(var);
        morseDot();
        delay(var);
        morseDash();
        delay(var);
        morseDash();
      } else if (inputString[i] == 'z') {
        morseDash();
        delay(var);
        morseDash();
        delay(var);
        morseDot();
        delay(var);
        morseDot();
      } else if (inputString[i] == '1') {
        morseDot();
        delay(var);
        morseDash();
        delay(var);
        morseDash();
        delay(var);
        morseDash();
        delay(var);
        morseDash();
      } else if (inputString[i] == '2') {
        morseDot();
        delay(var);
        morseDot();
        delay(var);
        morseDash();
        delay(var);
        morseDash();
        delay(var);
        morseDash();
      } else if (inputString[i] == '3') {
        morseDot();
        delay(var);
        morseDot();
        delay(var);
        morseDot();
        delay(var);
        morseDash();
        delay(var);
        morseDash();
      } else if (inputString[i] == '4') {
        morseDot();
        delay(var);
        morseDot();
        delay(var);
        morseDot();
        delay(var);
        morseDot();
        delay(var);
        morseDash();
      } else if (inputString[i] == '5') {
        morseDot();
        delay(var);
        morseDot();
        delay(var);
        morseDot();
        delay(var);
        morseDot();
        delay(var);
        morseDot();
      } else if (inputString[i] == '6') {
        morseDash();
        delay(var);
        morseDot();
        delay(var);
        morseDot();
        delay(var);
        morseDot();
        delay(var);
        morseDot();
      } else if (inputString[i] == '7') {
        morseDash();
        delay(var);
        morseDash();
        delay(var);
        morseDot();
        delay(var);
        morseDot();
        delay(var);
        morseDot();
      } else if (inputString[i] == '8') {
        morseDash();
        delay(var);
        morseDash();
        delay(var);
        morseDash();
        delay(var);
        morseDot();
        delay(var);
        morseDot();
      } else if (inputString[i] == '9') {
        morseDash();
        delay(var);
        morseDash();
        delay(var);
        morseDash();
        delay(var);
        morseDash();
        delay(var);
        morseDot();
      } else if (inputString[i] == '0') {
        morseDash();
        delay(var);
        morseDash();
        delay(var);
        morseDash();
        delay(var);
        morseDash();
        delay(var);
        morseDash();
      }
      
      if (inputString[i] != ' ') {
        betweenLetter();
      } else {
        morsePause();
      }
    }
  }
}

