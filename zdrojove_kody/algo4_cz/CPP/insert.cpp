#include <iostream>
using namespace std;

const int n=12;

int tab[n]={40,2,1,6,18,20,29,32,23,34,39,41};

void swap(int& a, int &b) // výmìna obou prvkù
{
int temp=a;
a=b;
b=temp;
}

void InsertSort(int *tab)
{
for(int i=1; i<n; i++)
 {
 int j=i; // èást 0..i-1 je už setøídìná
 int temp=tab[j];
 while ((j>0) && (tab[j-1]>temp))
    {
    tab[j]=tab[j-1];
    j--;
    }
 tab[j]=temp;
 }
}

int main()
{
for (int i=0;i<n;i++)
   cout << tab[i] <<"   ";
cout << endl;
InsertSort(tab);
for (int i=0; i<n; i++)
  cout << tab[i] <<"   ";;
cout << endl;
}


