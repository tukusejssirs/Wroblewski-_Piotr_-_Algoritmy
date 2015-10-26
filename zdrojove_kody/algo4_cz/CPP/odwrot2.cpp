#include <iostream>
using namespace std;

int a,b;

void P2()
{
if(a!=0) 
   { 
      a--; 
      P2(); 
      b=b+(++a);
   }
  else b=1;
}

void P2_ITERAT()
{
int k=0;
while (a!=0) 
   {
      a--;
      k++;
}
b=1;
while (k--!=0) 
   b=b+(++a);
}

int main()
{

for (int i=0; i<17;i++)
 {
  a=i;
  P2();
  cout << b << "  ";
 }
cout << endl;

for (int i=0; i<17;i++)
 {
  a=i;
  P2_ITERAT();
  cout << b << "  ";
 }
cout << endl;

}


