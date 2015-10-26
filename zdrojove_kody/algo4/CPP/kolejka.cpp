#include <iostream>
using namespace std;

#include "kolejka.h"

static char *tab[]={"Kowalska","Fronczak","Becki","Pigwa"};

int main()
{
int i;
FIFO<char*> kolejka(5); // kolejka 5-osobowa
for(int i=0; i<4; i++)
  kolejka.wstaw(tab[i]);
char *s;
for(i=0; i<5;i++)
  {
  int res=kolejka.obsluz(s);
  if (res==OK)
		cout <<  "Obs³u¿ony zosta³ klient: "<<s<<endl;
  else
		cout <<  "Kolejka pusta!\n";
  }

/* wersja 2:
  while(!kolejka.pusta())
	 {
	 int res=kolejka.obsluz(s);
	 cout <<  "Obs³u¿ony zosta³ klient:"<<s<<endl;
	 }
	 */
}
