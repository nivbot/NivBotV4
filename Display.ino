//this fuction used for start, it will display "NIVBOT and Power"
void Start_Display()
{
  long CheckPowr  = CheckPower();
  display.clear();
  display.setTextSize(3);
  display.setTextColor(WHITE); // 'inverted' text
  display.setCursor(12, 5);
  display.print("NIVBOT");
  display.setTextSize(2);
  display.setCursor(10, 50);
  display.print("Po:");
  display.print(CheckPowr);
  display.print("mV");
  display.update();
  
  if(CheckPowr > 3600) Blink_G();
  else if((CheckPowr < 3600) & (CheckPowr > 3400)) Blink_B();
  else if(CheckPowr < 3400) Blink_R();
  
  while(CheckPowr < 3200); 
}

void display_BlueOrder(char dis)
{
    //Serial.println(Data);
    display.clear();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    //display.setCursor(0, 0);
    //display.print("Turn:");
    display.setCursor(20, 20);
    display.print(dis);
    display.update();
}

void display_IrOrder()
{
  if (irrecv.decode(&results)) {
    //Serial.println(Data);
    display.clear();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    //display.setCursor(0, 0);
    //display.print("Turn:");
    display.setCursor(0, 0);
    display.print("Type:");
    display.setCursor(60, 15);
    display.print( results.decode_type);
    display.setCursor(0, 30);
    display.print("Value:");
    display.setCursor(50, 45);
    display.print(results.value, HEX);
    display.update();
    irrecv.resume(); // Receive the next value
  }
}

