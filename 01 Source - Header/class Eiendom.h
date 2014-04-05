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
	Eiendom(int onr);
	Eiendom(ifstream & inn, int onr);
	virtual ~Eiendom();
	void skrivTilFil(ofstream & ut);
	virtual void skrivBoligTilFil(ofstream & ut)
	{	/*tomt*/	};
	virtual void displayBolig()
	{ /*tomt*/		 };
	virtual bool type();
	void enumSwitch(char* t);
	virtual void display();          // Displayer informasjon om en eiendom
	bool finnPostnummer(int postnr);
	bool finnOppdragsnr(int oppdnr);
};

#endif
