void Start_RGB()
{
  digitalWrite(RGB_R, HIGH);
  delay(300);
  digitalWrite(RGB_R, LOW);
  digitalWrite(RGB_G, HIGH);
  delay(300);
  digitalWrite(RGB_G, LOW);
  digitalWrite(RGB_B, HIGH);
  delay(300);
  digitalWrite(RGB_B, LOW);
}

void RGB_ColorAndBrain()
{
  Off_RGB();
  if(BotData_Brain <= 100 && BotData_Brain > 85) {Blink_R();}
  else if(BotData_Brain <= 85 && BotData_Brain > 70) {Blink_R();Blink_G();}
  else if(BotData_Brain <= 70 && BotData_Brain > 55) {Blink_R();Blink_B();}
  else if(BotData_Brain <= 55 && BotData_Brain > 30) {Blink_G();}
  else if(BotData_Brain <= 30 && BotData_Brain > 15) {Blink_G();Blink_B();}
  else if(BotData_Brain <= 15 && BotData_Brain > 0)  {Blink_B();}
  else {}
}

void Blink_R()
{
  digitalWrite(RGB_R, HIGH);
//  delay(500);
//  digitalWrite(RGB_R, LOW);
}
void Blink_G()
{
  digitalWrite(RGB_G, HIGH);
//  delay(500);
//  digitalWrite(RGB_G, LOW);
}
void Blink_B()
{
  digitalWrite(RGB_B, HIGH);
//delay(500);
//  digitalWrite(RGB_B, LOW);
}

void Off_RGB()
{
  digitalWrite(RGB_R, LOW);
  digitalWrite(RGB_G, LOW);
  digitalWrite(RGB_B, LOW);
}

