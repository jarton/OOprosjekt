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

	cout << "\n\nTILDELT OPPDRAGSNUMMER: " << oppdragsnummer << endl;
	bruksnummer = lesTall("Bruksnummer", 1000, 9999); //Leser bruksnummer
	ansattnummer = lesTall("Ansattnr", 0, 1000); //Leser ansattnummer
	pris = lesTall("Pris", 1, 10000000); //Leser pris
	areal = lesTall("Areal", 1, 1000); //Leser areal

	lesTxt("Gateadresse", buffer, STRLEN);			//Leser gateadresse
	gateadresse = new char[strlen(buffer) + 1]; //Gir pekeren innhold
	strcpy(gateadresse, buffer); //Kopierer fra buffer til gateadresse
	lesTxt("Postadresse", buffer, STRLEN);			//Leser postadresse
	postadresse = new char[strlen(buffer) + 1]; //Gir pekeren innhold
	strcpy(postadresse, buffer); //Kopierer fra buffer til postadresse
	lesTxt("Eiernavn", buffer, STRLEN);			//Leser eiernavn
	eiernavn = new char[strlen(buffer) + 1];	//Gir pekeren innhold
	strcpy(eiernavn, buffer); //Kopierer fra buffer til eiernavn
	lesTxt("Kommunenavn", buffer, STRLEN);			//Leser kommunenavn
	kommunenavn = new char[strlen(buffer) + 1]; //Gir pekeren innhold
	strcpy(kommunenavn, buffer);	//Kopierer fra buffer til kommunenavn
	lesTxt("Beskrivelse", buffer, STRLEN);			//Leser beskrivelse
	beskrivelse = new char[strlen(buffer) + 1];	//Gir pekeren innhold 
	strcpy(beskrivelse, buffer);	//Kopierer fra buffer til beskrivelse.

	lesTxt("Type: tomt, enebolig, rekkehus eller hytte", buffer, STRLEN); 
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
    case 'p': *i = pris; break;    //setter i til pris
    case 'a': *i = areal; break;   //setter i til areal
		case 'o': *i = oppdragsnummer; break;
  }  
}

//returnerer enumverdi som en char peker
const char * Eiendom::hentEnum(const char * s) {
  if (!strcmp("Eiendomstype", s)) {    		//sjekker hvilken enum som skal
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

void Eiendom::endreData()  {
	char svar;
	char buffer[STRLEN];

	cout << "\n Endring av oppdrag nummer " << oppdragsnummer << endl<<endl;

	cout << "\n Dato: " << dato;
  cout << "\n Endre dato? (Tast 'J/N')";
  svar=les();
  if (svar == 'J')  {
	Timer * timer3 = new Timer;					//lager nyt timeobjekt
	dato = timer3->hentDato(); 				//Henter aktuell dato	
	delete timer3;	
	cout << "Dato Oppdater!" << endl;
	}

	cout << "\n Bruksnummer: " << bruksnummer;
  cout << "\n Endre bruksnummer? (Tast 'J/N')";
  svar=les();
    if (svar == 'J')  
			bruksnummer = lesTall("Bruksnummer", 1000, 9999); //Leser bruksnummer 

	cout << "\n Ansattnummer: " << ansattnummer;
  cout << "\n Endre ansattnummer? (Tast 'J/N')";
  svar=les();
    if (svar == 'J')  
			ansattnummer = lesTall("Ansattnr", 0, 1000); //Leser ansattnummer

  cout << "\n Gateaddresse: " << gateadresse;
  cout << "\n Endre gateaddresse? (Tast 'J/N')";
  svar=les();
    if (svar == 'J')  {
			delete [] gateadresse;
		  lesTxt("Gateadresse", buffer, STRLEN);			//Leser gateadresse
	    gateadresse = new char[strlen(buffer) + 1]; //Gir pekeren innhold
	    strcpy(gateadresse, buffer); //Kopierer fra buffer til gateadresse
		}

	cout << "\n Postaddresse: " << postadresse;
  cout << "\n Endre postaddresse? (Tast 'J/N')";
  svar=les();
    if (svar == 'J')  {
			delete [] postadresse;
		  lesTxt("Postaddresse", buffer, STRLEN);			//Leser gateadresse
			postadresse = new char[strlen(buffer) + 1]; //Gir pekeren innhold
			strcpy(postadresse, buffer); //Kopierer fra buffer til gateadresse
		}

	cout << "\n Eierens navn: " << eiernavn;
  cout << "\n Endre eiers navn? (Tast 'J/N')";
  svar=les();
    if (svar == 'J')  {
			delete [] eiernavn;
		  lesTxt("Navn", buffer, STRLEN);			//Leser gateadresse
			eiernavn = new char[strlen(buffer) + 1]; //Gir pekeren innhold
			strcpy(eiernavn, buffer); //Kopierer fra buffer til gateadresse
		}

	cout << "\n Kommune: " << kommunenavn;
  cout << "\n Endre kommune? (Tast 'J/N')";
  svar=les();
    if (svar == 'J')  {
			delete [] kommunenavn;
		  lesTxt("Kommune", buffer, STRLEN);			//Leser gateadresse
			kommunenavn = new char[strlen(buffer) + 1]; //Gir pekeren innhold
			strcpy(kommunenavn, buffer); //Kopierer fra buffer til gateadresse
		}

	cout << "\n Beskrivelse: " << beskrivelse;
  cout << "\n Endre Beskrivelse? (Tast 'J/N')";
  svar=les();
    if (svar == 'J')  {
			delete [] beskrivelse;
		  lesTxt("Beskrivelse", buffer, STRLEN);			//Leser gateadresse
			beskrivelse = new char[strlen(buffer) + 1]; //Gir pekeren innhold
			strcpy(beskrivelse, buffer); //Kopierer fra buffer til gateadresse
		}

  cout << "\n Endre Eiendomstype? (Tast 'J/N')";
  svar=les();
    if (svar == 'J')  {
		  lesTxt("Type: tomt, enebolig, rekkehus eller hytte", buffer, STRLEN); 
	     enumSwitch(buffer); //leser type eiendom
		}
}