#include <iostream>
using namespace std;

int silnia(int x, int res=1)
{
if (x==0) 
	return res; 
else
   silnia(x-1,x*res);
}

int silnia_it(int x,int res=1)
{
while (x!=0)
  {
  res=x*res;
  x--;
  }
return res;
}


int main()
{
cout << "silnia(5)="<<  silnia(5) << endl;
cout << "silnia(5)="<<  silnia_it(5) << endl;
}
