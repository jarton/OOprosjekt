#if !defined(__class_Eiendom_H)
#define __class_Eiendom_H
#include "enumer.h";


class Eiendom : public Num_element {
private:
	int oppdragsnummer, dato, bruksnummer, ansattnummer, pris, areal;
	char* gateadresse, postadresse, eiernavn, kommunenavn, beskrivelse;
	Eiendomstype eiendomstypen;

public:
};

#endif