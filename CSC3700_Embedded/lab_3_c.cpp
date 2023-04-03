// simulation available at https://www.tinkercad.com/things/2aNhVSX1XmL?sharecode=d3txOwnwvQFrvz4MiCiVfNsYN24MaFHmtOpw6lamzp4

// C++ code
// simulating 4-state traffic light system

// initialize variables 
int RED = 10;
int YELLOW = 9;
int GREEN = 8;

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop()
{ 
  // green -> yellow -> red
  digitalWrite(GREEN, HIGH);
  delay(500);
  digitalWrite(GREEN, LOW);
  delay(500); 
  digitalWrite(YELLOW, HIGH);
  delay(500);
  digitalWrite(YELLOW, LOW);
  delay(500); 
  digitalWrite(RED, HIGH);
  delay(500);
  digitalWrite(RED, LOW);
  delay(500); 
  
  // wait for some time
  delay(1000);
  
  // red -> yellow -> green
  digitalWrite(RED, HIGH);
  delay(500);
  digitalWrite(RED, LOW);
  delay(500);
  digitalWrite(YELLOW, HIGH);
  delay(500); 
  digitalWrite(YELLOW, LOW);
  delay(500); 
  digitalWrite(GREEN, HIGH);
  delay(500);
  digitalWrite(GREEN, LOW);
  delay(500);  
  
  // wait for some time
  delay(1000);
}