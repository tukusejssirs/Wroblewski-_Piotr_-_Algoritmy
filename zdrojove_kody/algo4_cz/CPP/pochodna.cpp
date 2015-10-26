#include <iostream>
using namespace std;

const int n=5; // øád poèítaných centrálních rozdílù èiní n-1

#define TEST

double t[n][n+1]=
{
#ifdef TEST
{0.8, 4.80}, // dvojice (x[i], y[i]) pro y=5x*x+2*x
{0.9, 5.85}, // (zapsané jsou dva první sloupce a nikoli øádky)
{1,   7.00},
{1.1, 8.25},
{1.2, 9.60}
#else
{0.8, -0.22314}, // dvojice (x[i], y[i]) pro y = ln x
{0.9, -0.10536},
{1,    0},
{1.1,  0.09531},
{1.2,  0.18232}
#endif
};

struct DERIVACE{double f1,f2;};

DERIVACE stirling(double t[n][n+1])
// funkce vrací hodnoty f'(z) a f''(z) kde z je centrálním
// prvkem: zde t[2][0]; pole 't' je nutné pøedtím centrálnì
// inicializovat, jeho správnost se nekontroluje
{
DERIVACE res;
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
DERIVACE res=stirling(t);
cout << "f'=" << res.f1 << ", f''=" << res.f2 <<endl;
}

