#if !defined(__class_Kunde_H)
#define __class_Kunde_H

#include "listtool2.h"
#include "enumer.h"

class Kunde : public Num_element  {
private:
	int kundenummer, tlf;
	char* navn, gateadresse, postadresse, mail;
	List* IntrSoneliste;

public:
	Kunde(int knr);		//Constructor
	void sjekkNrNvn(char* kundeinfo);
	void displayKunde();
	IntrSone* nyeIntrSoner();
};


#endif