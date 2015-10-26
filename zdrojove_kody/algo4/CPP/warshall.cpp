#include <iostream>
using namespace std;

const int n=5;

int G[n][n];

void zeruj(int g[n][n])
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

void wypisz (char *nazwa, int G[n][n])
{
int i, j;
cout << "Graf:" << nazwa << endl;
for(i=0;i<n;i++)
  for(j=0;j<n;j++)
    {
    cout<<G[i][j]<<"  ";
    if(j==n-1) cout << endl;
    }
}

int main()
{
zeruj(G);

G[0][1]=1;G[0][3]=1;
G[1][3]=1;
G[2][1]=1;
G[3][2]=1;
G[4][1]=1;

wypisz ("G - przed", G);
warshall(G);
wypisz ("G - po", G);

}


