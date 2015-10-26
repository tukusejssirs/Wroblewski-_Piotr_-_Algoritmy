#include <iostream>
using namespace std;
const	int n=10;
int	tab[n]={1, 2, 3, 2, -7, 44, 5, 1, 0, -3};

void szukaj(int tab[n],int left,int right,int x){
// left, right  = lewa i prawa granica obszaru poszukiwañ
// tab          = tablica
// x            = wartoœæ do odnalezienia
if (left>right)
cout << "Element " << x << " nie zosta³ odnaleziony\n";
else
	if (tab[left]==x)
		cout << "Znalaz³em szukany element "<< x << endl;
	else
		szukaj(tab,left+1,right,x);
}

int main()
{
szukaj(tab,0,n-1,7);
szukaj(tab,0,n-1,5);


}

// wyniki programu:
// Element 7 nie zosta³ odnaleziony
// Znalaz³em szukany element

