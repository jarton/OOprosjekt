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

void Kunder::fortsettelseMeny()  { //Meny innad K
	char valg;
	char kundeinfo[STRLEN];
	int kundenummer;

	valg = les(); //Leser et upcaset tegn
	switch(valg) {
		case 'D': 
		cin.ignore();
		cin.getline(kundeinfo,STRLEN);  //Leser inn kundeinfo
		finnKunde(kundeinfo);	//Finner kunden og displayer
		break;
		case 'N': nyKunde(); break; //Lager ny kunde
		case 'S': 
			cin >> kundenummer;		//Henter kundenummer
			if (kundenummer < forsteKunde || kundenummer > sisteKunde) //Hvis kunden ikke finnes
				cout << "\n OBS! Ingen kunde med kundenummer '"<<kundenummer<<"' er regisrtert!";
			else
  			slettKunde(kundenummer); break; //Sletter kunden.
		case 'E': break;
		default: break;
	 }
}

void Kunder::finnKunde(char* kundeinfo)  {
	Kunde* kunde;
	//List* kundeliste;
	int antallKunder= kundeliste->no_of_elements(); //ant. kunder
	int i;

	for(i=1; i<=antallKunder; i++)  {  //Går gjennom kundene.
	kunde = (Kunde*) kundeliste->remove_no(i); //Fjerner en kunde fra listen
	kunde->sjekkNrNvn(kundeinfo); //Sjekker infoen, displayer eventuelt.
	kundeliste->add(kunde); //Legger tilbake.
	}
}

void Kunder :: nyKunde()  { //Lager ny kunde
	Kunde* kunde;
	if (forsteKunde == 1000) //Hvis ingen kunder enda.
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

// Sletter en kunda fra datastrukturen, samt DTA- filen
void Kunder::slettKunde(int knr)  {
	Kunde* kunde;                                       // Kunde peker
	Kunde* forste;                               // Kunde peker (første kunde)
	int knum;                                       // variablel for kundenummer
	char* kundedta = new char[strlen("KUNDE0001000.DTA") + 1];
	int antkunder = kundeliste->no_of_elements();    // finner antall kunder

	for (int i = 1; i <= antkunder; i++)  {           // Loop gjennom alle kunder
		kunde = (Kunde*)kundeliste->remove_no(i);    // fjerner en kunde fra listen
		int nr = kunde->hentKundenummer();          // henter kundens kundenr
		LagNavn(kundedta, "KUNDE", ".DTA", nr, 7); // Oppretter filnavn
		ifstream dta(kundedta);                      // oppretter utfil
		if (!kundedta)                                // hvis utfil ikke eksisterer
      cout << "\nFilen '" << kundedta << "' finnes ikke!";
	  dta >> knum; 	                            // leser inn kundenummer fra fil
		if (knum == knr)  {             // hvis kundenummer på fil == datastruktur
			dta.close();                              // stenger filen
		  if (remove(kundedta) != 0)                 // fjerner filen
			  cout << "\n\nFilen '" << kundedta << "' ble IKKE fjernet!";
		  else
			  cout << "\n\nFilen '" << kundedta << "' ble fjernet!";
		}
		kundeliste->add(kunde);                // Legger kunden tilbake i listen
	}

for (int i = 1; i <= antkunder; i++)  {  // loop gjennom alle kunder
  kunde = (Kunde*)kundeliste->remove_no(i);  // fjerner en kunden fra listen
  if (kunde->sjekkNr(knr) == true)  {   // hvis kundenummeret er lik innskrevet
    kundeliste->destroy(i);             // destroyer kunden
		break;
	}
  else 
		kundeliste->add(kunde);            // legger kunden tilbake i listen
}
  int ant=kundeliste->no_of_elements();   // finner antallet i listen
	if(ant > 0)  {                          // hvis antallet er større enn 0
  	forste = (Kunde*)kundeliste->remove_no(1);  // fjerner 1. fra listen
	  forsteKunde = forste->hentKundenummer();  // henter kundenummeret
  	kundeliste->add(forste);                 // legger kundenummeret som forste
	  skrivTilFil();                            // Skriver til fil
	}
	else if (ant == 0) {                  // hvis antall kunder = 0
		forsteKunde=1000;                     // nullstiller forsteKunde
		sisteKunde=1000;                      // nullstiller sisteKunde
		skrivTilFil();                          // Skriver til fil
	}
}


// skriver kundedata til fil
void Kunder::skrivTilFil()  {
	char * kundefil  = new char [strlen("KUNDE0001001.DTA")+1];
	int antKunder = kundeliste->no_of_elements(); //finner antall kunder i listen
	Kunde* kunde;                                 // Kunder Peker
	for (int i = 1; i <= antKunder; i++)  {         // Lopp gjennom alle kunder
		kunde = (Kunde*)kundeliste->remove_no(i);    // fjerner kunde fra listen
	  int knr = kunde->hentKundenummer();             // henter kundenummeret
  	kundeliste->add(kunde);                    // legger kunde tilbake i listen
		LagNavn(kundefil, "KUNDE", ".DTA", knr, 7);  // lager filnavn
		ofstream ut(kundefil);                         // opprettter utfl
		kunde = (Kunde*) kundeliste->remove_no(i);   // fjerner fra listen
		kunde->skrivTilFil(ut);                         // Skriver til fil
		kundeliste->add(kunde);	                   // legger kunden tilbake i filen
	}
	ifstream inn("02 DTA/SISTE.DTA");       // henter inn Siste data
	int buf;                  
	inn.ignore();                      // ignorer 1. linje
	inn.ignore();                      // ignorer 2. linje
	inn >> buf;                         // leser inn oppdragsnummer

	ofstream ut("02 DTA/SISTE.DTA");    // skriver ut siste-data
	ut << forsteKunde << endl;          // skriver ut første kunde
	ut << sisteKunde << endl;           // skriver ut siste kunde
	ut << buf;                          // skriver ut oppdragsnummer
}