#include <iostream>
#include "globale funksjoner og variabler.h"
#include "class Eiendom.h"
#include "class Bolig.h"
#include <fstream>
#include "conster.h"

using namespace std;

//Parameterløs constructor som leser input til data
Bolig::Bolig(int oppdragsnr) : Eiendom(oppdragsnr)	{
	char buffer[STRLEN];

	byggeaar = lesTall("byggeår", 1800, 2014);
	bruttoareal = lesTall("bruttoareal", 2, 1000);
	boareal = lesTall("boareal", 2, 1000);
	antSoverom = lesTall("antall soverom", 0, 250);
	lesTxt("til   Leie / Salgs", buffer, STRLEN);
	if (buffer[0] == 'L' || 'l')
		statusonsket = leie;
	else if (buffer[0] == 'S' || 's')
		statusonsket = salg;
}

//Constructor som leser alle boligdata fra fil
Bolig::Bolig(ifstream & inn, int onr) : Eiendom(inn, onr)	{
	inn >> byggeaar >> bruttoareal
		>> boareal >> antSoverom;
	inn.ignore();
	char buffer[STRLEN];
	inn.getline(buffer, STRLEN);
	switch (buffer[0])	{
	case 's': statusonsket = salg; break;
	case 'l': statusonsket = leie; break;
	}	
}

//Skriver alle boligdata til fil
void Bolig::skrivBoligTilFil(ofstream & ut)	{
	skrivTilFil(ut);
	ut << '\n' << byggeaar << '\n'
		<< bruttoareal << '\n'
		<< boareal << '\n'
		<< antSoverom << '\n';
	if (statusonsket == leie)
		ut << "leie";
	else
		ut << "salg";
}

bool Bolig::type()	{
	return 0;
}

void Bolig::displayBolig()  {
	cout << "\n--BOLIG--\n";
	display();
	cout << "\nByggeaar: "<< byggeaar;
	cout << "\nBruttoadreal: " << bruttoareal;
	cout << "\nBoareal: " << boareal;
	cout << "\nAntall Soverom: " << antSoverom;
}
