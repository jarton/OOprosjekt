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

void Soner::displayEiendom(int nr)  {
	int i;
	for (i=1; i <=MAXSONER; i++)  {
		if (sonene[i]->hentInfo(nr))
			cout << "hei";
	}

}

void Soner::fortsettelseMeny(char valg) {
	char valg2;
	int nr;
	valg2 = les();
	while (valg2 != 'Q')  {
		switch(valg2) {
		case 'D': 
			if (valg == 'S')  {
			  cin >> nr;
			  displaySone(nr);
			}
			else if (valg =='E')  {
				cin >> nr;
				displayEiendom(nr);
			}
			break;
		case 'N': break;
		case 'S': break;
		case 'E': break;

			break;

			

		  break;	
		}
	}
}

