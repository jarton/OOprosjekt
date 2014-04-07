#include <iostream>
#include "globale funksjoner og variabler.h"
#include "class Eiendom.h"
#include "class Bolig.h"
#include <fstream>
#include "conster.h" //STRLEN

using namespace std;

//Parameterløs constructor som leser input til data
Bolig::Bolig(int oppdragsnr) : Eiendom(oppdragsnr) 	{
	char kommando;

	byggeaar = lesTall("byggeår", 1800, 2014);			//Leser byggeår
	bruttoareal = lesTall("bruttoareal", 2, 1000);	//Leser bruttoareal
	boareal = lesTall("boareal", 2, 1000);					//Leser boareal
	antSoverom = lesTall("antall soverom", 0, 250);	//Leser antall soverom
	cout << "\ntil leie eller salgs (L/S): ";		//Leser om den er til leie eller salgs
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
