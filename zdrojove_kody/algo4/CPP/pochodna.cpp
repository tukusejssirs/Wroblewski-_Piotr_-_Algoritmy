#include <iostream>
using namespace std;

const int n=5; // rz¹d obliczanych ró¿nic centralnych wynosi n-1

#define TEST

double t[n][n+1]=
{
#ifdef TEST
{0.8, 4.80}, // pary (x[i], y[i]) dla y=5x*x+2*x
{0.9, 5.85}, // (wpisane s¹ dwie pierwsze kolumy, a nie wiersze)
{1,   7.00},
{1.1, 8.25},
{1.2, 9.60}
#else
{0.8, -0.22314}, // pary (x[i], y[i]) dla y = ln x
{0.9, -0.10536},
{1,    0},
{1.1,  0.09531},
{1.2,  0.18232}
#endif
};

struct POCHODNE{double f1,f2;};

POCHODNE stirling(double t[n][n+1])
// funkcja zwraca wartoœci f'(z) i f''(z) gdzie z jest elementem
// centralnym: tutaj t[2][0]; tablica 't' musi byæ uprzednio centralnie
// zainicjowana, jej poprawnoœæ nie jest sprawdzana
{
POCHODNE res;
double h=(t[4][0]-t[0][0])/(double)(n-1);  // krok argumentu 'x'
for(int j=2;j<=n;j++)
	for(int i=0;i<=n-j;i++)
		t[i][j]=t[i+1][j-1]-t[i][j-1];
		res.f1=((t[1][2]+t[2][2])/2.0-(t[0][4]+t[1][4])/12.0)/h;
		res.f2=(t[1][3]-t[0][5]/12.0)/(h*h);
	return res;
}


int main()
{
POCHODNE res=stirling(t);
cout << "f'=" << res.f1 << ", f''=" << res.f2 <<endl;
}

