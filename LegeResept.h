#ifndef LegeResept
#define LegeResept

//		LISTTOOL
#include "ListTool2A.h"

//		GLOBALE VARIABLER
const int MAXTXT = 80;
const int MAXLEGR = 100;

//		LESFUNKSJONER
void les(char* skriv, char*& input);
char les(char* skriv);
int  les(char* skriv, int min, int max);
int  lesDato();

//		KLASSER
class Resept : public NumElement  {
private:
	char* pasientNavn;
	char* medisinNavn;
	int dosering;
public:
	Resept() {
		cout << "\n\nResept mÂ ha int parameter!\n";
	}

	Resept(int id) : NumElement(id) {
		cin.ignore();
		les("\nPasientnavn: ", pasientNavn);
		// sp¯r om legenavn
		// hvis finnes legg resept i liste
		// ellers lag ny lege og legg i liste
		les("\nMedisintype: ", medisinNavn);

	}
};

class Lege : public TextElement {
private:
	List* resepter;
	char* adresse;
	int telefon;
public:
	Lege() {
		cout << "\n\nFeil tilkalling av et Legeobjekt\n";
	}

	Lege(char* lNavn) : TextElement(lNavn){
		les("\nAdresse: ", adresse);
		telefon = ("\nTelefonnummer: ", 10000000, 99999999);
	}

	void addResept(Resept* ny) {
		resepter->add(ny);
	}
};

//		LESFUNKSJONER

// Les inn pointer tekst
void les(char* skriv, char*& input) {
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
		cout << "\n\t" << min << " til " << max;
		cout << "\n\t" << skriv; cin >> temp;
	} while (temp < min || temp > max);

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
