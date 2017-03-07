#ifndef __NEURALNETWORK_H_INCLUDED__
#define __NEURALNETWORK_H_INCLUDED__

#include "preFunction.h"

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

cli::array<System::String^>^ arrayTotimestamp() {
	time_t timer = time(0);
	struct tm *timeStruct = localtime(&timer);
	int year = timeStruct->tm_year + 1900;
	int month = timeStruct->tm_mon + 1;
	int day = timeStruct->tm_mday;
	int hour = timeStruct->tm_hour;
	int minute = timeStruct->tm_min;
	int second = timeStruct->tm_sec;

	stringstream dateSS, intSS;
	dateSS << year << "/" << setw(2) << setfill('0') << month << "/" << setw(2) << setfill('0') << day << "," << setw(2) << setfill('0') << hour << ";" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second;
	string getDate = dateSS.str();
	System::String^ timeStamp = gcnew System::String(getDate.c_str());
	intSS << numInt[3] << numInt[2] << numInt[1] << numInt[0];
	string integerSS = intSS.str();
	System::String^ numberN = gcnew System::String(integerSS.c_str());
	cli::array<System::String^>^ rows0 = gcnew cli::array<System::String^>{timeStamp, numberN};
	return rows0;
}

void dataToDGV(System::Windows::Forms::DataGridView^ dgvName) {
	DataGridViewRowCollection^ timestampRows = dgvName->Rows;
	timestampRows->Add(arrayTotimestamp());
}

void processNeuralNetwork(System::Windows::Forms::DataGridView^ nameGridView, System::Windows::Forms::PictureBox^ picbox1, System::Windows::Forms::PictureBox^ picbox2)
{
	for (int i = 0; i < commPlate.size(); i++)
	{
		numInt[0] = NULL;
		numInt[1] = NULL;
		numInt[2] = NULL;
		numInt[3] = NULL;

		number[0] = 0;
		number[1] = 0;
		number[2] = 0;
		number[3] = 0;

		//t = time(NULL);
		cv::Point pt1(commPlate[i].x + commPlate[i].width, commPlate[i].y + commPlate[i].height);
		cv::Point pt2(commPlate[i].x, commPlate[i].y);
		rectangle(image, pt1, pt2, colorNum, 2, 8, 0);

		originalNumberPlate = Mat(original, Rect(pt1, pt2));

		//developmentFunction_2(originalNumberPlate);

		resize(originalNumberPlate, resizedNP, cv::Size(200, 100), 1.0, 1.0, INTER_LINEAR);
		cvtColor(resizedNP, resizedMat, CV_32S);
		cvtColor(resizedNP, grayNP, CV_BGR2GRAY);

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

				if (wideArea.x < 0 || wideArea.y < 0 || wideArea.x + wideArea.width > contoursMat.cols || wideArea.y + wideArea.height > contoursMat.rows) {
					wideArea.x += 3;
					wideArea.width -= 6;
					wideArea.y += 3;
					wideArea.height -= 6;
				}

				if (contourRatio > 0.11 && contourRatio < 0.22 && pointArea[i].height > 30 && pointArea[i].height < 55) {
					wideArea.x -= wideArea.width / 2;
					wideArea.width += wideArea.width;
					if (wideArea.x < 0 || wideArea.y < 0 || wideArea.x + wideArea.width > contoursMat.cols || wideArea.y + wideArea.height > contoursMat.rows) {
						sortA[count] = { pointArea[i].x, Mat(binaryNP, pointArea[i]) };

					}
					else {
						rectangle(contoursMat, wideArea, Scalar(0, 255, 0), 1);
						sortA[count] = { pointArea[i].x, Mat(binaryNP, wideArea) };
					}
				}

				else {
					rectangle(contoursMat, wideArea, Scalar(0, 255, 0), 1);
					sortA[count] = { pointArea[i].x, Mat(binaryNP, wideArea) };
				}

				sortArray.push_back(sortA[count]);
				count++;
			}
		}
		if (!sortArray.size() == 0) {
			sort(sortArray.begin(), sortArray.end(),
				[](const sort_struct& a, const sort_struct& b) {return a.xLocation > b.xLocation; });

			for (int i = 0; i < sortArray.size(); i++) {

				if (i > 3) {
					return;
				}

				stringstream nameMatWindow;
				nameMatWindow << "num" << i;
				matrixArray(sortArray[i].numRect, nameMatWindow.str());

				Mat  result;
				cv::Point maxLocationResult;

				stringstream detectNum;
				detectNum << "./dat/" << nameMatWindow.str() << ".dat";

				ifstream ifs;
				ifs.open(detectNum.str(), ios::in | ios::binary);
				Mat binaryNumMat = Mat(cv::Size(N_INPUT, 1), CV_32F);


				for (int y = 0; y < 1; y++) {
					for (int x = 0; x < N_INPUT; x++) {
						char moji;
						int number;

						ifs.get(moji);
						number = atoi(&moji);

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
				//	detectedNum[i] = maxLocationResult.x;
				numInt[i] = maxLocationResult.x;
				number[i] = imread("./img/plate.png");

				putText(number[i], detectedNumber, cv::Point(point4, numHight), CV_FONT_HERSHEY_SIMPLEX, numScale, Scalar(128, 128, 0), numThik, 8);
			}
				vector<Mat> number_array{ number[3], number[2], number[1], number[0] };
				hconcat(number_array, concatnated);
				dataToDGV(nameGridView);
				DrawCVImage(picbox1, contoursMat);
				DrawCVImage(picbox2, concatnated);
				if (nameGridView->Rows->Count == 50) {
					nameGridView->Rows->RemoveAt(0);
				}
			}
		}
	
}
#endif
