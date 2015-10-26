#include <iostream>
using namespace std;

#include "kolejka.h"

static char *tab[]={"Kov��ov�","Fran�k","Berka","Pravec"};

int main()
{
int i;
FIFO<char*> fronta(5); // fronta s 5 prvky
for(int i=0; i<4; i++)
  fronta.vloz(tab[i]);
char *s;
for(i=0; i<5;i++)
  {
  int res=fronta.obsluz(s);
  if (res==OK)
      cout <<  "Byl obslou�en klient: "<<s<<endl;
  else
      cout <<  "Fronta je pr�zdn�!\n";
  }

/* verze 2:
  while(!fronta.prazdne())
    {
    int res=fronta.obsluz(s);
    cout <<  "Byl obslou�en klient:"<<s<<endl;
    }
    */
}
