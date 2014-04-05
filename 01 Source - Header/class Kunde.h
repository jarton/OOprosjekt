#if !defined(__class_Kunde_H)
#define __class_Kunde_H

#include "listtool2.h"
#include "enumer.h"
#include <fstream>
#include <iostream>
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
	Kunde(ifstream & inn, int nr);
	bool sjekkKNr(int knr);
	Kunde(int knr);		//Constructor
	void sjekkNrNvn(char* kundeinfo);
	void displayKunde();
	bool sjekkNr(int nr);
	
};


#endif