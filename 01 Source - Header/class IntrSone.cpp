#include <iostream>
#include <cstring>
#include "class Kunde.h"
#include "class IntrSone.h"
#include "globale funksjoner og variabler.h"
#include <cstdlib>

using namespace std;

//"returnerer" intene for sammenligning
void IntrSone::hentInt(int* i, const char s) {
  switch(s) { 				//referanseoverforer vha peker
	  case 'p': i = maxPris; break;    //setter i til maxpris
	  case 'a': i = minAreal; break;    //setter i til minareal
	  case 's': i = minAntSoverom; break;   //setter i til minsoverom
  }
}

//returner enumverdi som charpeker
const char* IntrSone::hentEnum(const char* s) {
  if (strcmp(s, "Eiendomstype")) {    		//sjekker hvilken enum som skal
    switch(eiendomstypen) {			//returnes
      case tomt: return "tomt"; break;		 //switch som returnerer
      case enebolig: return "enebolig"; break;	//verdien av enumen
      case rekkehus: return "rekkehus"; break;	// som har de ulike eiendomstypene
      case hytte: return "hytte"; break;
      case leilighet: return "leilighet"; break;
    };
  };
  if (strcmp(s, "Statusonske")) {    		//sjekker hvilken enum som skal
    switch(statusonsket) {			//returnes
      case salg: return "salg"; break;		 //switch som returnerer
      case leie: return "enebolig"; break;	//verdien av enumen
      case begge: return "begge"; break;
    };
  }
}


char IntrSone::hentBoligfeeden() {
  if (boligfeeden == snarest)
	  return 'S';
  else 
	 return 'U'; 
}

int IntrSone::hentsonenum() {
  return sonenummer;
}

IntrSone :: IntrSone(int sonenr) : Num_element(sonenr)  { //Constructor.
	
	sonenummer=sonenr;
	maxPris = lesTall("\nMaxpris", 1, 1000000000); //Leser max pris.
	minAreal = lesTall("\nMinimum areal", 1, 10000); //Leser minimum areal.
	minAntSoverom = lesTall("\nMinimum antall soverom", 0, 100); //Leser minimum ant. soverom.

  boligfeedFunk();
	eiendomstypeFunk();
	statusonskeFunk();
}

IntrSone :: IntrSone(IntrSone* intrsonen, int sonenr) : Num_element(sonenr) {
	maxPris = intrsonen->maxPris;							
	minAreal = intrsonen->minAreal;
	minAntSoverom = intrsonen->minAntSoverom;
	boligfeeden = intrsonen->boligfeeden;
	eiendomstypen = intrsonen->eiendomstypen;
	statusonsket = intrsonen->statusonsket;

}

IntrSone::IntrSone() {}

IntrSone :: ~IntrSone(){
	//Trenger ikke innmat

}

void IntrSone :: endreSonenr(int nyttnr){
	sonenummer = nyttnr; //Endrer sonenummer.
}

// Displayer informasjon om en interesse sone
void IntrSone::display()  {
	char* eiendomstype[] = {"Tomt", "Enebolig", "Rekkehus", "Leilighet", "Hytte"};
	char* statusonske[] = {"Salg", "Leie", "Salg og leie"};
  char* boligfeed[]=  {"Ukentlig", "Snarest"};
	cout << " \n\n-- Interessesone : ";
	cout << "\nSonenummer: " <<  sonenummer;
  cout << "\nMaksimums pris: " <<  maxPris;
  cout << "\nMinimums areal: " <<  minAreal;
  cout << "\nMinimum antall soverom: " <<  minAntSoverom;
  cout << "\nBoligfeed: " << boligfeed[boligfeeden];
  cout << "\nEiendomstype: " <<  eiendomstype[eiendomstypen];
  cout << "\n0nkes: " <<  statusonske[statusonsket];
}

IntrSone::IntrSone(ifstream & inn, int nr) : Num_element(nr)  {
	int bolFeed;
	int eiendomsTyp;
	int statOnsk;
	inn >> sonenummer;			//Constructor
	inn.ignore();						//som
	inn >> maxPris;					//leser
	inn.ignore();						//fra
	inn >> minAreal;				//fil.
	inn.ignore();
	inn >> minAntSoverom;
	inn.ignore();
  inn >> bolFeed;
	inn.ignore();
	inn >> eiendomsTyp;
	inn.ignore();
	inn >> statOnsk;
	inn.ignore();
	inn.ignore();

	enumBoligfeedSwitch(bolFeed);		//Initierer enum.
	enumEiendomstypeSwitch(eiendomsTyp);	//Initierer enum.
	enumStatusSwitch(statOnsk);			//Initierer enum.

}

void IntrSone::skrivTilFil(ofstream & ut, int nr)  {
	ut << sonenummer << endl;				//Skriver
	ut << maxPris << endl;					//informasjon
	ut << minAreal << endl;					//til
	ut << minAntSoverom << endl;		//fil.
	ut << boligfeeden << endl;
	ut << eiendomstypen << endl;
	ut << statusonsket << endl;
	ut << endl;
}


void IntrSone::enumBoligfeedSwitch(int nr)  {
	switch (nr)	{	//Tar imot int som parameter.
	case 0: boligfeeden = ukentlig; break;	//Setter riktig verdi i enum.
	case 1: boligfeeden = snarest; break;
	};
}

