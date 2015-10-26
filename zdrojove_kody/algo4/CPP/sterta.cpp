#include <iostream>
using namespace std;

#include "sterta.h"
int main()
{
int i, tab[14]={12,3,-12,9,34,23,1,81,45,17,9,23,11,4};
Sterta s(14);
for (i=0;i<14;i++) 
 s.wstaw(tab[i]);
for (i=14;i>0;i--)
 tab[i-1]=s.obsluz();
cout<<"Tablica posortowana:\n";
for (i=0;i<14;i++)
   cout << "  " << tab[i];
/*
int x,t[12]={37,41,26,14,19,99,23,17,12,20,25,42};
Sterta s(100);

for(int i=1;i<=12;i++)
	s.wstaw(t[i-1]);
cout<<"nowa sterta:\n";
s.pisz();
s.obsluz();s.obsluz();
cout<<"sterta po 2-krotnej obs³udze:\n";
s.pisz();
*/
}
//------------------------------------------------------------
