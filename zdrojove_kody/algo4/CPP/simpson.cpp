#include <iostream>
using namespace std;
const int n=4; // liczba punktów= 2n+1

double fun(double x) {return x*x-3*x+1;}
// funkcja x*x-3*x+1 w przedziale [-5,3]

double f[2*n+1]={41, 29, 19, 11, 5, 1, -1, -1, 1};

double simpson(double f[2*n+1], double a, double b)
// funkcja zwraca ca³kê funkcji f(x) w przedziale [a,b],
// której wartoœci s¹ podane tabelatycznie w 2n+1 punktach
{
double s=0,h=(b-a)/(2.0*n);
for(int i=0;i<2*n;i+=2) // skok cp dwa punkty!
  s+=h*(f[i]+4*f[i+1]+f[i+2])/3.0;
return s;
}

double simpson_f(double(*f)(double), double a, double b,int N)
// funkcja zwraca ca³kê znanej w postaci wzoru funkcji f(x)
// w przedziale [a,b], N - iloœæ podzia³ów
{
double s=0,h=(b-a)/(double)N;
for(int i=1;i<=N;i++)
  s+=h*(f(a+(i-1)*h)+4*f(a-h/2.0+i*h)+f(a+i*h))/6.0;
return s;
}


int main()
{
cout << "Wartoœæ ca³ki =" << simpson(f,-5,3) << endl; // 82.667
cout << "Wartoœæ ca³ki =" << simpson_f(fun,-5,3,8) << endl; // 82.667

}

