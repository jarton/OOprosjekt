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
	char kundeinfo[STRLEN];
	int kundenummer;

	valg = les();
	switch(valg) {
		case 'D': cin.getline(kundeinfo,STRLEN); 
		finnKunde(kundeinfo);	break;
		case 'N': nyKunde(); break;
		case 'S': 
			cin >> kundenummer; 
			if (kundenummer < forsteKunde || kundenummer > sisteKunde)
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
	int i;

	for(i=1; i<=sisteKunde; i++)  { 
	kunde = (Kunde*) kundeliste->remove_no(i);
	kunde->sjekkNrNvn(kundeinfo);
	kundeliste->add(kunde);
	}
}

void Kunder :: nyKunde()  { //Lager ny kunde
	char* kunden;
	Kunde* kunde;
	
	kunde = new Kunde(++sisteKunde); //Oppretter ny kunde i memory, øker sistekunde.
	kundeliste->add(kunde); //Legger den inn i listen over kunder.
}

Kunder :: Kunder()  { //CONSTRUCTOR
	Kunde* kunde;
	kundeliste = new List(Sorted); //Lager liste. 
	ifstream inn("02 DTA/SISTE.DTA");
	inn >> forsteKunde;
	inn >> sisteKunde; inn.ignore();

}


void Kunder::slettKunde(int knr)  {
	Kunde* kunde;
	int knum;
	char* kundedta = new char[strlen("KUNDE0001000.DTA") + 1];
	char* kundeinf = new char[strlen("KUNDE0001000.INF") + 1];
	int antkunder;
	antkunder = kundeliste->no_of_elements();

	for (int i = 1; i <= antkunder; i++)  {
		kunde = (Kunde*)kundeliste->remove_no(i);
		if (kunde->sjekkNr(knr) == true)
			kundeliste->destroy(i);
		else
			kundeliste->add(kunde);
	}

	for (int i = forsteKunde+1; i <= sisteKunde; i++)	{
		LagNavn(kundedta, "KUNDE", ".DTA", i, 7);
		LagNavn(kundeinf, "KUNDE", ".INF", i, 7);
		ifstream dta(kundedta);
		ifstream inf(kundeinf);
		if (!kundedta)
      cout << "\nFilen '" << kundedta << "' finnes ikke!";
		if (!kundeinf)
      cout << "\nFilen '" << kundeinf << "' finnes ikke!";
	  dta >> knum; 	
		if (knum == knr)  {
			dta.close();
		  if (remove(kundedta) != 0)
			  cout << "\n\nFilen '" << kundedta << "' ble IKKE fjernet!";
		  else
			  cout << "\n\nFilen '" << kundedta << "' ble fjernet!";
			inf.close();
			if (remove(kundeinf) != 0)
				cout << "\n\nFilen '" << kundeinf << "' ble IKKE fjernet!";
			else
				cout << "\n\nFilen '" << kundeinf << "' ble fjernet!";
		}
	}
	sisteKunde--;
}
// <<<<----------- .INF blir ikke fjernet