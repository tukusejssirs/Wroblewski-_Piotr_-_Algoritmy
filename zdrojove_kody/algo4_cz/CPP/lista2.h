#include <string.h>
const int n=5;
const int kriteria_trideni=2; // po�et krit�ri� t��d�n�

typedef struct rob
{
   char prijmeni[100];
   long  vydelek;
   struct rob *dalsi;   // ukazatel na
}PRVEK;                  // n�sleduj�c� prvek

typedef struct rob_ptr     // pracovn� struktura seznamu
{              // ukazatel�
   PRVEK *adresa;
   struct rob_ptr *dalsi;
}LPTR;

// ----"rozhodovac�" funkce--------------------------------
int abecedne(PRVEK *q1,PRVEK *q2)
{ // jsou z�znamy q1 a q2 uspo��d�ny abecedn�?
   return (strcmp(q1->prijmeni,q2->prijmeni)>=0);
}
int podle_vydelku(PRVEK *q1,PRVEK *q2)
{ // jsou z�znamy q1 a q2 uspo��d�ny podle v�d�lk�?
   return (q1->vydelek>=q2->vydelek);
}
int ident_prijmeni (PRVEK *q1,PRVEK *q2)
{ // maj� z�znamy q1 a q2 identick� p��jmen�?
   return (strcmp(q1->prijmeni,q2->prijmeni)==0);
}
int ident_vydelky (PRVEK *q1,PRVEK *q2)
{ // maj� z�znamy q1 a q2 identick� v�d�lky?
   return(q1->vydelek==q2->vydelek);
}
// -------------------------------------------------------
class SEZNAM
{
public:
  SEZNAM();              // konstruktor
 ~SEZNAM();              // destruktor
  void vloz(PRVEK *);  // p�ipoj� nov� prvek q
  void vypis(char);       // vyp�e obsah seznamu
  int  odstran(PRVEK*,int(*rozhodnuti)(PRVEK *,PRVEK*));
  // odstran� prvek, kter� se shoduje se vzorovou bu�kou uvedenou jako parametr
private:
   // soukrom� struktury:
   typedef struct               // informa�n� struktura seznamu dat
   {
   PRVEK *hlava;
   PRVEK *ocas;
   }
   INFO;
   typedef struct   // informa�n� struktura seznamu ukazatel�
   {
    LPTR *hlava;
    LPTR *ocas;
   }LPTR_INFO;

  LPTR_INFO inf_ptr[kriteria_trideni]; // kriteria_trideni = po�et krit�ri� t��d�n� dat danych
  INFO info_data;
// "vnit�n�" metody, ve�ejn� nedostupn�:
LPTR_INFO *vyhledej_ukz(LPTR_INFO*,PRVEK*, int(*)(PRVEK*,PRVEK*));
PRVEK *odstran_ukz(LPTR_INFO*, PRVEK*, int(*)(PRVEK*,PRVEK*));
int odstran_data(PRVEK*);
void vloz2(int, PRVEK*, int(*rozhodnuti)(PRVEK*,PRVEK*));
void vypis1(LPTR_INFO*);
};
