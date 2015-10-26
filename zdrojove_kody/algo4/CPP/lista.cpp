#include <iostream>
using namespace std;
#include "lista.h"
void LISTA::dorzuc1(int x)    // do³¹czamy rekord na koniec listy
{                             // bez sortowania
	ELEMENT *q=new ELEMENT;
	q->wartosc=x;
	q->nastepny=NULL;
	if (pusta())			// lista pusta?
		inf.glowa=inf.ogon=q;
	else                 // coœ jest w liscie
	{
		(inf.ogon)->nastepny=q;
		inf.ogon=q;
	}
}
// -------------------------------------------------------
LISTA& LISTA::operator --(int)
{
if (inf.glowa==inf.ogon)   // jeden element (lub lista pusta)
{
	delete inf.glowa;
	inf.glowa=inf.ogon=NULL;
} else
	{
	ELEMENT *temp=inf.glowa;
	while ((temp->nastepny) != inf.ogon) // szukamy przedostatniego
		temp=temp->nastepny;         // elementu listy...
	inf.ogon=temp;
	delete temp->nastepny;               // ... i usuwamy go
	temp->nastepny=NULL;
	}
return (*this);			  	  // zwracamy zmodyfikowany obiekt
}
// -------------------------------------------------------
void LISTA::dorzuc2(int x)    // do³¹czamy rekord na w³aœciwe miejsce
{                             // z sortowaniem
ELEMENT *q=new ELEMENT;       // tworzymy nowy element listy
q->wartosc=x;
// Poszukiwanie w³asciwej pozycji na wstawienie elementu
if (pusta())
{
	inf.glowa=inf.ogon=q;
	q->nastepny=NULL;
	}
	else //szukamy miejsca na wstawienie
	{
		ELEMENT *przed=NULL,*po=inf.glowa;
		enum {SZUKAJ,ZAKONCZ} stan=SZUKAJ; // zmienna wyliczeniowa
		while ((stan==SZUKAJ) && (po!=NULL))
		if (po->wartosc>=x)
			stan=ZAKONCZ; 	// znaleŸliœmy w³aœciwe miejsce!
		else        		// przemieszczamy siê w poszukiwaniach
			{         	// w³aœciwego miejsca
			 przed=po;     	// wskaŸniki "przed" i "po"
			 po=po->nastepny;// zapamiêtaj¹ miejsce wstawiania
			 }
	if (przed==NULL)  		// wstawiamy na pocz¹tek listy
	{
	 inf.glowa=q;
	 q->nastepny=po;
	} else
		if (po==NULL) // wstawiamy na koniec listy
		{
		inf.ogon->nastepny=q;
		q->nastepny=NULL;
		inf.ogon=q;
		}else    // wstawiamy gdzieœ w œrodku
			 {
			  przed->nastepny=q;
			  q->nastepny=po;
			 }
	  }
}
// -------------------------------------------------------
LISTA& operator +(LISTA &x,LISTA &y)
{
LISTA *temp=new LISTA;
ELEMENT *q1=(x.inf).glowa; // wskaŸniki robocze
ELEMENT *q2=(y.inf).glowa;
while (q1 != NULL) // przekopiowanie listy x do temp
{
	temp->dorzuc2(q1->wartosc);
	q1=q1->nastepny;
 }
while (q2 != NULL) // przekopiowanie listy y do temp
{
	temp->dorzuc2(q2->wartosc);
	q2=q2->nastepny;
}
return (*temp);
}
// ------------------------------------------------------
ELEMENT *sortuj(ELEMENT *a,ELEMENT *b)
{
if (a==NULL) 
	return b;
if (b==NULL) 
	return a;
if (a->wartosc<=b->wartosc)
   {
   a->nastepny=sortuj(a->nastepny,b);
   return a;
   }else
	{
	 b->nastepny=sortuj(b->nastepny,a);
	 return b;
	}
}
// ------------------------------------------------------
void  fuzja(LISTA &x,LISTA &y)
{// a i b musz¹ byæ posortowane
ELEMENT *a=x.inf.glowa,*b=y.inf.glowa;
ELEMENT *wynik=sortuj(a,b);
x.inf.glowa=wynik;
if(x.inf.ogon->wartosc <= y.inf.ogon->wartosc)
	x.inf.ogon=y.inf.ogon;
else x.inf.ogon=x.inf.ogon;
	y.zeruj();
}
// -------------------------------------------------------
void LISTA::wypisz()
{
ELEMENT *q=inf.glowa;
if (pusta()) cout << "(lista pusta)"; 
else
	while (q != NULL)
	{
	cout << q->wartosc << "   ";
	q=q->nastepny;
	}
cout << "\n";
}
// -------------------------------------------------------
int LISTA::szukaj(int x)
{
ELEMENT *q=inf.glowa;
while (q != NULL)
{
	if (q->wartosc==x) return SUKCES;
	q=q->nastepny;
}
return PORAZKA;
}
// -------------------------------------------------------
int main()
{
LISTA l1,l2;
const int n=6;
int tab1[n]={2,5,-11,4,14,12};
// ka¿dy element tablicy zostanie wstawiony do listy
cout << "\nL1 = ";
	 for (int i=0; i<n; l1.dorzuc2(tab1[i++]));
l1.wypisz();
int tab2[n]={9,6,77,1,7,4};
cout << "L2 = ";
	 for (int i=0; i<n; l2.dorzuc2(tab2[i++]));
  l2.wypisz();
cout << "Efekt poszukiwañ liczby 14 w liœcie l1: " << l1.szukaj(14) << endl;
cout << "Efekt poszukiwañ liczby 0 w liœcie  l1: " << l1.szukaj(0) << endl;
cout << "Oto lista bêd¹ca sum¹ dwóch poprzednich\nL3 = ";
  LISTA l3=l1+l2;
  l3.wypisz();
cout << "Listy L1 i L2 pozosta³y bez zmian:\nL1 = ";
  l1.wypisz();
cout << "L2 = ";
  l2.wypisz();
cout << "Lista L1 bez dwóch ostatnich elementów:\nL1 = ";
  (l1--)--.wypisz();
cout << "Efekt fuzji L1 z L2:\n";
  fuzja(l1,l2);
cout << "L1 = ";
  l1.wypisz();
cout << "L2 = ";
  l2.wypisz();
  l1.dorzuc2(80);l1.dorzuc2(8);
cout << "dorzucamy do L1 liczby 80 i 8\nL1 = ";
  l1.wypisz();
}
