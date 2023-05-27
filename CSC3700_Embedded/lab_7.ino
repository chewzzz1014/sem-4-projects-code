//Lab7

//pins of 74HC595
int latchPin = 8;     
int clockPin = 12;    
int dataPin = 11;      

// Variable - indicates LEDs turned on or off
byte leds = 0;      

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop()
{
  for (int i = 0; i <= 255; i++) {
    // Convert decimal value to binary pattern
    leds = byteToBinary(i);  
    // Update the shift register with new LED pattern
    updateShiftRegister();
    delay(200);
  }
}


//sets the latchPin to low, 
//then calls the Arduino function 'shiftOut' 
//to shift out contents of variable 'leds' 
//then, sets the latchPin high
void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}

//converts a decimal value to a binary pattern
byte byteToBinary(int value) {
  byte result = 0;

  // Loop through each bit position
  for (int i = 0; i < 8; i++) {
    // Determine the bit value at current position
    int bitValue = bitRead(value, i);

    // Set the corresponding bit in the result
    // Invert the bit position to match the wiring
    bitWrite(result, 7 - i, bitValue);  

  }

  return result;
}
