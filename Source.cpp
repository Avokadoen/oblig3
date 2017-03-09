#include <iostream>				// cin, cout					  |
//#include "ListTool2A.h"		//								  |
#include "LegeResept.h"			// Lege, resept, les, ListTool2A.h|
								//--------------------------------|		




//					GLOBALE FUNKSJONER
void hovedMeny();
void gjentager(char symbol, int lengde);

//					OBJEKT
Lege* leger[MAXLEGR];

// 
int antLeger;

//					MAIN
int main() {
	antLeger = 0;

	char kommando;

	hovedMeny();
	
	do {
		kommando = les("\nMenyvalg: ");
		switch (kommando) {
		case 'R': 
			
			char* tempLegeNavn;
			//Bekreft valgt kommando
			cout << endl;
			gjentager('-', 19); cout << " NY RESEPT "; gjentager('-', 19);
			//	lag en ny resept
			Resept* temp = new Resept; 
		

			//	Be om dato(i format ÅÅÅÅMMDD i interval 2015 - 2025, 01 - 12, 0 - 31) //lesfunk*
			//	Be om pasientens navn(kanskje sjekke om den har "x y")
			//	Be om Legens navn
			les("\nReseptgiver (navn): ", tempLegeNavn);
			for (int i = 0; i < antLeger; i++) {
				leger[i]->inList(tempLegeNavn);
			}
			//	if (eksisterer) { (sett objekt inn i lege objekt og sorter)*funk ? }
			//	else { ny lege(-|| -)*funk ? }
			//	Be om medisinens navn(Det er ialt ca. 50 forskjellige narkotiske stoffer ? )
			//		Be om dosering i milligram(intervall 1 - 1000)
			
			break;

		case 'L':
			break;
		case 'P':
			break;
		case 'F':
			break;
		case 'U':
			break;
		case 'I':
			break;

		case 'H': hovedMeny(); break; // Kaller på meny

		case 'Q':					  // Avslutter program
			char avsluttSvar;
			do{	// Går ikke ut av case før man har svart J

				// Bruker blir spurt om å lagre
				avsluttSvar = les("\n\t\tAvslutter program\n\n Onsker du aa lagre (j | n): ");
				if (avsluttSvar == 'J') {
					cout << "\n\nLagrer til fil..";
					// #lagre fil
				}

				else {
					// Hvis bruker velgger å ikke lagre så må han/hun bekrefte
					avsluttSvar = les("\nEr du sikker?(j | n): ");
				}
			} while (avsluttSvar != 'J');
			break;

		}
	} while (kommando != 'Q');

	// Avslutter program
	cout << "\nHa en fin dag videre.";
	return 0;
}

//
void hovedMeny() {
	cout << endl;
	cout << "\t"; gjentager('-', 20); cout << "HOVEDMENY"; gjentager('-', 20);
	cout << "\n\n"
		 << "\tR = Registrer en ny resept\n"
		 << "\tL = Lag oversikt over reseptene fra en bestemt lege\n"
		 << "\tP = Lag oversikt over resepter til en bestemt pasient\n"
		 << "\tF = Fjern alle gamle resepter\n"
		 << "\tU = Skriv ut til fil\n"
		 << "\tI = Les inn fra fil \n"
		 << "\tH = Hjelp\n"
		 << "\tQ = Quit \n";
}

void gjentager(char symbol, int lengde) {
	for (int i = 0; i < lengde; i++)
		cout << symbol;
}
//

