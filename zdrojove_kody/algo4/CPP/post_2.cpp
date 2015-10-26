#include <iostream>
using namespace std;

typedef unsigned long int UINT;

void post_dw(UINT n)
{
if(n!=0)
 {
 post_dw(n/2); // n modulo 2
 cout << n % 2;  // reszta z dzielenia przez 2
 }
}

int main()
{
post_dw(66);
}

