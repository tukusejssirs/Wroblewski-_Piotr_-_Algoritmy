#include <iostream>
using namespace std;


#include "complex.h"
// ------------------------------------------------------------------
void Complex::vypis()
   {
   cout << Re << "+j*" << Im << endl;
}
// ------------------------------------------------------------------
Complex& operator +(Complex x,Complex y)
{
double tmp_Re=x.Cast_Real()+y.Cast_Real();
double tmp_Im=x.Cast_Imag() +y.Cast_Imag();
Complex *NovyObjekt=new Complex(tmp_Re,tmp_Im);
return (*NovyObjekt);
}
// ------------------------------------------------------------------
ostream& operator << (ostream &str,Complex x)
{
str << x.Cast_Real() << "+j*" << x.Cast_Imag();
return str;
}
// ------------------------------------------------------------------
int main()
{
Complex c1(1,2),c2(3,4);
cout << "c1="; c1.vypis();
cout << "c2="; c2.vypis();
cout << "c1+c2="<<(c1+c2) << endl;
Complex *c_ukz=new Complex(1,7);
cout << "a) c_ukz odkazuje na objekt "; c_ukz->vypis();
cout << "b) c_ukz odkazuje na objekt " << *c_ukz << endl;
}
