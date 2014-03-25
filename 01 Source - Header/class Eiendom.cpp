#include <iostream>
#include "class Eiendom.h"
#include <cstdlib>																// itoa

using namespace std;


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
