#if !defined(__class_Sone_H)
#define __class_Sone_H

#include "listtool2.h"
#include <fstream>
#include <iostream>

using namespace std;

class Sone  {
private:
	char* beskrivelse;				//sonebeskrivelse
	int soneNummer;      	//sonens nr
	List* eiendommene;				//liste med eiendommene


public:
	Sone(int sonenr, int oppdragsnr);			//construcor som opretter 1 eiendom 
	Sone(ifstream & inn, int nr);				//construcor fra fil som leser flere eiendommer
	void nyEiendom(int oppdragsnr);			//opretter en ny eiendom
	void skrivTilFil(ofstream & ut);		//skriver sonen til fil
	bool slettEiendom(int oppdragnr);		//sletter en eiendom	
	void display();               // Displayer all info om en sone
	void displayEien(int nr);			//displayer en /flere eiendommmer
};


#endif
