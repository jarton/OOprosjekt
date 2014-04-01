#if !defined(__class_Eiendom_H)
#define __class_Eiendom_H

#include "listtool2.h"
#include "enumer.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

class Eiendom : public Num_element  {
private:
	int oppdragsnummer, dato, bruksnummer, ansattnummer, pris, areal;
	char* gateadresse;
	char* postadresse;
	char* eiernavn;
	char* kommunenavn;
	char* beskrivelse;
	Eiendomstype eiendomstypen;

public:
	Eiendom(ifstream & inn, int onr);
	void skrivTilFil(ofstream & ut);
:a
	virtual void display();          // Displayer informasjon om en eiendom
	bool finnPostnummer(int postnr);
	bool finnOppdragsnr(int oppdnr);
};

#endif
