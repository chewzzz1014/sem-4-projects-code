// simulation available at https://www.tinkercad.com/things/jVLd3DLSacx?sharecode=4lDvhdNXSKB-Sl7jB5semV_fESwPPVzvtD-6WYzYLPA

// C++ code
// LED chase effect using an array of LEDs

byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
void setup()
{
  for(int i=0; i<10; i++){
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop()
{
  // left to right
  for(int i=9; i>=0; i--){
    // blink the selected led
    digitalWrite(ledPin[i], HIGH);
    delay(500); 
    digitalWrite(ledPin[i], LOW);
    delay(300); 
  }
  
  // right to left
  for(int i=0; i<10; i++){
    // blink the selected led
    digitalWrite(ledPin[i], HIGH);
    delay(500); 
    digitalWrite(ledPin[i], LOW);
    delay(300); 
  }
}