#include <iostream>
#include "class Kunde.h"
#include "class IntrSone.h"
#include "globale funksjoner og variabler.h"
#include <cstdlib>

using namespace std;

IntrSone :: IntrSone(int sonenr) : Num_element(sonenr)  { //Constructor.
	char kommando; //Hjelpevariabel
	sonenummer=sonenr;
	maxPris = lesTall("\nMaxpris", 1, 1000000000); //Leser max pris.
	minAreal = lesTall("\nMinimum areal", 1, 10000); //Leser minimum areal.
	minAntSoverom = lesTall("\nMinimum antall soverom", 0, 100); //Leser minimum ant. soverom.

	cout << "\nBoligfeed ([U]kentlig / [S]narest): "; //Spør om ønsket boligfeed.

	kommando = 'B'; // Bare for å ikke ha noe søppel.

	while(kommando != 'U' && kommando != 'S') { // SENERE: Fix dette. Alternativ metode.
		kommando = les();		//Leser ønsket boligfeed.
		switch(kommando) {
		case 'U': boligfeeden = ukentlig; break;
		case 'S': boligfeeden = snarest; break;
		default: cout << "\nUlovlig kommando. Prov igjen."; break;

		}
	}
	
	cout << "\n\nEiendomstype ([T]omt, [E]nebolig, [R]ekkehus, [L]eilighet, [H]ytte): ";

	while(kommando != 'T' && kommando != 'E' && kommando != 'R' && 
		kommando != 'L' && kommando != 'H'){ //Senere: fix dette. Stygg metode.
		kommando = les(); //Leser eiendomstype.
		switch(kommando){
		case 'T': eiendomstypen = tomt; break;			//Setter
		case 'E': eiendomstypen = enebolig; break;	//Riktig
		case 'R': eiendomstypen = rekkehus; break;	//type.
		case 'L': eiendomstypen = leilighet; break;
		case 'H': eiendomstypen = hytte; break;
		default: cout << "\n\nUlovlig kommando. Prov igjen."; break;
		}
	}

	cout << "\n\nOnsket status ([S]alg / [L]eie): ";
	kommando = 'B'; //For å ikke inneholde søppel.

	while (kommando != 'S' && kommando != 'L'){ //SENERE: Fix dette. Stygg metode.
		kommando = les();		//Leser ønsket status.
		switch(kommando){
		case 'S': statusonsket = salg; break; //Setter riktig status.
		case 'L': statusonsket = leie; break;
		default: cout << "\n\nUlovlig kommando. Prov igjen."; break;
		}
	}

}

IntrSone :: IntrSone(IntrSone* intrsonen, int sonenr) : Num_element(sonenr) {
	maxPris = intrsonen->maxPris;							
	minAreal = intrsonen->minAreal;
	minAntSoverom = intrsonen->minAntSoverom;
	boligfeeden = intrsonen->boligfeeden;
	eiendomstypen = intrsonen->eiendomstypen;
	statusonsket = intrsonen->statusonsket;

}

IntrSone::IntrSone() {}

IntrSone :: ~IntrSone(){
	//Trenger ikke innmat

}

void IntrSone :: endreSonenr(int nyttnr){
	sonenummer = nyttnr; //Endrer sonenummer.
}

// Displayer informasjon om en interesse sone
void IntrSone::display()  {
	char* eiendomstype[] = {"Tomt", "Enebolig", "Rekkehus", "Leilighet", "Hytte"};
	char* statusonske[] = {"Salg", "Leie", "Salg og leie"};
  char* boligfeed[]=  {"Ukentlig", "Snarest"};
	cout << " \n\n-- Interessesone : ";
	cout << "\nSonenummer: " <<  sonenummer;
  cout << "\nMaksimums pris: " <<  maxPris;
  cout << "\nMinimums areal: " <<  minAreal;
  cout << "\nMinimum antall soverom: " <<  minAntSoverom;
  cout << "\nBoligfeed: " << boligfeed[boligfeeden];
  cout << "\nEiendomstype: " <<  eiendomstype[eiendomstypen];
  cout << "\n0nkes: " <<  statusonske[statusonsket];
}

IntrSone::IntrSone(ifstream & inn, int nr) : Num_element(nr)  {
	int bolFeed;
	int eiendomsTyp;
	int statOnsk;
	inn >> sonenummer;			//Constructor
	inn.ignore();						//som
	inn >> maxPris;					//leser
	inn.ignore();						//fra
	inn >> minAreal;				//fil.
	inn.ignore();
	inn >> minAntSoverom;
	inn.ignore();
  inn >> bolFeed;
	inn.ignore();
	inn >> eiendomsTyp;
	inn.ignore();
	inn >> statOnsk;
	inn.ignore();
	inn.ignore();

	enumBoligfeedSwitch(bolFeed);		//Initierer enum.
	enumEiendomstypeSwitch(eiendomsTyp);	//Initierer enum.
	enumStatusSwitch(statOnsk);			//Initierer enum.

}

void IntrSone::skrivTilFil(ofstream & ut, int nr)  {
	ut << sonenummer << endl;				//Skriver
	ut << maxPris << endl;					//informasjon
	ut << minAreal << endl;					//til
	ut << minAntSoverom << endl;		//fil.
	ut << boligfeeden << endl;
	ut << eiendomstypen << endl;
	ut << statusonsket << endl;
	ut << endl;
}


void IntrSone::enumBoligfeedSwitch(int nr)  {
	switch (nr)	{	//Tar imot int som parameter.
	case 0: boligfeeden = ukentlig; break;	//Setter riktig verdi i enum.
	case 1: boligfeeden = snarest; break;
	};
}

void IntrSone::enumEiendomstypeSwitch(int nr)  {
	switch (nr)	{ //Mottar int som parameter.
	case 0: eiendomstypen = tomt; break;
	case 1: eiendomstypen = enebolig; break;	//Setter riktig verdi i enum.
	case 2: eiendomstypen = rekkehus; break;
	case 3: eiendomstypen = leilighet; break;
	case 4: eiendomstypen = hytte; break;
	};
}

void IntrSone::enumStatusSwitch(int nr)  {
	switch (nr)	{	//Mottar int som parameter.
	case 0: statusonsket = salg; break;
	case 1: statusonsket = leie; break; //Setter riktig verdi i enum.
	case 2: statusonsket = begge; break;
	};
}
