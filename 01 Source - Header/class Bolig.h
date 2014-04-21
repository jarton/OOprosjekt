#if !defined(__class_Bolig_H)
#define __class_Bolig_H

#include "class Eiendom.h"
#include "enumer.h"

class Bolig : public Eiendom  {
private:
	int byggeaar, bruttoareal, boareal, antSoverom;
	Statusonske statusonsket;

public:
	Bolig(int onr);                       // Constructor. Leser inn data om bolig
	Bolig(ifstream & inn, int onr);       // Constructor. Leser data fra fil
	~Bolig();                             // Destructor
	bool type();                          // Sjekker type (Eiendom eller bolig)
	void skrivBoligTilFil(ofstream & ut); // Skriver data til fil
	void displayBolig();                  // Displayer informasjon om en bolig
	void hentInt(int* i, const char s);   // Return en int til sammenlikning
	const char * hentEnum(const char* s); // Return enum til sammenlikning
};

#endif
