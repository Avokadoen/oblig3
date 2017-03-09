#include <iostream>				// cin, cout
//#include "ListTool2A.h"		// 
#include "LegeResept.h"			// class Lege, resept og ListTool2A.h


//					GLOBALE CONST VARIABLER
const int MAXTXT = 80;

//					GLOBALE FUNKSJONER
void hovedMeny();
void gjentager(char symbol, int lengde);

void les(char* t, char* input);


int main() {
	hovedMeny();
	system("pause");
	return 0;
}

void hovedMeny() {
	cout << endl;
	cout << "\t"; gjentager('-', 20); cout << "HOVEDMENY"; gjentager('-', 20);
	cout << "\n\n"
		 << "\tR = Registrer en ny resept\n"
		 << "\tL = Lag oversikt over reseptene fra en bestemt lege\n"
		 << "\tP = Lag oversikt over resepter til en bestemt pasient\n"
		 << "\tF = Fjern alle gamle resepter\n"
		 << "\tU = Skriv ut til fil\n"
		 << "\tP = Lag oversikt over resepter til en bestemt pasient\n"
		 << "\tI = Les inn fra fil \n"
		 << "\tH = Hjelp\n"
		 << "\tQ = Quit \n";
}

void gjentager(char symbol, int lengde) {
	for (int i = 0; i < lengde; i++)
		cout << symbol;
}

void les(char* tekst, char* input) {
	char temp[MAXTXT];
	cout << tekst;
	cin.getline(temp, MAXTXT);
	input = new char[strlen(temp) + 1];
	strcpy_s(input, MAXTXT, temp);
}