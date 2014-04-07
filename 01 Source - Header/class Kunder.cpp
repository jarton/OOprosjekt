#include <iostream>
#include <fstream>
#include "class Kunder.h"
#include "class Kunde.h"
#include <cstdio>       // Remove
#include <stdio.h>      // Remove
#include <cstring>
#include "conster.h"
#include "globale funksjoner og variabler.h"
using namespace std;

void Kunder::fortsettelseMeny()  {
	char valg;
	char newline;
	char kundeinfo[STRLEN];
	int kundenummer;

	valg = les();
	switch(valg) {
		case 'D': 
		cin.get(newline);
		cin.getline(kundeinfo,STRLEN); 
		finnKunde(kundeinfo);	
		break;
		case 'N': nyKunde(); break;
		case 'S': 
			cin >> kundenummer; 
			if (kundenummer < forsteKunde+1 || kundenummer > sisteKunde)
				cout << "\n OBS! Ingen kunde med kundenummer '"<<kundenummer<<"' er regisrtert!";
			else
  			slettKunde(kundenummer); break;
		case 'E': break;
		default: break;
	 }
}

void Kunder::finnKunde(char* kundeinfo)  {
	Kunde* kunde;
	//List* kundeliste;
	int antallKunder= kundeliste->no_of_elements();
	int i;

	for(i=1; i<=antallKunder; i++)  { 
	kunde = (Kunde*) kundeliste->remove_no(i);
	kunde->sjekkNrNvn(kundeinfo);
	kundeliste->add(kunde);
	}
}

void Kunder :: nyKunde()  { //Lager ny kunde
	Kunde* kunde;
	if (forsteKunde == 1000)
	  forsteKunde++;
	kunde = new Kunde(++sisteKunde); //Oppretter ny kunde i memory, øker sistekunde.
	kundeliste->add(kunde); //Legger den inn i listen over kunder.
	skrivTilFil();
}

Kunder :: Kunder()  { //CONSTRUCTOR
	Kunde* kunde;
	kundeliste = new List(Sorted); //Lager liste. 
	ifstream inn("02 DTA/SISTE.DTA");
	inn >> forsteKunde;
	inn >> sisteKunde; inn.ignore();
	///////// OBS! Må også lage for KUNDE000000.INF!!
	char* kundedta = new char[strlen("KUNDE0001000.DTA")+1];
	for (int i = forsteKunde; i <=sisteKunde; i++)  {
		LagNavn(kundedta, "KUNDE", ".DTA", i, 7);
		ifstream dtainn(kundedta);
		if (dtainn)  {																						//hvis den finnes
			kunde = new Kunde(dtainn, i);
			kundeliste->add(kunde);
		}
	}
}


void Kunder::slettKunde(int knr)  {
	Kunde* kunde;
	int knum;
	char* kundedta = new char[strlen("KUNDE0001000.DTA") + 1];
	int antkunder;
	antkunder = kundeliste->no_of_elements();

	for (int i = 1; i <= antkunder; i++)  {
		kunde = (Kunde*)kundeliste->remove_no(i);
		if (kunde->sjekkNr(knr) == true)  {
			kundeliste->destroy(i);
			cout << "\nKunden ble fjernet!" ;
	  }
		else
			kundeliste->add(kunde);
	}

	for (int i = forsteKunde+1; i <= sisteKunde; i++)	{
		LagNavn(kundedta, "KUNDE", ".DTA", i, 7);
		ifstream dta(kundedta);
		if (!kundedta)
      cout << "\nFilen '" << kundedta << "' finnes ikke!";
	  dta >> knum; 	
		if (knum == knr)  {
			dta.close();
		  if (remove(kundedta) != 0)
			  cout << "\n\nFilen '" << kundedta << "' ble IKKE fjernet!";
		  else
			  cout << "\n\nFilen '" << kundedta << "' ble fjernet!";
		}
	}
	sisteKunde--;
	if (sisteKunde==1000)
		forsteKunde=sisteKunde;
	skrivTilFil();
}


void Kunder::skrivTilFil()  {
	char * kundefil  = new char [strlen("KUNDE0001001.DTA")+1];
	int antKunder = kundeliste->no_of_elements();	
	Kunde* kunde;
	for (int i = 1; i <= antKunder; i++)  {
		int r=i+1000;
		LagNavn(kundefil, "KUNDE", ".DTA", r, 7);
		ofstream ut(kundefil);
		kunde = (Kunde*) kundeliste->remove(r);
		kunde->skrivTilFil(ut);
		kundeliste->add(kunde);	
	}
	ifstream inn("02 DTA/SISTE.DTA");
	int buf;
	inn.ignore();
	inn.ignore();
	inn >> buf;

	ofstream ut("02 DTA/SISTE.DTA");
	ut << forsteKunde << endl;
	ut << sisteKunde << endl;
	ut << buf;
}