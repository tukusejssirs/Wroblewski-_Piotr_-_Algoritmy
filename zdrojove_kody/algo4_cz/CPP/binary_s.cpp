#include <iostream>
using namespace std;

int hledej_rek(int * tab, int x, int left, int right)
{
if(left>right) return -1; // prvek nebyl nalezen
   else
    {
   int mid=(left+right)/2;
    if(tab[mid]==x) 
      return mid; // prvek byl nalezen!
   else
      if(x<tab[mid])
         return hledej_rek(tab,x,left,mid-1); 
            else
         return hledej_rek(tab,x,mid+1,right);
      }
}

int main()
{
int tabl[12]={1,2,6,18,20,23,29,32,34,39,40,41};
cout << "výsledek="<<hledej_rek(tabl,23,0,11)<<endl;
}

