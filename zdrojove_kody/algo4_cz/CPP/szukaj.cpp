#include <iostream>
using namespace std;
const int n=10;

int   tab[n]={1,2,3,2,-7,44,5,1,0,-3};

int hledej(int tab[n],int x)
{
int pos=0;
while ((pos<n) && (tab[pos]!=x)) pos++;
if(pos<n) 
   return pos; // prvek byl nalezen
else
   return -1;  // prvek nebyl nalezen
}

int main()
{
cout << hledej(tab,7) <<endl; // výsledek = -1
cout << hledej(tab,5) <<endl; // výsledek =  6
}
