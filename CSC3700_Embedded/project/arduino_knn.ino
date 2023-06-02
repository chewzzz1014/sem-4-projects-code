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
float left[43][3] = {
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