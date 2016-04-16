void Set5883()
{
    writeToWire(0x1e, 0x00, 0x70); // 5883L
    writeToWire(0x1e, 0x01, 0x20); // 5883L
    writeToWire(0x1e, 0x02, 0x00); // 5883L
}
void writeToWire(int Dev, byte Addr, byte Val)
{
  Wire.beginTransmission(Dev);
  Wire.write(Addr);
  Wire.write(Val);
  Wire.endTransmission();
}

void readFromWire(int Dev, byte Addr, int count, byte *p)
{
  Wire.beginTransmission(Dev);
  Wire.write(Addr);
  Wire.endTransmission();
  Wire.requestFrom(Dev, count);

  while (Wire.available())
  {
    *(p++) = Wire.read();
  }
}

void test_hmc5883()
{
   byte data[6];
   readFromWire(0x1e,0x03,6,data);
   int mag[3];
   for(byte i=0; i<3; i++)
  {
    mag[i] = ((int)data[i + i + 1] << 8) | (int)data[i + i];
  }
//  display.print("X= ");
//  display.print( mag[0], DEC);
//  display.print(',');
//  display.print("   Y= ");
//  display.print( mag[1], DEC);
//  display.print(',');
//  display.print("   Z= ");
//  display.println( mag[2], DEC);
//  delay(100);
}

