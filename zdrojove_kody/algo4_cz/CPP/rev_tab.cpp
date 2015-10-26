#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
int temp=a;
a=b;
b=temp;
}

void obrat(int *tab, int left, int right)
{
if(left<right)
 {
 swap(tab[left],tab[right]);  // vymìòujeme krajní prvky
 obrat(tab,left+1,right-1); // obracíme zbytek
 }
}
int main()
{
int tabl[8]={1,2,3,4,5,6,7,8};
for(int i=0;i<8;i++)
   cout << tabl[i] << "  "; cout << endl;
obrat(tabl,0,7);
for(int i=0;i<8;i++)
   cout << tabl[i] << "  "; cout << endl;
}

