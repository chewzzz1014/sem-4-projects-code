// simulation available at https://www.tinkercad.com/things/6T3qW2S7dtB?sharecode=WYesBwJB37BQekY4gYT__fLs-79u8A8HvHYHs27wFCw

// LED chase effect using an array of LEDs
// blink interval is determined by potentiometer value

byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int sensorValue;

void setup()
{
  // pinMode for every led
  for(int i=0; i<10; i++){
    pinMode(ledPin[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop()
{
  // left to right
  for(int i=9; i>=0; i--){
    // read potentiometer value
    sensorValue = analogRead(A2);
    
    // blink the selected led
    digitalWrite(ledPin[i], HIGH);
    delay(sensorValue); 
    digitalWrite(ledPin[i], LOW);
    delay(sensorValue); 
  }
  
  
  // right to left
  for(int i=0; i<10; i++){
    // read potentiometer value
    sensorValue = analogRead(A2);
    
    // blink the selected led
    digitalWrite(ledPin[i], HIGH);
    delay(sensorValue); 
    digitalWrite(ledPin[i], LOW);
    delay(sensorValue); 
  }
  
}