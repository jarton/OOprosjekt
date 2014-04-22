#if !defined(__class_Kunder_H)
#define __class_Kunder_H

#include "listtool2.h"
#include "enumer.h"
#include "class Eiendom.h"

using namespace std;

class Kunder  {
private:
	int forsteKunde, sisteKunde;    // variabel for første og siste kunde
	List* kundeliste;               // liste med kunder

public:
	Kunder();                        // Paramterløs constructor
	void fortsettelseMeny();         // Videre meny etter den i main
	void finnKunde(char* kundeinfo);  //finner en kunde på kundenummer eller navn
	void displayKunde(int kundenr);  // displayer en kunde
	void nyKunde();                  // Oppretter en ny kunde
	void endreKunde(int knr);       // Endrer data om en kunde
	void slettKunde(int knr);         // Fjerner en kunde fra datastrukturen
	void skrivTilFil();               // Skriver kundens data til fil
	void sammenlign(Eiendom* eien);   // sammenlikner kundens data med annet
	void skrivEx(int kundenummer, int oppdrnr); //finne kunde og skriver Ex.DTA
};


#endif
