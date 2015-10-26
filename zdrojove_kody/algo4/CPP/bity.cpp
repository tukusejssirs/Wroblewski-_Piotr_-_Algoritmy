#include <iostream>
using namespace std;

// --Przyk³adowe operacje na bitach
int main() 
{
	long int n;
	n=100;
	cout << " n = 100, n:4=" << (n/4) << endl; // klasycznie
	cout << " n = 100, n:4=" << (n>>2) << endl; //przesuwaj¹c bity
	n=17;
	cout << " n = 17, n*8=" << (n*8) << endl; //  klasycznie
	cout << " n = 17, n*8=" << (n<<3) << endl; // przesuwaj¹c bity

}



