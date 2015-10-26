#include <iostream>
using namespace std;

const int n=5; // graf s 5 vrcholy
int G1[n][n],G2[n][n],G3[n][n];

void nuluj(int g[n][n])
{
for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
      g[i][j]=0; // konvence: 0=žádná hrana
}

void kompozice(int g1[n][n],int g2[n][n],int g3[n][n])
{
int z;
for(int x=0; x<n; x++)
  for(int y=0; y<n; y++)
  {
  z=0;
  while(1) // nekoneèný cyklus
    {
    if(z==n) 
      break; // opuštìní cyklu
    if( (g1[x][z]==1) && (g2[z][y]==1) )
      g3[x][y]=1;
    z++;
   }
  }
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

nuluj(G1);
nuluj(G2);
nuluj(G3);


G1[1][0]=1;
G1[0][2]=1;
G1[3][2]=1;
G1[1][3]=1;
G1[4][3]=1;
G1[1][4]=1;


G2[4][0]=1;
G2[0][1]=1;
G2[2][1]=1;
G2[4][2]=1;
G2[1][3]=1;
G2[3][3]=1;


kompozice(G1,G2,G3);

vypis("*** G1 ***", G1);
vypis("*** G2 ***", G2);
vypis("*** G1 ***", G3);

}


