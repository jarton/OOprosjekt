#if !defined(__class_Eiendom_H)
#define __class_Eiendom_H

#include "listtool2.h"
#include "enumer.h"
#include <fstream>     // ifstream, ofstream

using namespace std;

class Eiendom : public Num_element  {
private:
	int oppdragsnummer, dato, bruksnummer, ansattnummer;
	char* gateadresse;              // Data om en eiendom
	char* postadresse;
	char* eiernavn;
	char* kommunenavn;
	char* beskrivelse;
	Eiendomstype eiendomstypen;     // Enum (Hytte,Rekkehus etc)

protected:
	int pris, areal;

public:
	Eiendom(int onr);                     // Constructor. Leser inn data om bolig
	Eiendom(ifstream & inn, int onr);     // Constructor. Leser data fra fil
	virtual ~Eiendom();                   // Virtuell destructor
	void skrivTilFil(ofstream & ut);      // Skriver data til fil
	virtual void skrivBoligTilFil(ofstream & ut){} // Skriv til fil (bolig)
	virtual void displayBolig(){}               // Displayer en bolig
	virtual bool type();                        // Sjekker type (bolig\eiendom)
	virtual void hentInt(int* i, const char s); //Return en int til sammenlikning
	virtual const char* hentEnum(const char* s);//Return enum til sammenlikning
	void enumSwitch();                  // Setter verdi på enum
	virtual void display();                // Display informasjon om en eiendom
	bool finnPostnummer(int postnr);       // Sjekker om postnummer er rett
	bool finnOppdragsnr(int oppdnr);       // Sjekker om oppdragsnr er rett
	void endreData();                      // Endrer datra om en eiendom
	void skrivINF(ofstream &ut);           // Skriver data til INF-filen
};

#endif
