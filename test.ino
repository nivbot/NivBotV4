void test_RGB()
{
  digitalWrite(RGB_R, HIGH);
  delay(500);
  digitalWrite(RGB_R, LOW);
  digitalWrite(RGB_G, HIGH);
  delay(500);
  digitalWrite(RGB_G, LOW);
  digitalWrite(RGB_B, HIGH);
  delay(500);
  digitalWrite(RGB_B, LOW);
}

void test_IR_follow()
{
  int valL = analogRead(Leye);
  int valR = analogRead(Reye);

  //Serial.println(valR);

  if (valL > 200 && valR < 200)
  {
    digitalWrite(RGB_G, HIGH);
    TurnLeft();
    TurnState = State_TurnL;
    stepNum ++;
    IrBack_Enable;
    irsend.sendSony(0x101, 12);
    IrBack_Disable;
    delay(10);
  }
  else if (valR > 200 && valL < 200)
  {
    digitalWrite(RGB_B, HIGH);
    TurnRight();
    TurnState = State_TurnR;
    stepNum ++;
    IrBack_Enable;
    irsend.sendSony(0x101, 12);
    IrBack_Disable;
    delay(10);
  }
  /*
    else if(valL > 300 && valR > 300)
    {
    digitalWrite(RGB_R,HIGH);
    GoForward();
    stepNum += 2;
    IrBack_Enable;
    irsend.sendSony(0x101, 12);
    IrBack_Disable;
    }*/

  else if (valL < 200 && valR < 200) // not in the line
  {
    digitalWrite(RGB_R, LOW);
    digitalWrite(RGB_G, LOW);
    digitalWrite(RGB_B, LOW);
    Time = millis() - lastTime;
    lastTime = millis();
    //Serial.println(Time);
    switch (TurnState) {
      case State_TurnL:
        TurnState = State_Null;
        if (Time > 3000) {
          digitalWrite(RGB_R, HIGH);
          delay(500);
          digitalWrite(RGB_R, LOW);
          delay(500);
        }
        break;
      case State_TurnR:
        TurnState = State_Null;
        if (Time > 3000) {
          digitalWrite(RGB_R, HIGH);
          delay(100);
          digitalWrite(RGB_R, LOW);
          delay(100);
        }
        break;
      default: STOP(); break;
    }
  }
}

void test_Motor()
{
  TurnLeft();
  delay(50);
  TurnRight();
  delay(50
  );
  //  analogWrite(LMotorPin, LSpeed);
  //  analogWrite(RMotorPin, RSpeed);
  //  delay(200);
  //  analogWrite(LMotorPin, 0);
  //  analogWrite(RMotorPin, 0);
  //  delay(1000);
}

void test_Display()
{
  display.clear();
  display.setTextSize(3);
  display.setTextColor(WHITE); // 'inverted' text
  display.setCursor(12, 22);
  display.println("NIVBOT");
  display.update();
}

void test_display_Power()
{
  long CheckPow  = CheckPower();

  //  Serial.print(CheckPow);
  //  Serial.println("mV");

  display.clear();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 5);
  display.print("Battery:             ");
  display.print(CheckPow);
  display.print("mV");
  display.update();
}

void test_Tone()
{
  // iterate over the notes of the melody:
  int siz = sizeof(melody) / sizeof(int);
  for (int thisNote = 0; thisNote < siz; thisNote++) {
       // to calculate the note duration, take one second
       // divided by the note type.
       //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
       int noteDuration = 1000 / noteDurations[thisNote];
       buzz(TonePin, melody[thisNote], noteDuration);
       // to distinguish the notes, set a minimum time between them.
       // the note's duration + 30% seems to work well:
       int pauseBetweenNotes = noteDuration * 1.30;
       delay(pauseBetweenNotes);
       // stop the tone playing:
       buzz(TonePin,0,noteDuration);
  }
}
