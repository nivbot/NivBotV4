/*Pin Map
 *PIN   FUCTION
 * 2       NC
 * 3       IR_SEND_ALL
 * 4       RGB_R
 * 5       MOTOR_L
 * 6       MOTOR_R
 * 7       IR_SEND_ENABLE_BACK
 * 8       IR_SEND_ENABLE_LEFT
 * 9       IR_SEND_ENABLE_RIGHT
 * 10      TONE
 * 11      IR_REC
 * 12      SDA_DISPLAY
 * 13      SCL_DISPLAY
 * A0      POWER_CHECK
 * A1      RGB_G
 * A2      RGB_B
 * A3      NC
 */

byte BotData_Brain;
byte TurnDir;
byte BrainDat;
byte TapType;

/*************************************************
 * Tone Constants
 *************************************************/
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

///***********  Tone **************///
#define TonePin  10

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
/*
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
int noteDurations[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};*/

///***********  RGB  **************///
#define RGB_R  4
#define RGB_G  A1
#define RGB_B  A2

///********** Display  ***********///
#define SDA_PIN 12
#define SCL_PIN 13
Adafruit_ssd1306syp display(SDA_PIN,SCL_PIN);

///********** Power  ************///
int PowerCheck;

///********** EEPROM  ************///
int EEP_ADDR1 = 0;
int EEP_ADDR2 = 1;
int EEP_ADDR3 = 2;
int EEP_ADDR4 = 3;
int LSped;
int RSped;
int LTim;
int RTim;

///********** Motor  *************///
#define LMotorPin 5
#define RMotorPin 6
int LSpeed = EEPROM.read(EEP_ADDR1);
int RSpeed = EEPROM.read(EEP_ADDR2);
int LTime  = EEPROM.read(EEP_ADDR3);
int RTime  = EEPROM.read(EEP_ADDR4);

#define State_Null      0
#define State_TurnL     1
#define State_TurnR     2
#define State_Farward   3
#define State_Stop      4
#define State_TurnLL    5
#define State_TurnRR    6

unsigned int Time,lastTime;
unsigned char TurnState;

///*********** Bluetooth *************///
String BlueString;
unsigned int RecData = 0;

///***********  IR Order **************///
//Type 4
#define SS        0xFF02FD   //Stop
#define WW        0xFF629D   //GoForward
#define AA        0xFF22DD   //Turn Left
#define DD        0xFFC23D   //Turn Right

#define LSpeedAdd 0xFFA857
#define LSpeedDec 0xFFE01F
#define RSpeedAdd 0xFF9867
#define RSpeedDec 0xFF6897
#define LTimeAdd  0xFF18E7
#define LTimeDec  0xFF30CF  
#define RTimeAdd  0xFF38C7
#define RTimeDec  0xFF10EF
#define EQ        0xFF906F
#define DIS200    0xFFB04F

#define ON_R      0xFF42BD
#define ON_G      0xFF4AB5
#define ON_B      0xFF52AD
//0xFF7A85
#define Buzzing   0xFF5AA5

//Type 3
#define IR2_Sleep     0x011 //休眠
#define IR2_Work      0x100 //激活

#define IR2_BlinkR    0x101 //红灯亮
#define IR2_BlinkG    0x102 //绿灯亮
#define IR2_BlinkB    0x103 //蓝灯亮

#define IR2_MoveStop  0x110 //停止
#define IR2_MoveHead  0x111 //前进
#define IR2_MoveLeft  0x112 //左转
#define IR2_MoveRight 0x113 //右转

#define IR2_Gather    0x121 //聚集
#define IR2_Disperse  0x122 //分散
#define IR2_Follow    0x123 //跟随

#define IR2_Buzzer    0x131 //蜂鸣器响
#define IR2_ChkPower  0x132 //电量


///***********  IR Variable **************///
int codeType = -1; // The type of code
unsigned long codeValue; // The code value
int codeLen; // The length of the code

///*********** IR EYE ***************///
#define Leye  A0
#define Reye  A3
///***********  IR RCV **************///
#define RECV_PIN  11

///***********  IR SEND **************///
#define IrBack   7
#define IrLeft   8
#define IrRight  9

#define IrBack_Enable  digitalWrite(IrBack,  HIGH);
#define IrLeft_Enable  digitalWrite(IrLeft,  HIGH);
#define IrRight_Enable digitalWrite(IrRight, HIGH);
#define IrBack_Disable digitalWrite(IrBack,  LOW);
#define IrLeft_Disable digitalWrite(IrLeft,  LOW);
#define IrRight_Disable digitalWrite(IrRight, LOW);

IRrecv irrecv(RECV_PIN);
IRsend irsend;
decode_results results;

///******** Global variable ******///
long Order;
char Order_Blue;
char last_Order_Blue;

unsigned long Tim, last_Tim;
unsigned int stepNum;

///******  Set pinMode()  *******///
void SetPinMode()
{
  //Serial
  Serial.begin(115200);
  //Tone
  pinMode(TonePin, 10);
  
   //RGB
  pinMode(RGB_R, OUTPUT);
  pinMode(RGB_G, OUTPUT);
  pinMode(RGB_B, OUTPUT);
  
  //Motor
  pinMode(LMotorPin, OUTPUT);
  pinMode(RMotorPin, OUTPUT);
  
  //IR
  pinMode(RECV_PIN,  INPUT);
  pinMode(IrBack,  OUTPUT);
  pinMode(IrLeft,  OUTPUT);
  pinMode(IrRight, OUTPUT);
}

// Read data from Serial UART //
byte ReadOneByte() {
  byte ByteRead;
  while (!Serial.available());
  ByteRead = Serial.read();
  return ByteRead;
}



