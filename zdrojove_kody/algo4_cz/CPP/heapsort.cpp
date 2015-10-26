#include <iostream>
using namespace std;
#include "sterta.h"

int main()
{
int i, tab[14]={12,3,-12,9,34,23,1,81,45,17,9,23,11,4};
Halda s(14);
for (i=0; i<14; i++) 
   s.vloz(tab[i]);
cout<<"Halda:\n";
s.pis();
for (i=14; i>0; i--) 
   tab[i-1]=s.obsluz();
cout<<"Setøídìné pole:\n";
for (i=0; i<14; i++)
   cout << "  " << tab[i];
}
