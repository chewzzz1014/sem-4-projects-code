// simulation available at https://www.tinkercad.com/things/1TOCRA0Jya0?sharecode=G5YKBPSgA9c1BtwJsrsxS1BGdAKUgr1CcRxyDjXnnLI

// emit SOS message in Morse Code every 5 seconds
// long dits: 1000 ms
// short dits: 500 ms
// interval between dits: 500ms
void setup()
{
  pinMode(10, OUTPUT);
}

void loop()
{
  // S (3 short dits)
  digitalWrite(10, HIGH); // first dit
  delay(500); 
  digitalWrite(10, LOW);
  delay(500); 
  digitalWrite(10, HIGH); // second dit
  delay(500); 
  digitalWrite(10, LOW);
  delay(500); 
  digitalWrite(10, HIGH); // third dit
  delay(500); 
  digitalWrite(10, LOW);
  delay(500); 
 
  // O (3 ling dits)
  digitalWrite(10, HIGH); // first dit
  delay(1000); 
  digitalWrite(10, LOW);
  delay(500); 
  digitalWrite(10, HIGH); // second dit
  delay(1000); 
  digitalWrite(10, LOW);
  delay(500); 
  digitalWrite(10, HIGH); // third dit
  delay(1000); 
  digitalWrite(10, LOW);
  delay(500); 
  
  // S (3 short dits)
  digitalWrite(10, HIGH); // first dit
  delay(500); 
  digitalWrite(10, LOW);
  delay(500); 
  digitalWrite(10, HIGH); // second dit
  delay(500); 
  digitalWrite(10, LOW);
  delay(500); 
  digitalWrite(10, HIGH); // third dit
  delay(500); 
  digitalWrite(10, LOW);
  delay(500); 
  
  // wait for 5 seconds
  digitalWrite(10, LOW);
  delay(5000); 
}