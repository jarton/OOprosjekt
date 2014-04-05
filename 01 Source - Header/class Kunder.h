#if !defined(__class_Kunder_H)
#define __class_Kunder_H

#include "listtool2.h"
#include "enumer.h"
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
	void slettKunde(int knr);
};


#endif