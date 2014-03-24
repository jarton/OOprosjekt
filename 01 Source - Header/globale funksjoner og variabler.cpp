#include <iostream>
using namespace std;

//  Leser inn en tekst med lengde ulik 0:
void lesTxt(char t[], char s[], const int LEN) {    
  do  {
    cout << '\t' << t << ": ";                            //  Skriver ledetekst
    cin.getline(s, LEN);                                    //  Leser inn tekst
  } while (strlen(s) == 0);               //  Sjekker at tekstlengden er ulik 0
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
