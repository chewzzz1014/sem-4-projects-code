// read temperature and lights up LED based on temp range
const int TMP_PIN = A0;
const int LED_1 = 4;
const int LED_2 = 3;
const int LED_3 = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
}

void loop()
{
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
  
  // input value
  int value = analogRead(TMP_PIN);

  // convert input to volt
  float volt = (value * 5.0) / 1023.0;

  // convert volt to celcius
  float temp = (volt - 0.5) * 100;

  if(temp >= 60){ 
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
  } else if (temp <= 59 && temp >= 50){
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
  } else {
    digitalWrite(LED_3, HIGH);
  }
}