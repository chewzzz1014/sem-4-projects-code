// simulation available at https://www.tinkercad.com/things/eV4MnQra2pg?sharecode=ldQoZB3S9tHJuOE5bPm81FX9TlYa7qftnP6FQRiVC1k

int led = 13;

void setup()
{
  pinMode(led, OUTPUT);
}

void loop()
{
  digitalWrite(led, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(led, LOW);
  delay(3000); // Wait for 3000 millisecond(s)
}