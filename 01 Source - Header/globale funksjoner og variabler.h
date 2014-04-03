#if !defined(__GL_FV_H)
#define __GL_FV_H

#include "class Soner.h"
#include "class Kunder.h"
#include <fstream>




int  lesTall(char* t, int min, int max);          // Leser inn et tall 
void  lesTxt(char t[], char s[], const int LEN);   // Leser inn en tekst
char les();                                        // Leser inn et tegn

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

void lesFraFil();

#endif