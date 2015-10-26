#include <iostream>
using namespace std;

unsigned long int faktorial1(unsigned long int x)
{
if (x==0) 
   return 1; 
else
   return x*faktorial1(x-1);

}

unsigned long int  faktorial2(unsigned long int x, unsigned long int tmp=1)
{
if (x==0)  
   return tmp; 
else
   return faktorial2(x-1, x*tmp);
}


int main()
{
cout << "5!=" << faktorial1(5) << endl;
cout << "5!=" << faktorial2(5) << endl;
}
