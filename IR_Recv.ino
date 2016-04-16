void DebugNIVBOT()   //ir receive and adjust parameters of nivbot's motion
{
  if (irrecv.decode(&results)) {
    //Serial.println(results.decode_type);
    if (results.decode_type == 3) {
      digitalWrite(RGB_R, LOW);
      digitalWrite(RGB_G, LOW);
      digitalWrite(RGB_B, LOW);
      switch (results.value) {
        case LSpeedAdd:
          if (LSpeed < 240) LSpeed += 5;
          else if (LSpeed >= 240 ) {
            LSpeed = 240;
            Blink_R();
          }
          break;
        case LSpeedDec:
          if (LSpeed > 0 )  LSpeed -= 5;
          else if (LSpeed <= 0 ) {
            LSpeed = 0;
            Blink_R();
          }
          break;
        case RSpeedAdd:
          if (RSpeed < 240) RSpeed += 5;
          else if (RSpeed >= 240 ) {
            RSpeed = 240;
            Blink_R();
          }
          break;
        case RSpeedDec:
          if (RSpeed > 0 )  RSpeed -= 5;
          else if (RSpeed <= 0 ) {
            RSpeed = 0;
            Blink_R();
          }
          break;
        case LTimeAdd:
          if (LTime < 100 )  LTime += 5;
          else if (LTime >= 100 ) {
            LTime = 100;
            Blink_G();
          }
          break;
        case LTimeDec:
          if (LTime > 0 )  LTime -= 5;
          else if (LTime <= 0 ) {
            LTime = 0;
            Blink_G();
          }
          break;
        case RTimeAdd:
          if (RTime < 100 )  LTime += 5;
          else if (RTime >= 100 ) {
            RTime = 100;
            Blink_G();
          }
          break;
        case RTimeDec:
          if (RTime > 0 )  RTime -= 5;
          else if (RTime <= 0 ) {
            RTime = 0;
            Blink_G();
          }
          break;
        case EQ:
          EEPROM.write(EEP_ADDR1, LSpeed);
          EEPROM.write(EEP_ADDR2, RSpeed);
          EEPROM.write(EEP_ADDR3, RTime);
          EEPROM.write(EEP_ADDR4, RTime);
          break;
        case DIS200:
          LSped = EEPROM.read(EEP_ADDR1);
          RSped = EEPROM.read(EEP_ADDR2);
          LTim  = EEPROM.read(EEP_ADDR3);
          RTim  = EEPROM.read(EEP_ADDR4);
          display.clear();
          display.setTextSize(2);
          display.setTextColor(WHITE);
          display.setCursor(0, 0);
          display.print(LSped);
          display.setCursor(0, 15);
          display.print(LTim);
          display.setCursor(0, 35);
          display.print(RSped);
          display.setCursor(0, 50);
          display.print(RTim);
          display.update();
          break;
        case WW: GoForward(); break;
        case AA: TurnLeft(); break;
        case DD: TurnRight(); break;
        case SS: STOP();     break;
        case ON_R: Blink_R(); break;
        case ON_G: Blink_G(); break;
        case ON_B: Blink_B(); break;
        //case Buzzing: TurnON_Buzzer(); break;
        default: STOP();      break;
      }
    }
    irrecv.resume();
  }
}

void Read_IR()
{
  if (irrecv.decode(&results)) {
    //Serial.println(results.decode_type);
    if (results.decode_type == 4) { //have read system inside ir order
      switch (results.value) {
        case IR2_MoveStop: SendStop(); STOP();break;
        case IR2_MoveHead: SendForward(); GoForward();break;
        case IR2_MoveLeft: SendTurnL();   TurnLeft();break;
        case IR2_MoveRight:SendTurnR();   TurnRight();break;
        case IR2_Gather:   SendGather();  RunGather();break;
        case IR2_Disperse: SendDisperse();RunDisperse();break;
        case IR2_Follow:   SendFollow();  RunFollow(); break;
      }
    }
    irrecv.resume();
  }
}

void RunGather(){}
void RunDisperse(){}
void RunFollow()
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


void StoreCode(decode_results *results) {
  codeType = results->decode_type;
  codeValue = results->value;
  codeLen = results->bits;
  display_IrOrder();
  //  Serial.print("  Tyte: ");
  //  Serial.print(codeType);
  //  Serial.print("  Value: ");
  //  Serial.print(codeValue, HEX);
  //  Serial.print("  Len: ");
  //  Serial.println(codeLen);
  irrecv.resume();
  if (codeType == 4) {
    DoIrOrder(codeValue);
    sendCode();
  }
}

void DoIrOrder(unsigned long Order)
{
  if (Order == IR2_BlinkR) {
    Blink_R();
  }
  else if (Order == IR2_BlinkG) {
    Blink_G();
  }
  else if (Order == IR2_BlinkB) {
    Blink_B();
  }
}

void RunByOrder()
{
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    Order = results.value;
    if (Order == SS) {
      // Serial.println("Stop");
      STOP();
      //test_RGB();
    }
    else if (Order == WW) {
      //  Serial.println("Forward");
      Blink_R();
      GoForward();
    }
    else if (Order == AA) {
      //  Serial.println("Left");
      TurnLeft();
      Blink_G();
    }
    else if (Order == DD) {
      //  Serial.println("Right");
      TurnRight();
      Blink_B();
    }
    irrecv.resume(); // Receive the next value
  }
  delay(500);
}

