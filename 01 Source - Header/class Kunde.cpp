#include <iostream>
#include "class Kunde.h"
#include <cstdlib>
#include "conster.h"
#include "globale funksjoner og variabler.h"
#include "class IntrSone.h"

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
	//Denne funksjonen slettes sikkert senere..
	

}


Kunde :: Kunde(int knr) : Num_element(knr) {
	char ch[STRLEN];
	char kommando;
	int tall;
	IntrSone* intrsonen; // Peker til intrsone-objekt
	IntrSone* intrsonekopi; // Peker til kopiobjekt.

	tlf = lesTall("\nTelefon ", 10000000, 99999999); //Leser tlf-nummer

	lesTxt("\nNavn", ch, STRLEN); //leser navn
	navn = new char[strlen(ch)+1];
	strcpy(navn, ch);

	lesTxt("\nGateadresse", ch, STRLEN); //leser gateadresse
	gateadresse = new char[strlen(ch)+1];
	strcpy(gateadresse, ch);

	lesTxt("\nPostnummer", ch, STRLEN); //leser postnummer
	postadresse = new char[strlen(ch)+1];
	strcpy(postadresse, ch);

	lesTxt("\nE-post", ch, STRLEN); // leser mail
	mail = new char[strlen(ch)+1];
	strcpy(mail, ch);

	IntrSoneliste = new List(Sorted); //lager IntrSone-liste.
	
	intrsonen = new IntrSone; //Nytt IntrSone objekt..
	IntrSoneliste->add(intrsonen); //Legger det til i listen.
	
	cout << "\nLegge til en ny sone? (J/N)";
	kommando = les();

	while (kommando == 'J') { //Hvis "ja".
		intrsonekopi = new IntrSone(*intrsonen); //Forsøk på default copy constructor..
		int sonenr = lesTall("\nSonenummer", 1, 100); //Leser sonenummer.
		intrsonekopi->endreSonenr(sonenr);
		IntrSoneliste->add(intrsonekopi); //Legger til kopien.
		cout << "\n\nLegge til en ny sone? (J/N)";
		kommando = les();
	}
	

}
