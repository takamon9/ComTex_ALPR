#ifndef __NEURALNETWORK_H_INCLUDED__
#define __NEURALNETWORK_H_INCLUDED__

#include <iostream>
#include <opencv2\opencv.hpp>
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

int num[5] = { num[0], num[1], num[2], num[3], num[4] };


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
int detectedNum[] = { 0, 1, 2, 3, 4, 5 };

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


void matrixArray(Mat matrixName, string fileN)
{
	fstream inFile;
	stringstream fn;
	Mat resizedMat;

	resize(matrixName, resizedMat, cv::Size(size_X, size_Y));

	fn << "./dat/" << fileN << ".dat";
	inFile.open(fn.str(), ios::out | ios::trunc); inFile.close(); //delete contents
	inFile.open(fn.str(), ios::in | ios::app | ios::binary);

	for (int i = 0; i < resizedMat.rows; i++) {
		for (int j = 0; j < resizedMat.cols; j++) {
			inFile << (int)(resizedMat.at<uchar>(i, j)) / 255;
		}
	}
	inFile.close();
}


void processNeuralNetwork()

{

	num[0] = 0;
	num[1] = 0;
	num[2] = 0;
	num[3] = 0;
	num[4] = 0;


	for (int i = 0; i < commPlate.size(); i++)
	{

		number[0] = 0;
		number[1] = 0;
		number[2] = 0;
		number[3] = 0;

		//t = time(NULL);
		cv::Point pt1(commPlate[i].x + commPlate[i].width, commPlate[i].y + commPlate[i].height);
		cv::Point pt2(commPlate[i].x, commPlate[i].y);
		rectangle(image, pt1, pt2, colorNum, 2, 8, 0);

		Mat NumberPlate(original, Rect(pt1, pt2));
		resize(NumberPlate, resizedNP, cv::Size(200, 100), 1.0, 1.0, INTER_LINEAR);
		cvtColor(resizedNP, resizedMat, CV_32S);
		cvtColor(resizedNP, grayNP, CV_BGR2GRAY);

		//	strftime(fname, sizeof(fname), "C:/ImageStorage/commercialNP/commNP_%y%m_%d_%H_%M_%S.png", localtime(&t));
		//	imwrite(fname, grayNP);
		//	count++;
		//	cout << "We got Commercial Number Plate.No." << count << endl;

		Mat binaryNP, cannyNP;

		threshold(grayNP, binaryNP, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);
		Canny(binaryNP, cannyNP, 3, 3);

		vector<vector<cv::Point> > contours;
		findContours(cannyNP, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
		Rect pointArea[200];
		contoursMat = resizedNP.clone();
		int count = 0;
		sort_struct sortA[10];

		vector<sort_struct> sortArray;
		
		for (int i = 0; i < contours.size(); i++)
		{
			pointArea[i] = boundingRect(contours[i]);
			double contourRatio = (float)pointArea[i].width / pointArea[i].height;
			if ((contourRatio > 0.4  && contourRatio < 0.6 && pointArea[i].height > 30 && pointArea[i].height < 55) || (contourRatio > 0.11 && contourRatio < 0.22 && pointArea[i].height > 30 && pointArea[i].height < 55))
			{
				Rect wideArea = pointArea[i];
				wideArea.x -= 3;
				wideArea.width += 6;
				wideArea.y -= 3;
				wideArea.height += 6;

				if (wideArea.x < 0 || wideArea.y < 0 || wideArea.x + wideArea.width > contoursMat.cols || wideArea.y + wideArea.height > contoursMat.rows){
					wideArea.x += 3;
					wideArea.width -= 6;
					wideArea.y += 3;
					wideArea.height -= 6;
				}

				if (contourRatio > 0.11 && contourRatio < 0.22 && pointArea[i].height > 30 && pointArea[i].height < 55){
					wideArea.x -= wideArea.width/2;
					wideArea.width += wideArea.width;
					if (wideArea.x < 0 || wideArea.y < 0 || wideArea.x + wideArea.width > contoursMat.cols || wideArea.y + wideArea.height > contoursMat.rows){
						sortA[count] = { pointArea[i].x, Mat(binaryNP, pointArea[i]) };

					}else{
						rectangle(contoursMat, wideArea, Scalar(0, 255, 0), 1);
						sortA[count] = { pointArea[i].x, Mat(binaryNP, wideArea) };
					}
				}

				else{
					rectangle(contoursMat, wideArea, Scalar(0, 255, 0), 1);
					sortA[count] = { pointArea[i].x, Mat(binaryNP, wideArea) };
				}
				
				sortArray.push_back(sortA[count]);
				count++;
			}
		}

		sort(sortArray.begin(), sortArray.end(),
			[](const sort_struct& a, const sort_struct& b) {return a.xLocation > b.xLocation; });

		for (int i = 0; i < sortArray.size(); i++) {
			if (i > 3) {
				break;
			}
			//	stringstream nameImgFile;
			//	nameImgFile << "img/num/left" << i << ".png";
			//	imwrite(nameImgFile.str(), sortArray[i].numRect);
			stringstream nameMatWindow;
			nameMatWindow << "num" << i;
			//	imshow(nameMatWindow.str(), sortArray[i].numRect);
			//	cout << sortArray[i].xLocation << ",";
			matrixArray(sortArray[i].numRect, nameMatWindow.str());

			Mat  result;
			cv::Point maxLocationResult;

			stringstream detectNum;
			detectNum << "./dat/" << nameMatWindow.str() << ".dat";

			ifstream ifs;
			ifs.open(detectNum.str(), ios::in | ios::binary);

			Mat binaryNumMat = Mat(cv::Size(N_INPUT, 1), CV_32F);

			for (int y = 0; y < 1; y++){
				for (int x = 0; x < N_INPUT; x++){
					char moji;
					int number;

					ifs.get(moji);
					number = atoi(&moji);
					//cout << number;

					if (number == 0) binaryNumMat.at<float>(y, x) = 0.0f;
					else binaryNumMat.at<float>(y, x) = 1.0f;
				}
			}

			ifs.close();

			neuron->predict(binaryNumMat, result);
			minMaxLoc(result, NULL, NULL, NULL, &maxLocationResult);

			stringstream ss;
			ss << maxLocationResult.x;

			detectedNumber = ss.str();
			detectedNum[i] = maxLocationResult.x;
			num[i] = maxLocationResult.x;
			putText(number[i], detectedNumber, cv::Point(point4, numHight), CV_FONT_HERSHEY_SIMPLEX, numScale, Scalar(0, 255, 0), numThik, 8);

		}

		vector<Mat> number_array{ number[3], number[2], number[1], number[0] };
		hconcat(number_array, concatnated);

	}
	
}



#endif