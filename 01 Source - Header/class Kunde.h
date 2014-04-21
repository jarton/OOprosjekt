#if !defined(__class_Kunde_H)
#define __class_Kunde_H

#include "listtool2.h"
#include "enumer.h"
#include <fstream>           // ifstream, Ofstream
#include "class Eiendom.h"
using namespace std;


class Kunde : public Num_element  {
private:
	int kundenummer, tlf;
	char* navn;
	char* gateadresse;
	char* postadresse;
	char* mail;
	List* IntrSoneliste;

public:
	~Kunde();                        // Destructor
	Kunde(ifstream & inn, int nr);   // Constructor som leser fra fil
	void skrivTilFil(ofstream & ut);  // skriver data til fil
	bool sjekkKNr(int knr);           // Sjekker om kundenummer er rett
	Kunde(int knr);		                //Constructor - Ny Kunde
	void sjekkNrNvn(char* kundeinfo);  // Sjekker om Kundenummer og navn er rett
	void displayKunde();               // Displayer info om en kunde
	void finnMatch(const char boligfeed);  // Finner match: eiendommer og kunder
	int hentKundenummer();              // Henter kundenummer
	void endreKundeData();              // Endrer data om kunden
	void skrivExx(int oppdnrMatch);	    // Skriver kunde til Exxx.DTA
	void sjekkEnEien(Eiendom* eien);    // Finner match: eiendommer og kunder
	void skrivINF();                    // Skriver kunde til INF filen
};


#endif
