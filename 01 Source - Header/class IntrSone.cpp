#include <iostream>
#include "class Kunde.h"
#include "class IntrSone.h"
#include "globale funksjoner og variabler.h"
#include <cstdlib>

using namespace std;

IntrSone :: IntrSone(int sonenr) : Num_element(sonenr){ //Constructor.
	char kommando; //Hjelpevariabel
	
	maxPris = lesTall("\nMaxpris", 1, 1000000000); //Leser max pris.
	minAreal = lesTall("\nMinimum areal", 1, 10000); //Leser minimum areal.
	minAntSoverom = lesTall("\nMinimum antall soverom", 0, 100); //Leser minimum ant. soverom.

	cout << "\nBoligfeed ([U]kentlig / [S]narest): "; //Spør om ønsket boligfeed.
	kommando = les(); //Leser upcaset tegn.

	while(kommando != '.') { // '.' for a breake (hemmelig)
		switch(kommando) {
		case 'U': boligfeeden = ukentlig;
		case 'S': boligfeeden = snarest;
		default: cout << "\nUlovlig kommando. Prov igjen.";
		}
	}
	

	cout << "\n\nEiendomstype ([T]omt, [E]nebolig, [R]ekkehus, [L]eilighet, [H]ytte: ";
	kommando = les();

	while(kommando != '.'){ //'.' for a breake (hemmelig)
		switch(kommando){
		case 'T': eiendomstypen = tomt; break;
		case 'E': eiendomstypen = enebolig; break;
		case 'R': eiendomstypen = rekkehus; break;
		case 'L': eiendomstypen = leilighet; break;
		case 'H': eiendomstypen = hytte; break;
		default: cout << "\n\nUlovlig kommando. Prov igjen."; break;
		}
	}

	cout << "\n\nOnsket status ([S]alg / [L]eie): ";
	kommando = les();

	while (kommando != '.'){ //'.' for a breake (hemmelig)
		switch(kommando){
		case 'S': statusonsket = salg;
		case 'L': statusonsket = leie;
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

void IntrSone :: endreSonenr(int nyttnr){
	sonenummer = nyttnr;
}