// simulation available at https://www.tinkercad.com/things/jfsTObKy3H1?sharecode=WYWmAnJfji2hvvPh6bh8fTshB2OoSxkLLzvz86VAjCc

// to read anolog input from physical device
void setup()
{
  // begin serial communication at 9600 bits of data per second
  Serial.begin(9600);
}

void loop()
{
  // store resistance value (0-1023) coming from potentiometer
  // analog input 0
  int sensorValue = analogRead(A0);
  
  // print resistance value
  Serial.println(sensorValue, DEC);
}