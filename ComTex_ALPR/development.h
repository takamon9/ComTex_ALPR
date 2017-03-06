#ifndef __DEVELOPMENT_H_INCLUDED__
#define __DEVELOPMENT_H_INCLUDED__

#include "programHeader.h"

string dev_timeStampStr() {
	time_t dev_timer = time(0);
	struct tm *timeStruct = localtime(&dev_timer);
	int year = timeStruct->tm_year + 1900;
	int month = timeStruct->tm_mon + 1;
	int day = timeStruct->tm_mday;
	int hour = timeStruct->tm_hour;
	int minute = timeStruct->tm_min;
	int second = timeStruct->tm_sec;

	stringstream dateSS, intSS;
	dateSS << year << "/" << setw(2) << setfill('0') << month << "/" << setw(2) << setfill('0') << day << "," << setw(2) << setfill('0') << hour << ";" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second;
	string timeStamp = dateSS.str();
	return timeStamp;
}


void developmentFunction_1(int v, Mat binaryNumer) {
	stringstream nameImgFile;
	nameImgFile << "./dev/numImage/" << dev_timeStampStr() << "_" << v << ".png";
	cv::imwrite(nameImgFile.str(), binaryNumer);
}

void developmentFunction_2(Mat& rectanglePlate) {
	stringstream nameImgFile;
	nameImgFile << "./dev/plateImage/" << dev_timeStampStr() << ".png";
	cv::imwrite(nameImgFile.str(), rectanglePlate);
}

#endif
