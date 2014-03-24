#include "class Sone.h"
#include <iostream>
using namespace std;

void Sone::display() {
	cout << "\nSonenummer: " << soneNummer;
	cout << "\nBeskrivelse: " << beskrivelse << endl;

}

int Sone::hentSonenr()  {
	return soneNummer;
}