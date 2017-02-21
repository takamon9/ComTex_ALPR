#ifndef __HEADER_H_INCLUDED__
#define __HEADER_H_INCLUDED__

#include "neuralNetwork.h"


string uname = "root";
string password = "taka1974";
//string ip_address = "http://" + uname + ":" + password + "@192.168.100.50/mjpg/video.mjpg";//Axis
string ip_address = "http://" + uname + ":" + password + "@192.168.100.12/-wvhttp-01-/GetOneShot?image_size=640x480&frame_count=0";//canon vb-c300
//string ip_address = "http://" + uname + ":" + password + "@192.168.100.50/cgi-bin/mjpeg?session_id=[CHANNEL]&buffer=0&prio=high&frame=4";


using namespace System::Windows::Forms;


int loadNueron(){
	neuron = ANN_MLP::load<ANN_MLP>("./dat/neuron.xml", "nueron");
	{
		if (neuron == nullptr){
			MessageBox::Show("Check your neuron.xml exists the folder.","Caution",MessageBoxButtons::OK,MessageBoxIcon::Asterisk);
			return -1;
		}
	}

}


int accessIpCamera(){
	if (!capture.open(ip_address))
	{
		MessageBox::Show("Cannot connect IP camera! Check Your Camera Connection.","Cation",MessageBoxButtons::OK,MessageBoxIcon::Asterisk);
		system("pause");
		return -1;
	}
}

int accessCascade(){

	if (!general700_cascade.load("./cascade/700_cascade.xml"))
	{
		MessageBox::Show("cascade.load failed!! put the xml file into this project holder\n","Caution",MessageBoxButtons::OK,MessageBoxIcon::Asterisk);
		system("pause");
		return -1;
	}
}

void createNumberArray(){
	for (int j = 0; j < 4; j++) {

		number[j].create(numArrWidth, numArrHight, CV_8SC3);

	}


}


int readOriginal(){
	time_t t;

	if (!capture.read(original)) {
		return -1;
	}

	image = original.clone();
	cvtColor(original, gray, CV_BGR2GRAY);
	cvtColor(original, matrix32s,CV_32S);

}


void DrawCVImage(System::Windows::Forms::Control^ control, cv::Mat& colorImage)
{
	System::Drawing::Graphics^ graphics = control->CreateGraphics();
	System::IntPtr ptr(colorImage.ptr());
	System::Drawing::Bitmap^ b
		= gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
	System::Drawing::RectangleF rect(0, 0, control->Width, control->Height);
	graphics->DrawImage(b, rect);
	delete graphics;
}



#endif