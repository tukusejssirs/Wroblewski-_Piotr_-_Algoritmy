#include <iostream>
using namespace std;
const int n=5;	// stopieñ wielomianu
// -----------------------------------------
int oblicz_wielomian(int a, int w[], int rozm)
{ // metoda klasyczna
int res=0,pot=1;
for(int j=rozm-1;j>=0;j--)
	 {
	 res+=pot*w[j];  		// sumy cz¹stkowe
	 pot*=a; 			  	// nastêpna potêga a
	 }
return res;
}
// -----------------------------------------
int oblicz_wielomian_H(int a,int w[],int rozm)
// schemat Hornera
{
int res=w[0];
for(int j=1; j<rozm; res=res*a+w[j++]);
return res;
}
// -----------------------------------------
int main()
{
int w[n]={1,4,-2,0,7}; 	// wspó³czynniki wielomianu
cout << oblicz_wielomian(2,w,n) << endl;
cout << oblicz_wielomian_H(2,w,n) << endl;
}
