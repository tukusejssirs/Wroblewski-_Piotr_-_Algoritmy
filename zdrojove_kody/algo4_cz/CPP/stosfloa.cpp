#include "stos.h"

#include <iostream>
using namespace std;

int main()
{
ZASOBNIK<double> s; // deklarace jednoho objektu t��dy "ZASOBNIK"
double tab[3]={2.4,2.3,6.789};
for(int i=0; i<3;i++)
  {
  cout << "Vlo�en� do z�sobn�ku: "<< tab[i] <<endl;
  s.push(tab[i]);
  }

for(int i=0; i<3;i++)
  {
  double z;
  s.pop(z);
  cout << "Vyjmut� ze z�sobn�ku "<< z <<endl;
  }
}
