#include <iostream>
using namespace std;

int faktorial(int x, int res=1)
{
if (x==0) 
   return res; 
else
   faktorial(x-1,x*res);
}

int faktorial_it(int x,int res=1)
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
cout << "faktorial(5)="<<  faktorial(5) << endl;
cout << "faktorial(5)="<<  faktorial_it(5) << endl;
}
