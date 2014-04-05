#include "globale funksjoner og variabler.h"
#include "class Sone.h"
#include "class Eiendom.h"
#include "class Bolig.h"
#include "conster.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//Constructor som leser inn EN eiendom
Sone::Sone(int nr, int oppdragsnr)	{
	char buffer[STRLEN];
	soneNummer = nr;
	
	lesTxt("Sonebeskrivelse", buffer, STRLEN);
	beskrivelse = new char[strlen(buffer) + 1];
	strcpy(beskrivelse, buffer);

	eiendommene = new List(Sorted);
	nyEiendom(oppdragsnr);
}

// Constructor som leser fra fil
Sone::Sone(ifstream & inn, int nr)	{											//int er sonenr
	eiendommene = new List(Sorted);
	char buffer[STRLEN];																//buffer for innlesing
	inn.ignore();
	inn.getline(buffer, STRLEN);											 //leser inn beskrivelse
	beskrivelse = new char[strlen(buffer + 1)];         //peker p� array som er 
	strcpy(beskrivelse, buffer);
																													//akkuratt lang nok
	soneNummer = nr;																			//sonenr ble sendt med
	Eiendom* type;										//einendom som blir lest inn og opprettet
	int onr;
	char eientype[STRLEN];															//type: bolig einendom 
	inn >> eientype;																	//leser typen fra fil
	while (!inn.eof())	{																//l�kke for heile filen
		if (eientype[0] == 'e')	{										//sjekke om det st�r eiendom
			inn >> onr;
			type = new Eiendom(inn, onr);									//hvis ja ny einendom leses
			eiendommene->add(type);                				//legges til i liste
		}
		else	{																	//hvis ikkje er det bolig som
			inn >> onr;
			type = new Bolig(inn, onr); 								//skal leses inn og opprettes
			eiendommene->add(type);													//og legges i lista
		}
	inn >> eientype;										//prover a lese inn ny type
	}
}

//oppretter en ny eiendom
void Sone::nyEiendom(int oppdragsnr)	{
	Eiendom* eiendom;						//peker til bolig/eiendom
	char type[STRLEN];					//array for type eiendom/bolig
	
	lesTxt("velg type Bolig  /   Eiendom", type, STRLEN);	//leser inn
	if (type[0] == 'B' || type[0] == 'b')									//hvis bolig
		eiendom = new Bolig(oppdragsnr);						//bolig opprettes
	else if (type[0] == 'E' || type[0] == 'e')					//hvis eiendom
		eiendom = new Eiendom(oppdragsnr);				//eiendom opprettes
	eiendommene->add(eiendom);				//legger til nyopprettet i lista
}

//skriver sonen til fil
void Sone::skrivTilFil(ofstream & ut)	{
	int antallEiendommer;
	Eiendom* eiendom;
	ut << beskrivelse;
	
	antallEiendommer = eiendommene->no_of_elements();
	for (int i = 1; i <= antallEiendommer; i++)	{
		eiendom = (Eiendom*) eiendommene->remove_no(i);
		if (eiendom->type())	{
			ut << "\n\n" << "Eiendom\n";
			eiendom->skrivTilFil(ut);
		}
		else	{ 
			ut << "\n\n" << "Bolig\n";
			eiendom->skrivBoligTilFil(ut);
		}
		eiendommene->add(eiendom);
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
		if (eiendom->type())	{					//finner om det er ein eiendom
			cout << "\n--EIENDOM--\n";
			eiendom->display();                              // Displayer eiendom
		}
		else										//hvis det er en bolig
			eiendom->displayBolig();			//virtual display + eiendomdisplay
		eiendommene->add(eiendom);               // Legger eiendom tilbake i listen
	}
}

//Sletter en eiendom med et gitt oppdragsnr
bool Sone::slettEiendom(int oppdragnr)	{
	Eiendom* eiendom;
	int antEiendommer;
	int i = 1;
	bool funnet = false;
	char* sonefil = new char[strlen("SONE000.DTA") + 1];

	antEiendommer = eiendommene->no_of_elements();
	while (!funnet && i <= antEiendommer)	{
		eiendom = (Eiendom*)eiendommene->remove_no(i);
		if (eiendom->finnOppdragsnr(oppdragnr))	{
			funnet = true;
			eiendommene->destroy(i);
			LagNavn(sonefil, "SONE", ".DT2", i, 3);
			ofstream ut(sonefil);
			skrivTilFil(ut);
			i++;
			cout << "eiendommen ble fjernet\n";
		}
		else eiendommene->add(eiendom);
	}
	return funnet;
}

//Returnerer sonens nummer
int Sone::hentSonenr()  {
	return soneNummer;
}


void Sone::displayEien(int nr)  {
	Eiendom* eiendom;                                            // Eiendom-peker
	int antEiendommer;                             // Variabel: antall eiendommer
	int i = 1;                                                   // Variabel til loop

	antEiendommer=eiendommene->no_of_elements();      // Finner antall eiendommer

	for (i; i <= antEiendommer; i++){           // Loop gjennom alle eiendommer
		eiendom = (Eiendom*)eiendommene->remove_no(i); // Fjerner eiendom fra liste
		if ((eiendom->finnOppdragsnr(nr))
			|| (eiendom->finnPostnummer(nr)))	{
			if (eiendom->type())	{
				cout << "\n--EIENDOM--\n";
				eiendom->display();
			}
			else
				eiendom->displayBolig();
		}
		eiendommene->add(eiendom);               // Legger eiendom tilbake i listen
	}
}

