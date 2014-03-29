#include <iostream>
#include "class Kunder.h"
#include "class Kunde.h"
#include "conster.h"
#include "globale funksjoner og variabler.h"
using namespace std;

void Kunder::fortsettelseMeny()  {
	char valg;
	char kundeinfo[STRLEN];

	valg = les();
	while (valg != 'Q')  {
		switch(valg) {
		case 'D': 
			cin.getline(kundeinfo,STRLEN); 
			finnKunde(kundeinfo);
			break;
		case 'N':
			nyKunde();
			break;
		case 'S': break;
		case 'E': break;
	  }
  }
}

void Kunder::finnKunde(char* kundeinfo)  {
	Kunde* kunde;
	List* kundeliste;
	int i;

	for(i=1; i<=sisteKunde; i++)  { 
	kunde = (Kunde*) kundeliste->remove_no(i);
	kunde->sjekkNrNvn(kundeinfo);
	kundeliste->add(kunde);
	}
}

Kunder :: nyKunde(){ //Lager ny kunde
	char* kunden;

	kunden = new Kunde(++sisteKunde); //Oppretter ny kunde i memory, øker sistekunde.
	kundene->add(kunden); //Legger den inn i listen over kunder.
}