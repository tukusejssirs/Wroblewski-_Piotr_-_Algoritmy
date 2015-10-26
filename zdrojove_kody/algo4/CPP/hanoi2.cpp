#include <iostream>
using namespace std;


void hanoi2(int n, int a, int b)
{
while (n!=1)
	{
	hanoi2(n-1,a,3-a-b);
	cout << "Przesuñ dysk nr."<< n << " z " << a << " na "<< b <<endl;
	n=n-1;
	a=3-a-b;
	}
cout << "Przesuñ dysk nr.1 z " << a << " na "<< b <<endl;
}

int main()
{
hanoi2(4,0,1);
}
