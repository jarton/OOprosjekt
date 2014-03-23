#if !defined(__TIMER3_H) //  Sikrer at filen kun inkluderes en gang:
#define __TIMER3_H

#include <ctime>        //  Struct'en "tm".


class Timer  {
  private:
    int    dagerPrMaaned[12];  //  Antall dager i hver av årets 12 måneder.
    tm*    tidspunkt;          //  Peker til 'tm'-struct.
    time_t tid;                //  Avlest tid lagres i denne. (tidligere: 'long')
    bool   skuddaar(int aa);   //  3x private/skjulte hjelpefunksjoner:
    int    dagnummer(int da, int ma, int aa);

  public:
    Timer();
    int  hentDato();
    int  forskjellDatoer(int t1, int t2);
    void konverter(int t, int& da, int& ma, int& aa);
};

#endif