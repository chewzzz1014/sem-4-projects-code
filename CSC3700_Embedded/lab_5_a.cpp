// play simple melody at 200ms interval
#define PIN 9
#define c 3830 // 261 Hz
#define d 3400 // 294 Hz
#define e 3038 // 329 Hz
#define f 2864 // 349 Hz
#define g 2550 // 392 Hz
#define a 2272 // 440 Hz
#define b 2028 // 493 Hz
#define C 1912 // 523 Hz
// Define a special note, 'R', to represent a rest
#define R 0

void setup() {
  pinMode(PIN, OUTPUT);
}

void loop() {
  // Play the first phrase
  tone(PIN, c, 200);
  delay(200);
  tone(PIN, R, 200);
  delay(200);
  
  tone(PIN, d, 200);
  delay(200);
  tone(PIN, R, 200);
  delay(200);
  
  tone(PIN, e, 200);
  delay(200);
  tone(PIN, R, 200);
  delay(200);
  
  tone(PIN, f, 200);
  delay(200);
  tone(PIN, R, 200);
  delay(200);
  
  tone(PIN, g, 200);
  delay(200);
  tone(PIN, R, 200);
  delay(200);
  
  tone(PIN, a, 200);
  delay(200);
  tone(PIN, R, 200);
  delay(200);
  
  tone(PIN, b, 200);
  delay(200);
  tone(PIN, R, 200);
  delay(200);
  
  tone(PIN, c, 200);
  delay(200);
  tone(PIN, R, 200);
  delay(200);

  // Pause for a second before repeating the melody
  delay(1000);
}
