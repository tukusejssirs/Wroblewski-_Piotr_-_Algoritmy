#include <iostream>
using namespace std;
unsigned long int cpt=0;

unsigned long int  MacCarthy(int x)
{
cpt++;
if (x>100) 
   return (x-10); 
else
   return  MacCarthy(MacCarthy(x+11));
}

int main()
{
int x;
cout << "Zadejte hodnotu x ";
cin  >> x;
cout << "MacCarthy(" << x << ")=" << MacCarthy(x);
cout << " [poèet volání funkce: "<<  cpt << " ]\n";
}
