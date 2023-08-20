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
		MyForm2(String^ algoName, System::Collections::Generic::List<int>^ arr)
		{
			InitializeComponent(algoName,arr);
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
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(String^ title, System::Collections::Generic::List<int>^ arr)
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
				this->Controls->Add(myLabel);
				labelArray->Add(myLabel);
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

	private: System::Void start(System::Object^ sender, System::EventArgs^ e) {

	}

	};
}
