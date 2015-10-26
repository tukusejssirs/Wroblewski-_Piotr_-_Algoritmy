#include <iostream>
#include <math.h>
using namespace std;

const double epsilon=0.00000001;
double wart(double x, double yn)
{
double yn1=2*yn-x*yn*yn;
if( fabs(yn-yn1)<epsilon)
	return yn1;
else
	return wart(x,yn1);
}
int main()
{
cout << "Wartoœæ funkcji y=1/x dla x=7 wynosi "<<wart(7,0.1);  // wynik: 14.2857
}
