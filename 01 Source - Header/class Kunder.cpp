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
	int knum=0;
	char* kundefil = new char[strlen("KUNDE0001000.DTA") + 1];
	int antkunder;
	int filnvnlen;
	antkunder = kundeliste->no_of_elements();

	for (int i = 1; i <= antkunder; i++)  {
		kunde = (Kunde*)kundeliste->remove_no(i);
		if (kunde->sjekkNr(knr) == true)
			kundeliste->destroy(i);
		else
			kundeliste->add(kunde);
	}

	for (int i = forsteKunde+1; i <= sisteKunde; i++)	{
		LagNavn(kundefil, "KUNDE", ".DTA", i, 7);
		ifstream inn(kundefil);

		if (!kundefil)
      cout << "\nFilen '" << kundefil << "' finnes ikke!";
	  inn >> knum; 	
		if (knum == knr)  {
			inn.close();
		  if (remove(kundefil) != 0)
			  cout << "\n\nFilen '" << kundefil << "' ble IKKE fjernet!";
		  else
			  cout << "\n\nFilen '" << kundefil << "' ble fjernet!";
			filnvnlen = strlen(kundefil);           // <<<<-- feil fra her
			kundefil[filnvnlen - 1] = 'F';
			kundefil[filnvnlen - 2] = 'N';
			kundefil[filnvnlen - 3] = 'I';
			inn.close();
			if (remove(kundefil) != 0)
				cout << "\n\nFilen '" << kundefil << "' ble IKKE fjernet!";
			else
				cout << "\n\nFilen '" << kundefil << "' ble fjernet!";
		}
	}
	sisteKunde--;
}