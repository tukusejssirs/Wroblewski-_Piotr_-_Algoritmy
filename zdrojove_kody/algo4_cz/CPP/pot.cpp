#include <iostream>
using namespace std;

int moc1(int x, int n)
{
if (n==0) 
   return 1; 
else 
   return (moc1(x,n-1)*x);
}

int moc2(int x,int n,int temp=1)
{
if (n==0) 
   return temp; 
else
    return (moc2(x,n-1,temp*x));
}

int main()
{
cout << "Dvì na tøetí\n";
cout << "Metoda 1\t" << moc1(2,3)<< "\n";
cout << "Metoda 2\t" << moc2(2,3)<< "\n";
}

