#pragma once
#include <iostream>
#include <list>
#include <string>
#include "MyForm2.h"

namespace AlgoVisualizer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ inputBox;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ bubble;
	private: System::Windows::Forms::Button^ insertion;
	private: System::Windows::Forms::Button^ selection;
	private: System::Windows::Forms::Button^ merge;
	private: System::Windows::Forms::Button^ button1;





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
		void InitializeComponent(void)
		{
			this->inputBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->bubble = (gcnew System::Windows::Forms::Button());
			this->insertion = (gcnew System::Windows::Forms::Button());
			this->selection = (gcnew System::Windows::Forms::Button());
			this->merge = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// inputBox
			// 
			this->inputBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->inputBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->inputBox->Location = System::Drawing::Point(50, 150);
			this->inputBox->Name = L"inputBox";
			this->inputBox->Size = System::Drawing::Size(860, 38);
			this->inputBox->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->label1->Location = System::Drawing::Point(355, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(246, 39);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Algo-Visualizer";
			// 
			// bubble
			// 
			this->bubble->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->bubble->Location = System::Drawing::Point(172, 338);
			this->bubble->Name = L"bubble";
			this->bubble->Size = System::Drawing::Size(155, 42);
			this->bubble->TabIndex = 1;
			this->bubble->Text = L"Bubble Sort";
			this->bubble->UseVisualStyleBackColor = true;
			this->bubble->Click += gcnew System::EventHandler(this, &MyForm::Click_btn);
			// 
			// insertion
			// 
			this->insertion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->insertion->Location = System::Drawing::Point(387, 338);
			this->insertion->Name = L"insertion";
			this->insertion->Size = System::Drawing::Size(153, 42);
			this->insertion->TabIndex = 3;
			this->insertion->Text = L"Insertion Sort";
			this->insertion->UseVisualStyleBackColor = true;
			this->insertion->Click += gcnew System::EventHandler(this, &MyForm::Click_btn);
			// 
			// selection
			// 
			this->selection->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->selection->Location = System::Drawing::Point(600, 338);
			this->selection->Name = L"selection";
			this->selection->Size = System::Drawing::Size(158, 42);
			this->selection->TabIndex = 4;
			this->selection->Text = L"Selection Sort";
			this->selection->UseVisualStyleBackColor = true;
			this->selection->Click += gcnew System::EventHandler(this, &MyForm::Click_btn);
			// 
			// merge
			// 
			this->merge->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->merge->Location = System::Drawing::Point(172, 403);
			this->merge->Name = L"merge";
			this->merge->Size = System::Drawing::Size(155, 42);
			this->merge->TabIndex = 5;
			this->merge->Text = L"Merge Sort";
			this->merge->UseVisualStyleBackColor = true;
			this->merge->Click += gcnew System::EventHandler(this, &MyForm::Click_btn);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(960, 540);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->selection);
			this->Controls->Add(this->insertion);
			this->Controls->Add(this->merge);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->bubble);
			this->Controls->Add(this->inputBox);
			this->Name = L"MyForm";
			this->Text = L"Algo-Visualizer";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Collections::Generic::List<int>^ strToArr(String^ inp, String^ delimiter) {
			array<String^>^ tokens = inp->Split(gcnew array<String^> { delimiter }, StringSplitOptions::None);
			System::Collections::Generic::List<int>^ resultList = gcnew System::Collections::Generic::List<int>();
			for each (String ^ token in tokens) {
				int value;
				if (Int32::TryParse(token, value)) {
					resultList->Add(value);
				}
			}
			return resultList;
		}


	private: System::Void Click_btn(System::Object^ sender, System::EventArgs^ e) {
		MyForm2^ form2 = gcnew MyForm2(((System::Windows::Forms::Button^)sender)->Text->ToString(),strToArr(inputBox->Text->ToString(),","));
		form2->ShowDialog();
	}

};
}
