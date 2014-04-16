#include <iostream>                                 // cin, cout
#include "globale funksjoner og variabler.h"        // bruke globale funksj.
#include "class Soner.h"                            // bruke Soner
#include "class Kunder.h"                           // bruke Kunder

using namespace std;

  Soner soner;                                            // Lage Soner-objekt.
  Kunder kunder;                                         // Lage Kunder-objekt.

int main()  {

	char valg;                                       //  Brukerens valg/kommando.
	
  skrivMeny();                                             // Displayer menyen.
  valg = les();                                   // Leser inn et upcaset tegn.
  while (valg != 'Q')  {                         // Loop til brukeren taster Q.
    switch(valg)  {
      case 'E': soner.fortsettelseMeny(valg);  break; //Videre meny for Eiendom
			case 'S': soner.fortsettelseMeny(valg);  break;  // Videre meny for Sone.
      case 'K': kunder.fortsettelseMeny(); break;     // Videre meny for Kunde.
      case 'U': ukentligUtskrift(); break;                  // Lager .INF filen.
      default : cout << "\n\tOBS! Ugyldig kommando!\n\n";	 break;  //feilmedling
    }
		skrivMeny();                                             // Displayer meny
    valg = les();                                // Leser inn et upcaset tegn
  }
  return 0;
}
