#include <iostream>
#include "class Kunde.h"
#include "class IntrSone.h"
#include "globale funksjoner og variabler.h"
#include <cstdlib>

using namespace std;

IntrSone :: IntrSone(int sonenr) : Num_element(sonenr)  { //Constructor.
	char kommando; //Hjelpevariabel
	
	maxPris = lesTall("\nMaxpris", 1, 1000000000); //Leser max pris.
	minAreal = lesTall("\nMinimum areal", 1, 10000); //Leser minimum areal.
	minAntSoverom = lesTall("\nMinimum antall soverom", 0, 100); //Leser minimum ant. soverom.

	cout << "\nBoligfeed ([U]kentlig / [S]narest): "; //Spør om ønsket boligfeed.

	kommando = 'B'; // Bare for å ikke ha noe søppel.

	while(kommando != 'U' && kommando != 'S') { // SENERE: Fix dette. Alternativ metode.
		kommando = les();
		switch(kommando) {
		case 'U': boligfeeden = ukentlig; break;
		case 'S': boligfeeden = snarest; break;
		default: cout << "\nUlovlig kommando. Prov igjen."; break;

		}
	}
	
	cout << "\n\nEiendomstype ([T]omt, [E]nebolig, [R]ekkehus, [L]eilighet, [H]ytte: ";

	while(kommando != 'T' && kommando != 'E' && kommando != 'R' && 
		kommando != 'L' && kommando != 'H'){ //Senere: fix dette. Stygg metode.
		kommando = les();
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
	kommando = 'B'; //For å ikke ha søppel..

	while (kommando != 'S' && kommando != 'L'){ //SENERE: Fix dette. Stygg metode.
		kommando = les();
		switch(kommando){
		case 'S': statusonsket = salg; break;
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


void IntrSone :: endreSonenr(int nyttnr){
	sonenummer = nyttnr;
}

// Displayer informasjon om en interesse sone
void IntrSone::display()  {
	cout << "\nSonenummer: " <<  sonenummer;
  cout << "\nMaksimums pris: " <<  maxPris;
  cout << "\nMinimums areal: " <<  minAreal;
  cout << "\nMinimum antall soverom: " <<  minAntSoverom;
  cout << "\nBoligfeed: " <<  boligfeeden;
  cout << "\nEiendomstype: " <<  eiendomstypen;
  cout << "\n:0nkes: " <<  statusonsket;
}