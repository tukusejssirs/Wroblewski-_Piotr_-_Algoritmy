#include <iostream>
using namespace std;
#include <math.h> // z uwagi na fabs

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
for(int i=0; i<N; i++) // eliminacja
  {
  max=i;
  for(int j=i+1; j<N; j++)
	 if(fabs(a[j][i])>fabs(a[max][i]))
		max=j;
  for(int k=i; k<N+1; k++) // zamiana wierszy wartoœciami
	 {
	 tmp=a[i][k];
		  a[i][k]=a[max][k];
		  a[max][k]=tmp;
	 }
  if(a[i][i]==0)
    return 0;  // Uk³ad sprzeczny!

  for(int j=i+1; j<N; j++)
   for(int k=N; k>=i; k--) // mno¿enie wiersza j przez wspó³czynnik "zeruj¹cy":
	  a[j][k]=a[j][k]-a[i][k]*a[j][i]/a[i][i];
  }

#ifdef TEST
  cout << "MACIERZ TRÓJK¥TNA\n";
  for(int i=0;i<N;i++)
	{
	for(j=0;j<=N;j++)
		cout << a[i][j] << ", ";
	cout << endl;
  }
#endif
for(int j=N-1; j>=0; j--) // redukcja wsteczna
  {
  tmp=0;
  for(int k=j+1; k<=N; k++)
	  tmp=tmp+a[j][k]*x[k];
  x[j]=(a[j][N]-tmp)/a[j][j];
  }
 return 1;  // wszystko w porz¹dku!
}

int main()
{
if(!gauss(a,x))
	cout << "Uk³ad (1) jest sprzeczny!\n";
else
  {
  cout << "Rozwi¹zanie:\n";
  for(int i=0;i<N;i++)
  cout << "x["<<i<<"]="<<x[i] << endl;
  }

if(!gauss(as,x))
	cout << "Uk³ad (2) jest sprzeczny!\n";
}

