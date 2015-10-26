#include <iostream>
using namespace std;

#include "sterta.h"
int main()
{
int i, tab[14]={12,3,-12,9,34,23,1,81,45,17,9,23,11,4};
Halda s(14);
for (i=0;i<14;i++) 
 s.vloz(tab[i]);
for (i=14;i>0;i--)
 tab[i-1]=s.obsluz();
cout<<"Setøídìné pole:\n";
for (i=0;i<14;i++)
   cout << "  " << tab[i];
/*
int x,t[12]={37,41,26,14,19,99,23,17,12,20,25,42};
Halda s(100);

for(int i=1;i<=12;i++)
   s.vloz(t[i-1]);
cout<<"Nová halda:\n";
s.pis();
s.obsluz();s.obsluz();
cout<<"Halda po dvojí obsluze:\n";
s.pis();
*/
}
//------------------------------------------------------------
