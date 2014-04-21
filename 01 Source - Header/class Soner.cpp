#include <iostream>
#include "globale funksjoner og variabler.h"
#include "conster.h"
#include "class Soner.h"
#include <fstream>
#include <cstdlib>
#include <stdlib.h>  				
#include <cstring> 					// strcat, strcpy
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

	char* sonefil = new char[strlen("SONE000.DTA")+1];					//peker for navn på fil
	for (int i = 1; i <= 100; i++) {																//løkke for alle 100 soner
		LagNavn(sonefil, "SONE", ".DTA", i, 3);  						 //som lager filnavn for alle 100
		ifstream inn(sonefil);													//og prøver å lese dem inn
		if (inn)																						//hvis den finnes
			sonene[i] = new Sone(inn, i);								//lag ny sone og les den inn
	}																										//med les inn costructor
}

//Leser inn en ny einendom i eksisterende sone eller lager ny sone
void Soner::eiendomNy(int nr)	{									
	sisteOppdrag++;														//teller opp nytt oppdragsnr
	if (sonene[nr])															//hvis sonen eksisterer
		sonene[nr]->nyEiendom(sisteOppdrag);					//ny eiendom i eksisterende sone
	else																				//hvis sonen ikke eksisterer 
		sonene[nr] = new Sone(nr, sisteOppdrag);             //blir sonen opprettet

	ifstream inn("02 DTA/SISTE.DTA");			//leser inn alt på SISTE.DTA
	int kforste, ksiste;									//første og sistekunde
	inn >> kforste >> ksiste;							//leser de inn i midleritige variabler
	ofstream ut("02 DTA/SISTE.DT2");			//skriver SISTE.DTA filen
	ut << kforste << '\n' << ksiste << '\n'		//skriver ut første og sistekunde
		<< sisteOppdrag;												//og "oppdaterer" sisteoppdrag
	skrivTilFil();													//skriver nye eiendomen til fil
}

// Endrer informasjon om en eiendom
void Soner::eiendomEndre(int nr)  {
	int i = 1;													//int for do-while løkka
	bool funnet;												//om eiendommen er funnet

	do {														//går igjennom hvær sone som 
		if (sonene[i] != NULL)	{								//finnes
			funnet = sonene[i]->endreData(nr);			//og ser etter eiendommen
			if (funnet)
				break;
		}
	  i++;															//nestesone
	} while (!funnet && i<=MAXSONER);								//går sålenge den ikke er funnet
}

//Sletter en eiendom
void Soner::eiendomSlett(int nr)	{			//int nr er oppdragsnr
	int i = 1;													//int for do-while løkka
	bool funnet;												//om eiendommen er funnet

	do {														//går igjennom hvær sone som 
		if (sonene[i] != NULL)	{									//finnes
			funnet = sonene[i]->slettEiendom(nr);			//og ser etter eiendommen
			i++;																			//nestesone
		}
	} while (!funnet);								//går sålenge den ikke er funnet
}

void Soner::sammenlign(IntrSone* isone, int nr, int kundenr) {
  if (sonene[nr] != NULL)
	sonene[nr]->sammenlign(isone, kundenr);  // Tidligere : sonene[nr]->sammenlign(isone, kundenr, type)
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
	if (sonene[sonenr] != NULL)
		sonene[sonenr]->display();     //kaller den aktuelle sonen sin display
}

void Soner::displayEiendom(char* soneinfo)  {
	int nr=atoi(soneinfo);										//gjør om til int i tilfelle postnr +sted
	for (int i = 1; i <= MAXSONER; i++)	{			//går igjennom alle soner
		if (sonene[i] != NULL) {							//som finnes og sjekker om postnr / oppdragsnr
			sonene[i]->displayEien(nr);				//er like. isåfall displayes de eiendommene
		}
	}
}

//switch for soner /eiendom  E/S
void Soner::fortsettelseMeny(char valg) {
	char valg2;									//kommando nr 2
	char soneinfo[STRLEN];					//array for innlesing av postinfo / oppdragsnr
	int nr;												//sonenr for nyeiendom / slett
	valg2 = les();								//leser inn kommando nr 2

		switch(valg2) {							
		case 'D': 								//Display for sone / eiendom
			if (valg == 'S')  {				//hvis sone er førstekommando
			  cin >> nr;						//les sonenr
			  displaySone(nr);					//display akuell sone
			}
			else if (valg =='E')  {					//hvis førstekommando = E
				cin.getline(soneinfo,STRLEN);			//les inn soneinfo (postinfo/oppdrag)
				displayEiendom(soneinfo);				//display akuell(e) eiendomm(er)
			}
			break;
		case 'N': cin >> nr;				//ny eiendom, les nr, opprett ny eiendom i sonr nr
							cin.ignore();
			eiendomNy(nr); break;
		case 'S': cin >> nr;				//slett eiendom, les nr, slett eiendom i sone nr
			eiendomSlett(nr);  break;
		case 'E': cin >> nr;
			eiendomEndre(nr); break;
		}
}

