#include "dziedzic.h"

class C3:public C1,C2
{
 int z;
public:
 C3(int n)  : C1(n+1),C2(n-1)
     { z= 2*n;}
 void pisz();
 pisz_wszystko()
   {
    cout << "x="<<x<<endl;
    cout << "y="<< ret_y() <<endl;
    cout << "z="<<z<<endl;
    }
};

void C3::pisz() { cout << "nowa wersja metody `pisz'\n";}


void main()
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
