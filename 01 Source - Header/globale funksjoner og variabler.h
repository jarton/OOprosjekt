#if !defined(__GL_FV_H)
#define __GL_FV_H

#include "class Soner.h"
#include "class Kunder.h"
#include <fstream>
#include "class IntrSone.h"
#include "class Eiendom.h"

//Variabler
extern Soner soner;
extern Kunder kunder;
//Funksjoner
int  lesTall(const char* t, int min, int max);          // Leser inn et tall 
void  lesTxt(const char t[], char s[], const int LEN);   // Leser inn en tekst
char les();                                        // Leser inn et tegn
void ukentligUtskrift();

void skrivMeny();		         //Skriver ut menyen til display
void eiendomDisplay();
void eiendomSlett();
void eiendomEndre();
void soneDisplay();
void kundeDisplay();
void kundeNy();
void kundeSlett();
void kundeEndre();
void utskrift();
void LagNavn(char* t, char* s1, char * s2, int n, int LEN);
bool operator ==(IntrSone& kun, Eiendom* salg);
void lesFraFil();

#endif
