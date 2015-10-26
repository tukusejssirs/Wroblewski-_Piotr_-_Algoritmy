#include <iostream>
#include <iomanip> // z powodu funkcji setw
using namespace std;
#include "lista2.h"
// -------------------------------------------------------
LISTA::LISTA() //konstruktor zeruje komórki informacyjne
{
inf_ptr[0].glowa=inf_ptr[0].ogon=NULL;
inf_ptr[1].glowa=inf_ptr[1].ogon=NULL;
info_dane.glowa=info_dane.ogon=NULL;
}
// -------------------------------------------------------
LISTA::~LISTA() //destruktor zwalnia pamiêæ zajêt¹ przez obiekt
{
while (info_dane.glowa!=NULL) // niszczymy listê danych:
{
	ELEMENT *q=(info_dane.glowa)->nastepny; // zapamiêtaj wskaŸnik...
	delete info_dane.glowa;
	info_dane.glowa=q;                      // ... i odtwórz go
  }
for (int i=0;i<kryteria_sort;i++)        // niszczymy listy wskazników:
	while (inf_ptr[i].glowa!=NULL)
	{
	LPTR *q=(inf_ptr[i].glowa)->nastepny;
	delete inf_ptr[i].glowa;                // j.w.
	inf_ptr[i].glowa=q;
  }
}
// -------------------------------------------------------
LISTA::LPTR_INFO* LISTA::odszukaj_wsk(LISTA::LPTR_INFO *inf,ELEMENT *q,int(*decyzja)(ELEMENT *q1,ELEMENT *q2))
{
LPTR_INFO *res=new LPTR_INFO;
res->glowa=res->ogon=NULL;
if (inf->glowa==NULL) 
	return (res); // lista pusta!
else
 {
  LPTR *przed,*pos;
  przed=NULL;
  pos=inf->glowa;
  enum {SZUKAJ,ZAKONCZ} stan=SZUKAJ;
  while ((stan==SZUKAJ) && (pos!=NULL))
  if (decyzja(pos->adres,q))
	  	stan=ZAKONCZ;	// znaleŸliœmy miejsce, w którym element
  else					// istnieje (albo ma byæ wstawiony)
	{       // przemieszczamy siê w poszukiwaniach
	przed=pos;
	pos=pos->nastepny;
	}
  res->glowa=przed;
  res->ogon=pos;
  return (res);
  }
}
// -------------------------------------------------------
void LISTA::dorzuc(ELEMENT *q)
{                                // rekord do³¹czamy bez sortowania
if (info_dane.glowa==NULL)      // lista pusta
	info_dane.glowa=info_dane.ogon=q;
else                 // coœ jest w liœcie
	{
	(info_dane.ogon)->nastepny=q;
	info_dane.ogon=q;
	}
// do³¹czamy wskaŸnik do rekordu do listy posortowanej alfabetycznie
dorzuc2(0,q,alfabetycznie);
// do³¹czamy wskaŸnik do rekordu do listy posortowanej wg zarobkow
dorzuc2(1,q,wg_zarobkow);
}
// -------------------------------------------------------
void  LISTA::dorzuc2(int nr,ELEMENT *q,int(*decyzja)(ELEMENT *q1,ELEMENT *q2))
{
LPTR *wsk=new LPTR;
wsk->adres=q; // wpisujemy adres rekordu q
// Poszukiwanie w³aœciwej pozycji na wstawienie elementu
if (inf_ptr[nr].glowa==NULL) // pusta
{
 inf_ptr[nr].glowa=inf_ptr[nr].ogon=wsk;
 wsk->nastepny=NULL;
}
	else //szukamy miejsca na wstawienie
	{
	LPTR *przed,*po;
	LPTR_INFO *gdzie=odszukaj_wsk(&inf_ptr[nr],q,decyzja);
	przed=gdzie->glowa;
	po=gdzie->ogon;
	if (przed==NULL)  // wstawiamy na pocz¹tek listy
		{
		inf_ptr[nr].glowa=wsk;
		wsk->nastepny=po;
		} else
			if (po==NULL) // wstawiamy na koniec listy
			{
			inf_ptr[nr].ogon->nastepny=wsk;
			wsk->nastepny=NULL;
			inf_ptr[nr].ogon=wsk;
			}else    // wstawiamy gdzieœ "w œrodku"
				{
				przed->nastepny=wsk;
				wsk->nastepny=po;
				}
	 }
}
// -------------------------------------------------------
int  LISTA::usun(ELEMENT *q,int(*decyzja)(ELEMENT *q1,ELEMENT *q2))
{
// usuwa ca³kowicie informacje z obu list (wskaŸnikow i danych)
ELEMENT *ptr_dane;
for (int i=0; i<kryteria_sort; i++)
	ptr_dane=usun_wsk(&inf_ptr[i],q,decyzja);
if (ptr_dane==NULL) 
	return(0); 
else
	return  usun_dane(ptr_dane);
}

