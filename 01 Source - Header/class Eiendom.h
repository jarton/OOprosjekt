#if !defined(__class_Eiendom_H)
#define __class_Eiendom_H

#include "listtool2.h"
#include "enumer.h"
#include <cstdlib>


class Eiendom : public Num_element  {
private:
	int oppdragsnummer, dato, bruksnummer, ansattnummer, pris, areal;
	char* gateadresse, eiernavn, kommunenavn, beskrivelse;
	char* postadresse;  // Må stå alene!!!
	Eiendomstype eiendomstypen;

public:
	virtual void display();          // Displayer informasjon om en eiendom
	bool finnPostnummer(int postnr);
	bool finnOppdragsnr(int oppdnr);
};

#endif