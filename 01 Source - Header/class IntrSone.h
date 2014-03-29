#if !defined(__class_IntrSone_H)
#define __class_IntrSone_H

#include "enumer.h"

class IntrSone  {
private:
	int sonenummer, maxPris, minAreal, minAntSoverom;
	Boligfeed boligfeeden;

public:
	IntrSone(int postnr);
};

#endif