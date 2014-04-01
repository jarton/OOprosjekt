#include <iostream>
#include "class Eiendom.h"
#include "class Bolig.h"
#include <fstream>

using namespace std;

Bolig::Bolig(ifstream & inn, int onr) : Eiendom(inn, onr)	{
	//må gjøres

}

void Bolig::skrivTilFil(ofstream & ut)	{
	//Eiendom::skrivTilFil(ut);


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
