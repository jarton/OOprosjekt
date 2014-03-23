
#include <ctime>              //  tm-struct, time-funksjoner
#include "timer3.h"           //  (Denne filens deklarasjoner)


// **************************************************************************
//
// **    Funksjoner som behjelper med avlesning dato og datohåndtering.    **
//
// **************************************************************************


Timer::Timer()  {             //  Initialiserer med antall dager i hver måned:
 dagerPrMaaned[0]  = 31;
 dagerPrMaaned[1]  =  0;      //  Februar settes ikke opp, da den er avhengig
 dagerPrMaaned[2]  = 31;      //  av om det aktuelle året er skuddår eller ei.
 dagerPrMaaned[3]  = 30;
 dagerPrMaaned[4]  = 31;
 dagerPrMaaned[5]  = 30;
 dagerPrMaaned[6]  = 31;
 dagerPrMaaned[7]  = 31;
 dagerPrMaaned[8]  = 30;
 dagerPrMaaned[9]  = 31;
 dagerPrMaaned[10] = 30;
 dagerPrMaaned[11] = 31;
}

                              //  Avleser dagens dato på datamaskinen.
int Timer::hentDato()  {      //  Returnerer denne på formen ÅÅÅÅMMDD:
  int d, m, a;
  
  tid = time(NULL);            //  Avleser systemklokka
  tidspunkt = localtime(&tid); //     og konverterer:
  d = tidspunkt->tm_mday;      //  Henter aktuelle felter i struct'en:
  m = tidspunkt->tm_mon + 1;
  a = tidspunkt->tm_year + 1900;
  return ((a * 10000) + (m * 100) + d);  //  Regner ut/omgjør og returnerer.
}


                                             //  Returnerer antall dager mellom
int Timer::forskjellDatoer(int t1, int t2)  {  //  to datoer ('t1' og 't2'):
  int d1, d2, m1, m2, a1, a2, tot1, tot2, i; // Masse ulike hjelpevariable:

  konverter(t1, d1, m1, a1);                 //  Konverterer 't1/t2' over i 
  konverter(t2, d2, m2, a2);                 //   'd1/d2', 'm1/m2' og 'a1/a2':
  tot1 = dagnummer(d1, m1, a1);              //  Finner deres dagnummer i 
  tot2 = dagnummer(d2, m2, a2);              //   hvert sitt år ('a1/a2').
  for (i = 1900;  i < a1;  i++)              //  Finner TOTALT antall dager
	  tot1 += (skuddaar(i)) ? 366 : 365;     //   siden år 1900 for hvert av
  for (i = 1900;  i < a2;  i++)              //   de to datoene:
	  tot2 += (skuddaar(i)) ? 366 : 365;     
  return ((tot2 > tot1) ? tot2-tot1 : tot1-tot2);  //  Returnerer forskjellen.
}

                                   //  Konverterer 't' (på formen 'ÅÅÅÅMMDD'),
                                   //    over i de referanseoverførte 
                                   //    parametrene 'da', 'ma' og 'aa':
void Timer::konverter(int t, int& da, int& ma, int& aa)  { 
  aa = t / 10000;
  ma = (t - (aa * 10000)) / 100;
  da = t % 100;
}



// *********************  PRIVATE FUNKSJONER: **********************

                                   //  IDENTISK TIL OPPG_20 (høsten):
bool Timer::skuddaar(int aa)  {    //  Sjekker om et visst år er skuddår:
  if ((aa % 400 == 0)  || ((aa % 4 == 0) && (aa % 100) !=0))
     return true;                  //  Skuddår dersom: (delelig med 400)
  else                             //    ELLER (delelig med 4 OG ikke med 100)
     return false;
}
                      //  IDENTISK TIL OPPG_20 (høsten):
                      //  Ut fra datoens input, så returneres (om mulig)
                      //    denne datoens dagnummer i året, ellers returneres 0.
int Timer::dagnummer(int da, int ma, int aa)  {
                                   //  Setter opp antall dager i månedene.
                                   //   Verdien for februar settes senere.
  int totalDagnr, i;

  if (aa < 1600  ||  aa > 2100) return 0;    //  Ulovlig år.
  if (ma < 1     ||  ma > 12)   return 0;    //  Ulovlig måned.
                                   //  Ut fra om året er skuddår eller ei,
                                   //    så settes verdien for februar:
  dagerPrMaaned[1] = (skuddaar(aa))  ?  29 : 28;
  if (da < 1 ||  da > dagerPrMaaned[ma-1])  return 0;  // Ulovlig dag:
                                   //  Garantert at er en lovlig dato !!
  totalDagnr = da;
  for (i = 0;  i < ma-1;  i++)              // Regner ut datoens dagnummer.
     totalDagnr += dagerPrMaaned[i];

  return totalDagnr;                          // Returnerer dagnummeret.
}
