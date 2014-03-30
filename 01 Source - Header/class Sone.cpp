#include "class Sone.h"
#include "class Eiendom.h"
#include "conster.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

// Constructor som leser fra fil
Sone::Sone(ifstream & inn, int nr, char * nvn)	{							//int er sonenr
	char buffer[STRLEN];								//buffer for innlesing
	inn.getline(buffer, STRLEN);						 //leser inn beskrivelse
	beskrivelse = new char[strlen(buffer + 1)];         //peker på array som er 
															//akkuratt lang nok
	soneNummer = nr;									//sonenr ble sendt med
	Eiendom* eiendom;
	//ikke ferdig !!!!!
	
}


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


void Sone::finnSone(int nr)  {
	Eiendom* eiendom;                                            // Eiendom-peker
	int antEiendommer;                             // Variabel: antall eiendommer
	int i;                                                   // Variabel til loop
	antEiendommer=eiendommene->no_of_elements();      // Finner antall eiendommer
	for (i=1; i<=antEiendommer; i++)  {           // Loop gjennom alle eiendommer
		eiendom = (Eiendom*)eiendommene->remove_no(i); // Fjerner eiendom fra liste
		if (eiendom->finnOppdragsnr(nr) == true) 
			eiendom->display();
		if (eiendom->finnPostnummer(nr) == true)
			eiendom->display();
		eiendommene->add(eiendom);               // Legger eiendom tilbake i listen
	}
}

