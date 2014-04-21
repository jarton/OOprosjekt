#include <iostream>                              // cin, cout
#include "class Kunde.h"
#include "class Kunder.h"
#include <cstdlib>                              // itoa
#include <cstring>                              // strcpy
#include <fstream>                              // ifstream ofstream
#include "conster.h" 
#include "globale funksjoner og variabler.h"
#include "class IntrSone.h" 
#include "class Soner.h" 

using namespace std;

//g�r igjennom alle interessesonene til kunden og finner match for en eiendom
void Kunde::sjekkEnEien(Eiendom* eien) {
	IntrSone* intrsone;														//peker p� aktuell intrsone
	int antall;																		//antall i lista
	int* oppdragsnr = new int;										//intpeker som peker p� oppnr

	eien->hentInt(oppdragsnr, 'o');								//henter oppdragsnr til eiendom
  antall=IntrSoneliste->no_of_elements(); 								//finner ant i liste
  for (int i = 1; i <= antall; i++) {						 //l�kke som g�t igjennom antall
    intrsone = (IntrSone*) IntrSoneliste->remove_no(i);				//tar ut et objekt
    if (*intrsone == eien)   								//sammenligner eiendom og intrsone
			skrivExx(*oppdragsnr);							//skriver kunden til fila hvis match
		IntrSoneliste-> add(intrsone); 										//legger tilbake i lista
	}
}

//finner eiendommer som matcher kundens intrsoner 
void Kunde::finnMatch(const char boligfeed) {
  IntrSone* intrsone;	     										//peker son peker p� intessesoner
  int antall;		   													//antall interessoner som kunden har
  int sonenum;																//sonenummer kunden er interest i

  antall = IntrSoneliste->no_of_elements(); 								//finner ant i liste
  for (int i = 1; i <= antall; i++) {						 //l�kke som g�t igjennom antall
    intrsone = (IntrSone*) IntrSoneliste->remove_no(i);				//tar ut et objekt
    sonenum = intrsone->hentsonenum();													//henter sonnr
    if (intrsone->hentBoligfeeden() == boligfeed)  {  //sjekker om kunden vil ha info 
			skrivINF();
			soner.sammenlign(intrsone, kundenummer); 			//snarest, sammenligner inrsonen  
		}
		IntrSoneliste-> add(intrsone); 										//med alle eiendommer
	}
}						

//skriver ern kunde til exx.DTA
void Kunde::skrivExx(int oppdnrMatch) {
	char* filnavn = new char[strlen("Exxxxxxx.DTA")+1];  //array for filnavn
	LagNavn(filnavn, "E", ".DTA", oppdnrMatch, 7);				//lager navn
	ofstream ut(filnavn, ios::app);									//�pner filer og apphender

	ut << navn << '\n'													//skriver kundens navn og epost
		<< mail << "\n\n";												//bakerst p� filen
}

