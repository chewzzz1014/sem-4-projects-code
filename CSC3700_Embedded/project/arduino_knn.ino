// import library for ADXL345 accelerometer, Arduino KNN and LCM1602 LCD
#include <Arduino_KNN.h>
#include <Arduino.h>
#include <Wire.h>
#define ADXL345_ADDRESS (0xA6 >> 1) 
#define ADXL345_REGISTER_XLSB (0x32)

// store data from sensor
int accelerometer_data[3];
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

void setup() {
 // **************************** SETUP *********************************
  Serial.begin(9600);
  while (!Serial);


// **************************** TRAIN MODEL ****************************

// add examples to KNN
//   float example1[] =    {7.0, 7.0 };
//   float example2[] = { 5.0, 5.0 };
//   float example3[] = { 9.0, 9.0 };
//   float example4[] = { 5.0, 5.0 };

//   myKNN.addExample(example1, 7); // add example for class 7
//   myKNN.addExample(example2, 5); // add example for class 5
//   myKNN.addExample(example3, 9); // add example for class 9
//   myKNN.addExample(example4, 5); // add example for class 5 (again)



// ************************* PRINT OUT KNN COUNT *******************************
  // get and print out the KNN count
  Serial.print("\tmyKNN.getCount() = ");
  Serial.println(myKNN.getCount());
  Serial.println();

  // you can also print the counts by class
  //  Serial.print("\tmyKNN.getCountByClass(5) = ");
  //  Serial.println(myKNN.getCountByClass(5)); // expect 2




  // ************************ MAKE PREDICTION ************************************
  Serial.println("Classifying input ...");

 // predict incoming sensor data
  float input[] = { 1.3, 0.2, -0.98 };

  int classification = myKNN.classify(input, 3); // classify input with K=3
  float confidence = myKNN.confidence();

  // print the classification and confidence
  Serial.print("\tclassification = ");
  Serial.println(classification);

  // since there are 2 examples close to the input and K = 3,
  // expect the confidence to be: 2/3 = ~0.67
  Serial.print("\tconfidence     = ");
  Serial.println(confidence);
}

void loop() {
  // do nothing
}