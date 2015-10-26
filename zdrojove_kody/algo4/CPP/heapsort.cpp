#include <iostream>
using namespace std;
#include "sterta.h"

int main()
{
int i, tab[14]={12,3,-12,9,34,23,1,81,45,17,9,23,11,4};
Sterta s(14);
for (i=0; i<14; i++) 
	s.wstaw(tab[i]);
cout<<"sterta:\n";
s.pisz();
for (i=14; i>0; i--) 
	tab[i-1]=s.obsluz();
cout<<"tablica posortowana:\n";
for (i=0; i<14; i++)
	cout << "  " << tab[i];
}
