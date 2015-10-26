#include <iostream>
using namespace std;

const double epsilon=0.0001;

double f(double x)		// funkcja f(x)=3x2-2
{
	return 3*x*x-2;
}

double fp(double x)		// pochodna f’(x)=(3x2-2)’=6x
{
	return 6*x;
}

double zero(double x0, double(*f)(double), double(*fp)(double) )
 {
 if( fabs( f(x0) ) <epsilon)
	return x0;
 else
	return zero(x0-f(x0)/fp(x0),f,fp);
 }

int main()
{
cout << "Zero funkcji 3x*x-2 wynosi "<<zero(1,f,fp)<<endl;//wynik 0,816497
}
