#include <iostream>
using namespace std;

int pot1(int x, int n)
{
if (n==0) 
	return 1; 
else 
	return (pot1(x,n-1)*x);
}

int pot2(int x,int n,int temp=1)
{
if (n==0) 
	return temp; 
else
    return (pot2(x,n-1,temp*x));
}

int main()
{
cout << "Dwa do potêgi trzeciej\n";
cout << "Metoda 1\t" << pot1(2,3)<< "\n";
cout << "Metoda 2\t" << pot2(2,3)<< "\n";
}