void IntrSone::enumEiendomstypeSwitch(int nr)  {
	switch (nr)	{ //Mottar int som parameter.
	case 0: eiendomstypen = tomt; break;
	case 1: eiendomstypen = enebolig; break;	//Setter riktig verdi i enum.
	case 2: eiendomstypen = rekkehus; break;
	case 3: eiendomstypen = leilighet; break;
	case 4: eiendomstypen = hytte; break;
	};
}

void IntrSone::enumStatusSwitch(int nr)  {
	switch (nr)	{	//Mottar int som parameter.
	case 0: statusonsket = salg; break;
	case 1: statusonsket = leie; break; //Setter riktig verdi i enum.
	case 2: statusonsket = begge; break;
	};
}

// Endrer data på en intrsone
void IntrSone:: endreIntrSone()   {
	char svar;
	cout << "\n0nsker du aa endre data i sone nummer "<<sonenummer<<"? (J/N)";
	svar=les();
	if (svar=='J')  {
	  char* eiendomstype[] = {"Tomt", "Enebolig", "Rekkehus", "Leilighet", "Hytte"};
	  char* statusonske[] = {"Salg", "Leie", "Salg og leie"};
    char* boligfeed[]=  {"Ukentlig", "Snarest"};

    cout << "\nMaksimums pris: " <<  maxPris;
    cout << "\n Endre maksimums pris? (Tast 'J/N')";
	  svar=les();
	  if (svar == 'J')  
	    maxPris = lesTall("\nMaxpris", 1, 1000000000); //Leser max pris.

    cout << "\nMinimums areal: " <<  minAreal;
    cout << "\n Endre minimums areal? (Tast 'J/N')";
	  svar=les();
	  if (svar == 'J')  
	    minAreal = lesTall("\nMinimum areal", 1, 10000); //Leser minimum areal.

		cout << "\nMinimum antall soverom: " <<  minAntSoverom;
    cout << "\n Endre minimum antall soverom? (Tast 'J/N')";
	  svar=les();
	  if (svar == 'J')  
	    minAntSoverom = lesTall("\nMinimum antall soverom", 0, 100); //Leser minimum ant. soverom. 
  
  
    cout << "\nBoligfeed: " << boligfeed[boligfeeden];
    cout << "\n Endre boligfeed? (Tast 'J/N')";
	  svar=les();
	  if (svar == 'J')  
			boligfeedFunk();

    cout << "\nEiendomstype: " <<  eiendomstype[eiendomstypen];
    cout << "\n Endre eiendomstype? (Tast 'J/N')";
	  svar=les();
	  if (svar == 'J')  
			eiendomstypeFunk();

    cout << "\n0nkes: " <<  statusonske[statusonsket];
    cout << "\n Endre? (Tast 'J/N')";
	  svar=les();
	  if (svar == 'J')  
			statusonskeFunk();

	}

	/* TODO::::::FRA OPPGAVE::For de sonene kunden skifter til umiddelbar/snarest boliginfo om, vil det også være
aktuelt å legge til info om kunden bakerst på filene ’Exxxxxxx.DTA’.*/
}


void IntrSone::boligfeedFunk()  {
	char kommando; //Hjelpevariabel
	cout << "\nBoligfeed ([U]kentlig / [S]narest): "; //Spør om ønsket boligfeed.

	kommando = 'B'; // Bare for å ikke ha noe søppel.

	while(kommando != 'U' && kommando != 'S') { // SENERE: Fix dette. Alternativ metode.
		kommando = les();		//Leser ønsket boligfeed.
		switch(kommando) {
		case 'U': boligfeeden = ukentlig; break;
		case 'S': boligfeeden = snarest; break;
		default: cout << "\nUlovlig kommando. Prov igjen."; break;

		}
	}

}


void IntrSone::eiendomstypeFunk() {
	char kommando; //Hjelpevariabel
	cout << "\n\nEiendomstype ([T]omt, [E]nebolig, [R]ekkehus, [L]eilighet, [H]ytte): ";

	while(kommando != 'T' && kommando != 'E' && kommando != 'R' && 
		kommando != 'L' && kommando != 'H'){ //Senere: fix dette. Stygg metode.
		kommando = les(); //Leser eiendomstype.
		switch(kommando){
		case 'T': eiendomstypen = tomt; break;			//Setter
		case 'E': eiendomstypen = enebolig; break;	//Riktig
		case 'R': eiendomstypen = rekkehus; break;	//type.
		case 'L': eiendomstypen = leilighet; break;
		case 'H': eiendomstypen = hytte; break;
		default: cout << "\n\nUlovlig kommando. Prov igjen."; break;
		}
	}
}


void IntrSone::statusonskeFunk()  {
	char kommando; //Hjelpevariabel
	cout << "\n\nOnsket status ([S]alg / [L]eie): ";
	kommando = 'B'; //For å ikke inneholde søppel.

	while (kommando != 'S' && kommando != 'L'){ //SENERE: Fix dette. Stygg metode.
		kommando = les();		//Leser ønsket status.
		switch(kommando){
		case 'S': statusonsket = salg; break; //Setter riktig status.
		case 'L': statusonsket = leie; break;
		default: cout << "\n\nUlovlig kommando. Prov igjen."; break;
		}
	}
}
