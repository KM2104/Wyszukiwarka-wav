#include "MyForm.h"

using namespace Muzyka2;                      //przestrzeñ nazw systemu
using namespace System::Windows::Forms;      //przestrzeñ nazw form systemu Windows

[STAThreadAttribute]                         //komunikacja z komponentami com

int main(array<String^>^ args) {

	Application::EnableVisualStyles();       //w³¹czamy wizualny tryb aplikacji();
	Application::SetCompatibleTextRenderingDefault(false);     //ustawiamy  
						//aplikacje www które bêd¹ domyœlnie wy³¹czone(false);

	Muzyka2::MyForm forms;    //odwo³ujemy siê do naszej aplikacji :: tworzymy
										//formê Plansza 
	Application::Run(% forms);          //Uruchamiamy aplikacjê
	return 0;
}

/*
   UWAGI do wprowadzenia
   1. Je¿eli nie wyœwietlany po utworzeniu projekt okienko formularza tylko b³¹d lub sam
	  kod to : zamykamy Visual Studio i jeszcze raz uruchamiamy
	  je¿eli nie zadzia³a to :
	  zmieniamy we w³aœciwoœciach konfiguracyjnych ogólnych formularza zawartoœæ na tak.
   2. Nazwa projektu (PPM) W³aœciwoœci -> konsolidator -> system -> podsystem ustawiamy
	  na Okna (/SUBSYSTEM:WINDOWS)
   3. Nazwa projektu (PPM) W³aœciwoœci -> konsolidator -> zaawansowane -> punkt wejœcia ustawiamy
	  na nazwê funkcji g³ównej u nas w tym projekcie main

*/