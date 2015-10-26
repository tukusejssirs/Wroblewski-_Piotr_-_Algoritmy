#include <iostream>
using namespace std;

const int n=8;
inline void swap(int& a, int &b) // zamieñ elementy ze sob¹
{
int temp=a;
 a=b;
 b=temp;
}
//----------------------------------------
int tab[n]={7,6,3,2,1,6,5,4};
void wypisz(int t[])
{
for (int i=0; i<n; i++)
cout << tab[i] <<"   ";;
cout << endl;
}
//----------------------------------------
void ShakerSort(int *tab)
{
int left=1, right=n-1, k=n-1;
do
{
for(int j=right; j>=left; j--)
  if(tab[j-1]>tab[j])
	{
	swap(tab[j-1],tab[j]);
	k=j;
	}
left=k+1;
for(int j=left; j<=right; j++)
  if(tab[j-1]>tab[j])
	{
	swap(tab[j-1],tab[j]);
	k=j;
	}
right=k-1;
}
while (left<=right);
}
//----------------------------------------
int main()
{
wypisz(tab);
ShakerSort(tab);
wypisz(tab);
}
//----------------------------------------
