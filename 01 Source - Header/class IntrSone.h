#if !defined(__class_IntrSone_H)
#define __class_IntrSone_H

#include "enumer.h"

class IntrSone : public Num_element {
private:
	int sonenummer, maxPris, minAreal, minAntSoverom;
	Boligfeed boligfeeden;
	Eiendomstype eiendomstypen;
	Statusonske statusonsket;


public:
	IntrSone(int sonenr) : Num_element(sonenr);
	IntrSone(IntrSone* intrsonen, int sonenr) : Num_element(sonenr);
	void endreSonenr(int nyttnr);
};

#endif