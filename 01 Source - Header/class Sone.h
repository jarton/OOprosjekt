#if !defined(__class_Sone_H)
#define __class_Sone_H

#include "listtool2.h"

class Sone  {
private:
	char* beskrivelse;
	int soneNummer;      
	List* eiendommene;


public:
	void display();               // Displayer all info om en sone
	int hentSonenr();             // Returnerer sonens nummer
	int hentInfo(int nr);
};


#endif