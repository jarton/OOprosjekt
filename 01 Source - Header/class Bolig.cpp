#include <iostream>
#include "class Eiendom.h"
#include "class Bolig.h"
#include <fstream>
#include "conster.h"

using namespace std;

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

void Bolig::skrivBoligTilFil(ofstream & ut)	{
	skrivTilFil(ut);
	ut << byggeaar << '\n'
		<< bruttoareal << '\n'
		<< boareal << '\n'
		<< antSoverom << '\n'
		<< statusonsket;
}

bool Bolig::type()	{
	return 0;
}

void Bolig::display()  {
	cout << "\nBolig";
  cout << "\nByggeaar: "<< byggeaar;
	cout << "Bruttoadreal: " << bruttoareal;
	cout << "Boareal: " << boareal;
	cout << "Antall Soverom: " << antSoverom;
}
