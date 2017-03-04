#ifndef __HEADER_H_INCLUDED__
#define __HEADER_H_INCLUDED__

#include "neuralNetwork.h"

using namespace System::Windows::Forms;

int loadNueron() {

	cv::String fileName("./dat/neuron.xml");
	cv::String objName("neuron");

	neuron = ANN_MLP::load<ANN_MLP>(fileName, objName);

	if (neuron.empty() == true) {
		MessageBox::Show("Check your neuron.xml exists the folder.", "Caution", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		return -1;
	}
}

string MarshalString(System::String^ sys_str) {
	using namespace System;
	using namespace Runtime::InteropServices;
	string normal_str;

	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(sys_str)).ToPointer();
	normal_str = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	return normal_str;
}

int accessIpCamera(System::Windows::Forms::DataGridView^ cameraDGV) {

	int selectedrowIndex = cameraDGV->CurrentRow->Index;
	System::String^ camMaker = cameraDGV->Rows[selectedrowIndex]->Cells[1]->Value->ToString();
	System::String^ ipAd = cameraDGV->Rows[selectedrowIndex]->Cells[2]->Value->ToString();
	System::String^ userId = cameraDGV->Rows[selectedrowIndex]->Cells[3]->Value->ToString();
	System::String^ pass = cameraDGV->Rows[selectedrowIndex]->Cells[4]->Value->ToString();

	string name_of_ip_address;
	System::String^ accsessAddress;
	System::String^ canon = gcnew System::String("Canon");
	System::String^ panasonic = gcnew System::String("Panasonic");
	System::String^ axis = gcnew System::String("Axis");
	System::String^ sony = gcnew System::String("Sony");

	if (camMaker == canon) {
		accsessAddress = "-wvhttp-01-/GetOneShot?image_size=640x480&frame_count=0";
	}
	if (camMaker == panasonic) {
		accsessAddress = "nphMotionJpeg?Resolution=640x480&Quality=Standard";
	}
	if (camMaker == axis) {
		accsessAddress = "mjpg/video.mjpg";
	}
	if (camMaker == sony) {
		accsessAddress = "mjpg/video.mjpg";
	}

	System::String^ ip_address = gcnew System::String("http://" + userId + ":" + pass + "@" + ipAd + "/" + accsessAddress);
	name_of_ip_address = MarshalString(ip_address);
	capture.open(name_of_ip_address);

	if (capture.isOpened() == 0)
	{
		MessageBox::Show("We failed to connect to the camera! Check Your Camera Connection.", "Cation", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		checkStopKey = 0;
		return -1;
	} else {
		cameraDGV->CurrentRow->Cells[5]->Value = "Connected";
	}
}

int accessCascade() {

	if (!general700_cascade.load("./cascade/700_cascade.xml"))
	{
		MessageBox::Show("We failed to load the Cascade! Put the cascade xml file into './dat' holder\n", "Caution", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		system("pause");
		return -1;
	}
}

void loadCameraSet(System::Windows::Forms::DataGridView^ formCameraList) {

	vector<string> dataSetting;
	fstream cameraSet;

	string fileName = ("./dat/cameraSet.dat");
	cameraSet.open(fileName);
	if (cameraSet.is_open() == 0) {
		MessageBox::Show("Sorry, We can not open the Camera Setting file.", "Caution!");
	}

	string setting;
	int lineCount = 0;
	formCameraList->Rows->Clear();

	while (cameraSet.eof() == false) {
		formCameraList->Rows->Add(1);
		getline(cameraSet, setting);
		istringstream parts(setting);
		string words;

		for (int i = 0; i < 5; i++) {

			parts >> words;
			System::String^ sys_parts = gcnew System::String(words.c_str());

			formCameraList->Rows[lineCount]->Cells[i]->Value = sys_parts;
		//	formCameraList->Rows[lineCount]->Cells[5]->Value = "Disconnected";
		}
		lineCount++;
	}
}

void saveCameraList(System::Windows::Forms::DataGridView^ cameraDg) {

	int rowCount = cameraDg->Rows->Count;
	int columnCount = cameraDg->Columns->Count;
	
	fstream save_fs;

	save_fs.open("./dat/cameraSet.dat", ios::out | ios::ate);
	if (save_fs.is_open() == 0) {
		MessageBox::Show("Cannot open the Setting File.");
		return;
	}

	save_fs.close();

	stringstream save_ss;
	string text_srt;

	for (int i = 0; i < rowCount-1; i++) {
		for (int y = 0; y < columnCount-1; y++) {
			text_srt = MarshalString(cameraDg->Rows[i]->Cells[y]->Value->ToString());
			save_ss << text_srt << " ";
			if (i < rowCount-2 &&  y == 4) {
				save_ss << "\n";
			}
		}
	}

	string save_str = save_ss.str();
	const char* ss_char = save_str.c_str();
	save_fs.open("./dat/cameraSet.dat", ios::in | ios::out | ios::app);
	save_fs.write(ss_char, save_str.size());
	save_fs.close();
}


void createNumberArray() {
	for (int j = 0; j < 4; j++) {

		number[j].create(numArrWidth, numArrHight, CV_8SC3);

	}
}

int readOriginal() {
	time_t t;

	if (!capture.read(original)) {
		return -1;
	}

	image = original.clone();
	cvtColor(original, gray, CV_BGR2GRAY);
	cvtColor(original, matrix32s, CV_32S);

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
