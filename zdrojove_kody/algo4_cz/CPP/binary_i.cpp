#include <iostream>
using namespace std;

const int n=12;

int tab[n]={1, 2, 6, 18, 20, 23, 29, 32, 34, 39, 40, 41};

int hledej(int tab[],int x)
{ // vrácení indexu hledané hodnoty nebo èísla -1
enum {ANO,NE} Nalezeno=NE;

int left=0, right=n-1, mid;

while( (left<=right) && (Nalezeno!=ANO) )
{
mid=(left+right)/2;
if(tab[mid]==x)
   Nalezeno=ANO;
else
   if(tab[mid]<x)
      left=mid+1;
   else
      right=mid-1;
}

if(Nalezeno==ANO)
   return mid;
else
   return -1;
}

int main()
{
cout << hledej(tab,29)<<endl;
}

