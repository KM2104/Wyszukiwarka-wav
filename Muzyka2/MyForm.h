#pragma once

namespace Muzyka2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtPlik;
	private: System::Windows::Forms::Button^ btnPlik;
	protected:



	protected:

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ btnGraj;



	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtPlik = (gcnew System::Windows::Forms::TextBox());
			this->btnPlik = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->btnGraj = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtPlik
			// 
			this->txtPlik->Location = System::Drawing::Point(12, 31);
			this->txtPlik->Name = L"txtPlik";
			this->txtPlik->Size = System::Drawing::Size(517, 20);
			this->txtPlik->TabIndex = 0;
			// 
			// btnPlik
			// 
			this->btnPlik->Location = System::Drawing::Point(558, 31);
			this->btnPlik->Name = L"btnPlik";
			this->btnPlik->Size = System::Drawing::Size(75, 23);
			this->btnPlik->TabIndex = 1;
			this->btnPlik->Text = L"Wybierz plik";
			this->btnPlik->UseVisualStyleBackColor = true;
			this->btnPlik->Click += gcnew System::EventHandler(this, &MyForm::btnPlik_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(153, 139);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Beep";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// btnGraj
			// 
			this->btnGraj->Location = System::Drawing::Point(379, 139);
			this->btnGraj->Name = L"btnGraj";
			this->btnGraj->Size = System::Drawing::Size(75, 23);
			this->btnGraj->TabIndex = 3;
			this->btnGraj->Text = L"Odtwórz";
			this->btnGraj->UseVisualStyleBackColor = true;
			this->btnGraj->Click += gcnew System::EventHandler(this, &MyForm::btnGraj_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(645, 191);
			this->Controls->Add(this->btnGraj);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->btnPlik);
			this->Controls->Add(this->txtPlik);
			this->Name = L"MyForm";
			this->Text = L"DŸwiêki";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Console::Beep();
	}
	private: System::Void btnPlik_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ plik = gcnew OpenFileDialog;    //OtwarcieOknaDialogowego dla nowego obiektu plik 
		plik->Title = "Otwórz plik audio";              // nazwa okna dialogowego
		plik->Filter = "Pliki wav | *.wav";             //filtr dla plików typu wav w oknie dialogowym
			  //je¿eli otwarcie obiektu plik == bêdzie w formie potwierdzone (OK) to
		      // w oknie textowym txtPlik pojawi siê tekst nazwy pliku
		if (plik->ShowDialog() == Windows::Forms::DialogResult::OK) {
			txtPlik->Text = plik->FileName;
		}

	}
private: System::Void btnGraj_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		//otwarcie obiektu graj dla odtwarzacza systemowego
		System::Media::SoundPlayer^ graj = gcnew System::Media::SoundPlayer();
		graj->SoundLocation = txtPlik->Text;   //pokazanie lokalizacji pliku w obiekcie graj
		graj->Load();                          //za³adowanie pliku
		graj->Play();                          //odtworzenie pliku
	}
	catch (...) 
	{
	    // coœ posz³o nie tak b³¹d  
	}
}
};
}
