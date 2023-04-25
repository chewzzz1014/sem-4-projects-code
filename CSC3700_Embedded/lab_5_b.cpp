// volume control set using analogWrite
// volume is determined by value of potentiometer

const int speakerPin = 9; 
int volume = 0;

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  // read the volume level from a potentiometer
  volume = analogRead(A0) / 4; // normalize to range 0-255 
  
  // set the volume using PWM on the speaker pin
  analogWrite(speakerPin, volume);
  
  delay(10);
}