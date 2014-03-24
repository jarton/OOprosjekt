#include <iostream>
#include "conster.h"
#include "class Soner.h"
using namespace std;

//Finner sonenummer gitt i parameter og displayer
void Soner::finnSone(int sonenr)  {
	int i;
	for (i=1; i<=MAXSONER; i++)  {                     // loop gjennom alle soner
		if (sonene[i]->hentSonenr() == sonenr)        // Hvis sonens nr = parameter
			sonene[i]->display();                                 // Displayer sonen
	}
}

void Soner::fortsettelseMeny(char valg) {
	cout << "Test " << valg;
}

