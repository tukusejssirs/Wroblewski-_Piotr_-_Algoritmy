#include <iostream>
#include <math.h>
using namespace std;

const double epsilon=0.00000001;
double hodn(double x, double yn)
{
double yn1=2*yn-x*yn*yn;
if( fabs(yn-yn1)<epsilon)
   return yn1;
else
   return hodn(x,yn1);
}
int main()
{
cout << "Funkce y=1/x m� pro x=7 hodnotu "<<hodn(7,0.1);  // v�sledek: 14.2857
}
