#include <iostream>                               // cin,cout
#include <cstdlib>																// itoa
#include "conster.h"                              // bruke conster
#include "class Soner.h"                          // bruker Soner
#include "class Kunder.h"
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <fstream>
#include <cctype>   
#include "class Eiendom.h"

// to upper
using namespace std;

//overloda operator som finner om en eiendom matcher en kunde
bool operator ==(IntrSone& kun, Eiendom* salg) {
  int * kunInt = new int;	//peker på kunden sone verdier 
  int * salgInt = new int;	//peker på eindommen sine verdier 
  int antMatch = 0;		//antall kriterier som matcher 
  int matchSomKreves = 3;	//ant kriterier som kreves for match

if ((kun.hentEnum("Eiendomstype") ==  //sjekker om typene erlike
  salg->hentEnum("Eiendomstype")))    //dvs feks. tomt == tomt
    antMatch++;
  kun.hentInt(kunInt, 'p');    //henter kundens MAXpris
  salg->hentInt(salgInt, 'p');  //henter eiendommens pris
  if (*kunInt >= *salgInt) 	//sjekker om MAXprisen er større en eienprisen 
	antMatch++;		//hvis den koster mindre, en+ match
  kun.hentInt(kunInt, 'a');	//henter kundens MINareal 
  salg->hentInt(salgInt, 'a');  //henter eiendommens areal
  if (*kunInt <= *salgInt)     //sjekker om eienAreal er større en kundens min
	  antMatch++;		//hvis den er så enda en match +	
  if (salg->type() == 0) {      //hvis det er en bolig som sammenlignes
    matchSomKreves += 2;	//to ekstra kriterier skal stemme
    kun.hentInt(kunInt, 's');   //henter MINsoverom kunden vil ha
    salg->hentInt(salgInt, 's');   //henter antsoverom ibolig
    if (kunInt <= salgInt)	   //ser om det er så mange eller fler
	   antMatch++;           //en det kunden vil ha, hvis ja match++
    if ((kun.hentEnum("Statusonske")) ==    //sjekkerom enumene er like
	(salg->hentEnum("Statusonske")) ||     //eller om kunden er interesert i
	strcmp(kun.hentEnum("Statusonske"), "begge"))    //bege typer
	    antMatch++;					//hvis ja, match++
  } 
  if (antMatch == matchSomKreves)		//sjekker om alle kriterier er
	  return true;  			//møtt, hvis ja return true
  else return false;				//hvis ikke false
}

//  Leser inn en tekst med lengde ulik 0:
void lesTxt(char t[], char s[], const int LEN) {    
  do  {
    cout << '\t' << t << ": ";                            //  Skriver ledetekst
    cin.getline(s, LEN);                                    //  Leser inn tekst
  } while (strlen(s) == 0);               //  Sjekker at tekstlengden er ulik 0
}


// Oppretter filnavn ti len char peker
void LagNavn(char* t, char* s1, char * s2, int n, int LEN) {   //Lager filer
	int i = 0;                                                  //int for løkke
	char* nummer = new char[LEN+1];								//array for nummeret på filen 
	sprintf(nummer, "%d",  n);                         //Gjør nummeret om til tekst
	int potens = pow(10.0, (LEN-1));                     //Tall for regning av desimaler
	while ((potens > n) && potens != 1) {       //Løkke som finner antall nuller
		potens /= 10;                             //Deler på 10 til antall er funnet
		i++;	
}
char* nuller = new char[i];									 //array som inneholder alle nuller 
	int j = 0;																      //int for while løkka
	while (j < i) { 													  //løkke som skriver antall nuller
		nuller[j] = '0';
		j++;
	}
	nuller[j] = '\0';												       		 //legger til \0 på slutten
strcpy(t, s1);														    //legger første del av navnet inn
strcat(t, nuller);													     //legger sp på nullene
strcat(t, nummer);																        //så nummer
strcat(t, s2);																	      //og tilslutt filendingen
}


//  Leser og returnerer ETT upcaset tegn.
char les()  {                    
  char ch; 
  cout << "\n\nKommando:  ";
  cin >> ch;                                     // Leser in et tegn
  return (toupper(ch));                      // gjør tegnet om til stor bokstav
}


//  Skriver ledetekst (t), leser og returnerer et tall mellom min og max:
int lesTall(const char* t, int min, int max)  {
  int tall;
  do  {
    cout << '\t' << t << " (" << min << '-' << max <<  "):  ";
    cin >> tall;  cin.ignore();              // Leser inn et tall
  } while (tall < min  ||  tall > max);    // Loop til tallet er mellom min\max
  return tall;
}


// Skriver ut menyen
void skrivMeny()  {
	cout << "\n\nTilgjengelige funksjoner: "
		<< "\n\tE D - Eiendom Display <oppdr. nr / postnr>"
		<< "\n\tE N - Eiendom Ny <sonenr>"
		<< "\n\tE S - Eiendom Slett <oppdr. nr>"
		<< "\n\tE E - Eiendom Endre <oppdr. nr>"
		<< "\n\tS D - Sone Display <sonenr>"
		<< "\n\tK D - Kunde Display <kundenr / kundenavn>"
		<< "\n\tK N - Kunde Ny"
		<< "\n\tK S - Kunde Slett <kundenr>"
		<< "\n\tK E - Kunde Endre <kundenr>"
		<< "\n\tU - Ukentlig utskrift / status / sending";
}


// Ber om nummeret til en sone og displayer
void soneDisplay()  {
	Soner soner;
	int sonenr;
	sonenr=lesTall("Skriv inn sonenummer: ",1,MAXSONER);
	soner.displaySone(sonenr);
}

void ukentligUtskrift()  {

}
