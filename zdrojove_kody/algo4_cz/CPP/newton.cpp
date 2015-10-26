#include <iostream>
using namespace std;

const double epsilon=0.0001;

double f(double x)      // funkce f(x)=3x2-2
{
   return 3*x*x-2;
}

double fp(double x)     // derivace f’(x)=(3x2-2)’=6x
{
   return 6*x;
}

double nula(double x0, double(*f)(double), double(*fp)(double) )
 {
 if( fabs( f(x0) ) <epsilon)
   return x0;
 else
   return nula(x0-f(x0)/fp(x0),f,fp);
 }

int main()
{
cout << "Nulový bod funkce 3x*x-2 se rovná "<<nula(1,f,fp)<<endl; // výsledek 0,816497
}
