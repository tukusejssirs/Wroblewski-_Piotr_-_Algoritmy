#include <iostream>
using namespace std;

#include "kolejka.h"

static char *tab[]={"Kováøová","Franìk","Berka","Pravec"};

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
      cout <<  "Byl obsloužen klient: "<<s<<endl;
  else
      cout <<  "Fronta je prázdná!\n";
  }

/* verze 2:
  while(!fronta.prazdne())
    {
    int res=fronta.obsluz(s);
    cout <<  "Byl obsloužen klient:"<<s<<endl;
    }
    */
}
