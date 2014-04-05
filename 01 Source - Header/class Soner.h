#if !defined(__class_Soner_H)
#define __class_Soner_H

#include "conster.h"
#include "class Sone.h"

class Soner  {
private:
	int sisteOppdrag;
	Sone* sonene[MAXSONER+1];

public:
	Soner();								//constructor
	void eiendomNy(int nr);						//legger til ny eiendom
	void eiendomSlett(int nr);
	void skrivTilFil();							//skriver til fil
	void fortsettelseMeny(char valg);		// Viser meny
	void displaySone(int sonenr);          // Finner en sone
	void displayEiendom(char* soneinfo);
};


#endif
