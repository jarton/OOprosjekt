#if !defined(__class_Kunder_H)
#define __class_Kunder_H

#include "listtool2.h"
#include "enumer.h"

class Kunder : public Num_element  {
private:
	int forsteKunde, sisteKunde;
	List* kundeliste;

public:
	Kunder();
	void fortsettelseMeny();

};


#endif