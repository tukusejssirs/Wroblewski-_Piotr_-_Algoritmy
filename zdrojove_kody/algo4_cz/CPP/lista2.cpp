#include <iostream>
#include <iomanip> // kv�li funkci setw
using namespace std;
#include "lista2.h"
// -------------------------------------------------------
SEZNAM::SEZNAM() //konstruktor nuluje informa�n� bu�ky
{
inf_ptr[0].hlava=inf_ptr[0].ocas=NULL;
inf_ptr[1].hlava=inf_ptr[1].ocas=NULL;
info_data.hlava=info_data.ocas=NULL;
}
// -------------------------------------------------------
SEZNAM::~SEZNAM() // destruktor uvol�uje pam� obsazenou objektem
{
while (info_data.hlava!=NULL) // likvidace seznamu dat:
{
   PRVEK *q=(info_data.hlava)->dalsi; // ulo�en� ukazatele...
   delete info_data.hlava;
   info_data.hlava=q;                      // ...a jeho obnoven�
  }
for (int i=0;i<kriteria_trideni;i++)        // likvidace seznamu ukazatel�:
   while (inf_ptr[i].hlava!=NULL)
   {
   LPTR *q=(inf_ptr[i].hlava)->dalsi;
   delete inf_ptr[i].hlava;                // viz v��e
   inf_ptr[i].hlava=q;
  }
}
// -------------------------------------------------------
SEZNAM::LPTR_INFO* SEZNAM::vyhledej_ukz(SEZNAM::LPTR_INFO *inf,PRVEK *q,int(*rozhodnuti)(PRVEK *q1,PRVEK *q2))
{
LPTR_INFO *res=new LPTR_INFO;
res->hlava=res->ocas=NULL;
if (inf->hlava==NULL) 
   return (res); // seznam je pr�zdn�!
else
 {
  LPTR *pred,*pos;
  pred=NULL;
  pos=inf->hlava;
  enum {HLEDEJ,KONEC} stav=HLEDEJ;
  while ((stav==HLEDEJ) && (pos!=NULL))
  if (rozhodnuti(pos->adresa,q))
      stav=KONEC;  // nalezeno m�sto, kde se prvek
  else               // nach�z� (nebo kam m� b�t vlo�en)
   {       // pokra�uje hled�n�
   pred=pos;
   pos=pos->dalsi;
   }
  res->hlava=pred;
  res->ocas=pos;
  return (res);
  }
}
// -------------------------------------------------------
void SEZNAM::vloz(PRVEK *q)
{                                // p�ipojen� z�znamu bez t��d�n�
if (info_data.hlava==NULL)      // seznam je pr�zdn�
   info_data.hlava=info_data.ocas=q;
else                 // seznam nen� pr�zdn�
   {
   (info_data.ocas)->dalsi=q;
   info_data.ocas=q;
   }
// p�ipojen� ukazatele na z�znam v abecedn� se�azen�m seznamu
vloz2(0,q,abecedne);
// p�ipojen� ukazatele na z�znam v seznamu se�azen�m podle v�d�lk�
vloz2(1,q,podle_vydelku);
}
// -------------------------------------------------------
void  SEZNAM::vloz2(int poc,PRVEK *q,int(*rozhodnuti)(PRVEK *q1,PRVEK *q2))
{
LPTR *ukz=new LPTR;
ukz->adresa=q; // zad�n� adresy z�znamu q
// Hled�n� vhodn� pozice k vlo�en� prvku
if (inf_ptr[poc].hlava==NULL) // pr�zdn�
{
 inf_ptr[poc].hlava=inf_ptr[poc].ocas=ukz;
 ukz->dalsi=NULL;
}
   else // hled�n� m�sta k vlo�en�
   {
   LPTR *pred,*po;
   LPTR_INFO *kde=vyhledej_ukz(&inf_ptr[poc],q,rozhodnuti);
   pred=kde->hlava;
   po=kde->ocas;
   if (pred==NULL)  // vlo�en� na za��tek seznamu
      {
      inf_ptr[poc].hlava=ukz;
      ukz->dalsi=po;
      } else
         if (po==NULL) // vlo�en� na konec seznamu
         {
         inf_ptr[poc].ocas->dalsi=ukz;
         ukz->dalsi=NULL;
         inf_ptr[poc].ocas=ukz;
         }else    // vlo�en� n�kam doprost�ed
            {
            pred->dalsi=ukz;
            ukz->dalsi=po;
            }
    }
}
// -------------------------------------------------------
int  SEZNAM::odstran(PRVEK *q,int(*rozhodnuti)(PRVEK *q1,PRVEK *q2))
{
// kompletn� odstran�n� informac� z obou seznam� (ukazatel� i dat)
PRVEK *ptr_data;
for (int i=0; i<kriteria_trideni; i++)
   ptr_data=odstran_ukz(&inf_ptr[i],q,rozhodnuti);
if (ptr_data==NULL) 
   return(0); 
else
   return  odstran_data(ptr_data);
}

