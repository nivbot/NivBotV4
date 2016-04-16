void Read_Blue(boolean chose)
{
  byte Data_High;
  byte Data_Low;

  if (ReadOneByte() == 240) {    //recv SYN
    Data_High = ReadOneByte();    //High Data
    Data_Low  = ReadOneByte();    //Low  Data
    //RecData = Data_High << 8 + Data_Low;
    BotData_Brain = Data_Low;
    display.clear();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print(Data_High, BIN);
    display.setCursor(0, 20);
    display.print(Data_Low, DEC);
    display.update();
  }
  if (chose == true) {
    Parse_BlueDir(Data_High);
  }
  else  {
    Parse_BlueBrain(Data_Low);
  }
}

void Parse_BlueDir(byte OrderH)
{
  switch (OrderH) {
    case 0b10000: TurnDir = 0;break;  //stop
    case 0b10001: TurnDir = 1;break;  //forward
    case 0b10010: TurnDir = 2;break;  //left
    case 0b10011: TurnDir = 3;break;  //right
    case 0b10100: TapType = 1;break;  //single Tap
    case 0b11000: TapType = 2;break;   //double Tap
    default:      TurnDir = 0;TapType = 0;break;
  }
}
void Parse_BlueBrain(byte OrderL)
{
  switch (OrderL) {
    case 240: BrainDat = 0; break;  //0b11110000  Poor Quality
    case 127: BrainDat = 1; break;  //0b01111111  Touth Quality
    default:  BrainDat = 2; break;  //0bxxxxxxxx  Good Quality
  }
}

void Run_Blue()
{
  if (TurnDir == 0)      {
    SendStop();
    STOP();
  }
  else if (TurnDir == 1) {
    SendForward();
    GoForward();
  }
  else if (TurnDir == 2) {
    SendTurnL();
    TurnLeft();
  }
  else if (TurnDir == 3) {
    SendTurnR();
    TurnRight();
  }
  
  if (TapType == 1) {   //{SendGather();} 
    byte TapCount;
    int RunTime = millis();
    int ourTime = 0;
    while (ourTime < 5000) //读取5秒内单击次数；单击一次进入聚集行为；单击二次进入分散行为；等待双击跳出
    {
      ourTime = millis() - RunTime;
     
      Start_Tone();
      Read_Blue(1);
      Start_Display();
      if (TapType == 1)  TapCount++;
    }
    if(TapCount == 1) {
      while(TapType != 2){ //等待双击
        SendGather();
        Read_Blue(1);        
      }
    }
    else if(TapCount == 2){
      while(TapType != 2){ //等待双击
        SendDisperse();
        Read_Blue(1);        
      }
    }
  }
  else if (TapType == 2) {
    SendFollow();
  }
  else {
    SendStop();
    STOP();
  }

  if (BrainDat == 0 )      Blink_R();
  else if (BrainDat == 1)  Blink_G();
  else if (BrainDat == 2)  RGB_ColorAndBrain();
}

boolean is_GetOrder()
{
  while (Serial.available())
  {
    BlueString = BlueString + Serial.read();
    return true;
  }
  return false;
}

void deal_Order()
{
  last_Order_Blue = Order_Blue;
  switch (Order_Blue)
  {
    case 'S' : STOP();   break;
    case 'W' : GoForward(); break;
    case 'A' : TurnLeft();   break;
    case 'D' : TurnRight();  break;
    default: break;
  }
}

