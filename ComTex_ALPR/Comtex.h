#pragma once
#include "preFunction.h"


namespace ComTex_ALPR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Text;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Comtex の概要
	/// </summary>
	public ref class Comtex : public System::Windows::Forms::Form
	{
	public:
		Comtex(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~Comtex()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  startButton1;
	private: System::Windows::Forms::Button^  stopButton1;
	private: System::Windows::Forms::Button^  loadButton;
	private: System::Windows::Forms::Button^ saveButton;
	private: System::Windows::Forms::Button^ exitButton;
	private: System::Windows::Forms::Button^ addRow;
	private: System::Windows::Forms::Button^ deleteRow;
	private: System::Windows::Forms::RadioButton^ alprOn;
	private: System::Windows::Forms::RadioButton^ alprOff;
	private: System::Windows::Forms::Label^ onoffLamp;
	private: TextBox^ ipAddress;
	private: TextBox^ userName;
	private: TextBox^ password;
	private: ComboBox^ cameraMaker;
	private: TextBox^ cameraName;
//	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ checkBoxColumn;
	protected:

	protected:

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridView^ cameraList;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::GroupBox^ groupBox1;

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Comtex::typeid));
			this->startButton1 = (gcnew System::Windows::Forms::Button());
			this->stopButton1 = (gcnew System::Windows::Forms::Button());
			this->loadButton = (gcnew System::Windows::Forms::Button());
			this->ipAddress = (gcnew System::Windows::Forms::TextBox());
			this->userName = (gcnew System::Windows::Forms::TextBox());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->cameraList = (gcnew System::Windows::Forms::DataGridView());
			this->cameraName = (gcnew System::Windows::Forms::TextBox());
			this->cameraMaker = (gcnew System::Windows::Forms::ComboBox());
			this->addRow = (gcnew System::Windows::Forms::Button());
			this->deleteRow = (gcnew System::Windows::Forms::Button());
			this->alprOn = (gcnew System::Windows::Forms::RadioButton());
			this->alprOff = (gcnew System::Windows::Forms::RadioButton());
			this->onoffLamp = (gcnew System::Windows::Forms::Label());
		//	this->checkBoxColumn = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cameraList))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			//
			// GroupBox1
			//
			this->groupBox1->Text = (L"Recognition");
			this->groupBox1->Size = System::Drawing::Size(300, 40);
			this->groupBox1->Left = 100;
			this->groupBox1->Top = 5;
			this->groupBox1->AutoSize = false;
			this->groupBox1->FlatStyle = FlatStyle::Flat;
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
			this->groupBox1->ForeColor = Color::White;
			this->onoffLamp->Size = System::Drawing::Size(10, 10);
			this->onoffLamp->Left = 20;
			this->onoffLamp->Top = 20;
			this->onoffLamp->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->alprOn->Text = (L"ALPR ON");
			this->alprOn->Top = 15;
			this->alprOn->Left = 50;
			this->alprOn->Checked = true;
			this->alprOn->UseVisualStyleBackColor = true;
			this->alprOff->Text = (L"ALPR OFF");
			this->alprOff->Top = 15;
			this->alprOff->Left = alprOn->Right + 10;
			this->alprOff->UseVisualStyleBackColor = true;
			// 
			// startButton1
			// 
			this->startButton1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->startButton1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 13));
			this->startButton1->Location = System::Drawing::Point(10, 50);
			this->startButton1->Name = L"startButton1";
			this->startButton1->Size = System::Drawing::Size(80, 30);
			this->startButton1->TabIndex = 0;
			this->startButton1->Text = L"Start";
			this->startButton1->UseVisualStyleBackColor = false;
			this->startButton1->Click += gcnew System::EventHandler(this, &Comtex::startButton1_Click);
			// 
			// stopButton1
			// 
			this->stopButton1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->stopButton1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 13));
			this->stopButton1->Location = System::Drawing::Point(10, 100);
			this->stopButton1->Name = L"stopButton1";
			this->stopButton1->Size = System::Drawing::Size(80, 30);
			this->stopButton1->TabIndex = 1;
			this->stopButton1->Text = L"Stop";
			this->stopButton1->UseVisualStyleBackColor = false;
			this->stopButton1->Click += gcnew System::EventHandler(this, &Comtex::stopButton1_Click);
			// 
			// LoadButton
			// 
			this->loadButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->loadButton->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 13));
			this->loadButton->Location = System::Drawing::Point(10, 610);
			this->loadButton->Name = L"loadButton";
			this->loadButton->Size = System::Drawing::Size(80, 30);
			this->loadButton->TabIndex = 0;
			this->loadButton->Text = L"LOAD";
			this->loadButton->UseVisualStyleBackColor = false;
			this->loadButton->Click += gcnew System::EventHandler(this, &Comtex::loadButton_Click);
			// 
			// saveSettingButton
			// 
			this->saveButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->saveButton->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 13));
			this->saveButton->Location = System::Drawing::Point(10, 650);
			this->saveButton->Name = L"SaveButton";
			this->saveButton->Size = System::Drawing::Size(80, 30);
			this->saveButton->TabIndex = 0;
			this->saveButton->Text = L"SAVE";
			this->saveButton->UseVisualStyleBackColor = false;
			this->saveButton->Click += gcnew System::EventHandler(this, &Comtex::saveButton_Click);
			//
			// camera name
			//
			this->cameraName->AcceptsReturn = false;
			this->cameraName->AcceptsTab = true;
			this->cameraName->Multiline = false;
			this->cameraName->Text = "Cam Name";
			this->cameraName->Location = System::Drawing::Point(100, 540);
			this->cameraName->Size = System::Drawing::Size(100, 25);
			this->cameraName->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11));
			//
			// camera Maker
			//
			this->cameraMaker->DropDownStyle = ComboBoxStyle::DropDownList;
			this->cameraMaker->Items->Add("Canon");
			this->cameraMaker->Items->Add("Panasonic");
			this->cameraMaker->Items->Add("Axis");
			this->cameraMaker->Items->Add("Sony");
			this->cameraMaker->Text = "Manufacture";
			this->cameraMaker->Location = System::Drawing::Point(210, 540);
			this->cameraMaker->Size = System::Drawing::Size(100, 25);
			this->cameraMaker->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11));
			//
			// ipAddress
			//
			this->ipAddress->AcceptsReturn = false;
			this->ipAddress->AcceptsTab = true;
			this->ipAddress->Multiline = false;
			this->ipAddress->Text = "IP Address";
			this->ipAddress->Location = System::Drawing::Point(320, 540);
			this->ipAddress->Size = System::Drawing::Size(140, 25);
			this->ipAddress->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11));
			//
			// userName
			//
			this->userName->AcceptsReturn = false;
			this->userName->AcceptsTab = true;
			this->userName->Multiline = false;
			this->userName->Text = "User ID";
			this->userName->Location = System::Drawing::Point(470, 540);
			this->userName->Size = System::Drawing::Size(100, 25);
			this->userName->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11));
			//
			// password
			//
			this->password->AcceptsReturn = false;
			this->password->AcceptsTab = true;
			this->password->Multiline = false;
			this->password->Text = "Password";
			this->password->Location = System::Drawing::Point(580, 540);
			this->password->Size = System::Drawing::Size(100, 25);
			this->password->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11));
			//
			// exitButton
			//
			this->exitButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->exitButton->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 13));
			this->exitButton->Location = System::Drawing::Point(10, 500);
			this->exitButton->Name = L"exit";
			this->exitButton->Size = System::Drawing::Size(80, 30);
			this->exitButton->TabIndex = 0;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = false;
			this->exitButton->Click += gcnew System::EventHandler(this, &Comtex::exitButton_Click);
			//
			// addRow_button
			//
			this->addRow->BackColor = Color::AntiqueWhite;
			this->addRow->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 13));
			this->addRow->Location = System::Drawing::Point(690, 540);
			this->addRow->Name = L"Add";
			this->addRow->Size = System::Drawing::Size(50, 25);
			this->addRow->TabIndex = 0;
			this->addRow->Text = L"Add";
			this->addRow->UseVisualStyleBackColor = false;
			this->addRow->Click += gcnew System::EventHandler(this, &Comtex::addRow_Click);
			//
			// deleteRow_button
			//
			this->deleteRow->BackColor = Color::AntiqueWhite;
			this->deleteRow->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 13));
			this->deleteRow->Location = System::Drawing::Point(10, 570);
			this->deleteRow->Name = L"Delete";
			this->deleteRow->Size = System::Drawing::Size(80, 30);
			this->deleteRow->TabIndex = 0;
			this->deleteRow->Text = L"Delete";
			this->deleteRow->UseVisualStyleBackColor = false;
			this->deleteRow->Click += gcnew System::EventHandler(this, &Comtex::deleteRow_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = Image::FromFile("./img/imageAlpr.png");
			this->pictureBox1->Location = System::Drawing::Point(100, 50);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(640, 480);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// dataGridView1
			//
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(750, 250);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 21;
			this->dataGridView1->Size = System::Drawing::Size(430, 440);
			this->dataGridView1->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			//this->dataGridView1->TabIndex = 3;
			this->dataGridView1->TabStop = false;
			this->dataGridView1->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::DisplayedCellsExceptHeaders;
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->ColumnCount = 2;
			this->dataGridView1->Columns[0]->Name = "Date";
			this->dataGridView1->Columns[1]->Name = "Number";
			this->dataGridView1->AllowUserToAddRows = true;
			this->dataGridView1->Columns[0]->SortMode = DataGridViewColumnSortMode::Automatic;
			this->dataGridView1->Sort(dataGridView1->Columns[0], System::ComponentModel::ListSortDirection::Descending);
			//
			// CameraList
			//
			this->cameraList->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->cameraList->Location = System::Drawing::Point(100, 570);
			this->cameraList->Name = L"cameraList";
			this->cameraList->RowTemplate->Height = 21;
			this->cameraList->Size = System::Drawing::Size(640, 120);
			this->cameraList->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			//this->cameraList->TabIndex = 12;
			this->cameraList->TabStop = false;
			this->cameraList->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::DisplayedCellsExceptHeaders;
			this->cameraList->MultiSelect = false;
			this->cameraList->ColumnCount = 6;
		//	this->checkBoxColumn->Width = 25;
		//	this->checkBoxColumn->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
		//	this->cameraList->Columns->Insert(0,checkBoxColumn);
		//	this->checkBoxColumn->TrueValue = 1;
		//	this->checkBoxColumn->FalseValue = 0;
		//	this->cameraList->Columns[0]->Name = "C";
			this->cameraList->Columns[0]->Name = "Camera Name";
			this->cameraList->Columns[0]->Width = 90;
			this->cameraList->Columns[1]->Name = "Maker";
			this->cameraList->Columns[1]->Width = 90;
			this->cameraList->Columns[2]->Name = "IP Address";
			this->cameraList->Columns[3]->Name = "User ID";
			this->cameraList->Columns[3]->Width = 85;
			this->cameraList->Columns[4]->Name = "Password";
			this->cameraList->Columns[4]->Width = 85;
			this->cameraList->Columns[5]->Name = "Status";
			this->cameraList->AllowUserToAddRows = true;
			this->cameraList->Columns[0]->SortMode = DataGridViewColumnSortMode::Automatic;
			this->cameraList->Sort(cameraList->Columns[0], System::ComponentModel::ListSortDirection::Descending);
			//
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->pictureBox2->Location = System::Drawing::Point(750, 50);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(200, 100);
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->pictureBox3->Location = System::Drawing::Point(960, 50);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(200, 50);
			this->pictureBox3->TabIndex = 5;
			this->pictureBox3->TabStop = false;
			// 
			// Comtex
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->ClientSize = System::Drawing::Size(1280, 768);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->stopButton1);
			this->Controls->Add(this->startButton1);
			this->Controls->Add(this->loadButton);
			this->Controls->Add(this->ipAddress);
			this->Controls->Add(this->userName);
			this->Controls->Add(this->password);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->cameraList);
			this->Controls->Add(this->cameraName);
			this->Controls->Add(this->cameraMaker);
			this->Controls->Add(this->addRow);
			this->Controls->Add(this->deleteRow);
			this->groupBox1->Controls->Add(alprOn);
			this->groupBox1->Controls->Add(alprOff);
			this->groupBox1->Controls->Add(onoffLamp);
			this->Name = L"Comtex";
			this->Text = L"Comtex";
			this->Load += gcnew System::EventHandler(this, &Comtex::Comtex_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cameraList))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Comtex_Load(System::Object^  sender, System::EventArgs^  e) {
		loadCameraSet(cameraList);
		//cameraList->CurrentRow->Cells[0]->Value = 1;
	}

	private: System::Void addRow_Click(System::Object^  sender, System::EventArgs^  e) {
		System::String^ camName = this->cameraName->Text;
		System::String^ manfName = this->cameraMaker->Text;
		System::String^ ipAddress = this->ipAddress->Text;
		System::String^ userID = this->userName->Text;
		System::String^ pass = this->password->Text;

		this->cameraList->Rows->Add(camName, manfName, ipAddress, userID, pass);
	}

	private: System::Void deleteRow_Click(System::Object^  sender, System::EventArgs^  e) {

		int selectRows = this->cameraList->SelectedRows[0]->Index;
		int oldestRow = this->cameraList->Rows->Count-1;

		if (selectRows == oldestRow) {
			MessageBox::Show("Sorry,We cannot delete this row");
			return;
		}
	
		if (MessageBox::Show("Are you sure you want to delete the Row?", "Warning!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Cancel) {
			return;
		}

		this->cameraList->Rows->RemoveAt(selectRows);
	}

	private: System::Void exitButton_Click(System::Object^  sender, System::EventArgs^  e) {
		int anserValue;
		System::String^ caption = "Warning!";
		if (MessageBox::Show("Are you sure you want to close the program?", caption, MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No) {
			return;
		}

		checkStopKey = 0;
		this->Close();
	}

	private: System::Void loadButton_Click(System::Object^  sender, System::EventArgs^  e) {
		vector<std::string> wordBuff;
		loadCameraSet(cameraList);
	}

	private: System::Void saveButton_Click(System::Object^  sender, System::EventArgs^  e) {
		saveCameraList(this->cameraList);
	}


	private: System::Void startButton1_Click(System::Object^  sender, System::EventArgs^  e) {

		this->startButton1->Enabled = false;
		this->alprOn->Enabled = false;
		this->alprOff->Enabled = false;
		
		accessCascade();
		createNumberArray();
		checkStopKey = 1;

		System::Windows::Forms::DataGridView^ cameraDataGrid = this->cameraList;
		accessIpCamera(cameraDataGrid);

		loadNueron();

		if (checkStopKey == 0) {
			this->startButton1->Enabled = true;
			this->alprOn->Enabled = true;
			this->alprOff->Enabled = true;
			return;
		}

		numInt[0] = NULL;
		numInt[1] = NULL;
		numInt[2] = NULL;
		numInt[3] = NULL;
		numInt[4] = NULL;

		//System::Windows::Forms::DataGridView^ gridName = this->dataGridView1;
		Thread ^subThread = gcnew Thread(gcnew ThreadStart(this, &Comtex::processThread));
		subThread->IsBackground;
		subThread->Start();
	}

	private: System::Void processThread() {
		if (this->alprOn->Checked == true) {
			this->onoffLamp->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
		}
		while (checkStopKey == 1) {

			readOriginal();
			DrawCVImage(pictureBox1, matrix32s);

			if (this->alprOn->Checked) {
				general700_cascade.detectMultiScale(gray, commPlate, 1.3, 5);
				if (general700_cascade.empty()) {
						MessageBox::Show("No Cascade file detected! Check the data holder.");
						break;
				}
				else {
					processNeuralNetwork();
					BeginInvoke(gcnew delegate_of_gridView(this, &Comtex::gridView));
					DrawCVImage(pictureBox2, contoursMat);
					DrawCVImage(pictureBox3, concatnated);
				}
				BeginInvoke(gcnew conditionStopDelegate(this, &Comtex::stopFunction));
			}
		}
		BeginInvoke(gcnew delegateOfenableStartButton(this, &Comtex::enableSartButton));

	}

	private: delegate System::Void conditionStopDelegate();
	private: System::Void stopFunction() {
		this->dataGridView1->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells);

	}

	private: delegate System::Void delegate_of_gridView();
	private: System::Void gridView() {

		if (numInt[0] == 0 && numInt[1] == 0 && numInt[2] == 0 && numInt[3] == 0) {
			return;
		}

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
		DataGridViewRowCollection^ rows = this->dataGridView1->Rows;
		rows->Add(rows0);
		if (rows->Count == 30) {
			rows->RemoveAt(0);
		}
	}

	private: delegate System::Void delegateOfenableStartButton();
	private: System::Void enableSartButton() {
		this->startButton1->Enabled = true;
		this->alprOn->Enabled = true;
		this->alprOff->Enabled = true;
		this->pictureBox1->Invalidate();
		this->onoffLamp->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));
	}


	private: System::Void stopButton1_Click(System::Object^  sender, System::EventArgs^  e) {
		checkStopKey = 0;
	}


	};
}
