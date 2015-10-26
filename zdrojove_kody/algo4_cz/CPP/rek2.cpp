#include <iostream>
using namespace std;
unsigned long int  faktorial(int x){
if (x==0)
   return 1; 
else
   return x*faktorial(x-1);
}

int main()
{
cout << "faktorial(5)="<<  faktorial(5) << endl;
}

// výsledky programu:
// faktorial(5)=120
