#include <iostream>
using namespace std;
const int n=10;
int   tab[n]={1, 2, 3, 2, -7, 44, 5, 1, 0, -3};

void hledej(int tab[n],int left,int right,int x){
// left, right  = lev� a prav� hranice prohled�van� oblasti
// tab          = pole
// x            = hledan� hodnota
if (left>right)
cout << "Prvek " << x << " nebyl nalezen\n";
else
   if (tab[left]==x)
      cout << "Byl nalezen hledan� prvek "<< x << endl;
   else
      hledej(tab,left+1,right,x);
}

int main()
{
hledej(tab,0,n-1,7);
hledej(tab,0,n-1,5);


}

// v�sledky programu:
// Prvek 7 nebyl nalezen
// Hledan� prvek byl nalezen

