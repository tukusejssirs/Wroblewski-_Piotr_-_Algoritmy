#include <iostream>
using namespace std;
unsigned long int  silnia(int x){
if (x==0)
	return 1; 
else
	return x*silnia(x-1);
}

int main()
{
cout << "silnia(5)="<<  silnia(5) << endl;
}

//  wyniki programu:
// silnia(5)=120
