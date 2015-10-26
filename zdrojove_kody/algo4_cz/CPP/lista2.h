#include <string.h>
const int n=5;
const int kriteria_trideni=2; // poèet kritérií tøídìní

typedef struct rob
{
   char prijmeni[100];
   long  vydelek;
   struct rob *dalsi;   // ukazatel na
}PRVEK;                  // následující prvek

typedef struct rob_ptr     // pracovní struktura seznamu
{              // ukazatelù
   PRVEK *adresa;
   struct rob_ptr *dalsi;
}LPTR;

// ----"rozhodovací" funkce--------------------------------
int abecedne(PRVEK *q1,PRVEK *q2)
{ // jsou záznamy q1 a q2 uspoøádány abecednì?
   return (strcmp(q1->prijmeni,q2->prijmeni)>=0);
}
int podle_vydelku(PRVEK *q1,PRVEK *q2)
{ // jsou záznamy q1 a q2 uspoøádány podle výdìlkù?
   return (q1->vydelek>=q2->vydelek);
}
int ident_prijmeni (PRVEK *q1,PRVEK *q2)
{ // mají záznamy q1 a q2 identická pøíjmení?
   return (strcmp(q1->prijmeni,q2->prijmeni)==0);
}
int ident_vydelky (PRVEK *q1,PRVEK *q2)
{ // mají záznamy q1 a q2 identické výdìlky?
   return(q1->vydelek==q2->vydelek);
}
// -------------------------------------------------------
class SEZNAM
{
public:
  SEZNAM();              // konstruktor
 ~SEZNAM();              // destruktor
  void vloz(PRVEK *);  // pøipojí nový prvek q
  void vypis(char);       // vypíše obsah seznamu
  int  odstran(PRVEK*,int(*rozhodnuti)(PRVEK *,PRVEK*));
  // odstraní prvek, který se shoduje se vzorovou buòkou uvedenou jako parametr
private:
   // soukromé struktury:
   typedef struct               // informaèní struktura seznamu dat
   {
   PRVEK *hlava;
   PRVEK *ocas;
   }
   INFO;
   typedef struct   // informaèní struktura seznamu ukazatelù
   {
    LPTR *hlava;
    LPTR *ocas;
   }LPTR_INFO;

  LPTR_INFO inf_ptr[kriteria_trideni]; // kriteria_trideni = poèet kritérií tøídìní dat danych
  INFO info_data;
// "vnitøní" metody, veøejnì nedostupné:
LPTR_INFO *vyhledej_ukz(LPTR_INFO*,PRVEK*, int(*)(PRVEK*,PRVEK*));
PRVEK *odstran_ukz(LPTR_INFO*, PRVEK*, int(*)(PRVEK*,PRVEK*));
int odstran_data(PRVEK*);
void vloz2(int, PRVEK*, int(*rozhodnuti)(PRVEK*,PRVEK*));
void vypis1(LPTR_INFO*);
};
