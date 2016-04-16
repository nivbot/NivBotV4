long CheckPower(){
  // Read 1.1V reference against AVcc
  // set the reference to Vcc and the measurement to the internal 1.1V reference
  //REFS0=0,REFS0=1 means voltage reference select AVCC with external capacitor at AREF pin 
  //MUX3:0 = 1110 means 1.1V(VBG) 
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);  
    
  delay(2); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Start conversion
  while (bit_is_set(ADCSRA,ADSC)); // measuring //this is including in <avr/io.h>

  uint8_t low  = ADCL; // must read ADCL first - it then locks ADCH  
  uint8_t high = ADCH; // unlocks both

  long result = (high<<8) | low;  
  // Calculate Vcc (in mV); 1125300 = 1.1*1023*1000  
  // The spec sheet gives a nominal value of 1.1 volts, 
  // but states that it can vary from 1.0 to 1.2 volts.
  // so we can adjust the percentage to correct,such as 1.1*1023*1000*(+-)0.98
  result = 1125000 / result; 
  return result; // Vcc in millivolts
}
