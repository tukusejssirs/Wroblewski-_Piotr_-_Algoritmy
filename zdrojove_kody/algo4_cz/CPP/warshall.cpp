#include <iostream>
using namespace std;

const int n=5;

int G[n][n];

void nuluj(int g[n][n])
{
for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
      g[i][j]=0;
}


void warshall(int g[n][n])
{
for(int x=0; x<n; x++)
  for(int y=0; y<n; y++)
    for(int z=0; z<n; z++)
       if(g[y][z]==0) g[y][z]=g[y][x]*g[x][z];
}

void vypis(char *nazev, int G[n][n])
{
int i, j;
cout << "Graf:" << nazev << endl;
for(i=0;i<n;i++)
  for(j=0;j<n;j++)
    {
    cout<<G[i][j]<<"  ";
    if(j==n-1) cout << endl;
    }
}

int main()
{
nuluj(G);

G[0][1]=1;G[0][3]=1;
G[1][3]=1;
G[2][1]=1;
G[3][2]=1;
G[4][1]=1;

vypis ("G - pred", G);
warshall(G);
vypis ("G - po", G);

}


