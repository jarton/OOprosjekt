#if !defined(__class_Kunder_H)
#define __class_Kunder_H

#include "listtool2.h"
#include "enumer.h"
#include "class Eiendom.h"
using namespace std;

class Kunder  {
private:
	int forsteKunde, sisteKunde;
	List* kundeliste;

public:
	Kunder();
	void fortsettelseMeny();
	void finnKunde(char* kundeinfo);
	void displayKunde(int kundenr);
	void nyKunde();
	void endreKunde(int knr);
	void slettKunde(int knr);
	void skrivTilFil();
	void sammenlign(Eiendom* eien);
};


#endif
