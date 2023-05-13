// simulation available at:
// https://www.tinkercad.com/things/bCjCtu62Cuk?sharecode=Plf-ZXaGDJ-LqEWLbOffL2znGO3aaFWOfGha7l0Ya5k
// https://www.tinkercad.com/things/jRBgmCrzyVv
// https://www.tinkercad.com/things/jfsTObKy3H1?sharecode=WYWmAnJfji2hvvPh6bh8fTshB2OoSxkLLzvz86VAjCc
// https://www.tinkercad.com/things/eV4MnQra2pg?sharecode=ldQoZB3S9tHJuOE5bPm81FX9TlYa7qftnP6FQRiVC1k  

void setup()
{
  // initialize
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // turn on
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  
  // turn off
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}