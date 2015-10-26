#include <iostream>
#include <string.h>
using namespace std;


int index(char c)
{
switch(c)
 {
 case ' ':return 0;  // mezera=0
 case 'á':return 53;
 case 'Á':return 54; // èeská písmena
 case 'è':return 55;
 case 'È':return 56; // atd. pro zbývající èeská písmena
 default: 
    if(islower(c)) 
       return c-'a'+1; 
    else 
       return c-'A'+27;
 }
}

const long p=33554393; // velké prvoèíslo
const int b=64;         // velká + malá písmena + "nìco navíc"
//-------------------------------------------------------

int rk(char w[],char t[])
{
unsigned long i,bM_1=1, Hw=0, Ht=0, M=strlen(w), N=strlen(t);
for(i=0; i<M; i++)
  {
  Hw=(Hw*b+index(w[i]))%p;   // iniciování funkce H pro vzor
  Ht=(Ht*b+index(t[i]))%p;   // iniciování funkce H pro text
  }
for(i=1; i<M; i++) 
   bM_1=(b*bM_1)%p;
for(i=0; Hw!=Ht; i++)         // posun v textu
  {
  Ht=(Ht+b*p-index(t[i])*bM_1)%p;
  Ht=(Ht*b+index(t[i+M]))%p;
  if (i>N-M) 
     return -1;      // vyhledávání nebylo úspìšné
  }
return i;
}
//-------------------------------------------------------
int main()
 {
 char *t="Zemský ráj to na pohled";
 cout << "Výsledek vyhledávání="<<rk("hle",t)<<endl;
 }
