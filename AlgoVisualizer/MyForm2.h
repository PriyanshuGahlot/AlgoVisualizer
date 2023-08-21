#pragma once

namespace AlgoVisualizer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;


	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		System::Collections::Generic::List<Label^>^ labelArray;
		System::Collections::Generic::List<int>^ arr;
		String^ algoName;
		MyForm2(String^ algoName, System::Collections::Generic::List<int>^ arr)
		{
			this->arr = arr;
			this->algoName = algoName;
			labelArray = gcnew System::Collections::Generic::List<Label^>();
			timer = gcnew System::Windows::Forms::Timer();
			timer->Interval = 25;
			timer->Tick += gcnew System::EventHandler(this, &MyForm2::timer_Tick);
			InitializeComponent(algoName);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;
		System::Windows::Forms::Timer^ timer;
		bool isSwapping = false;
		bool hold = false;
		Label^ label1;
		Label^ label2;
		System::Drawing::Point p1;
		System::Drawing::Point p2;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(String^ title)
		{
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(960, 540);
			this->Text = title;
			int currPos = 50;
			for each (int i in arr) {
				Label^ myLabel = gcnew Label();
				myLabel->Text = i.ToString();
				myLabel->Location = Point(currPos, 50);
				myLabel->AutoSize = false;
				myLabel->BackColor = System::Drawing::Color::Yellow;
				myLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				myLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
				myLabel->TextAlign = ContentAlignment::MiddleCenter;
				myLabel->Size = System::Drawing::Size(30, 30);
				currPos += 50;
				this->labelArray->Add(myLabel);
				this->Controls->Add(myLabel);
			}

			Button^ startBtn = gcnew Button();
			startBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			startBtn->Location = System::Drawing::Point(400, 400);
			startBtn->Name = L"startBtn";
			startBtn->Size = System::Drawing::Size(160, 40);
			startBtn->TabIndex = 3;
			startBtn->Text = L"Start";
			startBtn->UseVisualStyleBackColor = true;
			startBtn->Click += gcnew System::EventHandler(this, &MyForm2::start);
			this->Controls->Add(startBtn);

		}
#pragma endregion

		void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
			int step = 1;
			int multiplyer = 1;
			if (label1->Location.X != p2.X) {
				if (label1->Location.X > p2.X) multiplyer = -1;
				label1->Location = System::Drawing::Point(label1->Location.X + step*multiplyer, label1->Location.Y);
			}
			else if (label2->Location.X != p1.X) {
				if (label2->Location.X > p1.X) multiplyer = -1;
				label2->Location = System::Drawing::Point(label2->Location.X + step*multiplyer, label1->Location.Y);
			}
			else {
				isSwapping = false;
				timer->Stop();
			}

		}

	private: System::Void start(System::Object^ sender, System::EventArgs^ e) {
		int n = arr->Count;
		if (algoName->Equals("Bubble Sort")) {
			for (int i = 0;i < n;i++) {
				bool swaped = false;
				for (int j = 0;j < n - i - 1;j++) {
					if (arr[j] > arr[j + 1]) {
						swap(arr, j, j + 1);
						isSwapping = true;
						while (isSwapping)
						{
							Application::DoEvents();
						}
						label1->BackColor = System::Drawing::Color::Yellow;
						label2->BackColor = System::Drawing::Color::Yellow;
						swaped = true;
					}
					else
					{
						label1 = labelArray[j+1];
						label2 = labelArray[j];
						label1->BackColor = System::Drawing::Color::LightGreen;
						label2->BackColor = System::Drawing::Color::LightGreen;
						//wait for 1 sec
						DateTime startTime = DateTime::Now;

						// Process messages while waiting
						while ((DateTime::Now - startTime).TotalMilliseconds < 1000) {
							Application::DoEvents();
						}

						label1->BackColor = System::Drawing::Color::Yellow;
						label2->BackColor = System::Drawing::Color::Yellow;
						
					}
				}
				if (!swaped) break;
			}
		}
	}

		   void swap(System::Collections::Generic::List<int>^ arr, int i, int j) {
			   Debug::WriteLine("swap");
			   int temp = arr[i];
			   arr[i] = arr[j];
			   arr[j] = temp;
			   label1 = labelArray[i];
			   label2 = labelArray[j];
			   label1->BackColor = System::Drawing::Color::LightGreen;
			   label2->BackColor = System::Drawing::Color::LightGreen;
			   p1 = label1->Location;
			   p2 = label2->Location;
			   Label^ tempLabel = labelArray[i];
			   labelArray[i] = labelArray[j];
			   labelArray[j] = tempLabel;
			   timer->Start();
		   }

		   void waitTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
			   System::Windows::Forms::Timer^ waitTimer = static_cast<System::Windows::Forms::Timer^>(sender);
			   hold = false;
			   waitTimer->Stop();
		   }
	};
}
