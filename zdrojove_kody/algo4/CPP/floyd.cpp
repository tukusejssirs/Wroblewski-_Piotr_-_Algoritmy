#include <iostream>
using namespace std;

const int n=7;
int G[n][n];

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
      g[i][j]=min( g[i][j], g[i][k]+g[k][j]);
}

int main()
{
for(int i=0;i<n;i++) // inicjalizacja grafu
   for(int j=0;j<n;j++)
		G[i][j]=10000; // 10000 = "nieskoñczonoœæ"
G[0][3]=30; G[0][1]=10; // graf, jak na rysunku w ksi¹¿ce
G[1][2]=15; G[1][4]=40;
G[2][3]=5;  G[2][4]=20; G[4][5]=20; 
G[4][6]=10; G[5][6]=5;  G[6][3]=25;

floyd(G); // Wywo³ujemy algorytm i sprawdzamy wynik:
for(int i=0; i<n; i++)
   for(int j=0; j<n; j++)
     {
     if(G[i][j]==10000) cout << i << "  -->  " << j << "[drogi nie ma]\n";
		else
     if(i!=j) cout << i << "  -->  " << j << "="<<G[i][j]<<endl;
     }
}
