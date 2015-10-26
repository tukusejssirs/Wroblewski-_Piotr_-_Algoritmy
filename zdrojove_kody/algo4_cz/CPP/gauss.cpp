#include <iostream>
using namespace std;
#include <math.h> // kvùli funkci fabs

const int N=3;
double x[N];

double a[N][N+1]=
{
  {5 ,  0,  1, 9},
  {1 ,  1,-1,  6},
  {2,  -1, 1,  0}
};

double as[N][N+1]=
{
  {1 ,  1,  1, 9},
  {0 ,  1, 1,  6},
  {0,   1, 1,  4}
};


int gauss(double a[N][N+1], double x[N])
{
int max;
double tmp;
for(int i=0; i<N; i++) // eliminace
  {
  max=i;
  for(int j=i+1; j<N; j++)
    if(fabs(a[j][i])>fabs(a[max][i]))
      max=j;
  for(int k=i; k<N+1; k++) // nahrazení øádkù hodnotami
    {
    tmp=a[i][k];
        a[i][k]=a[max][k];
        a[max][k]=tmp;
    }
  if(a[i][i]==0)
    return 0;  // soustava nemá øešení

  for(int j=i+1; j<N; j++)
   for(int k=N; k>=i; k--) // násobení øádku j "nulujícím" koeficientem:
     a[j][k]=a[j][k]-a[i][k]*a[j][i]/a[i][i];
  }

#ifdef TEST
  cout << "TROJÚHELNÍKOVÁ MATICE\n";
  for(int i=0;i<N;i++)
   {
   for(j=0;j<=N;j++)
      cout << a[i][j] << ", ";
   cout << endl;
  }
#endif
for(int j=N-1; j>=0; j--) // zpìtná redukce
  {
  tmp=0;
  for(int k=j+1; k<=N; k++)
     tmp=tmp+a[j][k]*x[k];
  x[j]=(a[j][N]-tmp)/a[j][j];
  }
 return 1;  // všechno v poøádku
}

int main()
{
if(!gauss(a,x))
   cout << "Rovnice (1) nemá øešení!\n";
else
  {
  cout << "Øešení:\n";
  for(int i=0;i<N;i++)
  cout << "x["<<i<<"]="<<x[i] << endl;
  }

if(!gauss(as,x))
   cout << "Rovnice (2) nemá øešení!\n";
}

