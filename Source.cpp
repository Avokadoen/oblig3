#include <iostream>				// cin, cout					  |
//#include "ListTool2A.h"		//								  |
#include "LegeResept.h"			// Lege, resept, les, ListTool2A.h|
								//--------------------------------|		




//					GLOBALE FUNKSJONER
void hovedMeny();
void gjentager(char symbol, int lengde);

//					OBJEKT
List* Leger;


//					MAIN
int main() {
	Leger = new List(Sorted);

	Resept* temp;
	char* tempLegeNavn = nullptr;

	char kommando;

	hovedMeny();
	
	do {
		kommando = les("\nMenyvalg: ");
		switch (kommando) {
		case 'R': 
			int Id;
			Lege* reseptGiver;

			cout << endl;
			gjentager('-', 19); cout << " NY RESEPT "; gjentager('-', 19);
			Id = lesDato();
			temp = new Resept(Id);

			//	Be om Legens navn
			les("\nReseptgiver (navn): ", tempLegeNavn);
			
			reseptGiver = (Lege*)Leger->remove(tempLegeNavn);

			if (reseptGiver) { reseptGiver->addResept(temp); }

			else { reseptGiver = new Lege(tempLegeNavn); 
				   reseptGiver->addResept(temp);}

			Leger->add(reseptGiver);
			
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

