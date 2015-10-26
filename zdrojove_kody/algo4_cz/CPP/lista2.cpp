#include <iostream>
#include <iomanip> // kvùli funkci setw
using namespace std;
#include "lista2.h"
// -------------------------------------------------------
SEZNAM::SEZNAM() //konstruktor nuluje informaèní buòky
{
inf_ptr[0].hlava=inf_ptr[0].ocas=NULL;
inf_ptr[1].hlava=inf_ptr[1].ocas=NULL;
info_data.hlava=info_data.ocas=NULL;
}
// -------------------------------------------------------
SEZNAM::~SEZNAM() // destruktor uvolòuje pamì obsazenou objektem
{
while (info_data.hlava!=NULL) // likvidace seznamu dat:
{
   PRVEK *q=(info_data.hlava)->dalsi; // uložení ukazatele...
   delete info_data.hlava;
   info_data.hlava=q;                      // ...a jeho obnovení
  }
for (int i=0;i<kriteria_trideni;i++)        // likvidace seznamu ukazatelù:
   while (inf_ptr[i].hlava!=NULL)
   {
   LPTR *q=(inf_ptr[i].hlava)->dalsi;
   delete inf_ptr[i].hlava;                // viz výše
   inf_ptr[i].hlava=q;
  }
}
// -------------------------------------------------------
SEZNAM::LPTR_INFO* SEZNAM::vyhledej_ukz(SEZNAM::LPTR_INFO *inf,PRVEK *q,int(*rozhodnuti)(PRVEK *q1,PRVEK *q2))
{
LPTR_INFO *res=new LPTR_INFO;
res->hlava=res->ocas=NULL;
if (inf->hlava==NULL) 
   return (res); // seznam je prázdný!
else
 {
  LPTR *pred,*pos;
  pred=NULL;
  pos=inf->hlava;
  enum {HLEDEJ,KONEC} stav=HLEDEJ;
  while ((stav==HLEDEJ) && (pos!=NULL))
  if (rozhodnuti(pos->adresa,q))
      stav=KONEC;  // nalezeno místo, kde se prvek
  else               // nachází (nebo kam má být vložen)
   {       // pokraèuje hledání
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
{                                // pøipojení záznamu bez tøídìní
if (info_data.hlava==NULL)      // seznam je prázdný
   info_data.hlava=info_data.ocas=q;
else                 // seznam není prázdný
   {
   (info_data.ocas)->dalsi=q;
   info_data.ocas=q;
   }
// pøipojení ukazatele na záznam v abecednì seøazeném seznamu
vloz2(0,q,abecedne);
// pøipojení ukazatele na záznam v seznamu seøazeném podle výdìlkù
vloz2(1,q,podle_vydelku);
}
// -------------------------------------------------------
void  SEZNAM::vloz2(int poc,PRVEK *q,int(*rozhodnuti)(PRVEK *q1,PRVEK *q2))
{
LPTR *ukz=new LPTR;
ukz->adresa=q; // zadání adresy záznamu q
// Hledání vhodné pozice k vložení prvku
if (inf_ptr[poc].hlava==NULL) // prázdný
{
 inf_ptr[poc].hlava=inf_ptr[poc].ocas=ukz;
 ukz->dalsi=NULL;
}
   else // hledání místa k vložení
   {
   LPTR *pred,*po;
   LPTR_INFO *kde=vyhledej_ukz(&inf_ptr[poc],q,rozhodnuti);
   pred=kde->hlava;
   po=kde->ocas;
   if (pred==NULL)  // vložení na zaèátek seznamu
      {
      inf_ptr[poc].hlava=ukz;
      ukz->dalsi=po;
      } else
         if (po==NULL) // vložení na konec seznamu
         {
         inf_ptr[poc].ocas->dalsi=ukz;
         ukz->dalsi=NULL;
         inf_ptr[poc].ocas=ukz;
         }else    // vložení nìkam doprostøed
            {
            pred->dalsi=ukz;
            ukz->dalsi=po;
            }
    }
}
// -------------------------------------------------------
int  SEZNAM::odstran(PRVEK *q,int(*rozhodnuti)(PRVEK *q1,PRVEK *q2))
{
// kompletní odstranìní informací z obou seznamù (ukazatelù i dat)
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
if (inf->hlava==NULL)  // seznam je prázdný, takže nelze nic odstranit
   return NULL;
else              // hledání prvku k odstranìní
    {
   LPTR *pred,*pos;
   LPTR_INFO *kde=vyhledej_ukz(inf,q,rozhodnuti);
   pred=kde->hlava;
   pos=kde->ocas;
   if (pos==NULL) return NULL;  // prvek nebyl nalezen

   if (pos==inf->hlava)         // odstranìní ze zaèátku seznamu
    inf->hlava=pos->dalsi;
   else
      if (pos->dalsi==NULL) // odstranìní z konce seznamu
      {
      inf->ocas=pred;
      pred->dalsi=NULL;
      }else    // odstranìní odnìkud "zprostøedka"
          pred->dalsi=pos->dalsi;
   PRVEK *ret=pos->adresa;
   delete pos;
   return ret;
   }
}
// -------------------------------------------------------
int  SEZNAM::odstran_data(PRVEK *q)
{// pøedpoklad: q existuje!
PRVEK *pred,*pos;
pred=NULL;
pos=info_data.hlava;
while ((pos!=q) && (pos!=NULL)) // hledání prvku "pred"
  {
  pred=pos;
  pos=pos->dalsi;
  }
if (pos!=q) 
   return(0); // prvek nebyl nalezen?!
if (pos==info_data.hlava)         // odstranìní ze zaèátku seznamu
{
 info_data.hlava=pos->dalsi;
 delete pos;
}else
   if (pos->dalsi==NULL) // odstranìní z konce seznamu
   {
   info_data.ocas=pred;
   pred->dalsi=NULL;
   delete pos;
   }else    // odstranìní odnìkud "zprostøedka"
      {
       pred->dalsi=pos->dalsi;
       delete pos;
       }
return(1);
}
// -------------------------------------------------------
void SEZNAM::vypis1(LPTR_INFO *inf) // vypíše obsah setøídìného seznamu
{                          // ukazatelù (samozøejmì nechceme
LPTR *q=inf->hlava;              // vypsat ukazatele, protože se jedná o adresy, ale
while (q != NULL)             // informace, na které odkazují)
  {
  cout << setw(9)<<q->adresa->prijmeni<< " vydìlává "<<setw(4)<<q->adresa->vydelek<<" Kè\n";
  q=q->dalsi;
  }
cout << "\n";
}
// -------------------------------------------------------
void SEZNAM::vypis(char c)
{
if (c=='a')  // abecednì
  vypis1(&inf_ptr[0]); 
else
  vypis1(&inf_ptr[1]);
}
// -------------------------------------------------------
int main()
{
SEZNAM l1;
char *tab1[n]={"Bednáø","Berka","Frynta","Pražák","Èerný"};
int   tab2[n]={13000,10000,12000,20000,30000};
for (int i=0; i<n; i++)
 {
 PRVEK *novy=new PRVEK;     // fyzické vytvoøení nového záznamu...
 strcpy(novy->prijmeni,tab1[i]);
 novy->vydelek= tab2[i];
 novy->dalsi=NULL;
 l1.vloz(novy);   // ...a jeho vložení do seznamu
 }
cout << "\n*** Databáze setøídìná abecednì ***\n";
l1.vypis('a');
cout << "*** Databáze setøídìná podle výdìlkù ***\n";
l1.vypis('z');
PRVEK *f=new PRVEK;
    f->vydelek=20000;

cout << "Výsledek odstranìní záznamu pracovníka, který vydìlává 20 000 Kè="<< l1.odstran(f, ident_vydelky) <<endl;
delete f;
cout << "*** Databáze setøídìná abecednì ***\n";
l1.vypis('a');
cout << "*** Databáze setøídìná podle výdìlkù ***\n";
l1.vypis('z');
}
// -------------------------------------------------------

