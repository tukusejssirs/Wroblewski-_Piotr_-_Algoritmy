#include <iostream>
using namespace std;


#include "complex.h"
// ------------------------------------------------------------------
void Complex::wypisz()
   {
   cout << Re << "+j*" << Im << endl;
}
// ------------------------------------------------------------------
Complex& operator +(Complex x,Complex y)
{
double tmp_Re=x.Czesc_Rzecz()+y.Czesc_Rzecz();
double tmp_Im=x.Czesc_Uroj() +y.Czesc_Uroj();
Complex *NowyObiekt=new Complex(tmp_Re,tmp_Im);
return (*NowyObiekt);
}
// ------------------------------------------------------------------
ostream& operator << (ostream &str,Complex x)
{
str << x.Czesc_Rzecz() << "+j*" << x.Czesc_Uroj();
return str;
}
// ------------------------------------------------------------------
int main()
{
Complex c1(1,2),c2(3,4);
cout << "c1="; c1.wypisz();
cout << "c2="; c2.wypisz();
cout << "c1+c2="<<(c1+c2) << endl;
Complex *c_ptr=new Complex(1,7);
cout << "a) c_ptr wskazuje na obiekt "; c_ptr->wypisz();
cout << "b) c_ptr wskazuje na obiekt " << *c_ptr << endl;
}
