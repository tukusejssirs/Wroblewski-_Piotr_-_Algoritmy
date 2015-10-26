#include <iostream>
using namespace std;

const int n=7;

int G[n][n]; // graf
int R[n][n]; // macierz kierowania ruchem


void initG()
{
for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
		G[i][j]=10000; // umowna "nieskonczonoœæ"
}

void initR()
{
for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
		R[i][j]=0; // brak drogi
}


void zeruj(int g[n][n])
{
for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		g[i][j]=0;
}

void floyd(int g[n][n])
{
for(int k=0;k<n;k++)
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if( g[i][k]+g[k][j]<g[i][j])
	    {
		 g[i][j]=g[i][k]+g[k][j];
		 R[i][j]=k;
		}
}

void droga(int i, int j)
{
int k = R[i][j];
if (k != 0)
 {
  droga(i,k);
    cout << k << "  ";
  droga(k,j);
  }
}



int main()
{
initG();// zerowanie grafu, wszêdzie G[i][j] = nieskoñczonoœæ
initR();// zerowanie matrycy kierowania ruchem, wszêdzie R[i][j]=0

G[0][3]=30; G[0][1]=10; G[1][2]=15; G[1][4]=40; G[2][3]=5;
G[2][4]=20; G[4][5]=20; G[4][6]=10; G[5][6]=5;  G[6][3]=25;

floyd(G); // wywo³anie algorytmu i jego sprawdzenie:

for(int i=0; i<n; i++)
   for(int j=0; j<n; j++)
     {
     if(G[i][j]==10000) 
		cout << i << "  -->  " << j << "[drogi nie ma]\n";
	else
		if(i!=j) 
		{
		 cout << i << "  -->  " << j << "="<<G[i][j]<<", droga przez: ";
		 droga(i,j);
		 cout << endl;
		}
     }
}
