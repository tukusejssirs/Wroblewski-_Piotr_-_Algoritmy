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
USS_PTR q; // pomocná promìnná
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
      cout << z_indexu(i) << endl <<" ";// zapsání znaku konce øádku
   else
      cout << z_indexu(i);
      cout << "---"; // kvùli pøehlednosti
      pis_slovnik(p->t[i]); // rekurzivní výpis zbývající èásti
    }
}
// ------------------------------------------------------------------------
void hledej(char *slovo,USS_PTR p) 
{// hledání slova ve slovníku
 int test=1, i=0;
 while ((test==1) && (i<strlen(slovo)) )
  {
  if (p->t[do_indexu(slovo[i])]==NULL) 
test=0; // pøíslušná vìtev chybí, slovo neexistuje!
   else 
p=p->t[do_indexu(slovo[i++])]; // vyhledávání pokraèuje
  }
if ( (i==strlen(slovo)) && (p->t[n-1]==p) && test)
   cout << "Slovo bylo nalezeno!\n";
else  
cout << "Slovo se ve slovníku nenachází\n";;
} 


// ------------------------------------------------------------------------
int main()
{
int i;
char obsah[100];
USS_PTR p=new USS; // vytvoøení nového slovníku
for (i=0; i<n; p->t[i++]=NULL);
for(i=1 ;i<=7;i++) // naètení 7 slov
 {
   cout << "Zadejte slovo, které chcete umístit do slovníku:";
   cin >> obsah;
   zapis(obsah,p);
 }
pis_slovnik(p);    // výpis obsahu slovníku
for(i=1 ;i<=4;i++)  // hledání 4 slov
 {
   cout << "Zadejte slovo, které chcete vyhledat ve slovníku:";
   cin >> obsah;
   hledej(obsah,p);
 }
}
