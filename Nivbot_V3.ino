#include <EEPROM.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <Wire.h>
#include <Adafruit_ssd1306syp.h>
#include "Define.h"

#define Leader 1

void setup() {
  SetPinMode();
  Wire.begin();
  delay(10);
  //IR Init
  IrBack_Disable;      //disable to send Ir Order
  IrLeft_Disable;
  IrRight_Disable;
  irrecv.enableIRIn(); // Start the receive
  //Display Init
  display.initialize();
  test_Motor();
  Start_RGB();
  Start_Tone();
  int StartTime = millis();
  while ((millis() - StartTime) < 1000)
  {
    Start_Display();
  }
}

void loop() {
  //第一：读取Type4的红外校正调节数据
// DebugNIVBOT();

#if Leader
  //第二：读取系统外蓝牙数据并解析
  Read_Blue(1);  //Dir and Tap
  Read_Blue(0);  //Brain 
  //第三：执行蓝牙解析完的命令
  Run_Blue();
#endif

#if !Leader
  //第四：接收系统内红外数据并解析
  Read_IR();
  //第五：执行红外解析完的命令
  //Run_IR();
#endif

}


