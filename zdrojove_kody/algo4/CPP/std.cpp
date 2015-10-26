#include <iostream>
using namespace std;

int StadDoWiecznosci(int n)
{
if (n==1) 
	return 1; 
else
	if ( (n %2) == 0 ) // n parzyste
		return StadDoWiecznosci(n-2)*n;
			else
		return StadDoWiecznosci(n-1)*n;
}

int main()
{
cout << StadDoWiecznosci(2) << endl;
}