// -------------------------------------------------------
ELEMENT*  LISTA::usun_wsk(LPTR_INFO *inf,ELEMENT *q,int(*decyzja)(ELEMENT *q1,ELEMENT *q2))
{
if (inf->glowa==NULL)  // lista pusta, czyli nie ma czego usuwaæ!
	return NULL;
else              //szukamy elementu do usuniêcia
    {
	LPTR *przed,*pos;
	LPTR_INFO *gdzie=odszukaj_wsk(inf,q,decyzja);
	przed=gdzie->glowa;
	pos=gdzie->ogon;
	if (pos==NULL) return NULL;  // element nieodnaleziony

	if (pos==inf->glowa)         // usuwamy z pocz¹tku listy
	 inf->glowa=pos->nastepny;
	else
		if (pos->nastepny==NULL) // usuwamy z koñca listy
		{
		inf->ogon=przed;
		przed->nastepny=NULL;
		}else    // usuwamy gdzieœ "ze œrodka"
			 przed->nastepny=pos->nastepny;
	ELEMENT *ret=pos->adres;
	delete pos;
	return ret;
	}
}
// -------------------------------------------------------
int  LISTA::usun_dane(ELEMENT *q)
{// za³o¿enie: q istnieje!
ELEMENT *przed,*pos;
przed=NULL;
pos=info_dane.glowa;
while ((pos!=q) && (pos!=NULL)) // szukamy elementu "przed"
  {
  przed=pos;
  pos=pos->nastepny;
  }
if (pos!=q) 
	return(0); // element nieodnaleziony?!
if (pos==info_dane.glowa)         // usuwamy z pocz¹tku listy
{
 info_dane.glowa=pos->nastepny;
 delete pos;
}else
	if (pos->nastepny==NULL) // usuwamy z koñca listy
	{
	info_dane.ogon=przed;
	przed->nastepny=NULL;
	delete pos;
	}else    // usuwamy gdzieœ "ze œrodka"
		{
		 przed->nastepny=pos->nastepny;
		 delete pos;
		 }
return(1);
}
// -------------------------------------------------------
void LISTA::wypisz1(LPTR_INFO *inf) // wypisujemy zawartoœæ posortowanej listy
{									// wskaŸników (oczywiœcie nie interesuje nas
LPTR *q=inf->glowa;					// wypisanie wskaŸnikow, gdy¿ s¹ to adresy), lecz
while (q != NULL)					// informacji, na które one wskazuj¹
  {
  cout << setw(9)<<q->adres->nazwisko<< " zarabia "<<setw(4)<<q->adres->zarobek<<"z³\n";
  q=q->nastepny;
  }
cout << "\n";
}
// -------------------------------------------------------
void LISTA::wypisz(char c)
{
if (c=='a')  //alfabetycznie
  wypisz1(&inf_ptr[0]); 
else
  wypisz1(&inf_ptr[1]);
}
// -------------------------------------------------------
int main()
{
LISTA l1;
char *tab1[n]={"Bec","Becki","Fikus","Pertek","Czerniak"};
int   tab2[n]={1300,1000,1200,2000,3000};
for (int i=0; i<n; i++)
 {
 ELEMENT *nowy=new ELEMENT;     // tworzymy fizycznie nowy rekord...
 strcpy(nowy->nazwisko,tab1[i]);
 nowy->zarobek= tab2[i];
 nowy->nastepny=NULL;
 l1.dorzuc(nowy);   // ...i dorzucamy go do listy
 }
cout << "\n*** Baza danych posortowana alfabetyczne ***\n";
l1.wypisz('a');
cout << "*** Baza danych posortowana wg zarobków ***\n";
l1.wypisz('z');
ELEMENT *f=new ELEMENT;
	 f->zarobek=2000;

cout << "Wynik usuniêcia rekordu pracownika zarabiaj¹cego 2000zl="<< l1.usun(f, ident_zarobki) <<endl;
delete f;
cout << "*** Baza danych posortowana alfabetyczne ***\n";
l1.wypisz('a');
cout << "*** Baza danych posortowana wg zarobków ***\n";
l1.wypisz('z');
}
// -------------------------------------------------------

