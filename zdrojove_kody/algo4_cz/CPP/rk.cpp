#include <iostream>
#include <string.h>
using namespace std;


int index(char c)
{
switch(c)
 {
 case ' ':return 0;  // mezera=0
 case '�':return 53;
 case '�':return 54; // �esk� p�smena
 case '�':return 55;
 case '�':return 56; // atd. pro zb�vaj�c� �esk� p�smena
 default: 
    if(islower(c)) 
       return c-'a'+1; 
    else 
       return c-'A'+27;
 }
}

const long p=33554393; // velk� prvo��slo
const int b=64;         // velk� + mal� p�smena + "n�co nav�c"
//-------------------------------------------------------

int rk(char w[],char t[])
{
unsigned long i,bM_1=1, Hw=0, Ht=0, M=strlen(w), N=strlen(t);
for(i=0; i<M; i++)
  {
  Hw=(Hw*b+index(w[i]))%p;   // iniciov�n� funkce H pro vzor
  Ht=(Ht*b+index(t[i]))%p;   // iniciov�n� funkce H pro text
  }
for(i=1; i<M; i++) 
   bM_1=(b*bM_1)%p;
for(i=0; Hw!=Ht; i++)         // posun v textu
  {
  Ht=(Ht+b*p-index(t[i])*bM_1)%p;
  Ht=(Ht*b+index(t[i+M]))%p;
  if (i>N-M) 
     return -1;      // vyhled�v�n� nebylo �sp�n�
  }
return i;
}
//-------------------------------------------------------
int main()
 {
 char *t="Zemsk� r�j to na pohled";
 cout << "V�sledek vyhled�v�n�="<<rk("hle",t)<<endl;
 }
