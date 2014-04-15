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
	IntrSone(ifstream & inn, int nr);
	IntrSone(int sonenr);
	IntrSone(IntrSone* intrsonen, int sonenr);
	~IntrSone();
	void endreSonenr(int nyttnr);
	void endreIntrSone();
	void display();               // Displater info om IntrSone
	void skrivTilFil(ofstream & ut, int nr);
	int hentsonenum();
	void statusonskeFunk();
	char hentBoligfeeden();
	void boligfeedFunk();
	void eiendomstypeFunk();
	void enumBoligfeedSwitch(int nr);
	void enumEiendomstypeSwitch(int nr);
	void enumStatusSwitch(int nr);
};

#endif
