#ifndef __PROGRMHEADER_H_INCLUDED__
#define __PROGRMHEADER_H_INCLUDED__

#include <iostream>
#include <opencv2/opencv.hpp>
#include <fstream>
#include <vector>
#include <time.h>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace cv;
using namespace std;
using namespace ml;

int numInt[4] = { numInt[0], numInt[1], numInt[2], numInt[3] };

char fname[100];
Scalar colorNum(0, 255, 0);
Scalar colorComm(255, 255, 0);

Mat grayNP;
Mat cropNumberPlate, commercialPlate;
Mat original, gray, number[4];
Mat image = Mat(640, 480, CV_32S);
Mat resizedNP;
Mat concatnated = Mat(200, 50, CV_32S);
Mat contoursMat(200, 100, CV_32S);
Mat matrix32s;
Mat binaryNP, cannyNP;
Mat resizedMat = Mat(200, 100, CV_32S);

int checkStopKey = 0;
//int detectedNum[] = { 0, 1, 2, 3, 4, 5 };

Mat neuralMat;
Mat teacher;

vector<Rect> commPlate;
VideoCapture capture;
CascadeClassifier general700_cascade;
Ptr<ANN_MLP> neuron;

//time_t t;

int size_X = 10;
int size_Y = 20;
int N_INPUT = size_X * size_Y;

string detectedNumber;

float numScale = 1.0;
int numThik = 2;
int point4 = 20;
int numHight = 35;
int numArrWidth = 50;
int numArrHight = 50;


struct sort_struct {
	int xLocation;
	Mat numRect;
};
#endif
