#include <iostream>
using namespace std;
#include "lista.h"
void SEZNAM::vloz1(int x)    // p�ipojen� z�znamu na konec seznamu
{                             // bez t��d�n�
   PRVEK *q=new PRVEK;
   q->hodnota=x;
   q->dalsi=NULL;
   if (prazdne())         // je seznam pr�zdn�?
      inf.hlava=inf.ocas=q;
   else                 // seznam nen� pr�zdn�
   {
      (inf.ocas)->dalsi=q;
      inf.ocas=q;
   }
}
// -------------------------------------------------------
SEZNAM& SEZNAM::operator --(int)
{
if (inf.hlava==inf.ocas)   // jeden prvek (nebo pr�zdn� seznam)
{
   delete inf.hlava;
   inf.hlava=inf.ocas=NULL;
} else
   {
   PRVEK *temp=inf.hlava;
   while ((temp->dalsi) != inf.ocas) // hled�n� p�edposledn�ho
      temp=temp->dalsi;         // prvku seznamu�
   inf.ocas=temp;
   delete temp->dalsi;               // �a jeho odstran�n�
   temp->dalsi=NULL;
   }
return (*this);              // vr�cen� upraven�ho objektu
}
// -------------------------------------------------------
void SEZNAM::vloz2(int x)    // p�ipojen� z�znamu na spr�vn� m�sto
{                             // s t��d�n�m
PRVEK *q=new PRVEK;       // vytvo�en� nov�ho prvku seznamu
q->hodnota=x;
// Hled�n� vhodn� pozice k vlo�en� prvku
if (prazdne())
{
   inf.hlava=inf.ocas=q;
   q->dalsi=NULL;
   }
   else // hled�n� m�sta k vlo�en�
   {
      PRVEK *pred=NULL,*po=inf.hlava;
      enum {HLEDEJ,KONEC} stav=HLEDEJ; // v��tov� prom�nn�
      while ((stav==HLEDEJ) && (po!=NULL))
      if (po->hodnota>=x)
         stan=KONEC;  // nalezeno vhodn� m�sto
      else              // pokra�uje hled�n�
         {           // vhodn�ho m�sta
          pred=po;        // ukazatele "pred" a "po"
          po=po->dalsi;// uchov�vaj� m�sto vlo�en�
          }
   if (pred==NULL)        // vlo�en� na za��tek seznamu
   {
    inf.hlava=q;
    q->dalsi=po;
   } else
      if (po==NULL) // vlo�en� na konec seznamu
      {
      inf.ocas->dalsi=q;
      q->dalsi=NULL;
      inf.ocas=q;
      }else    // vlo�en� n�kam doprost�ed
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
PRVEK *q1=(x.inf).hlava; // pracovn� ukazatele
PRVEK *q2=(y.inf).hlava;
while (q1 != NULL) // zkop�rov�n� seznamu x do temp
{
   temp->vloz2(q1->hodnota);
   q1=q1->dalsi;
 }
while (q2 != NULL) // zkop�rov�n� seznamu y do temp
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
{// seznamy a i b mus� b�t set��d�n�
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
if (prazdne()) cout << "(seznam je pr�zdn�)"; 
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
// v�echny prvky pole jsou vlo�eny do seznamu
cout << "\nL1 = ";
    for (int i=0; i<n; l1.vloz2(tab1[i++]));
l1.vypis();
int tab2[n]={9,6,77,1,7,4};
cout << "L2 = ";
    for (int i=0; i<n; l2.vloz2(tab2[i++]));
  l2.vypis();
cout << "V�sledek vyhled�v�n� ��sla 14 v seznamu l1: " << l1.hledej(14) << endl;
cout << "V�sledek vyhled�v�n� ��sla 0 v seznamu l1: " << l1.hledej(0) << endl;
cout << "Tento seznam vznikl slou�en�m dvou p�edchoz�ch\nL3 = ";
  SEZNAM l3=l1+l2;
  l3.vypis();
cout << "Seznamy L1 a L2 se nezm�nily:\nL1 = ";
  l1.vypis();
cout << "L2 = ";
  l2.vypis();
cout << "Seznam L1 bez dvou posledn�ch prvk�:\nL1 = ";
  (l1--)--.vypis();
cout << "V�sledek slou�en� seznam� L1 a L2:\n";
  fuze(l1,l2);
cout << "L1 = ";
  l1.vypis();
cout << "L2 = ";
  l2.vypis();
  l1.vloz2(80);l1.vloz2(8);
cout << "Do seznamu L1 p�id�v�me ��sla 80 a 8\nL1 = ";
  l1.vypis();
}
