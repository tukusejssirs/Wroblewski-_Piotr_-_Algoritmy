#include <iostream>
using namespace std;

unsigned long int  fib(int x){
if (x<2)
	return x;
else
	return fib(x-1)+fib(x-2);
}

int main()
{
for (int i=1; i < 15; i++)
   cout << "fib[" << i << "]=" <<  fib(i) << endl;
}
