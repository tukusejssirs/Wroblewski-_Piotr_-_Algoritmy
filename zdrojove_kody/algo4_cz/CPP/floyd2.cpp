#include <iostream>
using namespace std;

const int n=7;

int G[n][n]; // graf
int R[n][n]; // matice navrhovaných cest


void initG()
{
for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
      G[i][j]=10000; // smluvní "nekoneèno"
}

void initR()
{
for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
      R[i][j]=0; // cesta neexistuje
}


void nuluj(int g[n][n])
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

void cesta(int i, int j)
{
int k = R[i][j];
if (k != 0)
 {
  cesta(i,k);
    cout << k << "  ";
  cesta(k,j);
  }
}



int main()
{
initG();// nulování grafu, všude G[i][j] = nekoneèno
initR();// nulování matice navrhovaných cest, všude R[i][j]=0

G[0][3]=30; G[0][1]=10; G[1][2]=15; G[1][4]=40; G[2][3]=5;
G[2][4]=20; G[4][5]=20; G[4][6]=10; G[5][6]=5;  G[6][3]=25;

floyd(G); // vyvolání algoritmu a kontrola jeho výsledkù:

for(int i=0; i<n; i++)
   for(int j=0; j<n; j++)
     {
     if(G[i][j]==10000) 
      cout << i << "  -->  " << j << "[cesta neexistuje]\n";
   else
      if(i!=j) 
      {
       cout << i << "  -->  " << j << "="<<G[i][j]<<", cesta pøes: ";
       cesta(i,j);
       cout << endl;
      }
     }
}
