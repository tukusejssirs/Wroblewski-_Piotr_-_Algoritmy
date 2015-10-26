#include "dziedzic.h"

class C3:public C1,C2
{
 int z;
public:
 C3(int n)  : C1(n+1),C2(n-1)
     { z= 2*n;}
 void pis();
 pis_vse()
   {
    cout << "x="<<x<<endl;
    cout << "y="<< ret_y() <<endl;
    cout << "z="<<z<<endl;
    }
};

void C3::pis() { cout << "Nová verze metody 'pis'\n";}


void main()
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
