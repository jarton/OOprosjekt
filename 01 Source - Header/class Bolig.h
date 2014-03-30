#if !defined(__class_Bolig_H)
#define __class_Bolig_H

#include "class Eiendom.h"
#include "enumer.h"

class Bolig : public Eiendom  {
private:
	int byggeaar, bruttoareal, boareal, antSoverom;
	Statusonske statusonsket;

public:
	Bolig(ifstream & inn);
	void display();  // Displayer informasjon om en bolig
};


#endif