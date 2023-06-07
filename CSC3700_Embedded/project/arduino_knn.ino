// import library for ADXL345 accelerometer, Arduino KNN and LCM1602 LCD
#include <Arduino_KNN.h>
#include <Arduino.h>
#include <Wire.h>
#define ADXL345_ADDRESS (0xA6 >> 1) 
#define ADXL345_REGISTER_XLSB (0x32)

// store data from sensor
float accelerometer_data[3];
// Create a new KNNClassifier, input values are array of N (floats),
KNNClassifier myKNN(3);
// data for training model
float left[20][3] = {
        {0.05, -0.17, 1.06},
        {0.05, -0.17, 1.06},
        {0.05, -0.16, 1.06},
        {0.05, -0.17, 1.06},
        {0.05, -0.16, 1.06},
        {0.05, -0.16, 1.06},
        {0.04, -0.17, 1.06},
        {0.06, -0.17, 1.05},
        {0.06, -0.16, 1.05},
        {0.05, -0.18, 1.06},
        {0.05, -0.16, 1.06},
        {0.04, -0.18, 1.07},
        {0.04, -0.17, 1.06},
        {-0.06, -0.05, 1.20},
        {0.06, 0.10, 1.00},
        {0.11, 0.11, 1.16},
        {0.05, 0.09, 1.01},
        {0.10, 0.15, 1.05},
        {0.14, 0.14, 1.08},
        {0.07, 0.12, 1.09}
    };

  float right[20][3] = {
        {0.12, 0.12, 1.05},
        {0.11, 0.13, 1.05},
        {0.09, 0.15, 1.07},
        {0.06, 0.13, 1.06},
        {0.10, 0.15, 1.07},
        {0.02, 0.11, 1.07},
        {0.04, 0.15, 1.06},
        {0.04, 0.12, 1.06},
        {0.01, 0.11, 1.05},
        {0.05, 0.12, 1.07},
        {0.02, 0.13, 1.08},
        {0.05, 0.14, 1.05},
        {0.05, 0.12, 1.09},
        {0.04, 0.14, 1.08},
        {0.07, 0.14, 1.07},
        {0.42, 0.09, 0.98},
        {0.58, 0.14, 0.91},
        {0.49, 0.09, 0.94},
        {0.49, 0.14, 1.01},
        {0.49, 0.14, 0.99}
    };

  float up[20][3] = {
    {-0.17, 0.97, 0.13},
    {-0.16, 0.99, 0.11},
    {-0.18, 0.99, 0.12},
    {-0.16, 0.98, 0.12},
    {-0.15, 0.98, 0.11},
    {-0.18, 0.98, 0.13},
    {-0.16, 0.97, 0.12},
    {-0.18, 0.98, 0.12},
    {-0.17, 0.98, 0.12},
    {-0.18, 0.98, 0.11},
    {-0.18, 0.97, 0.12},
    {-0.18, 0.98, 0.12},
    {-0.19, 0.98, 0.13},
    {-0.18, 0.97, 0.13},
    {-0.43, 0.79, 0.42},
    {-0.44, 0.78, 0.40},
    {-0.41, 0.79, 0.39},
    {-0.43, 0.80, 0.43},
    {-0.43, 0.80, 0.43},
    {-0.45, 0.81, 0.40}
};

float down[20][3] = {
    {-0.02,-0.93,0.37},
    {-0.01,-0.94,0.40},
    {-0.00,-0.94,0.42},
    {-0.00,-0.94,0.44},
    {0.00,-0.95,0.43},
    {0.00,-0.94,0.43},
    {0.00,-0.94,0.42},
    {-0.01,-0.93,0.41},
    {-0.01,-0.94,0.42},
    {-0.00,-0.94,0.43},
    {-0.01,-0.94,0.43},
    {-0.02,-0.93,0.42},
    {-0.04,-0.91,0.41},
    {-0.04,-0.91,0.39},
    {-0.01,-0.94,0.43},
    {-0.01,-0.94,0.43},
    {-0.00,-0.94,0.43},
    {-0.02,-0.93,0.42},
    {-0.03,-0.92,0.41},
    {-0.03,-0.93,0.43}
};
// define prediction classes
String directions[] = {"left", "right", "up", "down"};

// train arduino knn model. Each direction has 20 data
// 0=left; 1=right; 2=up; 3=down;
void trainModel() {
  // int numRowsLeft = sizeof(left) / sizeof(left[0]);
  for (int i=0; i<20; i++) {
      myKNN.addExample(left[i], 0);
  }
  for (int i=0; i<20; i++) {
    myKNN.addExample(right[i], 1);
  }
  for (int i=0; i<20; i++) {
    myKNN.addExample(up[i], 2);
  }
  for (int i=0; i<20; i++) {
    myKNN.addExample(down[i], 3);
  }
}

// writes data to the slave's buffer
void i2c_write(int address, byte reg, byte data) {
  // Send output register address
  Wire.beginTransmission(address);
  // Connect to device
  Wire.write(reg);
  // Send data
  Wire.write(data); //low byte
  Wire.endTransmission();
}

// microcontroller reads data from the sensor's input register
void i2c_read(int address, byte reg, int count, byte* data) {
  // Used to read the number of data received
  int i = 0;
  // Send input register address
  Wire.beginTransmission(address);
  // Connect to device
  Wire.write(reg);
  Wire.endTransmission();
  // Connect to device
  Wire.beginTransmission(address);
  // Request data from slave
  // Count stands for number of bytes to request
  Wire.requestFrom(address, count);
  while(Wire.available()) // slave may send less than requested
  {
    char c = Wire.read(); // receive a byte as character
    data[i] = c;
    i++;
  }
  Wire.endTransmission();
}

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

void read_adxl345() {
  byte bytes[6];
  memset(bytes,0,6);
  // Read 6 bytes from the ADXL345
  i2c_read(ADXL345_ADDRESS, ADXL345_REGISTER_XLSB, 6, bytes);
  // Unpack data
  for (int i=0;i<3;++i) {
    accelerometer_data[i] = (int)bytes[2*i] + (((int)bytes[2*i + 1]) << 8);
  }
}

void setup() {
  Serial.begin(9600);

  // start arduino knn training
  while (!Serial); 
  trainModel();
  Serial.print("\tmyKNN.getCount() = ");
  Serial.println(myKNN.getCount());
  Serial.println();

  // setup ADXL345  
  Wire.begin();
  Serial.begin(9600);
  for(int i=0; i<3; ++i) {
    accelerometer_data[i]  = 0;
  }
}

void loop() {
  // PART 1: Read Data From Sensor
  Serial.println("Reading data from sensor ...");
  read_adxl345();
  // normalize data
  for (int i=0; i<3; i++) {
    accelerometer_data[i] = float(accelerometer_data[i])*3.9/1000;
  }


  // PART 2: Make Prediction
  Serial.println("Classifying input ...");

  int classification = myKNN.classify(accelerometer_data, 3); // classify input with K=3
  float confidence = myKNN.confidence(); // get confidence score

  Serial.print("\tclassification = ");
  Serial.println(classification);

  // since there are 2 examples close to the input and K = 3,
  // expect the confidence to be: 2/3 = ~0.67
  Serial.print("\tconfidence     = ");
  Serial.println(confidence);

  // PART 3: Display prediction result to LCD
  // TODO

  delay(5000); // at every 5s interval
}