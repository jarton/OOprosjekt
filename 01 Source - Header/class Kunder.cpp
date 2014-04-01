#include <iostream>
#include <fstream>
#include "class Kunder.h"
#include "class Kunde.h"
#include "conster.h"
#include "globale funksjoner og variabler.h"
using namespace std;

void Kunder::fortsettelseMeny()  {
	char valg;
	char kundeinfo[STRLEN];

	valg = les();
	switch(valg) {
		case 'D': cin.getline(kundeinfo,STRLEN); 
		finnKunde(kundeinfo);	break;
		case 'N': nyKunde(); break;
		case 'S': break;
		case 'E': break;
		default: break;
	 }
}

void Kunder::finnKunde(char* kundeinfo)  {
	Kunde* kunde;
	//List* kundeliste;
	int i;

	for(i=1; i<=sisteKunde; i++)  { 
	kunde = (Kunde*) kundeliste->remove_no(i);
	kunde->sjekkNrNvn(kundeinfo);
	kundeliste->add(kunde);
	}
}

void Kunder :: nyKunde()  { //Lager ny kunde
	char* kunden;
	Kunde* kunde;
	
	kunde = new Kunde(++sisteKunde); //Oppretter ny kunde i memory, øker sistekunde.
	kundeliste->add(kunde); //Legger den inn i listen over kunder.
}

Kunder :: Kunder()  { //CONSTRUCTOR
	Kunde* kunde;
	kundeliste = new List(Sorted); //Lager liste. 
	ifstream inn("02 DTA/SISTE.DTA");
	inn >> forsteKunde;
	inn >> sisteKunde; inn.ignore();

}