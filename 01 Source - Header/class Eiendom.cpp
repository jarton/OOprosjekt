#include <iostream>
#include "class Eiendom.h"

using namespace std;

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

	// oppdragsnummer, dato, bruksnummer, ansattnummer, pris, areal;
	// gateadresse, postadresse, eiernavn, kommunenavn, beskrivelse;