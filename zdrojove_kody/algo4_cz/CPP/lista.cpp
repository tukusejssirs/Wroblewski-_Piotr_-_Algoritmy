#include <iostream>
using namespace std;
#include "lista.h"
void SEZNAM::vloz1(int x)    // pøipojení záznamu na konec seznamu
{                             // bez tøídìní
   PRVEK *q=new PRVEK;
   q->hodnota=x;
   q->dalsi=NULL;
   if (prazdne())         // je seznam prázdný?
      inf.hlava=inf.ocas=q;
   else                 // seznam není prázdný
   {
      (inf.ocas)->dalsi=q;
      inf.ocas=q;
   }
}
// -------------------------------------------------------
SEZNAM& SEZNAM::operator --(int)
{
if (inf.hlava==inf.ocas)   // jeden prvek (nebo prázdný seznam)
{
   delete inf.hlava;
   inf.hlava=inf.ocas=NULL;
} else
   {
   PRVEK *temp=inf.hlava;
   while ((temp->dalsi) != inf.ocas) // hledání pøedposledního
      temp=temp->dalsi;         // prvku seznamu…
   inf.ocas=temp;
   delete temp->dalsi;               // …a jeho odstranìní
   temp->dalsi=NULL;
   }
return (*this);              // vrácení upraveného objektu
}
// -------------------------------------------------------
void SEZNAM::vloz2(int x)    // pøipojení záznamu na správné místo
{                             // s tøídìním
PRVEK *q=new PRVEK;       // vytvoøení nového prvku seznamu
q->hodnota=x;
// Hledání vhodné pozice k vložení prvku
if (prazdne())
{
   inf.hlava=inf.ocas=q;
   q->dalsi=NULL;
   }
   else // hledání místa k vložení
   {
      PRVEK *pred=NULL,*po=inf.hlava;
      enum {HLEDEJ,KONEC} stav=HLEDEJ; // výètová promìnná
      while ((stav==HLEDEJ) && (po!=NULL))
      if (po->hodnota>=x)
         stan=KONEC;  // nalezeno vhodné místo
      else              // pokraèuje hledání
         {           // vhodného místa
          pred=po;        // ukazatele "pred" a "po"
          po=po->dalsi;// uchovávají místo vložení
          }
   if (pred==NULL)        // vložení na zaèátek seznamu
   {
    inf.hlava=q;
    q->dalsi=po;
   } else
      if (po==NULL) // vložení na konec seznamu
      {
      inf.ocas->dalsi=q;
      q->dalsi=NULL;
      inf.ocas=q;
      }else    // vložení nìkam doprostøed
          {
           pred->dalsi=q;
           q->dalsi=po;
          }
     }
}
// -------------------------------------------------------
SEZNAM& operator +(SEZNAM &x,SEZNAM &y)
{
SEZNAM *temp=new SEZNAM;
PRVEK *q1=(x.inf).hlava; // pracovní ukazatele
PRVEK *q2=(y.inf).hlava;
while (q1 != NULL) // zkopírování seznamu x do temp
{
   temp->vloz2(q1->hodnota);
   q1=q1->dalsi;
 }
while (q2 != NULL) // zkopírování seznamu y do temp
{
   temp->vloz2(q2->hodnota);
   q2=q2->dalsi;
}
return (*temp);
}
// ------------------------------------------------------
PRVEK *setrid(PRVEK *a,PRVEK *b)
{
if (a==NULL) 
   return b;
if (b==NULL) 
   return a;
if (a->hodnota<=b->hodnota)
   {
   a->dalsi=setrid(a->dalsi,b);
   return a;
   }else
   {
    b->dalsi=setrid(b->dalsi,a);
    return b;
   }
}
// ------------------------------------------------------
void  fuze(SEZNAM &x,SEZNAM &y)
{// seznamy a i b musí být setøídìné
PRVEK *a=x.inf.hlava,*b=y.inf.hlava;
PRVEK *vysledek=setrid(a,b);
x.inf.hlava=vysledek;
if(x.inf.ocas->hodnota <= y.inf.ocas->hodnota)
   x.inf.ocas=y.inf.ocas;
else x.inf.ocas=x.inf.ocas;
   y.nuluj();
}
// -------------------------------------------------------
void SEZNAM::vypis()
{
PRVEK *q=inf.hlava;
if (prazdne()) cout << "(seznam je prázdný)"; 
else
   while (q != NULL)
   {
   cout << q->hodnota << "   ";
   q=q->dalsi;
   }
cout << "\n";
}
// -------------------------------------------------------
int SEZNAM::hledej(int x)
{
PRVEK *q=inf.hlava;
while (q != NULL)
{
   if (q->hodnota==x) return USPECH;
   q=q->dalsi;
}
return NEUSPECH;
}
// -------------------------------------------------------
int main()
{
SEZNAM l1,l2;
const int n=6;
int tab1[n]={2,5,-11,4,14,12};
// všechny prvky pole jsou vloženy do seznamu
cout << "\nL1 = ";
    for (int i=0; i<n; l1.vloz2(tab1[i++]));
l1.vypis();
int tab2[n]={9,6,77,1,7,4};
cout << "L2 = ";
    for (int i=0; i<n; l2.vloz2(tab2[i++]));
  l2.vypis();
cout << "Výsledek vyhledávání èísla 14 v seznamu l1: " << l1.hledej(14) << endl;
cout << "Výsledek vyhledávání èísla 0 v seznamu l1: " << l1.hledej(0) << endl;
cout << "Tento seznam vznikl slouèením dvou pøedchozích\nL3 = ";
  SEZNAM l3=l1+l2;
  l3.vypis();
cout << "Seznamy L1 a L2 se nezmìnily:\nL1 = ";
  l1.vypis();
cout << "L2 = ";
  l2.vypis();
cout << "Seznam L1 bez dvou posledních prvkù:\nL1 = ";
  (l1--)--.vypis();
cout << "Výsledek slouèení seznamù L1 a L2:\n";
  fuze(l1,l2);
cout << "L1 = ";
  l1.vypis();
cout << "L2 = ";
  l2.vypis();
  l1.vloz2(80);l1.vloz2(8);
cout << "Do seznamu L1 pøidáváme èísla 80 a 8\nL1 = ";
  l1.vypis();
}
