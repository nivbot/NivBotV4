void STOP()
{
  digitalWrite(LMotorPin, LOW);
  digitalWrite(RMotorPin, LOW);
}


void GoForward()
{
    TurnLeft();
    TurnRight();
}

void TurnLeft()
{
  analogWrite(LMotorPin, 0);
  analogWrite(RMotorPin, RSpeed);
  delay(RTime);
  analogWrite(LMotorPin, 0);
  analogWrite(RMotorPin, 0);
}

void TurnRight()
{
  analogWrite(LMotorPin, LSpeed);
  analogWrite(RMotorPin, 0);
  delay(LTime);
  analogWrite(LMotorPin, 0);
  analogWrite(RMotorPin, 0);
}
