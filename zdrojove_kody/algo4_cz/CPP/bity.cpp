#include <iostream>
using namespace std;

// --Ukázkové operace s bity
int main() 
{
   long int n;
   n=100;
   cout << " n = 100, n:4=" << (n/4) << endl; // klasicky
   cout << " n = 100, n:4=" << (n>>2) << endl; // s bitovým posunem
   n=17;
   cout << " n = 17, n*8=" << (n*8) << endl; //  klasicky
   cout << " n = 17, n*8=" << (n<<3) << endl; // s bitovým posunem

}



