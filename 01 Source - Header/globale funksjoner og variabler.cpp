#include <iostream>
#include <cstdlib>																// itoa
#include "conster.h"
#include "class Soner.h"
#include "class Kunder.h"
#include <cstring>
using namespace std;


// Variabler



// Funksjoner

//  Leser inn en tekst med lengde ulik 0:
void lesTxt(char t[], char s[], const int LEN) {    
  do  {
    cout << '\t' << t << ": ";                            //  Skriver ledetekst
    cin.getline(s, LEN);                                    //  Leser inn tekst
  } while (strlen(s) == 0);               //  Sjekker at tekstlengden er ulik 0
}

void LagNavn(char* t, char* s1, char * s2, int n, int LEN) {   //Lager filer
	int tall = strlen(s1) + strlen (s2) + LEN;	            //Antall tegn i navn
	int i = 0;                                                  //int for løkke
	t = new char[tall+1];                       //Lager en array for filnavn
	char tall[] = itoa(n);                         //Gjør nummeret om til tekst
	int potens = 10 ^ (LEN-1);                     //Tall for regning av desimaler
	while ((potens > LEN) || potens == 1) {       //Løkke som finner antall nuller
		potens /= 10;                             //Deler på 10 til antall er funnet
		i++;	
	}
char nuller[i];
for (int j = 0; j < i; j++) {
 	nuller[j]='0';	
	}
strcat(s1, nuller);
strcat(s1, s2)
t = s1;
}

//  Leser og returnerer ETT upcaset tegn.
char les()  {                    
  char ch;
  cout << "\n\nKommando:  ";
  cin >> ch;
  return (toupper(ch));
}


//  Skriver ledetekst (t), leser og returnerer et tall mellom min og max:
int lesTall(char* t, int min, int max)  {
  int tall;
  do  {
    cout << '\t' << t << " (" << min << '-' << max <<  "):  ";
    cin >> tall;  cin.ignore();
  } while (tall < min  ||  tall > max);
  return tall;
}

void skrivMeny(){
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
	soner.finnSone(sonenr);
}
