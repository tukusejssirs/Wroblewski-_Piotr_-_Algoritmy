#include <string.h>
const int n=5;
const int kryteria_sort=2; // liczba kryteriów sortowania

typedef struct rob
{
	char nazwisko[100];
	long  zarobek;
	struct rob *nastepny; 	// wskaźnik do
}ELEMENT;            		// następnego elementu

typedef struct rob_ptr  	// struktura robocza listy
{	        		// wskazników
	ELEMENT *adres;
	struct rob_ptr *nastepny;
}LPTR;

// ----funkcje "decyzyjne"--------------------------------
int alfabetycznie(ELEMENT *q1,ELEMENT *q2)
{ // czy rekordy q1 i q2 sś uporządkowane alfabetycznie?
	return (strcmp(q1->nazwisko,q2->nazwisko)>=0);
}
int wg_zarobkow(ELEMENT *q1,ELEMENT *q2)
{ // czy rekordy q1 i q2 są uporządkowane wg zarobków?
	return (q1->zarobek>=q2->zarobek);
}
int ident_nazwiska (ELEMENT *q1,ELEMENT *q2)
{ // czy rekordy q1 i q2 mają identyczne nazwiska?
	return (strcmp(q1->nazwisko,q2->nazwisko)==0);
}
int ident_zarobki (ELEMENT *q1,ELEMENT *q2)
{ // czy rekordy q1 i q2 maą identyczne zarobki?
	return(q1->zarobek==q2->zarobek);
}
// -------------------------------------------------------
class LISTA
{
public:
  LISTA(); 					// konstruktor
 ~LISTA(); 					// destruktor
  void dorzuc(ELEMENT *);	// dołącz nowy element q
  void wypisz(char);     	// wypisz zawartość listy
  int  usun(ELEMENT*,int(*decyzja)(ELEMENT *,ELEMENT*));
  // usuń element, który jest zgodny z wzorcową komorką podaną jako parametr
private:
	// prywatne struktury:
	typedef struct               // struktura informacyjna listy danych
	{
	ELEMENT *glowa;
	ELEMENT *ogon;
	}
	INFO;
	typedef struct   // struktura informacyjna listy wskazników
	{
	 LPTR *glowa;
	 LPTR *ogon;
	}LPTR_INFO;

  LPTR_INFO inf_ptr[kryteria_sort]; // kryteria_sort = ilość kryteriow sortowania danych
  INFO info_dane;
// metody "wewnętrzne", nieudostępnione publicznie:
LPTR_INFO *odszukaj_wsk(LPTR_INFO*,ELEMENT*, int(*)(ELEMENT*,ELEMENT*));
ELEMENT *usun_wsk(LPTR_INFO*, ELEMENT*, int(*)(ELEMENT*,ELEMENT*));
int usun_dane(ELEMENT*);
void dorzuc2(int, ELEMENT*, int(*decyzja)(ELEMENT*,ELEMENT*));
void wypisz1(LPTR_INFO*);
};
