#include <iostream>
#include "class Kunde.h"
#include "class Kunder.h"
#include <cstdlib>
#include <fstream>
#include "conster.h"
#include "globale funksjoner og variabler.h"
#include "class IntrSone.h"

using namespace std;


// Displayer kundeinfo og interesse sone info
void Kunde::sjekkNrNvn(char* kundeinfo)  {
  IntrSone* intrSone;                                    // Interessesone peker
	int knr;                                          // variabel til kundenummer
	knr = atoi(kundeinfo);                //henter kundenummer(inr) fra kundeinfo
	int antintsonr = IntrSoneliste->no_of_elements();  // finner antall intrsoner
	if (knr==kundenummer || strcmp(kundeinfo,navn)==0)  {               // hvis innskrevet knr = kundenummeret
    displayKunde();                                      // displayer kundeinfo
		for (int i = 1; i <= antintsonr; i++)  {    // loop gjennom alle intersoner
      intrSone = (IntrSone*) IntrSoneliste->remove_no(i);// fjerner  fra listen
	    intrSone->display();                          // Displayer interessesonen
  	  IntrSoneliste->add(intrSone);                // Legges tilbake til listen
		  }
   }
}
  

// Displyer info om en kunde
void Kunde::displayKunde()  {
	cout << "\n Navn: " << navn;
	cout << "\n Kundenummer: " << kundenummer;
	cout << "\n Telefon: " << tlf;
	cout << "\n E-post: " << mail;
	cout << "\n Adresse: " << gateadresse<<", "<<postadresse;
}	



Kunde :: Kunde(int knr) : Num_element(knr) {
	char ch[STRLEN];
	char kommando;
	int tall;
	IntrSone* intrsonen; // Peker til intrsone-objekt
	IntrSone* intrsonekopi; // Peker til kopiobjekt.

	kundenummer = knr;
	cout << "\n\nTILDELT KUNDENUMMER: " << knr;

	tlf = lesTall("\nTelefon ", 10000000, 99999999); //Leser tlf-nummer

	lesTxt("\nNavn", ch, STRLEN); //leser navn
	navn = new char[strlen(ch)+1];
	strcpy(navn, ch);

	lesTxt("\nGateadresse", ch, STRLEN); //leser gateadresse
	gateadresse = new char[strlen(ch)+1];
	strcpy(gateadresse, ch);

	lesTxt("\nPostnummer", ch, STRLEN); //leser postnummer
	postadresse = new char[strlen(ch)+1];
	strcpy(postadresse, ch);

	lesTxt("\nE-post", ch, STRLEN); // leser mail
	mail = new char[strlen(ch)+1];
	strcpy(mail, ch);

	IntrSoneliste = new List(Sorted); //lager IntrSone-liste.
	int sonenr = lesTall("\nSonenummer", 1, 100);
	
	intrsonen = new IntrSone(sonenr); //Nytt IntrSone objekt..
	IntrSoneliste->add(intrsonen); //Legger det til i listen.
	
	cout << "\nLegge til en ny sone? (J/N)";
	kommando = les();

	while (kommando == 'J') { //Hvis "ja".
		intrsonekopi = new IntrSone(*intrsonen); //Forsøk på default copy constructor..
		sonenr = lesTall("\nSonenummer", 1, 100); //Leser sonenummer.
		intrsonekopi->endreSonenr(sonenr);
		IntrSoneliste->add(intrsonekopi); //Legger til kopien.
		cout << "\n\nLegge til en ny sone? (J/N)";
		kommando = les();
	}
	

}


bool Kunde::sjekkNr(int Knr)  {
	if (Knr == kundenummer)
		return true;
	else
		return false;
}


Kunde::Kunde(ifstream & inn, int nr) : Num_element(nr)  {
	//kundeliste = new List(Sorted);
	char buffer[STRLEN];
	int ant;
	IntrSone* intrsone;

	inn >> kundenummer;
	inn.ignore();
	if (kundenummer == nr)  {
	inn.getline(buffer,STRLEN);
	navn = new char[strlen(buffer + 1)];
	strcpy(navn,buffer);
	inn >> tlf;
	inn.ignore();

	inn.getline(buffer,STRLEN);
	gateadresse = new char[strlen(buffer + 1)];
	strcpy(gateadresse,buffer);

	inn.getline(buffer,STRLEN);
	postadresse = new char[strlen(buffer + 1)];
	strcpy(postadresse,buffer);

	inn.getline(buffer,STRLEN);
	mail = new char[strlen(buffer + 1)];
	strcpy(mail,buffer);

	inn >> ant;
	inn.ignore();
	if (ant > 1)
		IntrSoneliste = new List(Sorted);
	for (int i = 1; i <= ant; i++)  {
  	intrsone = new IntrSone(inn,nr);
	  IntrSoneliste->add(intrsone);
	 }
	}
	else
		cout << "FEIL! Kundenummer fra fil '"<<kundenummer<<"' stemmer ikke overens med"
		"kundenummeret i datastrukturen: '"<<nr<<"'\n";


}

void Kunde::skrivTilFil(ofstream & ut)  {
	int antIntrSoner = IntrSoneliste->no_of_elements();
	ut << kundenummer << endl;
	ut << navn << endl;
	ut << tlf << endl;
	ut << gateadresse << endl;
	ut << postadresse << endl;
	ut << mail << endl;
	ut << antIntrSoner << endl;
	ut << endl;
	IntrSone* intrsone;
	for (int i = 1; i <= antIntrSoner; i++)  {
	  intrsone = (IntrSone*) IntrSoneliste->remove_no(i);
		intrsone->skrivTilFil(ut,antIntrSoner);
		IntrSoneliste->add(intrsone);
	}
}