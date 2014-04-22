#if !defined(__GL_FV_H)
#define __GL_FV_H

#include "class Soner.h"
#include "class Kunder.h"
#include <fstream>
#include "class IntrSone.h"
#include "class Eiendom.h"


extern Soner soner;                   // Eksternt sone-objekt
extern Kunder kunder;                 // Ekstrent kunde-objekt

int  lesTall(const char* t, int min, int max);          // Leser inn et tall 
void  lesTxt(const char t[], char s[], const int LEN);   // Leser inn en tekst
char les();                                               // Leser inn et tegn
void skrivMeny();		                                  //Skriver ut menyen i main
void soneDisplay();                              // Displayer info om en sone
void LagNavn(char* t, char* s1, char * s2, int n, int LEN);  // Lager filnavn
bool operator ==(IntrSone& kun, Eiendom* salg); // Sammenlikner eiendom\Intrsone
void lesFraFil();                                  // Leser fra fil

#endif
