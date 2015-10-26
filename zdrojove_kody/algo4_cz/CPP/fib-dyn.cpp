#include <iostream>
using namespace std;

unsigned long int  fib(int x)
{
if (x<2) 
   return x; 
else
   return fib(x-1)+fib(x-2);
}

void fib_dyn(int x, int f[])
{
f[0]=0;
f[1]=1;
for(int i=2; i<x; i++)
  f[i]=f[i-1]+f[i-2];
}

int main()
{
int f[100];
fib_dyn(16,f); // výpoèet 15 sousedních prvkù Fibonacciho posloupnosti
for(int i=0;i<=15;i++)
  cout << "fib("<<i<<")="<<fib(i) << "  " << f[i] << endl;
}