// Displayer kundeinfo og interesse sone info
void Kunde::sjekkNrNvn(char* kundeinfo)  {
  IntrSone* intrSone;                                    // Interessesone peker
	int knr;                                          // variabel til kundenummer
	knr = atoi(kundeinfo);                //henter kundenummer(inr) fra kundeinfo
	int antintsonr = IntrSoneliste->no_of_elements();  // finner antall intrsoner
	if (knr==kundenummer || strcmp(kundeinfo,navn)==0)  {   //kundenummer erlikt 
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


// Kunde constructor som legger til ny kunde
Kunde :: Kunde(int knr) : Num_element(knr) {  
	char ch[STRLEN];
	char kommando;
	IntrSone* intrsonen;                         // Peker til intrsone-objekt
	IntrSone* intrsonekopi;                      // Peker til kopiobjekt.

	kundenummer = knr;           
	cout << "\n\nTILDELT KUNDENUMMER: " << knr;

	tlf = lesTall("\nTelefon ", 10000000, 99999999);      //Leser tlf-nummer

	lesTxt("\nNavn", ch, STRLEN);                         //leser inn navn
	navn = new char[strlen(ch)+1];             // lager ny char med eksakt lengde
	strcpy(navn, ch);

	lesTxt("\nGateadresse", ch, STRLEN);             //leser gateadresse
	gateadresse = new char[strlen(ch)+1];      // lager ny char med eksakt lengde
	strcpy(gateadresse, ch);

	lesTxt("\nPostnummer", ch, STRLEN);              //leser postnummer
	postadresse = new char[strlen(ch)+1];      // lager ny char med eksakt lengde
	strcpy(postadresse, ch);

	lesTxt("\nE-post", ch, STRLEN);              // leser mail
	mail = new char[strlen(ch)+1];           // lager ny char med eksakt lengde
	strcpy(mail, ch);

	IntrSoneliste = new List(Sorted);            //lager IntrSone-liste.
	int sonenr = lesTall("\nSonenummer", 1, 100);  // leser inn tall 1-100
	
	intrsonen = new IntrSone(sonenr);                 //Nytt IntrSone objekt..
	IntrSoneliste->add(intrsonen);                     //Legger det til i listen.
	
	cout << "\nLegge til en ny sone? (J/N)";
	kommando = les();                                // Leser inn et upcaset tegn

	while (kommando == 'J') {                      //Hvis "ja".
		intrsonekopi = new IntrSone(*intrsonen);       //Default copy constructor
		sonenr = lesTall("\nSonenummer", 1, 100);        //Leser sonenummer.
		intrsonekopi->endreSonenr(sonenr);        //Endrer sonenummeret p� kopien.
		IntrSoneliste->add(intrsonekopi);              //Legger til kopien i listen.
		cout << "\n\nLegge til en ny sone? (J/N)";
		kommando = les();                             // Leser inn et upercaset teg
	}
	finnMatch('S');			//finner eiendommer nye kunden kan v�re intr i
}

// Funksjon som returnerer true\false om kundenummer er rett
bool Kunde::sjekkNr(int Knr)  {
	if (Knr == kundenummer)
		return true;
	else
		return false;
}

// Constructor som leser fra fil
Kunde::Kunde(ifstream & inn, int nr) : Num_element(nr)  {
	char buffer[STRLEN];                 // Buffer til innlesing
	int ant;                         // antall interessesoner
	IntrSone* intrsone;                //Interessesonepeker

	inn >> kundenummer;                 // Leser inn kundenummer
	inn.ignore();                        // ignorere 1 linje
	if (kundenummer == nr)  {             // hvis kundenummeret stemmer
	inn.getline(buffer,STRLEN);           // leser inn navn til buffer
	navn = new char[strlen(buffer + 1)];   // lager char til navn
	strcpy(navn,buffer);
	inn >> tlf;                              // leser inn tlf nr
	inn.ignore();                            // ignorere 1

	inn.getline(buffer,STRLEN);         // Leser onn gateadresse
	gateadresse = new char[strlen(buffer + 1)];
	strcpy(gateadresse,buffer);

	inn.getline(buffer,STRLEN);        // leser inn postadresse
	postadresse = new char[strlen(buffer + 1)];
	strcpy(postadresse,buffer);

	inn.getline(buffer,STRLEN);        // leser inn mail
	mail = new char[strlen(buffer + 1)];
	strcpy(mail,buffer);

	inn >> ant;                            // leser inn antall interessesoner
	inn.ignore();                          // ignorere 1 blank
	if (ant > 0)                           // hvis antall inrsoner > 0
		IntrSoneliste = new List(Sorted);    // Lager ny liste 
	for (int i = 1; i <= ant; i++)  {      // Loop gjennom antallet
  	intrsone = new IntrSone(inn,nr);     // opprett ny intrsone
	  IntrSoneliste->add(intrsone);        // legger intrsone til i listen
	 }
	}
	else
		cout << "FEIL! Kundenummer fra fil '"<<kundenummer<<
						"' stemmer ikke overens med" <<
		"kundenummeret i datastrukturen: '"<<nr<<"'\n";
}                                         // Feilmelding

// Destructor
Kunde :: ~Kunde(){
	delete [] navn; delete [] gateadresse;       //Slette chararrayer
	delete [] postadresse; delete [] mail;
	delete IntrSoneliste;              //Slette listen av IntrSone-objekter.
}


// Skriver Kundedata til fil
void Kunde::skrivTilFil(ofstream & ut)  {
	int antIntrSoner = IntrSoneliste->no_of_elements(); // antall intrsoner
	ut << kundenummer << endl;                          // Skriver ut data
	ut << navn << endl;
	ut << tlf << endl;
	ut << gateadresse << endl;
	ut << postadresse << endl;
	ut << mail << endl;
	ut << antIntrSoner << endl;
	ut << endl;
	IntrSone* intrsone;                              // lager intrsone peker
	for (int i = 1; i <= antIntrSoner; i++)  {       //loop gjennom alle intrsoner
	  intrsone = (IntrSone*) IntrSoneliste->remove_no(i);  // fjerner fra listen
		intrsone->skrivTilFil(ut,antIntrSoner);              // skriver til fil
		IntrSoneliste->add(intrsone);                     // legger tilbake i listen
	}
}


//Returnerer kundenummeret
int Kunde::hentKundenummer()  {
	return kundenummer;
}

void Kunde::endreKundeData()  {
	char ch[STRLEN];
	char svar;
	char endre;

	cout << "\n Endring av kunde " << kundenummer << endl<<endl;

	cout << "\n 0nsker du aa endre personelldata? (J/N)";
	endre=les();
	if (endre == 'J')  {
  	cout << "\n Navn: " << navn;
  	cout << "\n Endre navn? (Tast 'J/N')";
  	svar=les();
  	if (svar == 'J')  {
	    delete [] navn;
	  	lesTxt("\nNavn", ch, STRLEN);                         //leser inn navn
	    navn = new char[strlen(ch)+1];          // lager ny char med eksakt lengde
	    strcpy(navn, ch);
    } 

    cout << "\n Telefon: " << tlf;
    cout << "\n Endre telefonnummer? (Tast 'J/N')";
	  svar=les();
	  if (svar == 'J')  
			tlf = lesTall("\nTelefon ", 10000000, 99999999);      //Leser tlf-nummer  

    cout << "\n E-post: " << mail;
  	cout << "\n Endre E-post? (Tast 'J/N')";
  	svar=les();
  	if (svar == 'J')  {
	    delete [] mail;
      lesTxt("\nE-post", ch, STRLEN);              // leser mail
	    mail = new char[strlen(ch)+1];          // lager ny char med eksakt lengde
	    strcpy(mail, ch);
	  }	

	  cout << "\n Adresse: " << gateadresse<<", "<<postadresse;
	  cout << "\n Endre Adresse? (Tast 'J/N')";
	  svar=les();
	  if (svar == 'J')  {
	   	delete [] gateadresse;
		  delete [] postadresse;
   	  lesTxt("\nGateadresse", ch, STRLEN);             //leser gateadresse
	    gateadresse = new char[strlen(ch)+1];   // lager ny char med eksakt lengde
	    strcpy(gateadresse, ch);

  	  lesTxt("\nPostnummer", ch, STRLEN);              //leser postnummer
	    postadresse = new char[strlen(ch)+1];   // lager ny char med eksakt lengde
	    strcpy(postadresse, ch);
	  }
	}
	cout << "0nsker du aa endre data om kundens interesser? (J/N)";
	svar=les();
	if (svar=='J')  {
		int antIntrSoner = IntrSoneliste->no_of_elements(); // antall intrsoner
  	IntrSone* intrsone;                              // lager intrsone peker
	  for (int i = 1; i <= antIntrSoner; i++)  {    // loop gjennom alle intrsoner
	    intrsone = (IntrSone*) IntrSoneliste->remove_no(i);  // fjerner fra listen
	  	intrsone->endreIntrSone();              // skriver til fil
		  IntrSoneliste->add(intrsone);                   // legger tilbake i listen
	  }
  }
}

// Skriver persondata til INF-filen
void Kunde::skrivINF() {
	char * kundeINF  = new char [strlen("KUNDE0001001.INF")+1];
	LagNavn(kundeINF, "KUNDE", ".INF", kundenummer, 7);
  ofstream ut(kundeINF);
	ut << kundenummer << endl;
	ut << navn << endl;
	ut << postadresse <<", "<< gateadresse << endl;
	ut << tlf << endl;
	ut << mail << endl << endl;
}