/*
  SimpleKNN

  This example demonstrates how to use the Arduino KNN library.

  It creates a KNN classifier that expects an input array of 2 (floats).
  Then adds 4 example inputs with their respective classifications.
  After this it demonstrates how to classify an input value and get
  the classifications confidence.

  This example code is in the public domain.
*/
#include <string>
#include <Arduino_KNN.h>

// Create a new KNNClassifier, input values are array of N (floats),
KNNClassifier myKNN(3);

void setup() {
 // **************************** SETUP *********************************
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Simple KNN");
  Serial.println();

  Serial.print("Adding examples to myKNN ... ");
  Serial.println();


// ************************* DEFINE CLASSESS ************************
string directions[] = {"left", "right", "up", "down"};



// **************************** DATA *********************************
float left[45][3] = {
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
        {0.07, 0.12, 1.09},
        {0.00, 0.09, 1.04},
        {0.01, 0.11, 1.06},
        {0.01, 0.11, 1.08},
        {0.03, 0.11, 1.04},
        {0.01, 0.09, 1.05},
        {0.07, 0.12, 1.10},
        {0.03, 0.09, 1.06},
        {-0.02, 0.19, 1.05},
        {-0.01, 0.27, 1.06},
        {-0.08, 0.23, 1.02},
        {-0.07, 0.27, 1.06},
        {-0.10, 0.24, 1.03},
        {-0.10, 0.24, 1.04},
        {-0.10, 0.24, 1.05},
        {-0.11, 0.23, 1.03},
        {-0.12, 0.21, 1.01},
        {-0.12, 0.23, 1.02},
        {-0.09, 0.24, 1.02},
        {-0.08, 0.25, 1.04},
        {-0.10, 0.23, 1.04},
        {-0.09, 0.21, 1.01},
        {-0.11, 0.25, 1.04},
        {-0.12, 0.24, 1.04},
        {-0.10, 0.25, 1.03},
        {-0.12, 0.24, 1.03},
        {-0.11, 0.23, 1.02}
    };

  float right[99][3] = {
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
        {0.49, 0.14, 0.99},
        {0.50, 0.12, 0.98},
        {0.48, 0.12, 0.98},
        {0.48, 0.14, 1.01},
        {0.47, 0.12, 0.98},
        {0.46, 0.11, 1.03},
        {0.39, 0.08, 1.01},
        {0.41, 0.09, 0.98},
        {0.39, 0.09, 1.01},
        {0.42, 0.08, 0.98},
        {0.43, 0.11, 1.02},
        {0.38, 0.07, 1.03},
        {0.43, 0.11, 0.97},
        {0.43, 0.10, 1.03},
        {0.42, 0.11, 1.03},
        {0.45, 0.11, 1.01},
        {0.44, 0.11, 1.01},
        {0.41, 0.07, 0.98},
        {0.40, 0.10, 0.98},
        {0.39, 0.09, 1.04},
        {0.41, 0.07, 1.02},
        {0.43, 0.12, 1.02},
        {0.42, 0.08, 1.05},
        {0.35, 0.06, 1.02},
        {0.40, 0.05, 0.99},
        {0.40, 0.07, 1.02},
        {0.44, 0.08, 1.01},
        {0.25, 0.11, 1.04},
        {0.25, 0.11, 1.07},
        {0.25, 0.11, 1.07},
        {0.27, 0.11, 1.05},
        {0.25, 0.12, 1.06},
        {0.26, 0.11, 1.05},
        {0.25, 0.11, 1.06},
        {0.26, 0.11, 1.06},
        {0.25, 0.11, 1.06},
        {0.27, 0.11, 1.05},
        {0.27, 0.12, 1.05},
        {0.27, 0.11, 1.04},
        {0.27, 0.12, 1.08},
        {0.28, 0.11, 1.05},
        {0.30, 0.12, 1.05},
        {0.30, 0.11, 1.05},
        {0.28, 0.11, 1.06},
        {0.29, 0.12, 1.04},
        {0.29, 0.11, 1.07},
        {0.29, 0.11, 1.05},
        {0.29, 0.12, 1.05},
        {0.29, 0.12, 1.05},
        {0.30, 0.10, 1.06},
        {0.29, 0.10, 1.03},
        {0.29, 0.12, 1.04},
        {0.28, 0.11, 1.05},
        {0.30, 0.11, 1.08},
        {0.29, 0.11, 1.05},
        {0.29, 0.11, 1.06},
        {0.30, 0.11, 1.04},
        {0.29, 0.12, 1.05},
        {0.30, 0.12, 1.05},
        {0.29, 0.12, 1.02},
        {0.33, 0.10, 1.03},
        {0.13, 0.13, 1.13},
        {0.08, 0.07, 1.06},
        {0.05, 0.03, 1.06},
        {0.05, 0.06, 1.06},
        {0.02, 0.06, 1.09},
        {0.00, 0.03, 1.09},
        {0.03, 0.04, 1.07},
        {0.05, 0.07, 1.08},
        {0.03, 0.04, 1.07},
        {0.01, 0.05, 1.09},
        {0.03, 0.05, 1.06},
        {0.04, 0.05, 1.06},
        {0.02, 0.05, 1.08},
        {0.02, 0.04, 1.08},
        {0.03, 0.05, 1.08},
        {0.01, 0.04, 1.07},
        {0.02, 0.04, 1.08},
        {0.02, 0.05, 1.07},
        {0.04, 0.04, 1.08},
        {0.03, 0.04, 1.08}
    };

  float up[79][3] = {
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
    {-0.45, 0.81, 0.40},
    {-0.43, 0.79, 0.42},
    {-0.44, 0.79, 0.41},
    {-0.43, 0.80, 0.43},
    {-0.45, 0.78, 0.44},
    {-0.45, 0.79, 0.41},
    {-0.42, 0.80, 0.43},
    {-0.43, 0.80, 0.42},
    {-0.44, 0.79, 0.42},
    {-0.44, 0.79, 0.41},
    {-0.43, 0.78, 0.42},
    {-0.41, 0.78, 0.43},
    {-0.42, 0.79, 0.40},
    {-0.44, 0.78, 0.40},
    {-0.43, 0.78, 0.40},
    {-0.43, 0.80, 0.42},
    {-0.44, 0.77, 0.42},
    {-0.43, 0.78, 0.43},
    {-0.44, 0.78, 0.42},
    {-0.46, 0.80, 0.42},
    {-0.46, 0.78, 0.42},
    {-0.45, 0.78, 0.41},
    {-0.46, 0.78, 0.42},
    {-0.12, 0.97, 0.07},
    {-0.13, 0.89, -0.16},
    {-0.16, 0.89, -0.26},
    {-0.21, 0.89, -0.25},
    {-0.24, 0.87, -0.25},
    {-0.22, 0.89, -0.35},
    {-0.29, 0.86, -0.25},
    {-0.06, 0.83, -0.31},
    {-0.24, 0.87, -0.48},
    {-0.19, 0.83, -0.43},
    {-0.18, 0.82, -0.38},
    {-0.17, 0.82, -0.38},
    {-0.20, 0.81, -0.37},
    {-0.18, 0.80, -0.40},
    {-0.20, 0.80, -0.43},
    {-0.20, 0.80, -0.43},
    {-0.21, 0.82, -0.43},
    {-0.17, 0.80, -0.42},
    {-0.20, 0.82, -0.42},
    {-0.17, 0.81, -0.41},
    {0.40, 0.97, 0.02},
    {0.34, 0.96, 0.06},
    {0.34, 0.94, 0.03},
    {0.37, 0.95, 0.05},
    {0.36, 0.95, 0.07},
    {0.35, 0.94, 0.05},
    {0.36, 0.96, 0.07},
    {0.36, 0.95, 0.06},
    {0.36, 0.95, 0.07},
    {0.36, 0.96, 0.07},
    {0.36, 0.96, 0.08},
    {0.36, 0.96, 0.07},
    {0.35, 0.96, 0.07},
    {0.38, 0.96, 0.08},
    {0.37, 0.96, 0.08},
    {0.35, 0.95, 0.05},
    {0.36, 0.96, 0.08},
    {0.38, 0.96, 0.06}
};



// **************************** TRAIN MODEL ****************************

// add examples to KNN
//   float example1[] = { 7.0, 7.0 };
//   float example2[] = { 5.0, 5.0 };
//   float example3[] = { 9.0, 9.0 };
//   float example4[] = { 5.0, 5.0 };

//   myKNN.addExample(example1, 7); // add example for class 7
//   myKNN.addExample(example2, 5); // add example for class 5
//   myKNN.addExample(example3, 9); // add example for class 9
//   myKNN.addExample(example4, 5); // add example for class 5 (again)
for (int i=0; i<left.length; i++) {
    myKNN.addExample(left[i], 0);
}

for (int i=0; i<right.length; i++) {
  myKNN.addExample(right[i], 1);
}

for (int i=0; i<up.length; i++) {
  myKNN.addExample(up[i], 2);
}

for (int i=0; i<down.length; i++) {
  myKNN.addExample(down[i], 3);
}



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

  float input[] = { 3.0, 3.0 };

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