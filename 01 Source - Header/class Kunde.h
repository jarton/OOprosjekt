#if !defined(__class_Kunde_H)
#define __class_Kunde_H
#include "listtool2.h";

class Kunde{
private:
	int kundenummer, tlf;
	char* navn, gateadresse, postadresse, mail;
	List* IntrSoneliste;

public:
	Kunde();
};


#endif