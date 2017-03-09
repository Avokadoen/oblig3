#ifndef LegeResept
#define LegeResept

//		LISTTOOL
#include "ListTool2A.h"

//		GLOBALE VARIABLER
const int MAXTXT = 80;
const int MAXRSPT = 50;
const int MAXLEGR = 100;

//		KLASSER
class Resept : NumElement  {
private:
	char* pasientNavn;
	char* medisinNavn;
	int dosering;
public:
	Resept() {
		number = lesDato();
		les("\nPasientnavn: ", pasientNavn);
		// sp¯r om legenavn
		// hvis finnes legg resept i liste
		// ellers lag ny lege og legg i liste
		les("\nMedisintype: ", medisinNavn);

	}
};

class Lege : TextElement {
private:
	Resept* resepter[MAXRSPT];
	char* navn;
	char* adresse;
	int telefon;
	int antResepter;
};

//		LESFUNKSJONER

// Les inn pointer tekst
void les(char* skriv, char* input) {
	char temp[MAXTXT];
	cout << skriv;
	cin.getline(temp, MAXTXT);
	input = new char[strlen(temp) + 1];
	strcpy_s(input, MAXTXT, temp);
}

// les inn en karakter
char les(char* skriv) {
	char temp;
	cout << skriv; cin >> temp;
	return (toupper(temp));
}

// les inn tall
int les(char* skriv, int min, int max) {
	int temp;
	do {
		cout << "\n\t" << min << " til " << max << endl;
		cout << skriv; cin >> temp;
	} while (temp < min && temp > max);

	return temp;
}

// Leser inn dato for resept (indirekte)
int lesDato() {
	int temp≈r, tempMÂn, tempDag;
	temp≈r = les("\nReseptaar: ", 2015, 2025);
	tempMÂn = les("\nReseptmaaned: ", 1, 12);
	tempDag = les("\nReseptdag: ", 1, 31);
	return((temp≈r * 10000) + (tempMÂn * 100) + tempDag);
}
#endif
