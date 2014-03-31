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
	IntrSone();
	IntrSone(int sonenr);
	IntrSone(IntrSone* intrsonen, int sonenr);
	void endreSonenr(int nyttnr);
	void display();               // Displater info om IntrSone
};

#endif