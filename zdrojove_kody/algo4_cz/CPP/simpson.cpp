#include <iostream>
using namespace std;
const int n=4; // poèet bodù = 2n+1

double fun(double x) {return x*x-3*x+1;}
// funkce x*x-3*x+1 v intervalu [-5,3]

double f[2*n+1]={41, 29, 19, 11, 5, 1, -1, -1, 1};

double simpson(double f[2*n+1], double a, double b)
// funkce vrací integrál funkce f(x) v intervalu [a,b],
// jejíž hodnoty jsou uvedeny tabulkovì v 2n+1 bodech
{
double s=0,h=(b-a)/(2.0*n);
for(int i=0;i<2*n;i+=2) // skok co dva body
  s+=h*(f[i]+4*f[i+1]+f[i+2])/3.0;
return s;
}

double simpson_f(double(*f)(double), double a, double b,int N)
// funkce vrací integrál funkce f(x) známé v podobì vzorce
// na intervalu [a, b], N - poèet èástí
{
double s=0,h=(b-a)/(double)N;
for(int i=1;i<=N;i++)
  s+=h*(f(a+(i-1)*h)+4*f(a-h/2.0+i*h)+f(a+i*h))/6.0;
return s;
}


int main()
{
cout << "Hodnota integrálu =" << simpson(f,-5,3) << endl; // 82.667
cout << "Hodnota integrálu =" << simpson_f(fun,-5,3,8) << endl; // 82.667

}

