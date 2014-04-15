#include <iostream>
#include "class Eiendom.h"
#include <cstdlib>																// itoa
#include <fstream>
#include "conster.h"
#include "stdio.h"
#include <cstring>
#include "globale funksjoner og variabler.h"
#include "timer3.h"

using namespace std;

//Constructor u/parameter
Eiendom::Eiendom(int oppdragsnr) : Num_element(oppdragsnr)	{
	char buffer[STRLEN]; 								//buffer for innlesing
	Timer * timer3 = new Timer;					//lager nyt timeobjekt
	oppdragsnummer = oppdragsnr;				//setter oppdragsnr

	dato = timer3->hentDato(); 				//Henter aktuell dato	
	delete timer3;								//sletter timer objekter	

	bruksnummer = lesTall("bruksnummer", 1000, 9999); //Leser bruksnummer
	ansattnummer = lesTall("ansattnr", 0, 1000); //Leser ansattnummer
	pris = lesTall("pris", 1, 10000000); //Leser pris
	areal = lesTall("areal", 1, 1000); //Leser areal

	lesTxt("gateadresse:", buffer, STRLEN);			//Leser gateadresse
	gateadresse = new char[strlen(buffer) + 1]; //Gir pekeren innhold
	strcpy(gateadresse, buffer); //Kopierer fra buffer til gateadresse
	lesTxt("postadresse:", buffer, STRLEN);			//Leser postadresse
	postadresse = new char[strlen(buffer) + 1]; //Gir pekeren innhold
	strcpy(postadresse, buffer); //Kopierer fra buffer til postadresse
	lesTxt("eiernavn:", buffer, STRLEN);			//Leser eiernavn
	eiernavn = new char[strlen(buffer) + 1];	//Gir pekeren innhold
	strcpy(eiernavn, buffer); //Kopierer fra buffer til eiernavn
	lesTxt("kommunenavn:", buffer, STRLEN);			//Leser kommunenavn
	kommunenavn = new char[strlen(buffer) + 1]; //Gir pekeren innhold
	strcpy(kommunenavn, buffer);	//Kopierer fra buffer til kommunenavn
	lesTxt("beskrivelse:", buffer, STRLEN);			//Leser beskrivelse
	beskrivelse = new char[strlen(buffer) + 1];	//Gir pekeren innhold 
	strcpy(beskrivelse, buffer);	//Kopierer fra buffer til beskrivelse.

	lesTxt("type: tomt, enebolig, rekkehus eller hytte", buffer, STRLEN); 
	enumSwitch(buffer); //leser type eiendom.
}

//Constructor som leser eiendomsdata fra fil
Eiendom::Eiendom(ifstream & inn, int onr): Num_element(onr)	{
	oppdragsnummer = onr;
	inn >> dato >> bruksnummer
	 	>> ansattnummer	>> pris >> areal; //Leser diverse data.

	char buffer[STRLEN];								//buffer for innlesing
	inn.ignore();
	inn.getline(buffer, STRLEN);	//Leser gateadresse.
	gateadresse = new char[strlen(buffer + 1)];
	strcpy(gateadresse, buffer); //Kopierer.
	inn.getline(buffer, STRLEN); //Leser postadresse.
	postadresse = new char[strlen(buffer + 1)];
	strcpy(postadresse, buffer); //Kopierer.
	inn.getline(buffer, STRLEN); //Leser eiernavn.
	eiernavn = new char[strlen(buffer + 1)];
	strcpy(eiernavn, buffer); //Kopierer.
	inn.getline(buffer, STRLEN); //Leser kommunenavn.
	kommunenavn = new char[strlen(buffer + 1)];
	strcpy(kommunenavn, buffer); //Kopierer.
	inn.getline(buffer, STRLEN); //Leser beskrivelse.
	beskrivelse = new char[strlen(buffer + 1)];
	strcpy(beskrivelse, buffer); //Kopierer.
	inn.getline(buffer, STRLEN); //Leser type.
	enumSwitch(buffer);
}

