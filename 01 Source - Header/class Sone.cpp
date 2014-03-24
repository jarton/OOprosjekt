#include "class Sone.h"
#include "class Eiendom.h"
#include <iostream>
using namespace std;

// Displayer all informasjon om en sone
void Sone::display()  {
	Eiendom* eiendom;                                            // Eiendom-peker
	int antEiendommer;                             // Variabel: antall eiendommer
	int i;                                                   // Variabel til loop
	cout << "\nSonenummer: " << soneNummer;                  // Skriver ut sonenr
	cout << "\nBeskrivelse: " << beskrivelse << endl;          // Skriver ut info
	antEiendommer=eiendommene->no_of_elements();      // Finner antall eiendommer
	for (i=1; i<=antEiendommer; i++)  {           // Loop gjennom alle eiendommer
		eiendom = (Eiendom*)eiendommene->remove_no(i); // Fjerner eiendom fra liste
		eiendom->display();                                    // Displayer eiendom
		eiendommene->add(eiendom);               // Legger eiendom tilbake i listen
	}
}


//Returnerer sonens nummer
int Sone::hentSonenr()  {
	return soneNummer;
}

