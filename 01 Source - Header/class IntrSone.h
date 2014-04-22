#if !defined(__class_IntrSone_H)
#define __class_IntrSone_H

#include <fstream>         // ifstream, ofstream
#include "enumer.h"
#include "listtool2.h"

using namespace std;

class IntrSone : public Num_element {
private:
	int sonenummer, maxPris, minAreal, minAntSoverom;  //data om en intrsone
	Boligfeed boligfeeden;                   // Ukentlig, Snarest
	Eiendomstype eiendomstypen;              //Hytte, enebolig etc
	Statusonske statusonsket;                // Salg, Leie


public:
	IntrSone();                     // Tom  constructor
	IntrSone(ifstream & inn, int nr); //Constructor som leser fra fil
	IntrSone(int sonenr);             // Constructor. Leser inn data om Intrsone
	IntrSone(IntrSone* intrsonen, int sonenr); // Kopierer data
	~IntrSone();                          // Destructor
	void endreSonenr(int nyttnr);         // Endrer sonens nummer
	void endreIntrSone();                  // Endrer data om Intrsone
	void display();                        // Displater info om IntrSone
	void skrivTilFil(ofstream & ut, int nr); // Skriver data til fil
	int hentsonenum();                       // Henter sonenummeret
	void statusonskeFunk();                  // Leser inn enum verdi
	char hentBoligfeeden();                  // Leser inn enum verdi
	void hentInt(int* i, const char s);      // Henter en int og sammenlikner
	void boligfeedFunk();                    // Leser inn enum verdi
	void eiendomstypeFunk();                 // Leser inn enum verdi                
	void enumBoligfeedSwitch(int nr);        // Setter enum til riktig verdi
	void enumEiendomstypeSwitch(int nr);     // Setter enum til riktig verdi
	void enumStatusSwitch(int nr);           // Setter enum til riktig verdi
	const char* hentEnum(const char* s);     // Return enumverdi som peker
};

#endif
