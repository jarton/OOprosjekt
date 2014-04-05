#include <iostream>
#include "globale funksjoner og variabler.h"
#include "conster.h"
#include "class Soner.h"
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <cctype>           // to upper
using namespace std;



//constructor
Soner::Soner()	{
	ifstream inn("02 DTA/SISTE.DTA");				//leser inn siste brukte oppdrag
	inn.ignore(1000000, '\n');
	inn.ignore(1000000, '\n');							//ignorerer kundedata på fil
	inn >> sisteOppdrag;										//leser sisteoppdrag
	inn.close();

	for (int j = 0; j <= MAXSONER; j++)			//arrayen med sonepekere null-
		sonene[j] = NULL;																					//stilles

	char* sonefil = new char[strlen("SONE000.DTA")+1];														//peker for navn på fil
	for (int i = 1; i <= 100; i++) {																//løkke for alle 100 soner
		LagNavn(sonefil, "SONE", ".DTA", i, 3);  						 //som lager filnavn for alle 100
		ifstream inn(sonefil);													//og prøver å lese dem inn
		if (inn)																						//hvis den finnes
			sonene[i] = new Sone(inn, i);								//lag ny sone og les den inn
	}																										//med les inn costructor
}

//Leser inn en ny einendom i eksisterende sone eller lager ny sone
void Soner::eiendomNy(int nr)	{									
	sisteOppdrag++;
	if (sonene[nr])									//hvis sonen eksisterer
		sonene[nr]->nyEiendom(sisteOppdrag);					//ny eiendom i eksisterende sone
	else												//hvis sonen ikke eksisterer 
		sonene[nr] = new Sone(nr, sisteOppdrag);             //blir sonen opprettet

	ifstream inn("02 DTA/SISTE.DTA");
	int kforste, ksiste;
	inn >> kførste >> ksiste;
	ofstream ut("02 DTA/SISTE.DT2");
	ut << kforste << '\n' << ksiste << '\n'
		<< sisteOppdrag;
	skrivTilFil();
}

//Sletter en eiendom
void Soner::eiendomSlett(int nr)	{
	int i = 1;
	bool funnet;

	do {
		if (sonene[i] != NULL)	{
			funnet = sonene[i]->slettEiendom(nr);
			i++;
		}
	} while (!funnet);
}

//Skriver alle sonene til fil
void Soner::skrivTilFil()	{																	//skriver alle sonene til filer
	char * sonefil  = new char [strlen("SONE000.DTA")+1];								//peker for navn på fil
	for (int i = 1; i <= MAXSONER; i++)	{														//peker for navn på fil
		if (sonene[i] != NULL)	{																	//hvis en sone eksister
			LagNavn(sonefil, "SONE", ".DT2", i, 3);
			ofstream ut(sonefil);   																//lag navn på fil
			sonene[i]->skrivTilFil(ut);												        //sonen sin skriv fil
		}
	}
}

//Finner sonenummer gitt i parameter og displayer
void Soner::displaySone(int sonenr)  {
	for (int i = 1; i <= MAXSONER; i ++)  {
		if (sonene[i]->hentSonenr() == sonenr)        // Hvis sonens nr = parameter
			sonene[i]->display();   
	}  // Displayer sonen
}

void Soner::displayEiendom(char* soneinfo)  {
	int i = 1;
	int nr=atoi(soneinfo);
	for (i; i <= MAXSONER; i++)	{
		if (sonene[i] != NULL) {
			sonene[i]->displayEien(nr);
		}
	}
}

void Soner::fortsettelseMeny(char valg) {
	char valg2;
	char soneinfo[STRLEN];
	int nr;
	valg2 = les();

		switch(valg2) {
		case 'D': 
			if (valg == 'S')  {
			  cin >> nr;
			  displaySone(nr);
			}
			else if (valg =='E')  {
				cin.getline(soneinfo,STRLEN);
				displayEiendom(soneinfo);
			}
			break;
		case 'N': cin >> nr;
			eiendomNy(nr); break;
		case 'S': cin >> nr;
			eiendomSlett(nr);  break;
		case 'E': break;
		}
}