// -------------------------------------------------------
PRVEK*  SEZNAM::udstran_ukz(LPTR_INFO *inf,PRVEK *q,int(*rozhodnuti)(PRVEK *q1,PRVEK *q2))
{
if (inf->hlava==NULL)  // seznam je pr�zdn�, tak�e nelze nic odstranit
   return NULL;
else              // hled�n� prvku k odstran�n�
    {
   LPTR *pred,*pos;
   LPTR_INFO *kde=vyhledej_ukz(inf,q,rozhodnuti);
   pred=kde->hlava;
   pos=kde->ocas;
   if (pos==NULL) return NULL;  // prvek nebyl nalezen

   if (pos==inf->hlava)         // odstran�n� ze za��tku seznamu
    inf->hlava=pos->dalsi;
   else
      if (pos->dalsi==NULL) // odstran�n� z konce seznamu
      {
      inf->ocas=pred;
      pred->dalsi=NULL;
      }else    // odstran�n� odn�kud "zprost�edka"
          pred->dalsi=pos->dalsi;
   PRVEK *ret=pos->adresa;
   delete pos;
   return ret;
   }
}
// -------------------------------------------------------
int  SEZNAM::odstran_data(PRVEK *q)
{// p�edpoklad: q existuje!
PRVEK *pred,*pos;
pred=NULL;
pos=info_data.hlava;
while ((pos!=q) && (pos!=NULL)) // hled�n� prvku "pred"
  {
  pred=pos;
  pos=pos->dalsi;
  }
if (pos!=q) 
   return(0); // prvek nebyl nalezen?!
if (pos==info_data.hlava)         // odstran�n� ze za��tku seznamu
{
 info_data.hlava=pos->dalsi;
 delete pos;
}else
   if (pos->dalsi==NULL) // odstran�n� z konce seznamu
   {
   info_data.ocas=pred;
   pred->dalsi=NULL;
   delete pos;
   }else    // odstran�n� odn�kud "zprost�edka"
      {
       pred->dalsi=pos->dalsi;
       delete pos;
       }
return(1);
}
// -------------------------------------------------------
void SEZNAM::vypis1(LPTR_INFO *inf) // vyp�e obsah set��d�n�ho seznamu
{                          // ukazatel� (samoz�ejm� nechceme
LPTR *q=inf->hlava;              // vypsat ukazatele, proto�e se jedn� o adresy, ale
while (q != NULL)             // informace, na kter� odkazuj�)
  {
  cout << setw(9)<<q->adresa->prijmeni<< " vyd�l�v� "<<setw(4)<<q->adresa->vydelek<<" K�\n";
  q=q->dalsi;
  }
cout << "\n";
}
// -------------------------------------------------------
void SEZNAM::vypis(char c)
{
if (c=='a')  // abecedn�
  vypis1(&inf_ptr[0]); 
else
  vypis1(&inf_ptr[1]);
}
// -------------------------------------------------------
int main()
{
SEZNAM l1;
char *tab1[n]={"Bedn��","Berka","Frynta","Pra��k","�ern�"};
int   tab2[n]={13000,10000,12000,20000,30000};
for (int i=0; i<n; i++)
 {
 PRVEK *novy=new PRVEK;     // fyzick� vytvo�en� nov�ho z�znamu...
 strcpy(novy->prijmeni,tab1[i]);
 novy->vydelek= tab2[i];
 novy->dalsi=NULL;
 l1.vloz(novy);   // ...a jeho vlo�en� do seznamu
 }
cout << "\n*** Datab�ze set��d�n� abecedn� ***\n";
l1.vypis('a');
cout << "*** Datab�ze set��d�n� podle v�d�lk� ***\n";
l1.vypis('z');
PRVEK *f=new PRVEK;
    f->vydelek=20000;

cout << "V�sledek odstran�n� z�znamu pracovn�ka, kter� vyd�l�v� 20 000 K�="<< l1.odstran(f, ident_vydelky) <<endl;
delete f;
cout << "*** Datab�ze set��d�n� abecedn� ***\n";
l1.vypis('a');
cout << "*** Datab�ze set��d�n� podle v�d�lk� ***\n";
l1.vypis('z');
}
// -------------------------------------------------------

