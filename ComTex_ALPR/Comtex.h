#pragma once
#include "preFunction.h"


namespace ComTex_ALPR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
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
	protected:

	protected:

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;




	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// startButton1
			// 
			this->startButton1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->startButton1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
			this->startButton1->Location = System::Drawing::Point(12, 61);
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
			this->stopButton1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
			this->stopButton1->Location = System::Drawing::Point(12, 118);
			this->stopButton1->Name = L"stopButton1";
			this->stopButton1->Size = System::Drawing::Size(80, 30);
			this->stopButton1->TabIndex = 1;
			this->stopButton1->Text = L"Stop";
			this->stopButton1->UseVisualStyleBackColor = false;
			this->stopButton1->Click += gcnew System::EventHandler(this, &Comtex::stopButton1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Location = System::Drawing::Point(98, 37);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(640, 480);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// dataGridView1
			//
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(750, 200);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 21;
			this->dataGridView1->Size = System::Drawing::Size(430, 400);
			this->dataGridView1->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->TabIndex = 3;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Comtex::dataGridView1_CellContentClick);
			this->dataGridView1->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::DisplayedCellsExceptHeaders;
			this->dataGridView1->MultiSelect = true;
			this->dataGridView1->ColumnCount = 2;
			this->dataGridView1->Columns[0]->Name = "Date";
			this->dataGridView1->Columns[1]->Name = "Number";
			this->dataGridView1->AllowUserToAddRows = true;
			this->dataGridView1->Columns[0]->SortMode = DataGridViewColumnSortMode::Automatic;
			this->dataGridView1->Sort(dataGridView1->Columns[0], System::ComponentModel::ListSortDirection::Descending);


			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->pictureBox2->Location = System::Drawing::Point(750, 37);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(200, 100);
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->pictureBox3->Location = System::Drawing::Point(960, 37);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(200, 50);
			this->pictureBox3->TabIndex = 5;
			this->pictureBox3->TabStop = false;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->ForeColor = System::Drawing::Color::White;
			this->radioButton1->Location = System::Drawing::Point(98, 15);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(72, 16);
			this->radioButton1->TabIndex = 6;
			this->radioButton1->Text = L"ALPR ON";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Comtex::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Checked = false;
			this->radioButton2->ForeColor = System::Drawing::Color::White;
			this->radioButton2->Location = System::Drawing::Point(192, 15);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(78, 16);
			this->radioButton2->TabIndex = 7;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"ALPR OFF";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// Comtex
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->ClientSize = System::Drawing::Size(1264, 761);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->stopButton1);
			this->Controls->Add(this->startButton1);
			this->Name = L"Comtex";
			this->Text = L"Comtex";
			this->Load += gcnew System::EventHandler(this, &Comtex::Comtex_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Comtex_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	}
	private: System::Void startButton1_Click(System::Object^  sender, System::EventArgs^  e) {
		startButton1->Enabled = false;
		radioButton1->Enabled = false;
		radioButton2->Enabled = false;
		loadNueron();
		accessIpCamera();
		accessCascade();
		createNumberArray();
		checkStopKey = 1;
        //System::Windows::Forms::DataGridView^ gridName = this->dataGridView1;
		Thread ^subThread = gcnew Thread(gcnew ThreadStart(this, &Comtex::processThread));
		subThread->IsBackground;
		subThread->Start();
		
	}

	private: System::Void processThread(){
		while(checkStopKey == 1){
			readOriginal();
			DrawCVImage(pictureBox1, matrix32s);

			general700_cascade.detectMultiScale(gray, commPlate, 1.3, 5);
			if (commPlate.empty()){
				
			}
			else{
				processNeuralNetwork();
				BeginInvoke(gcnew delegate_of_gridView(this, &Comtex::gridView));
				DrawCVImage(pictureBox2, contoursMat);
				DrawCVImage(pictureBox3, concatnated);
			}
		    BeginInvoke(gcnew conditionStopDelegate(this, &Comtex::stopFunction));
	}
		BeginInvoke(gcnew delegateOfenableStartButton(this, &Comtex::enableSartButton));

}

	 private: delegate System::Void conditionStopDelegate();
	 private: System::Void stopFunction(){
		 this->dataGridView1->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells);

	}

	private: delegate System::Void delegate_of_gridView();
	private: System::Void gridView(){
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
			intSS << num[3] << num[2] << num[1] << num[0];
			string integerSS = intSS.str();
			System::String^ numberN = gcnew System::String(integerSS.c_str());
			array<System::String^>^ rows0 = gcnew array<System::String^>{timeStamp,numberN};
			DataGridViewRowCollection^ rows = this->dataGridView1->Rows;
			rows->Add(rows0);
			if (rows->Count == 30){
				rows->RemoveAt(0);
			}
	 }

	 private: delegate System::Void delegateOfenableStartButton();
	 private: System::Void enableSartButton(){
		   startButton1->Enabled = true;
		   radioButton1->Enabled = true;
		   radioButton2->Enabled = true;
		   pictureBox1->Invalidate();
	}


	private: System::Void stopButton1_Click(System::Object^  sender, System::EventArgs^  e) {
		checkStopKey = 0;
	
	}


	private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
