#include <iostream>
using namespace std;

unsigned long int silnia1(unsigned long int x)
{
if (x==0) 
	return 1; 
else
	return x*silnia1(x-1);

}

unsigned long int  silnia2(unsigned long int x, unsigned long int tmp=1)
{
if (x==0)  
	return tmp; 
else
	return silnia2(x-1, x*tmp);
}


int main()
{
cout << "5!=" << silnia1(5) << endl;
cout << "5!=" << silnia2(5) << endl;
}