//Virtuell Deconstructor
Eiendom::~Eiendom()	{
	delete[] gateadresse,
		postadresse,
		eiernavn,
		kommunenavn,
		beskrivelse;
}

//Skriver alle eiendomsdata til fil 
void Eiendom::skrivTilFil(ofstream & ut)	{
	ut << oppdragsnummer << '\n'	//Skriver
		<< dato << '\n'							//data
		<< bruksnummer << '\n'			//fra
		<< ansattnummer << '\n'			//Eiendom
		<< pris << '\n' << areal		//til
		<< '\n' << gateadresse			//fil.
		<< '\n' << postadresse
		<< '\n' << eiernavn
		<< '\n' << kommunenavn
		<< '\n' << beskrivelse
		<< '\n';
	if (eiendomstypen == tomt)						//Sjekker
		ut << "tomt";												//type
	else if (eiendomstypen == enebolig)		//eiendom
		ut << "enebolig";										//og
	else if (eiendomstypen == rekkehus)		//skriver
		ut << "rekkehus";										//den
	else if (eiendomstypen == leilighet)	//til
		ut << "leilighet";									//fil
	else
		ut << "hytte";
}

//"returner" intene for sammenligning
void Eiendom::hentInt(int* i, const char s) {
  switch(s) {			//referanseoverforing vha peker	
    case 'p': i = pris; break;    //setter i til pris
    case 'a': i = areal; break;   //setter i til areal
  }  
}

//returnerer enumverdi som en char peker
const char * Eiendom::hentEnum(const char * s) {
  if (strcmp(s, "Eiendomstype")) {    		//sjekker hvilken enum som skal
    switch(eiendomstypen) {			//returnes
      case tomt: return "tomt"; break;		 //switch som returnerer
      case enebolig: return "enebolig"; break;	//verdien av enumen
      case rekkehus: return "rekkehus"; break;	// som har de ulike eiendomstypene
      case hytte: return "hytte"; break;
      case leilighet: return "leilighet"; break;
    };
  };
}

void Eiendom::enumSwitch(char * b)	{
	switch (b[0])	{		//Sjekker første bokstav i array.
	case 't': eiendomstypen = tomt; break;			//Setter
	case 'e': eiendomstypen = enebolig; break;	//riktig
	case 'r': eiendomstypen = rekkehus; break;	//verdi
	case 'l': eiendomstypen = leilighet; break;	//i
	case 'h': eiendomstypen = hytte; break;			//enum.
	};
}

//Returnerer 1 om det er en eiendom
bool Eiendom::type()	{
	return 1;
}

// Displayer all informasjon om en eiendom
void Eiendom::display()  {
  cout << "\n\nOppdragsnummer: " << oppdragsnummer;
	cout << "\nDato: " << dato;
	cout << "\nBruksnummer: " << bruksnummer;
	cout << "\nSaksbehandlerens ansattnummer: " << ansattnummer;
	cout << "\nPris: " << pris;
	cout << "\nAreal: " << areal;
	cout << "\n\nGateadresse: " << gateadresse;
	cout << "\nPostadresse: " << postadresse;
	cout << "\nEier: " << eiernavn;
	cout << "\nKommune: " << kommunenavn;
	cout << "\nBeskrivelse: " << beskrivelse << "\n\n";
}

bool Eiendom::finnPostnummer(int postnr)  {
	bool erlik;
	char * postpek = postadresse; //Hjelpepeker
	char postarr[5]; //Hjelpearray
	int i = 0;

	sprintf(postarr, "%d", postnr); //Gjør postnr om til tekst,	
	do {														//og setter inn i postarr.
		if (*postpek++ == postarr[i++])
			erlik = true;
		else erlik = false;
	} while (erlik);
		
	if (i > 4)
		return true;
	else
		return false;
}

bool Eiendom::finnOppdragsnr(int oppdnr)  {
	if(oppdnr==oppdragsnummer) //Sjekker om oppdragsnummeret er likt.
		return true;
	else
		return false;
}
