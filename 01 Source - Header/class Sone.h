#if !defined(__class_Sone_H)
#define __class_Sone_H

#include "listtool2.h"

class Sone  {
private:
	char* beskrivelse;
	int soneNummer;      
	List* eiendommene;

public:
	void display();
	int hentSonenr();
};


#endif