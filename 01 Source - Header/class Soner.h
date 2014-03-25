#if !defined(__class_Soner_H)
#define __class_Soner_H

#include "conster.h"
#include "class Sone.h"

class Soner  {
private:
	int sisteOppdrag;
	Sone* sonene[MAXSONER+1];

public:
	Soner();
	void fortsettelseMeny();   // Viser meny
	void displaySone(int sonenr);          // Finner en sone
};


#endif