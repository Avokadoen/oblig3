#ifndef LegeResept
#define LegeResept

#include "ListTool2A.h"

class Resept : NumElement  {
private:
	char* pasientNavn;
	char* medisinNavn;
	int dosering;
};

class Lege : TextElement {
private:
	char* navn;
	char* adresse;
	int telefon;

};


#endif
