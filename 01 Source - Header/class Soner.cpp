#include <iostream>
#include "globale funksjoner og variabler.h"
#include "conster.h"
#include "class Soner.h"
using namespace std;

//Finner sonenummer gitt i parameter og displayer
void Soner::displaySone(int sonenr)  {
	int i;
	for (i=1; i<=MAXSONER; i++)  {                     // loop gjennom alle soner
		if (sonene[i]->hentSonenr() == sonenr)        // Hvis sonens nr = parameter
			sonene[i]->display();                                 // Displayer sonen
	}
}

void Soner::fortsettelseMeny() {
	char valg2;
	int sonenr;
	valg2 = les();
	while (valg2 != 'Q')  {
		switch(valg2) {
		case 'D': 
		  cin >> sonenr;
			displaySone(sonenr);
		  break;	
		}
	}
}

