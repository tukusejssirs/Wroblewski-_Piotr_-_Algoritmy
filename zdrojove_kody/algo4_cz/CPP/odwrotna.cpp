#include <iostream>
using namespace std;

void P1(int a,int& b)
{
if(a==0) 
   b=1; 
else
   {
   P1(a-1,b);
   b=b+a;
   }
}


int a,b; // globální promìnné!

void P2()
{
if(a==0) 
   b=1; 
else
   {
   a=a-1;
   P2();
   a=a+1;
   b=b+a;
   }
}

int main()
{

for (int i=0; i<17;i++)
 {
  P1(i,b);
  cout << b << "  ";
 }

cout << endl;

for (int i=0; i<17;i++)
 {
  a=i;
  P2();
  cout << b << "  ";
 }
cout << endl;
}
