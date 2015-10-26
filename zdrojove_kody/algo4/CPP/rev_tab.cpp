#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
int temp=a;
a=b;
b=temp;
}

void odwroc(int *tab, int left, int right)
{
if(left<right)
 {
 swap(tab[left],tab[right]); // zamieniamy elementy skrajne
 odwroc(tab,left+1,right-1); // odwracamy resztê
 }
}
int main()
{
int tabl[8]={1,2,3,4,5,6,7,8};
for(int i=0;i<8;i++)
	cout << tabl[i] << "  "; cout << endl;
odwroc(tabl,0,7);
for(int i=0;i<8;i++)
	cout << tabl[i] << "  "; cout << endl;
}

