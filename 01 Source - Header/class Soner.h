#if !defined(__class_Soner_H)
#define __class_Soner_H

#include "conster.h"
#include "class Sone.h"
#include "class IntrSone.h"

class Soner  {
private:
	int sisteOppdrag;              // siste oppdrag
	Sone* sonene[MAXSONER+1];      // Array med max 100 siner

public:
	Soner();																	//constructor
	void eiendomNy(int nr);				       		//legger til ny eiendom
	void eiendomSlett(int nr);		         	//sletter en eiendom
	void skrivTilFil();						        	//skriver til fil
	void fortsettelseMeny(char valg);	     	// Viser meny
	void displaySone(int sonenr);            // displayer en hel sone 
	void displayEiendom(char* soneinfo);      //displayer en/flere eiendom
	void sammenlign(IntrSone* isone, int nr, int kundenr); //match:intrsone\sone
	void eiendomEndre(int nr);                 // Endrer data om en eiendom
};

#endif
