#pragma once

#include "Company.h"
#include "AdminForm.h"
#include "ClientForm.h"

namespace CarRent {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CompanyForm
	/// </summary>
	public ref class CompanyForm : public System::Windows::Forms::Form
	{
	public:
		CompanyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			company = new Company(100000);
			char s[10];
			itoa(company->getMoney(), s, 10);
			label5->Text = gcnew String(s);
			carIndex = 0;
			adm = new Admin("Takashi", "1111");
			company->setAdm(adm);
			textBox3->Text = gcnew String(company->getAdm()->getName().data());
			textBox4->Text = gcnew String(company->getAdm()->getPass().data());
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CompanyForm()
		{
			if(company)
			{
				delete company;
				company = NULL;
			}
			if(adm)
			{
				//delete adm;
				adm = NULL;
			}
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;

	private: System::Windows::Forms::ToolStripMenuItem^  administratorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  clientToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;


	protected: 

	private:
		Company* company;
		int carIndex;
		Admin* adm;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Button^  button4;
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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->administratorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clientToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->administratorToolStripMenuItem, 
				this->clientToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(690, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// administratorToolStripMenuItem
			// 
			this->administratorToolStripMenuItem->Name = L"administratorToolStripMenuItem";
			this->administratorToolStripMenuItem->Size = System::Drawing::Size(92, 20);
			this->administratorToolStripMenuItem->Text = L"Administrator";
			this->administratorToolStripMenuItem->Click += gcnew System::EventHandler(this, &CompanyForm::administratorToolStripMenuItem_Click);
			// 
			// clientToolStripMenuItem
			// 
			this->clientToolStripMenuItem->Name = L"clientToolStripMenuItem";
			this->clientToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->clientToolStripMenuItem->Text = L"Client";
			this->clientToolStripMenuItem->Click += gcnew System::EventHandler(this, &CompanyForm::clientToolStripMenuItem_Click);
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(463, 63);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(103, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(392, 135);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(55, 47);
			this->button1->TabIndex = 2;
			this->button1->Text = L"<";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &CompanyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(577, 135);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(55, 47);
			this->button2->TabIndex = 3;
			this->button2->Text = L">";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &CompanyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(479, 146);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(71, 25);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Add";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &CompanyForm::button3_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(587, 66);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(45, 17);
			this->checkBox1->TabIndex = 5;
			this->checkBox1->Text = L"Add";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &CompanyForm::checkBox1_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(389, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(31, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Cars:";
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(463, 103);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 7;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(424, 47);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(39, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Model:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(424, 86);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Price ($):";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(21, 24);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(42, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Money:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(69, 24);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"label5";
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(238, 89);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(63, 17);
			this->checkBox2->TabIndex = 12;
			this->checkBox2->Text = L"Change";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &CompanyForm::checkBox2_CheckedChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(24, 47);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(39, 13);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Admin:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(59, 70);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(38, 13);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Name:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(59, 122);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(56, 13);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Password:";
			// 
			// textBox3
			// 
			this->textBox3->Enabled = false;
			this->textBox3->Location = System::Drawing::Point(93, 86);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 16;
			// 
			// textBox4
			// 
			this->textBox4->Enabled = false;
			this->textBox4->Location = System::Drawing::Point(93, 146);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 17;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(105, 182);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 18;
			this->button4->Text = L"Save";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &CompanyForm::button4_Click);
			// 
			// CompanyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(690, 418);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"CompanyForm";
			this->Text = L"CompanyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void administratorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 AdminForm^ admin_form= gcnew AdminForm(company);
				 admin_form->ShowDialog();
				 char s[10];
				 itoa(company->getMoney(), s, 10);
				 label5->Text = gcnew String(s);
			 }
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if(checkBox1->Checked)
			{
				textBox1->Enabled = true;
				textBox2->Enabled = true;
				button1->Enabled = false;
				button2->Enabled = false;
				button3->Enabled = true;
			}
			else
			{
				textBox1->Enabled = false;
				textBox2->Enabled = false;
				button1->Enabled = false;
				button2->Enabled = false;
				button3->Enabled = false;
				if(company->getCars().size() > 0)
				{
					textBox1->Text = gcnew String(company->getCars()[carIndex].getName().data());
					char s[10];
					itoa(company->getCars()[carIndex].getPrice(), s, 10);
					textBox2->Text = gcnew String(s);
					if(carIndex < company->getCars().size())
						button2->Enabled = true;
					if(carIndex > 0)
						button1->Enabled = true;
				}
			}
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(textBox1->Text != "" && textBox2->Text != "")
			 {
				string name;
				string price;
				for(int i = 0; i < textBox1->Text->Length; i++)
					name += (char)textBox1->Text[i];
				for(int i = 0; i < textBox2->Text->Length; i++)
					price += (char)textBox2->Text[i];
				Car newCar(name, 1.15 * atoi(price.data()));
				company->addCar(newCar);
				carIndex = 0;
				company->changeMoney(-atoi(price.data()));
				char s[10];
				itoa(company->getMoney(), s, 10);
				label5->Text = gcnew String(s);
			 }
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			if(carIndex > 0)
			{
				carIndex--;
				textBox1->Text = gcnew String(company->getCars()[carIndex].getName().data());
				char s[10];
				itoa(company->getCars()[carIndex].getPrice(), s, 10);
				textBox2->Text = gcnew String(s);
				if(carIndex <= 0)
					button1->Enabled = false;
				if(carIndex <= company->getCars().size() - 1)
					 button2->Enabled = true;
			}
		}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(carIndex < company->getCars().size() - 1)
			 {
				 carIndex++;
				 textBox1->Text = gcnew String(company->getCars()[carIndex].getName().data());
				 char s[10];
				 itoa(company->getCars()[carIndex].getPrice(), s, 10);
				 textBox2->Text = gcnew String(s);
				 if(carIndex >= company->getCars().size() - 1)
					 button2->Enabled = false;
				 if(carIndex >= 0)
					 button1->Enabled = true;
			 }
		 }
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(checkBox2->Checked)
			 {
				 textBox3->Enabled = true;
				 textBox4->Enabled = true;
			 }
			 else
			 {
				 textBox3->Enabled = false;
				 textBox4->Enabled = false;
				 textBox3->Text = gcnew String(company->getAdm()->getName().data());
				 textBox4->Text = gcnew String(company->getAdm()->getPass().data());
			 }
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(textBox3->Text != "" && textBox4->Text != "")
			 {
				 string tmp;
				 for(int i = 0; i < textBox3->Text->Length; i++)
					tmp += (char)textBox3->Text[i];
				 company->getAdm()->setName((char*)tmp.data());
				 tmp.clear();
				 for(int i = 0; i < textBox4->Text->Length; i++)
					tmp += (char)textBox4->Text[i];
				 company->getAdm()->setPass((char*)tmp.data());
			 }
		 }
private: System::Void clientToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			ClientForm^ client_form= gcnew ClientForm(company);
			client_form->ShowDialog();
		 }
};
}
