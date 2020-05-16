#pragma once

namespace codex {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for form_about
	/// </summary>
	public ref class form_about : public System::Windows::Forms::Form
	{
	public:
		form_about(void)
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
		~form_about()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pic_codex;
	private: System::Windows::Forms::Label^  lbl_dev;
	protected:

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
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(form_about::typeid));
			this->pic_codex = (gcnew System::Windows::Forms::PictureBox());
			this->lbl_dev = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_codex))->BeginInit();
			this->SuspendLayout();
			// 
			// pic_codex
			// 
			this->pic_codex->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pic_codex.Image")));
			this->pic_codex->Location = System::Drawing::Point(12, 12);
			this->pic_codex->MaximumSize = System::Drawing::Size(570, 320);
			this->pic_codex->MinimumSize = System::Drawing::Size(570, 320);
			this->pic_codex->Name = L"pic_codex";
			this->pic_codex->Size = System::Drawing::Size(570, 320);
			this->pic_codex->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pic_codex->TabIndex = 0;
			this->pic_codex->TabStop = false;
			this->pic_codex->Click += gcnew System::EventHandler(this, &form_about::codex_Click);
			// 
			// lbl_dev
			// 
			this->lbl_dev->AutoSize = true;
			this->lbl_dev->ForeColor = System::Drawing::Color::White;
			this->lbl_dev->Location = System::Drawing::Point(540, 332);
			this->lbl_dev->MaximumSize = System::Drawing::Size(42, 13);
			this->lbl_dev->MinimumSize = System::Drawing::Size(42, 13);
			this->lbl_dev->Name = L"lbl_dev";
			this->lbl_dev->Size = System::Drawing::Size(42, 13);
			this->lbl_dev->TabIndex = 1;
			this->lbl_dev->Text = L"quosego";
			// 
			// form_about
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(594, 354);
			this->ControlBox = false;
			this->Controls->Add(this->lbl_dev);
			this->Controls->Add(this->pic_codex);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(600, 360);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(600, 360);
			this->Name = L"form_about";
			this->Opacity = 0.9;
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->TopMost = true;
			this->Click += gcnew System::EventHandler(this, &form_about::form_about_Click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_codex))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void form_about_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Close();
	}
	private: System::Void codex_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Close();
	}
	};
}
