#include <iostream>
#include <stdlib.h>
using namespace std;

int comp(const void *x, const void *y)
{
int xx=*(int*)x; // jawna konwersja z typu
int yy=*(int*)y; // 'void*' do 'int*'
if( xx <  yy)  
	return -1;
if( xx == yy)  
	return  0;
else
    return 1;
}
const int n=12;
int tab[n]={40,29,2,1,6,18,20,32,34,39,23,41};

int main()
{
for (int i=0; i<n; i++)
	cout << tab[i] <<"   ";
cout << endl;
qsort(tab, n, sizeof(int), comp);
for (int i=0; i<n; i++)
	cout << tab[i] <<"   ";;
cout << endl;
}
