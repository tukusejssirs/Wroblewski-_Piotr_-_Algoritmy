#include "dziedzic.h"

class C3:public C1,C2
{
 int z;
public:
 C3(int n)  : C1(n+1),C2(n-1)
     { z= 2*n;}
 void pis();
 void pis_vse()
   {
    cout << "Všechny položky:\n";
    cout << "\t x="<<x<<endl;
    cout << "\t y="<< ret_y() <<endl;
    cout << "\t z="<<z<<endl;
    }
};

void C3::pis()
  {
   cout << "** nová verze metody 'pis': z="<<z<<" **\n";
  }


int main()
{
C3 ob(10);
ob.pis();

ob.C1::pis();

ob.pis_vse();
}


/*
 výsledek:

x=11
x=11
y=9
z=20

*/
