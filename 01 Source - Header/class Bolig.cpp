#include <iostream>
#include "class Eiendom.h"
#include "class Bolig.h"
#include <fstream>

using namespace std;

Bolig::Bolig(ifstream & inn, int onr) : Eiendom(inn) : Num_element(onr) {
	//m� gj�res

}

void Bolig::display()  {
	cout << "\nBolig";
  cout << "\nByggeaar: "<< byggeaar;
	cout << "Bruttoadreal: " << bruttoareal;
	cout << "Boareal: " << boareal;
	cout << "Antall Soverom: " << antSoverom;
}
