// CSC3700 Embedded Programming Group 6: Gesture Recognition 
#include <Wire.h>
#include <Arduino_KNN.h>
#include <LiquidCrystal_I2C.h>

// Registers for ADXL345
#define ADXL345_ADDRESS (0xA6 >> 1)
#define ADXL345_REGISTER_XLSB (0x32)

// LCD module connections (update the values according to your setup)
#define LCD_I2C_ADDR 0x27
#define LCD_COLS 16
#define LCD_ROWS 2

// Initialize LCD
LiquidCrystal_I2C lcd(LCD_I2C_ADDR, LCD_COLS, LCD_ROWS);

// Create a new KNNClassifier, input values are array of 3 (floats) for x, y, z coordinates
KNNClassifier classifier(3);
// Store accelerometer data
float sample[3];

// Reads data from the sensor's input register
void i2c_read(int address, byte reg, int count, byte* data) {
  Wire.beginTransmission(address);
  Wire.write(reg);
  Wire.endTransmission();

  Wire.beginTransmission(address);
  Wire.requestFrom(address, count);
  int i = 0;
  while (Wire.available()) {
    char c = Wire.read();
    data[i] = c;
    i++;
  }
  Wire.endTransmission();
}

// Writes data to the slave's buffer
void i2c_write(int address, byte reg, byte data) {

  // Send output register address
  Wire.beginTransmission(address);
  // Connect to device
  Wire.write(reg);
  // Send data
  Wire.write(data); //low byte
  Wire.endTransmission();
}

// Read accelerometer data and store into sample array
void read_adxl345() {
  byte bytes[6];
  memset(bytes,0,6);

  // Read 6 bytes from the ADXL345
  i2c_read(ADXL345_ADDRESS, ADXL345_REGISTER_XLSB, 6, bytes);
  // Unpack data
  for (int i=0;i<3;++i) {
    sample[i] = (int)bytes[2*i] + (((int)bytes[2*i + 1]) << 8);
  }
}

// Setup ADXL345 accelerometer
void init_adxl345() {
  byte data = 0;

  i2c_write(ADXL345_ADDRESS, 0x31, 0x0B);   // 13-bit mode  +_ 16g
  i2c_write(ADXL345_ADDRESS, 0x2D, 0x08);   // Power register


  i2c_write(ADXL345_ADDRESS, 0x1E, 0x00);   // x
  i2c_write(ADXL345_ADDRESS, 0x1F, 0x00);   // Y
  i2c_write(ADXL345_ADDRESS, 0x20, 0x05);   // Z
 
  // Check to see if it worked!
  i2c_read(ADXL345_ADDRESS, 0X00, 1, &data);
  if(data==0xE5)
    Serial.println("it work Success");
  else
    Serial.println("it work Fail");
}

// Setup LCD, train Arduino KNN model
void setup() {
  Wire.begin();
  Serial.begin(9600);
  while (!Serial);

  // Initialize the LCD
  lcd.begin();
  lcd.backlight();

  // Add training examples for directions
  float example1[] = {1000, 0, 0}; // Right
  float example2[] = {-1000, 0, 0}; // Left
  float example3[] = {0, 1000, 0}; // Up
  float example4[] = {0, -1000, 0}; // Down

  // Train data
  classifier.addExample(example1, 0); // Right (label: 0)
  classifier.addExample(example2, 1); // Left (label: 1)
  classifier.addExample(example3, 2); // Up (label: 2)
  classifier.addExample(example4, 3); // Down (label: 3)

  for(int i=0; i<3; ++i) {
   sample[i]  = 0;
  }
  init_adxl345();
}

void loop() {
  // Read accelerometer data from ADXL345
  read_adxl345();

  // Print the data
  Serial.println(String(sample[0]) + ", " + String(sample[1]) + ", " + String(sample[2]));

  // Predict the label using k-NN algorithm
  int predictedLabel = classifier.classify(sample);

  // Print the predicted direction on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  if (predictedLabel == 0)
    lcd.print("Direction: Right");
  else if (predictedLabel == 1)
    lcd.print("Direction: Left");
  else if (predictedLabel == 2)
    lcd.print("Direction: Up");
  else if (predictedLabel == 3)
    lcd.print("Direction: Down");

  delay(1000);
}