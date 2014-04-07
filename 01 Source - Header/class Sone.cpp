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
	char buffer[STRLEN];									//buffer for innlesing
	soneNummer = nr;								//setter sonens nr til medsent nr
	
	lesTxt("Sonebeskrivelse", buffer, STRLEN);		//leser inn sonebeskrivelse
	beskrivelse = new char[strlen(buffer) + 1];		//lager array som er akkurat passe
	strcpy(beskrivelse, buffer);									//kopierer fra buffer inn i array

	eiendommene = new List(Sorted);					//lager en liste for eiendommene
	nyEiendom(oppdragsnr);						//kaller på nyeiendom funksjonen
}

// Constructor som leser fra fil
Sone::Sone(ifstream & inn, int nr)	{											//int er sonenr
	eiendommene = new List(Sorted);										//lager en eiendomsliste
	char buffer[STRLEN];																//buffer for innlesing
	inn.ignore();																			//ignore foran getline
	inn.getline(buffer, STRLEN);											 //leser inn beskrivelse
	beskrivelse = new char[strlen(buffer + 1)];         //peker p� array som er 
	strcpy(beskrivelse, buffer);									//akkuar lang nok, kopierer over	
																												
	soneNummer = nr;																			//sonenr ble sendt med
	Eiendom* type;										//einendom som blir lest inn og opprettet
	int onr;														//oppdragsnr
	char eientype[STRLEN];															//type: bolig einendom 
	inn >> eientype;																	//leser typen fra fil
	while (!inn.eof())	{																//l�kke for heile filen
		if (eientype[0] == 'e')	{										//sjekke om det st�r eiendom
			inn >> onr;												//leser inn eiendomsnr
			type = new Eiendom(inn, onr);									//lager en ny eiendom
			eiendommene->add(type);                				//legges til i liste
		}
		else	{																	//hvis ikkje er det bolig 
			inn >> onr;														//leser inn oppdragsnr
			type = new Bolig(inn, onr); 						//lager ny bolig	
			eiendommene->add(type);													//og legges i lista
		}
	inn >> eientype;										//prover a lese inn ny type
	}
}

//oppretter en ny eiendom
void Sone::nyEiendom(int oppdragsnr)	{
	Eiendom* eiendom;									//peker til bolig/eiendom
	char type[STRLEN];								//array for type eiendom/bolig
	
	lesTxt("velg type Bolig  /   Eiendom", type, STRLEN);	//leser inn
	if (type[0] == 'B' || type[0] == 'b')									//hvis bolig
		eiendom = new Bolig(oppdragsnr);						//bolig opprettes
	else if (type[0] == 'E' || type[0] == 'e')					//hvis eiendom
		eiendom = new Eiendom(oppdragsnr);				//eiendom opprettes
	eiendommene->add(eiendom);				//legger til nyopprettet i lista
}

//skriver sonen til fil
void Sone::skrivTilFil(ofstream & ut)	{
	int antallEiendommer;					//antall eiendommer i liste
	Eiendom* eiendom;							//peker til eiendom/bolig
	ut << beskrivelse;						//skriver sonebeskrivelse
	
	antallEiendommer = eiendommene->no_of_elements();	//finner antall i liste
	for (int i = 1; i <= antallEiendommer; i++)	{			//går igjennom lista
		eiendom = (Eiendom*) eiendommene->remove_no(i);		//tar ut aktuelle
		if (eiendom->type())	{													//finner typen
			ut << "\n\n" << "Eiendom\n";				//skrver ut typen
			eiendom->skrivTilFil(ut);						//og eiendommen til fil
		}
		else	{ 														//hvis ikke eiendom så er den bolig
			ut << "\n\n" << "Bolig\n";				//skriver ut type
			eiendom->skrivBoligTilFil(ut);			//skriver boligen til fil
		}
		eiendommene->add(eiendom);					//legger eiendommen/boligen tilbake
	}																				//i lista
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
	Eiendom* eiendom;									//peker til bolig/eiendom
	int antEiendommer;							//antall eiendommer i liste
	int i = 1;										//int for whileloop
	bool funnet = false;						//bool om eiendommen er funnet
	char* sonefil = new char[strlen("SONE000.DTA") + 1];	//navn på fil

	antEiendommer = eiendommene->no_of_elements();	//finner antall i liste
	while (!funnet && i <= antEiendommer)	{				//sålenge ikke funnet & mindre en antall
		eiendom = (Eiendom*)eiendommene->remove_no(i);	//fjern akuelle
		if (eiendom->finnOppdragsnr(oppdragnr))	{		//sjekk oppdragsnr
			funnet = true;													//hvis det er likt funnet er true
			eiendommene->destroy(i);								//slett den akuelle
			LagNavn(sonefil, "SONE", ".DT2", soneNummer, 3);	//får navn på sonen sin fil
			ofstream ut(sonefil);												//åpener sonen sin fil
			skrivTilFil(ut);							//skriver oppdart eiendomliste til fil
			cout << "eiendommen ble fjernet\n";		//bekreftelse på sletting
		}
		else { eiendommene->add(eiendom); i++;} //hvis ikke erlik legg tilbake og tell opp
	}
	return funnet;	    //return om eiendommen ble funnet i aktuelle sonen
}

//displayer en/flere eiendommer
void Sone::displayEien(int nr)  {
	Eiendom* eiendom;                                            // Eiendom-peker
	int antEiendommer;                             // Variabel: antall eiendommer

	antEiendommer=eiendommene->no_of_elements();      // Finner antall eiendommer

	for (int i = 1; i <= antEiendommer; i++){           // Loop gjennom alle eiendommer
		eiendom = (Eiendom*)eiendommene->remove_no(i); // Fjerner eiendom fra liste
		if ((eiendom->finnOppdragsnr(nr))					//vhis oppdragsnr er likt
			|| (eiendom->finnPostnummer(nr)))	{				//eller postnr er likt
			if (eiendom->type())	{									//hvis det er eiendom
				cout << "\n--EIENDOM--\n";						//skriv eiendom og display
				eiendom->display();
			}
			else 																			//hvis det er bolig
				eiendom->displayBolig();								//display den
		}
		eiendommene->add(eiendom);               // Legger eiendom tilbake i listen
	}
}

