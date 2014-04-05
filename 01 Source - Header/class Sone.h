#if !defined(__class_Sone_H)
#define __class_Sone_H

#include "listtool2.h"
#include <fstream>
#include <iostream>

using namespace std;

class Sone  {
private:
	char* beskrivelse;
	int soneNummer;      
	List* eiendommene;


public:
	Sone(int sonenr, int oppdragsnr);
	Sone(ifstream & inn, int nr);
	void nyEiendom(int oppdragsnr);
	void skrivTilFil(ofstream & ut);
	bool slettEiendom(int oppdragnr);
	void skrivTypeFil(ofstream & ut);	
	void display();               // Displayer all info om en sone
	int hentSonenr();             // Returnerer sonens nummer
	void displayEien(int nr);
};


#endif
