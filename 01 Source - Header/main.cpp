#include <iostream>
#include "globale funksjoner og variabler.h"
#include "class Soner.h"
#include "class Kunder.h"

using namespace std;



int main()  {

	char valg;                               //  Brukerens valg/kommando.
	Soner* soner;
	Kunder* kunder;

  //lesFraFil();                             //  Oppgave 2F

  skrivMeny();
  cout << "\n\n\nKommando: ";   valg = les();
  while (valg != 'Q')  {
    switch(valg)  {
      case 'E': soner->fortsettelseMeny(valg);  break;  // Eiendom
			case 'S': soner->fortsettelseMeny(valg);  break;  // Sone (display)
      case 'K': kunder->fortsettelseMeny(valg); break;  // Kunde
      //case 'U': ;         break;  //  Senere
      default : skrivMeny();	 break; // 
    }
    cout << "\n\n\nKommando: ";   valg = les();
  }

 // skrivTilFil();                           //  Oppgave 2E
  cout << "\n\n";
  return 0;
}