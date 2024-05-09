#pragma once
#include <string>
#include <windows.h>
#include <tlhelp32.h>
#include <map>

#include "InitDll.h"
#include "Utils.h"
#include "Process.h"

namespace dllinjectorsc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Diagnostics;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for main
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ comboBoxProcessesList;
	private: System::Windows::Forms::Button^ btnAddDll;
	private: System::Windows::Forms::CheckedListBox^ chListBoxDlls;
	private: System::Windows::Forms::Button^ btnClearList;
	private: System::Windows::Forms::Button^ btnRemoveChecked;
	private: System::Windows::Forms::Button^ btnInject;
	private: System::Windows::Forms::TextBox^ textBoxProcessName;

	private: System::Windows::Forms::Label^ labelProcessName;


	protected:

	protected:

	protected:


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->comboBoxProcessesList = (gcnew System::Windows::Forms::ComboBox());
			this->btnAddDll = (gcnew System::Windows::Forms::Button());
			this->chListBoxDlls = (gcnew System::Windows::Forms::CheckedListBox());
			this->btnClearList = (gcnew System::Windows::Forms::Button());
			this->btnRemoveChecked = (gcnew System::Windows::Forms::Button());
			this->btnInject = (gcnew System::Windows::Forms::Button());
			this->textBoxProcessName = (gcnew System::Windows::Forms::TextBox());
			this->labelProcessName = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// comboBoxProcessesList
			// 
			this->comboBoxProcessesList->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->comboBoxProcessesList->DropDownHeight = 250;
			this->comboBoxProcessesList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->comboBoxProcessesList->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(204)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->comboBoxProcessesList->FormattingEnabled = true;
			this->comboBoxProcessesList->IntegralHeight = false;
			this->comboBoxProcessesList->ItemHeight = 16;
			this->comboBoxProcessesList->Location = System::Drawing::Point(21, 12);
			this->comboBoxProcessesList->Name = L"comboBoxProcessesList";
			this->comboBoxProcessesList->Size = System::Drawing::Size(536, 24);
			this->comboBoxProcessesList->TabIndex = 0;
			this->comboBoxProcessesList->Click += gcnew System::EventHandler(this, &MainForm::comboBoxProcessesList_Click);
			// 
			// btnAddDll
			// 
			this->btnAddDll->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(16)));
			this->btnAddDll->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnAddDll->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(204)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->btnAddDll->Location = System::Drawing::Point(21, 77);
			this->btnAddDll->Name = L"btnAddDll";
			this->btnAddDll->Size = System::Drawing::Size(100, 35);
			this->btnAddDll->TabIndex = 1;
			this->btnAddDll->Text = L"Add DLL";
			this->btnAddDll->UseVisualStyleBackColor = false;
			this->btnAddDll->Click += gcnew System::EventHandler(this, &MainForm::btnAddDll_Click);
			// 
			// chListBoxDlls
			// 
			this->chListBoxDlls->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->chListBoxDlls->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->chListBoxDlls->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(204)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->chListBoxDlls->FormattingEnabled = true;
			this->chListBoxDlls->Location = System::Drawing::Point(21, 118);
			this->chListBoxDlls->Name = L"chListBoxDlls";
			this->chListBoxDlls->Size = System::Drawing::Size(536, 202);
			this->chListBoxDlls->TabIndex = 2;
			// 
			// btnClearList
			// 
			this->btnClearList->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(16)));
			this->btnClearList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnClearList->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(204)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->btnClearList->Location = System::Drawing::Point(447, 77);
			this->btnClearList->Name = L"btnClearList";
			this->btnClearList->Size = System::Drawing::Size(110, 35);
			this->btnClearList->TabIndex = 3;
			this->btnClearList->Text = L"Clear List";
			this->btnClearList->UseVisualStyleBackColor = false;
			this->btnClearList->Click += gcnew System::EventHandler(this, &MainForm::btnClearList_Click);
			// 
			// btnRemoveChecked
			// 
			this->btnRemoveChecked->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(16)));
			this->btnRemoveChecked->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnRemoveChecked->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(204)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->btnRemoveChecked->Location = System::Drawing::Point(261, 77);
			this->btnRemoveChecked->Name = L"btnRemoveChecked";
			this->btnRemoveChecked->Size = System::Drawing::Size(180, 35);
			this->btnRemoveChecked->TabIndex = 4;
			this->btnRemoveChecked->Text = L"Remove Checked";
			this->btnRemoveChecked->UseVisualStyleBackColor = false;
			this->btnRemoveChecked->Click += gcnew System::EventHandler(this, &MainForm::btnRemoveChecked_Click);
			// 
			// btnInject
			// 
			this->btnInject->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(16)));
			this->btnInject->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnInject->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(204)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->btnInject->Location = System::Drawing::Point(214, 344);
			this->btnInject->Name = L"btnInject";
			this->btnInject->Size = System::Drawing::Size(150, 35);
			this->btnInject->TabIndex = 5;
			this->btnInject->Text = L"Inject";
			this->btnInject->UseVisualStyleBackColor = false;
			this->btnInject->Click += gcnew System::EventHandler(this, &MainForm::btnInject_Click);
			// 
			// textBoxProcessName
			// 
			this->textBoxProcessName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->textBoxProcessName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold));
			this->textBoxProcessName->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(204)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->textBoxProcessName->Location = System::Drawing::Point(136, 42);
			this->textBoxProcessName->Name = L"textBoxProcessName";
			this->textBoxProcessName->Size = System::Drawing::Size(421, 24);
			this->textBoxProcessName->TabIndex = 6;
			// 
			// labelProcessName
			// 
			this->labelProcessName->AutoSize = true;
			this->labelProcessName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->labelProcessName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F));
			this->labelProcessName->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(204)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->labelProcessName->Location = System::Drawing::Point(18, 45);
			this->labelProcessName->Name = L"labelProcessName";
			this->labelProcessName->Size = System::Drawing::Size(112, 18);
			this->labelProcessName->TabIndex = 7;
			this->labelProcessName->Text = L"Process Name:";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->ClientSize = System::Drawing::Size(578, 744);
			this->Controls->Add(this->labelProcessName);
			this->Controls->Add(this->textBoxProcessName);
			this->Controls->Add(this->btnInject);
			this->Controls->Add(this->btnRemoveChecked);
			this->Controls->Add(this->btnClearList);
			this->Controls->Add(this->chListBoxDlls);
			this->Controls->Add(this->btnAddDll);
			this->Controls->Add(this->comboBoxProcessesList);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->Text = L"Dll Injector by FuDeeP";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void comboBoxProcessesList_Click(System::Object^ sender, System::EventArgs^ e) {
		this->comboBoxProcessesList->Items->Clear();
		InitProcessList();

		for (std::map<CHAR*, DWORD, cmp_str>::iterator it = processes.begin(); it != processes.end(); it++) {
			this->comboBoxProcessesList->Items->Add(gcnew String(it->first) + "|" + it->second.ToString());
		}
	}
	private: System::Void btnAddDll_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;

		openFileDialog->Filter = "(*.dll)|*.dll";

		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			this->chListBoxDlls->Items->Add(openFileDialog->FileName->ToString());
	}
	private: System::Void btnClearList_Click(System::Object^ sender, System::EventArgs^ e) {
		this->chListBoxDlls->Items->Clear();
	}
	private: System::Void btnRemoveChecked_Click(System::Object^ sender, System::EventArgs^ e) {
		while (this->chListBoxDlls->CheckedItems->Count > 0)
			this->chListBoxDlls->Items->RemoveAt(this->chListBoxDlls->CheckedIndices[0]);
	}
	private: System::Void btnInject_Click(System::Object^ sender, System::EventArgs^ e) {
		HANDLE processHandle;

		if (this->textBoxProcessName->Text->Length <= 0) {
			if (this->comboBoxProcessesList->Text->Length > 0) {
				CHAR* selectedItem = ToCHAR(this->comboBoxProcessesList->Text);
				CHAR* processName = std::strtok(selectedItem, "|");
				CHAR* processNameStr;
				if (processName != nullptr)
					processNameStr = processName;

				for each (auto control in this->Controls->Find("labelInject", false)) {
					this->Controls->Remove(control);
				}

				processHandle = OpenProcess(PROCESS_ALL_ACCESS, NULL, processes[processNameStr]);
			}
		}
		else {
			DWORD processId = getPIDByName(ToWstring(this->textBoxProcessName->Text->ToString()));
			processHandle = OpenProcess(PROCESS_ALL_ACCESS, NULL, processId);
		}

		if (processHandle != NULL) {
			int index = 0;

			for each (auto item in this->chListBoxDlls->CheckedItems)
			{
				CHAR* path = ToCHAR(item->ToString());

				if (FileExists(path))
				{
					Label^ label = gcnew Label;

					if (InjectDLL(processHandle, path))
					{
						label->Text = gcnew String(path) + " - INJECTED";
						label->ForeColor = Color::SpringGreen;
					}
					else
					{
						label->Text = gcnew String(path) + " - NOT INJECTED";
						label->ForeColor = Color::Red;
					}

					label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					label->Location = System::Drawing::Point(10, 400 + index * 40);
					label->Name = L"labelInject";
					label->Size = System::Drawing::Size(580, 35);
					this->Controls->Add(label);
					index++;
				}
			}
		}
	}
	};
}
