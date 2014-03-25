#include <iostream>
#include "class Kunde.h"
#include <cstdlib>

using namespace std;

void Kunde::sjekkNrNvn(char* kundeinfo)  {
	int knr;
	knr = atoi(kundeinfo);
	if (knr==kundenummer)
		displayKunde();
	else if (strcmp(kundeinfo,navn)==0)
		displayKunde();

	// TODO SENERE: må også vise informasjon om kundes interessesone
}

void Kunde::displayKunde()  {
	cout << "\n Navn: " << navn;
	cout << "\n Kundenummer: " << kundenummer;
	cout << "\n Telefon: " << tlf;
	cout << "\n E-post: " << mail;
	cout << "\n Adresse: " << gateadresse<<", "<<postadresse;
}	