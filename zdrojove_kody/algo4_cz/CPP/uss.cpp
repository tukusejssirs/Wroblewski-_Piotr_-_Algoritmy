#include <iostream>
#include <string.h>

using namespace std;
const int n=29;

typedef struct slovnik
   {
   struct slovnik *t[n];
   } USS, *USS_PTR;
// ------------------------------------------------------------------------
int do_indexu(char c) // znak ASCII -> index
{
if ( (c<='Z') && (c>='A') || (c<='z') && (c>='a') )
      return toupper(c)-'A';
else
   {
   if (c==' ')  return 26;
   if (c=='-')  return 27;
   }
}
// ------------------------------------------------------------------------
char z_indexu(int n) // index -> znak ASCII
{
if ( (n>=0)  &&  (n<= ('Z'-'A')) )
   return toupper((char) n+'A');
else
   {
    if (n==26) return ' ';
    if (n==27) return '-';
   }
}
// ------------------------------------------------------------------------
void zapis(char *slovo,USS_PTR p)
{
USS_PTR q; // pomocn� prom�nn�
int pos;
for (int i=1; i<=strlen(slovo); i++)
  {
  pos=do_indexu(slovo[i-1]);
  if (p->t[pos] != NULL) p=p->t[pos];
   else
   {
    q=new USS;
    p->t[pos]=q;
    for (int k=0; k<n; q->t[k++]=NULL);
    p=q;
   }
  }
p->t[n-1]=p; // cyklus jako konec slova
}
// ------------------------------------------------------------------------
void pis_slovnik(USS_PTR p)
{
 for (int i=0; i<26; i++)
   if (p->t[i] != NULL)
   {
    if ( (p->t[i])->t[n-1]==p->t[i])     // na konec slova
      cout << z_indexu(i) << endl <<" ";// zaps�n� znaku konce ��dku
   else
      cout << z_indexu(i);
      cout << "---"; // kv�li p�ehlednosti
      pis_slovnik(p->t[i]); // rekurzivn� v�pis zb�vaj�c� ��sti
    }
}
// ------------------------------------------------------------------------
void hledej(char *slovo,USS_PTR p) 
{// hled�n� slova ve slovn�ku
 int test=1, i=0;
 while ((test==1) && (i<strlen(slovo)) )
  {
  if (p->t[do_indexu(slovo[i])]==NULL) 
test=0; // p��slu�n� v�tev chyb�, slovo neexistuje!
   else 
p=p->t[do_indexu(slovo[i++])]; // vyhled�v�n� pokra�uje
  }
if ( (i==strlen(slovo)) && (p->t[n-1]==p) && test)
   cout << "Slovo bylo nalezeno!\n";
else  
cout << "Slovo se ve slovn�ku nenach�z�\n";;
} 


// ------------------------------------------------------------------------
int main()
{
int i;
char obsah[100];
USS_PTR p=new USS; // vytvo�en� nov�ho slovn�ku
for (i=0; i<n; p->t[i++]=NULL);
for(i=1 ;i<=7;i++) // na�ten� 7 slov
 {
   cout << "Zadejte slovo, kter� chcete um�stit do slovn�ku:";
   cin >> obsah;
   zapis(obsah,p);
 }
pis_slovnik(p);    // v�pis obsahu slovn�ku
for(i=1 ;i<=4;i++)  // hled�n� 4 slov
 {
   cout << "Zadejte slovo, kter� chcete vyhledat ve slovn�ku:";
   cin >> obsah;
   hledej(obsah,p);
 }
}
