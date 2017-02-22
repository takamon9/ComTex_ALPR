#ifndef __HEADER_H_INCLUDED__
#define __HEADER_H_INCLUDED__

#include "neuralNetwork.h"


//string uname = "root";
//string password = "taka1974";
//string ip_address = "http://" + uname + ":" + password + "@192.168.100.50/mjpg/video.mjpg";//Axis
//string ip_address = "http://" + uname + ":" + password + "@192.168.100.30/-wvhttp-01-/GetOneShot?image_size=640x480&frame_count=0";//canon vb-c300
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

string MarshalString(System::String^ sys_str) {
	using namespace System;
	using namespace Runtime::InteropServices;
	string normal_str;

	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(sys_str)).ToPointer();
	normal_str = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	return normal_str;
}

int accessIpCamera(System::String^ ipAddress, System::String^ user_name, System::String^ pass_word) {
	string name_of_ip_address;
	System::String^ ip_address = gcnew System::String("http://" + user_name + ":" + pass_word + "@" + ipAddress + "/-wvhttp-01-/GetOneShot?image_size=640x480&frame_count=0");
	name_of_ip_address = MarshalString(ip_address);
	if (!capture.open(name_of_ip_address))
	{
		MessageBox::Show("Cannot connect IP camera! Check Your Camera Connection.", "Cation", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		checkStopKey = 0;
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

System::String^ cameraSet(int nameOf) {

	string fileName = ("./dat/cameraSet.dat");
	vector<std::string> buffer_of_setting;
	char setting[256];
	vector<string> dataSetting;
	ifstream cameraSet;
	cameraSet.open(fileName);

	string collection;

		cameraSet.getline(setting, 255);

		string setting_str(setting);
		istringstream parts(setting_str);
		string bbs;


		for(int num = 0; num < 3; num++) {
			parts >> bbs;
			buffer_of_setting.push_back(bbs);

		}

		System::String^ sys_ip,^ sys_user,^ sys_pass;

	sys_ip = gcnew System::String(buffer_of_setting[0].c_str());
	sys_user = gcnew System::String(buffer_of_setting[1].c_str());
	sys_pass = gcnew System::String(buffer_of_setting[2].c_str());

//	MessageBox::Show(sys_user);

	if (nameOf == 0) { return sys_ip; }
	if (nameOf == 1) { return sys_user; }
	if (nameOf == 2) { return sys_pass;}
}

void saveSetting(System::String^ ip,System::String^ user,System::String^ pass) {

	string saveIp,saveUser,savePass;
	saveIp = MarshalString(ip);
	saveUser = MarshalString(user);
	savePass = MarshalString(pass);

	stringstream save_ss;
	save_ss << saveIp << " " << saveUser << " " << savePass;
	
	fstream save_fs;
	save_fs.open("./dat/cameraSet.dat",ios::in |ios::out | ios::trunc);
	if (save_fs.is_open() == 0) {
		MessageBox::Show("Cannot open Setting File.");
		return;
	}

	std::string save_str = save_ss.str();
	const char* ss_char = save_str.c_str();
	save_fs.write(ss_char, save_str.size());
	save_fs.close();

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
