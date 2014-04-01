#if !defined(__class_Bolig_H)
#define __class_Bolig_H

#include "class Eiendom.h"
#include "enumer.h"

class Bolig : public Eiendom  {
private:
	int byggeaar, bruttoareal, boareal, antSoverom;
	Statusonske statusonsket;

public:
	Bolig(ifstream & inn, int onr);
	bool type();
	void skrivBoligTilFil(ofstream & ut);
	void displayBolig();  // Displayer informasjon om en bolig
};


#endif
