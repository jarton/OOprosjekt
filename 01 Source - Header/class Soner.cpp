#include <iostream>
#include "globale funksjoner og variabler.h"
#include "conster.h"
#include "class Soner.h"
#include <fstream>
#include <stdlib.h>
using namespace std;



//constructor
Soner::Soner()	{
	ifstream inn("02 DTA/SISTE.DTA");				//leser inn siste brukte oppdrag
	inn.ignore(1000000, '\n');
	inn.ignore(1000000, '\n');							//ignorerer kundedata på fil
	inn >> sisteOppdrag;										//leser sisteoppdrag
	inn.close();

	for (int j = 0; j <= MAXSONER + 1; j++)			//arrayen med sonepekere null-
		sonene[j] = NULL;																					//stilles

	char* sonefil = new char[strlen("SONE000.DTA"+1)];														//peker for navn på fil
	for (int i = 1; i <= 100; i++) {								//løkke for alle 100 soner
		LagNavn(sonefil, "SONE", ".DTA", i, 3);   //som lager filnavn for alle 100
		ifstream inn(sonefil);													//og prøver å lese dem inn
		if (inn)																								//hvis den finnes
			sonene[i] = new Sone(inn, i);								//lag ny sone og les den inn
	}																										//med les inn costructor
}

//Skriver alle sonene til fil
void Soner::skrivTilFil()	{									//skriver alle sonene til filer
	char * sonefil  = NULL;										//peker for navn på fil
	for (int i = 1; i <= MAXSONER; i++)	{											//peker for navn på fil
		if (sonene[i] != NULL)	{																	//hvis en sone eksister
			LagNavn(sonefil, "SONE", ".DT2", i, 3);
			ofstream ut(sonefil);   				//lag navn på fil
			sonene[i]->skrivTilFil(ut);												        //sonen sin skriv fil

		}
	}
}

//Finner sonenummer gitt i parameter og displayer

void Soner::displaySone(int sonenr)  {
	int i;
	for (i=1; i<=MAXSONER; i++)  {                     // loop gjennom alle soner
		if (sonene[i]->hentSonenr() == sonenr)        // Hvis sonens nr = parameter
			sonene[i]->display();                                 // Displayer sonen
	}
}

void Soner::displayEiendom(int nr)  {
	int i;
	for (i=1; i <=MAXSONER; i++)  
	  sonene[i]->finnSone(nr);
}

void Soner::fortsettelseMeny(char valg) {
	char valg2;
	int nr;
	valg2 = les();
	while (valg2 != 'Q')  {
		switch(valg2) {
		case 'D': 
			if (valg == 'S')  {
			  cin >> nr;
			  displaySone(nr);
			
			}
			else if (valg =='E')  {
				cin >> nr;
				displayEiendom(nr);
			}
			break;
		case 'N': break;
		case 'S': break;
		case 'E': break;

			break;

			

		  break;	
		}
	}
}

