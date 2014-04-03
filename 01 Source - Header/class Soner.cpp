#include <iostream>
#include "globale funksjoner og variabler.h"
#include "conster.h"
#include "class Soner.h"
#include <fstream>
#include <stdlib.h>
#include <cstring>
using namespace std;



//constructor
Soner::Soner()	{
	ifstream inn("02 DTA/SISTE.DTA");				//leser inn siste brukte oppdrag
	inn.ignore(1000000, '\n');
	inn.ignore(1000000, '\n');							//ignorerer kundedata p� fil
	inn >> sisteOppdrag;										//leser sisteoppdrag
	inn.close();

	for (int j = 0; j <= MAXSONER + 1; j++)			//arrayen med sonepekere null-
		sonene[j] = NULL;																					//stilles

	char* sonefil = new char[strlen("SONE000.DTA")+1];														//peker for navn p� fil
	for (int i = 1; i <= 100; i++) {																//l�kke for alle 100 soner
		LagNavn(sonefil, "SONE", ".DTA", i, 3);  						 //som lager filnavn for alle 100
		ifstream inn(sonefil);													//og pr�ver � lese dem inn
		if (inn)																						//hvis den finnes
			sonene[i] = new Sone(inn, i);								//lag ny sone og les den inn
	}																										//med les inn costructor
}

//Leser inn en ny einendom i eksisterende sone eller lager ny sone
void Soner::eiendomNy()	{									
	int soneNR;									//Sonen som einendommen skal ligge i
	soneNR = lesTall("skriv inn �nsket soneNR: \n", 1, 100);   //leser inn aktuelt nr
	sisteOppdrag++;
	if (sonene[soneNR])									//hvis sonen eksisterer
		sonene[soneNR]->nyEiendom(sisteOppdrag);					//ny eiendom i eksisterende sone
	else												//hvis sonen ikke eksisterer 
		sonene[soneNR] = new Sone(soneNR, sisteOppdrag);             //blir sonen opprettet

	ifstream inn("02 DTA/SISTE.DTA");
	int kf�rste, ksiste;
	inn >> kf�rste >> ksiste;
	ofstream ut("02 DTA/SISTE.DT2");
	ut << kf�rste << '\n' << ksiste << '\n'
		<< sisteOppdrag;
	skrivTilFil();
}

//Skriver alle sonene til fil
void Soner::skrivTilFil()	{																	//skriver alle sonene til filer
	char * sonefil  = new char [strlen("SONE000.DTA")+1];								//peker for navn p� fil
	for (int i = 1; i <= MAXSONER; i++)	{														//peker for navn p� fil
		if (sonene[i] != NULL)	{																	//hvis en sone eksister
			LagNavn(sonefil, "SONE", ".DT2", i, 3);
			ofstream ut(sonefil);   																//lag navn p� fil
			sonene[i]->skrivTilFil(ut);												        //sonen sin skriv fil
		}
	}
}

//Finner sonenummer gitt i parameter og displayer
void Soner::displaySone(int sonenr)  {
		if (sonene[sonenr]->hentSonenr() == sonenr)        // Hvis sonens nr = parameter
			sonene[sonenr]->display();                                 // Displayer sonen
}

void Soner::displayEiendom(int nr)  {
	int i;
	for (i=1; i <=MAXSONER; i++)  
	  if (sonene[i] != NULL)
		  sonene[i]->finnSone(nr);
}

void Soner::fortsettelseMeny(char valg) {
	char valg2;
	int nr;
	valg2 = les();
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
		case 'N': eiendomNy(); break;
		case 'S': break;
		case 'E': break;
		}
}

