#include <iostream>
using namespace std;

int CestaNaVecnost(int n)
{
if (n==1) 
   return 1; 
else
   if ( (n %2) == 0 ) // n sudé
      return CestaNaVecnost(n-2)*n;
         else
      return CestaNaVecnost(n-1)*n;
}

int main()
{
cout << CestaNaVecnost(2) << endl;
}

