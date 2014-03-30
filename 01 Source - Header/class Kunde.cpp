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

IntrSone* Kunde :: nyeIntrSoner(){
	int pstnr = lesTall("Hvilket postnummer er kunden interessert i?", 1000, 9999);

	

}


void Kunde :: Kunde(int knr) : Num_element(knr) {
	char ch[STRLEN];
	char kommando;
	int tall;
	IntrSone* intrsonen; // Peker til intrsone-objekt
	Intrsone* intrsonekopi; // Peker til kopiobjekt.

	tlf = lesTall("\nTelefon ", 10000000, 99999999); //Leser tlf-nummer

	les("\nNavn", ch, STRLEN); //leser navn
	navn = ch;

	les("\nGateadresse", ch, STRLEN); //leser gateadresse
	gateadresse = ch;

	les("\nPostnummer", ch, STRLEN); //leser postnummer
	postadresse = ch;

	les("\nE-post", ch, STRLEN); // leser mail
	mail = ch;

	IntrSoneliste = new List(Sorted); //lager IntrSone-liste.
	
	intrsonen = new IntrSone; //Nytt IntrSone objekt..
	IntrSoneliste->add(intrsonen); //Legger det til i listen.
	
	cout << "\nLegge til en ny sone? (J/N)";
	kommando = les();

	while (kommando == 'J') { //Hvis "ja".
		intrsonekopi = new IntrSone(intrsonen); //Forsøk på default copy constructor..
		intrsonekopi->number = les("\nPostnummer", 1000, 9999); //Leser postnummer.
		IntrSoneliste->add(intrsonekopi); //Legger til kopien.
		cout << "\n\nLegge til en ny sone? (J/N)";
		kommando = les();
	}
	

}
