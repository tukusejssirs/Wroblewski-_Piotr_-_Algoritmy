#include "stos.h"

#include <iostream>
using namespace std;

int main()
{
STOS<double> s; // deklarujemy jeden obiekt klasy "STOS"
double tab[3]={2.4,2.3,6.789};
for(int i=0; i<3;i++)
  {
  cout << "Odk³adam na stos: "<< tab[i] <<endl;
  s.push(tab[i]);
  }

for(int i=0; i<3;i++)
  {
  double z;
  s.pop(z);
  cout << "Zdejmujê ze stosu "<< z <<endl;
  }
}
