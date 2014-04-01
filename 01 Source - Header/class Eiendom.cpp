#include <iostream>
#include "class Eiendom.h"
#include <cstdlib>																// itoa
#include <fstream>
#include "conster.h"
#include <cstring>

using namespace std;

Eiendom::Eiendom(ifstream & inn, int onr): Num_element(onr)	{
	oppdragsnummer = onr;
	inn >> dato >> bruksnummer
	 	>> ansattnummer	>> pris >> areal;

	char buffer[STRLEN];								//buffer for innlesing
	inn.ignore();
	inn.getline(buffer, STRLEN);						
	gateadresse = new char[strlen(buffer + 1)];
	strcpy(gateadresse, buffer);
	inn.getline(buffer, STRLEN);
	postadresse = new char[strlen(buffer + 1)];
	strcpy(postadresse, buffer);
	inn.getline(buffer, STRLEN);
	eiernavn = new char[strlen(buffer + 1)];
	strcpy(eiernavn, buffer);
	inn.getline(buffer, STRLEN);
	kommunenavn = new char[strlen(buffer + 1)];
	strcpy(kommunenavn, buffer);
	inn.getline(buffer, STRLEN);
	beskrivelse = new char[strlen(buffer + 1)];
	strcpy(beskrivelse, buffer);
	inn.getline(buffer, STRLEN);
	switch (buffer[0])	{
	case 't': eiendomstypen = tomt; break;
	case 'e': eiendomstypen = enebolig; break;
	case 'r': eiendomstypen = rekkehus; break;
	case 'l': eiendomstypen = leilighet; break;
	case 'h': eiendomstypen = hytte; break;
	};
}

void Eiendom::skrivTilFil(ofstream & ut)	{
	//ut << Displaye	
}

bool Eiendom::type()	{
	return 1;
}

// Displayer all informasjon om en eiendom
void Eiendom::display()  {
  cout << "\nOppdragsnummer: " << oppdragsnummer;
	cout << "\nDato: " << dato;
	cout << "\nBruksnummer: " << bruksnummer;
	cout << "\nSaksbehandlerens ansattnummer: " << ansattnummer;
	cout << "\nPris: " << pris;
	cout << "\nAreal: " << areal;
	cout << "\n\nGateadresse: " << gateadresse;
	cout << "\nPostadresse: " << postadresse;
	cout << "\nEier: " << eiernavn;
	cout << "\nKommune: " << kommunenavn;
	cout << "\nBeskrivelse: " << oppdragsnummer;
}

bool Eiendom::finnPostnummer(int postnr)  {
	int pnr;
	pnr = atoi(postadresse);
	if(postnr==pnr)
		return true;
	else
		return false;
}

bool Eiendom::finnOppdragsnr(int oppdnr)  {
	if(oppdnr==oppdragsnummer)
		return true;
	else
		return false;
}
