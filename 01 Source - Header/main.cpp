#include <iostream>
#include "globale funksjoner og variabler.h"
#include "class Soner.h"
#include "class Sone.h"
#include "class Kunde.h"

#include "class Kunder.h"

using namespace std;



int main()  {

	char valg;                               //  Brukerens valg/kommando.
	Soner* soner;
	Kunder* kunder;
	//List* Kundeliste;
	//List* Soneliste;

	//Kundeliste = new List(Sorted);
	//Soneliste = new List(Sorted);
	

  //lesFraFil();                             //  Oppgave 2F

  skrivMeny();
  valg = les();
  while (valg != 'Q')  {
    switch(valg)  {
      case 'E': soner->fortsettelseMeny();  break;  // Eiendom
			case 'S': soner->fortsettelseMeny();  break;  // Sone (display)
      case 'K': kunder->fortsettelseMeny(); break;  // Kunde
      //case 'U': ;         break;  //  Senere
      default : skrivMeny();	 break; // 
    }
    valg = les();
  }

 // skrivTilFil();                           //  Oppgave 2E
  cout << "\n\n";
  return 0;
}