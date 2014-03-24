#include "class Sone.h"
#include "class Eiendom.h"
#include <iostream>
using namespace std;

void Sone::display() {
	Eiendom* eiendom;
	int antEiendommer;
	int i;
	cout << "\nSonenummer: " << soneNummer;
	cout << "\nBeskrivelse: " << beskrivelse << endl;
	antEiendommer=eiendommene->no_of_elements();
	for (i=1; i<=antEiendommer; i++)  {
		eiendom = (Eiendom*)eiendommene->remove_no(i);
		eiendom->display();
		eiendommene->add(eiendom);
	}


	// SENERE displaye info om alle eiendommer og oppdrag
}

int Sone::hentSonenr()  {
	return soneNummer;
}