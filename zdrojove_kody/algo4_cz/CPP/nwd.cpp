// nejvìtší spoleèný dìlitel

#include <iostream>
using namespace std;

// verze 1

int nsd1 (int a, int b)
  {
  if (b>a) 
   return nsd1 (a, b-a);
  if (b<a) 
   return nsd1 (a-b, b);
  if (a==b) 
   return b;
}

// verze 2;

int nsd2 (int a, int b)
  {
  if (b==0) 
     return a;
  else
      return nsd2(b, a % b); // modulo
}


int main()
{

cout << " Metoda 1\n";

cout << " nsd(12,3)=" << nsd1(12,3) << ",";
cout << " nsd(24,30)=" << nsd1(24,30) << ",";
cout << " nsd(5,7)=" << nsd1(5,7) << ",";
cout << " nsd(54,69)=" << nsd1(54,69) << endl;

cout << " Metoda 2\n";

cout << " nsd(12,3)=" << nsd2(12,3) << ",";
cout << " nsd(24,30)=" << nsd2(24,30) << ",";
cout << " nsd(5,7)=" << nsd2(5,7) << ",";
cout << " nsd(54,69)=" << nsd2(54,69) << endl;

}
//-----------------------------------------------------------------------
