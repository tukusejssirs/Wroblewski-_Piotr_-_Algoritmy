#include <iostream>
using namespace std;

const int n=5; // graf o 5 wierzcho³kach
int G1[n][n],G2[n][n],G3[n][n];

void zeruj(int g[n][n])
{
for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		g[i][j]=0; // konwencja: 0=brak krawêdzi
}

void kompozycja(int g1[n][n],int g2[n][n],int g3[n][n])
{
int z;
for(int x=0; x<n; x++)
  for(int y=0; y<n; y++)
  {
  z=0;
  while(1) // pêtla nieskoñczona
    {
    if(z==n) 
		break; // wyjœcie z pêtli
    if( (g1[x][z]==1) && (g2[z][y]==1) )
      g3[x][y]=1;
    z++;
   }
  }
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

zeruj(G1);
zeruj(G2);
zeruj(G3);


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


kompozycja(G1,G2,G3);

wypisz ("*** G1 ***", G1);
wypisz ("*** G2 ***", G2);
wypisz ("*** G1 ***", G3);

}


