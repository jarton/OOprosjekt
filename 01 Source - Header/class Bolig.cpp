#include <iostream>
#include <cstring>
#include "globale funksjoner og variabler.h"
#include "class Eiendom.h"
#include "class Bolig.h"
#include <fstream>
#include "conster.h" //STRLEN

using namespace std;

//Parameterløs constructor som leser input til data
Bolig::Bolig(int oppdragsnr) : Eiendom(oppdragsnr) 	{
	char kommando;

	byggeaar = lesTall("Byggeaar", 1800, 2014);			//Leser byggeår
	bruttoareal = lesTall("Bruttoareal", 2, 1000);	//Leser bruttoareal
	boareal = lesTall("Boareal", 2, 1000);					//Leser boareal
	antSoverom = lesTall("Antall soverom", 0, 250);	//Leser antall soverom
	cout << "\nTil leie eller salgs (L/S): ";		//Leser om den er til leie eller salgs
	kommando = les();
	if (kommando == 'L')
		statusonsket = leie;
	else if (kommando == 'S')
		statusonsket = salg;
}

//Constructor som leser alle boligdata fra fil
Bolig::Bolig(ifstream & inn, int onr) : Eiendom(inn, onr)	{
	inn >> byggeaar >> bruttoareal		//leser relevante data fra fil
		>> boareal >> antSoverom;
	inn.ignore();
	char buffer[STRLEN];
	inn.getline(buffer, STRLEN); //Leser om til salg eller leie
	switch (buffer[0])	{	//Sjekker første bokstav på linjen
	case 's': statusonsket = salg; break;
	case 'l': statusonsket = leie; break;
	}	
}

//Decononstructor
Bolig::~Bolig()  {
	//Trenger ingen innmat
}

//Skriver alle boligdata til fil
void Bolig::skrivBoligTilFil(ofstream & ut)	{
	skrivTilFil(ut); //Skriver Eiendomsdata.
	ut << '\n' << byggeaar << '\n' //Skriver Boligdata.
		<< bruttoareal << '\n'
		<< boareal << '\n'
		<< antSoverom << '\n';
	if (statusonsket == leie) //Skriver enten "leie" eller "salg".
		ut << "leie";
	else
		ut << "salg";
}

//returnerer enumene for sammenligning
const char* Bolig::hentEnum(const char* s) {
	Eiendom::hentEnum(s);	     //kaller baseklassen for eiendomstype
  if (!strcmp("Statusonske", s)) {    		//sjekker hvilken enum som skal
    switch(statusonsket) {			//returnes
      case salg: return "salg"; break;		 //switch som returnerer
      case leie: return "enebolig"; break;	//verdien av enumen
    };
  }
}


//returner intene for sammenligning
void Bolig::hentInt(int* i, const char s) {
  switch(s) {			//referanseoverforing vha peker	
    case 'p': *i = pris; break;    //setter i til pris
    case 'a': *i = areal; break;   //setter i til areal
    case 's': *i = antSoverom; break; //setter i til antsoverom
  }
}


bool Bolig::type()	{ //Funksjon for å sjekke objektets type.
	return 0; // (0 tilsvarer bolig, 1 tilsvarer eiendom.)
}


void Bolig::displayBolig()  { //Skriver info til display
	cout << "\n--BOLIG--\n";
	display(); //Viser data fra Eiendom.
	cout << "\nByggeaar: "<< byggeaar;	//Viser data fra Bolig..
	cout << "\nBruttoadreal: " << bruttoareal;
	cout << "\nBoareal: " << boareal;
	cout << "\nAntall Soverom: " << antSoverom;
}

// endrer informasjonen om en bolig
void Bolig::endreData()  {
	char svar;
	char kommando;

	Eiendom::endreData();			//kaller baseklassens endredata først

	cout << "\n Byggeaar: " << byggeaar;
  cout << "\n Endre byggeaar? (Tast 'J/N')";
  svar=les();
    if (svar == 'J')  
			byggeaar = lesTall("Byggeaar", 1800, 2014);			//Leser byggeår

	cout << "\n Bruttoareal: " << bruttoareal;
  cout << "\n Endre bruttoareal? (Tast 'J/N')";
  svar=les();
    if (svar == 'J')  
			bruttoareal = lesTall("Bruttoareal", 2, 1000);	//Leser bruttoareal

	cout << "\n Boareal: " << boareal;
  cout << "\n Endre boareal? (Tast 'J/N')";
  svar=les();
    if (svar == 'J')  
			boareal = lesTall("Boareal", 2, 1000);					//Leser boareal

	cout << "\n Antall soverom: " << boareal;
  cout << "\n Endre antall? (Tast 'J/N')";
  svar=les();
    if (svar == 'J')  
			antSoverom = lesTall("Antall soverom", 0, 250);	//Leser antall soverom

	cout << "\n Endre Status? (Tast 'J/N')";
  svar=les();
    if (svar == 'J')  {
		  cout << "\nTil leie eller salgs (L/S): ";		//Leser om den er til leie eller salgs
	    kommando = les();
	    if (kommando == 'L')
		    statusonsket = leie;
	    else if (kommando == 'S')
		    statusonsket = salg;
		}
}


		
	
	
	