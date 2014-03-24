#include <iostream>
#include "conster.h"
#include "class Soner.h"
using namespace std;

void Soner::finnSone(int sonenr)  {
	int i;
	for (i=1; i<=MAXSONER; i++)  {
		if (sonene[i]->hentSonenr() == sonenr)
			sonene[i]->display();
	}
}