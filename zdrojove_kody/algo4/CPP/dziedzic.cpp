#include "dziedzic.h"

class C3:public C1,C2
{
 int z;
public:
 C3(int n)  : C1(n+1),C2(n-1)
	  { z= 2*n;}
 void pisz();
 void pisz_wszystko()
	{
	 cout << "Wszystkie pola:\n";
	 cout << "\t x="<<x<<endl;
	 cout << "\t y="<< ret_y() <<endl;
	 cout << "\t z="<<z<<endl;
	 }
};

void C3::pisz()
  {
	cout << "** nowa wersja metody 'pisz': z="<<z<<" **\n";
  }


int main()
{
C3 ob(10);
ob.pisz();

ob.C1::pisz();

ob.pisz_wszystko();
}


/*
 wynik:

x=11
x=11
y=9
z=20

*/
