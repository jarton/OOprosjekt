#if !defined(__class_Kunde_H)
#define __class_Kunde_H

#include "listtool2.h"
#include "enumer.h"
#include <fstream>
#include <iostream>
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
	~Kunde();
	Kunde(ifstream & inn, int nr);
	void skrivTilFil(ofstream & ut);
	bool sjekkKNr(int knr);
	Kunde(int knr);		//Constructor
	void sjekkNrNvn(char* kundeinfo);
	void displayKunde();
	bool sjekkNr(int nr);
	void finnMatch(const char boligfeed);
	int hentKundenummer();
	void endreKundeData();
	void skrivExx(int oppdnrMatch);	
	void sjekkEnEien(Eiendom* eien);

	void skrivINF();
};


#endif
