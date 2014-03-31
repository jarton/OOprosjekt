#include "class Sone.h"
#include "class Eiendom.h"
#include "class Bolig.h"
#include "conster.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

// Constructor som leser fra fil
Sone::Sone(ifstream & inn, int nr)	{											//int er sonenr
	char buffer[STRLEN];																//buffer for innlesing
	inn.ignore();
	inn.getline(buffer, STRLEN);											 //leser inn beskrivelse
	beskrivelse = new char[strlen(buffer + 1)];         //peker på array som er 
																													//akkuratt lang nok
	soneNummer = nr;																			//sonenr ble sendt med
	Eiendom* type;										//einendom som blir lest inn og opprettet
	char eientype[STRLEN];															//type: bolig einendom 
	inn >> eientype;																	//leser typen fra fil
	while (!inn.eof)	{																//løkke for heile filen
		if (eientype[1] == 'e')	{										//sjekke om det står eiendom
			type = new Eiendom(inn);									//hvis ja ny einendom leses
			einendommene->add(type)};                				//legges til i liste
		else	{																	//hvis ikkje er det bolig som
			type = new Bolig(inn); 								//skal leses inn og opprettes
			einendommene->add(type)};													//og legges i lista
		inn >> eientype;												//prover a lese inn ny type
	}
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

