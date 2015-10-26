#include <iostream>
using namespace std;

const int n=6; // graf o 6 wierzcho³kach

int graf[n][n];

void zeruj(int R[n][n])
{
for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		R[i][j]=0;
}

void route(int R[n][n])
{
for(int x=0; x<n; x++)
  for(int y=0; y<n; y++)
	if(R[y][x]!=0) // wiemy jak dojœæ z 'y' do 'x'
    for(int z=0;z<n;z++)
       if( (R[y][z]==0) && (R[x][z]!=0) ) 
		   R[y][z]=R[y][x];
}

void pisz(int x, int y, int R[n][n])
{
int k;
if(R[x][y]==0) 
 cout << "Droga nie istnieje\n";
else
  {
  cout << x << endl;
  k=x;
  while(k!=y)
   {
    k=R[k][y];
    cout << k << endl;
    }
  }
//cout << "----------------\n";
}


int main()
{
int i,j;

zeruj(graf);

graf[0][3]=3;
graf[0][5]=5;
graf[1][2]=2;
graf[2][4]=4;
graf[3][1]=1;
graf[3][4]=4;
graf[5][4]=4;
graf[4][5]=5;
graf[5][2]=2;


route(graf);
for(i=0;i<n;i++)
   for(j=0;j<n;j++)
    {
     cout<<"Doga od wierzcholka "<<i<<" do "<<j<<":\n";
     pisz(i,j,graf);
    }


}

