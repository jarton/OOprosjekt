#include <iostream>
#include "class Eiendom.h"
#include <cstdlib>																// itoa
#include <fstream>
#include "conster.h"
#include <cstring>
#include "globale funksjoner og variabler.h"
#include "timer3.h"

using namespace std;

//Constructor u/parameter
Eiendom::Eiendom(int oppdragsnr)	{
	char buffer[STRLEN];
	Timer * timer3 = new Timer;
	oppdragsnummer = oppdragsnr;

	dato = timer3->hentDato();
	bruksnummer = lesTall("bruksnummer", 1000, 9999);
	ansattnummer = lesTall("ansattnr", 0, 1000);
	pris = lesTall("pris", 1, 100000000);
	areal = lesTall("areal", 1, 1000);

	lesTxt("gateadresse:", buffer, STRLEN);
	gateadresse = new char[strlen(buffer) + 1];
	strcpy(gateadresse, buffer);
	lesTxt("postadresse:", buffer, STRLEN);
	postadresse = new char[strlen(buffer) + 1];
	strcpy(postadresse, buffer);
	lesTxt("eiernavn:", buffer, STRLEN);
	eiernavn = new char[strlen(buffer) + 1];
	strcpy(eiernavn, buffer);
	lesTxt("komunenavn:", buffer, STRLEN);
	kommunenavn = new char[strlen(buffer) + 1];
	strcpy(kommunenavn, buffer);
	lesTxt("beskrivelse:", buffer, STRLEN);
	beskrivelse = new char[strlen(buffer) + 1];
	strcpy(beskrivelse, buffer);

	lesTxt("type: tomt, enebolig, rekkehus eller hytte", buffer, STRLEN);
	enumSwitch(buffer);
}

//Constructor som leser eiendomsdata fra fil
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
	enumSwitch(buffer);
}

//Skriver alle eiendomsdata til fil 
void Eiendom::skrivTilFil(ofstream & ut)	{
	ut << oppdragsnummer << '\n'
		<< dato << '\n'
		<< bruksnummer << '\n'
		<< ansattnummer << '\n'
		<< pris << '\n' << areal
		<< '\n' << gateadresse
		<< '\n' << postadresse
		<< '\n' << eiernavn
		<< '\n' << kommunenavn
		<< '\n' << beskrivelse
		<< '\n';
	if (eiendomstypen == tomt)
		ut << "tomt";
	else if (eiendomstypen == enebolig)
		ut << "enebolig";
	else if (eiendomstypen == rekkehus)
		ut << "rekkehus";
	else if (eiendomstypen == leilighet)
		ut << "rekkehust";
	else
		ut << "hytte";
}

void Eiendom::enumSwitch(char * b)	{
	switch (b[0])	{
	case 't': eiendomstypen = tomt; break;
	case 'e': eiendomstypen = enebolig; break;
	case 'r': eiendomstypen = rekkehus; break;
	case 'l': eiendomstypen = leilighet; break;
	case 'h': eiendomstypen = hytte; break;
	};
}

//Returnerer 1 om det er en eiendom
bool Eiendom::type()	{
	return 1;
}

// Displayer all informasjon om en eiendom
void Eiendom::display()  {
  cout << "\n\nOppdragsnummer: " << oppdragsnummer;
	cout << "\nDato: " << dato;
	cout << "\nBruksnummer: " << bruksnummer;
	cout << "\nSaksbehandlerens ansattnummer: " << ansattnummer;
	cout << "\nPris: " << pris;
	cout << "\nAreal: " << areal;
	cout << "\n\nGateadresse: " << gateadresse;
	cout << "\nPostadresse: " << postadresse;
	cout << "\nEier: " << eiernavn;
	cout << "\nKommune: " << kommunenavn;
	cout << "\nBeskrivelse: " << beskrivelse << "\n\n";
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
