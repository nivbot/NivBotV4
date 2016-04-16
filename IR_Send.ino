void SendStop(){
  //Back Send:
  IrBack_Enable;
  irsend.sendSony(IR2_MoveStop, 12);
  IrBack_Disable;
  delay(10);
  //Left Send
  IrLeft_Enable;
  irsend.sendSony(IR2_MoveStop, 12);
  IrLeft_Disable;
  delay(10);
  //Right Send
  IrRight_Enable;
  irsend.sendSony(IR2_MoveStop, 12);
  IrRight_Disable;
  delay(10);
  irrecv.enableIRIn();
}

void SendForward(){
  //Back Send:
  IrBack_Enable;
  irsend.sendSony(IR2_MoveHead, 12);
  IrBack_Disable;
  delay(10);
  //Left Send
  IrLeft_Enable;
  irsend.sendSony(IR2_MoveHead, 12);
  IrLeft_Disable;
  delay(10);
  //Right Send
  IrRight_Enable;
  irsend.sendSony(IR2_MoveHead, 12);
  IrRight_Disable;
  delay(10);
  irrecv.enableIRIn();
}

void SendTurnL(){
  //Back Send:
  IrBack_Enable;
  irsend.sendSony(IR2_MoveLeft, 12);
  IrBack_Disable;
  delay(10);
  //Left Send
  IrLeft_Enable;
  irsend.sendSony(IR2_MoveLeft, 12);
  IrLeft_Disable;
  delay(10);
  //Right Send
  IrRight_Enable;
  irsend.sendSony(IR2_MoveLeft, 12);
  IrRight_Disable;
  delay(10);
  irrecv.enableIRIn();
}
void SendTurnR(){
  //Back Send:
  IrBack_Enable;
  irsend.sendSony(IR2_MoveRight, 12);
  IrBack_Disable;
  delay(10);
  //Left Send
  IrLeft_Enable;
  irsend.sendSony(IR2_MoveRight, 12);
  IrLeft_Disable;
  delay(10);
  //Right Send
  IrRight_Enable;
  irsend.sendSony(IR2_MoveRight, 12);
  IrRight_Disable;
  delay(10);
  irrecv.enableIRIn();
}

void SendGather(){
  //Back Send:
  IrBack_Enable;
  irsend.sendSony(IR2_Gather, 12);
  IrBack_Disable;
  delay(10);
  //Left Send
  IrLeft_Enable;
  irsend.sendSony(IR2_Gather, 12);
  IrLeft_Disable;
  delay(10);
  //Right Send
  IrRight_Enable;
  irsend.sendSony(IR2_Gather, 12);
  IrRight_Disable;
  delay(10);
  irrecv.enableIRIn();
}
void SendDisperse(){
  //Back Send:
  IrBack_Enable;
  irsend.sendSony(IR2_Disperse, 12);
  IrBack_Disable;
  delay(10);
  //Left Send
  IrLeft_Enable;
  irsend.sendSony(IR2_Disperse, 12);
  IrLeft_Disable;
  delay(10);
  //Right Send
  IrRight_Enable;
  irsend.sendSony(IR2_Disperse, 12);
  IrRight_Disable;
  delay(10);
  irrecv.enableIRIn();
}
void SendFollow(){
  //Back Send:
  IrBack_Enable;
  irsend.sendSony(IR2_Follow, 12);
  IrBack_Disable;
  delay(10);
  //Left Send
  IrLeft_Enable;
  irsend.sendSony(IR2_Follow, 12);
  IrLeft_Disable;
  delay(10);
  //Right Send
  IrRight_Enable;
  irsend.sendSony(IR2_Follow, 12);
  IrRight_Disable;
  delay(10);
  irrecv.enableIRIn();
}


void sendCode() {
  SendOtherIR();
  irrecv.enableIRIn();
}

void SendOtherIR()
{
  //Back Send:
  IrBack_Enable;
  irsend.sendSony(0x101, 12);
  IrBack_Disable;
  delay(10);
  //Left Send
  IrLeft_Enable;
  irsend.sendSony(0x102, 12);
  IrLeft_Disable;
  delay(10);
  //Right Send
  IrRight_Enable;
  irsend.sendSony(0x103, 12);
  IrRight_Disable;
  delay(10);
}



