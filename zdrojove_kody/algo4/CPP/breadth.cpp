#include <iostream>
using namespace std;

const int n=7;

int G[n][n], V[n];
// G - graf n x n
// V - przechowuje informacjê, czy dany wierzcho³ek
//     by³ ju¿ badany (1) lub nie (0)


#include "kolejka.h"

#define TEST


void szukaj(int G[n][n],int V[n],int i)
// rozpoczynamy od wierzcho³ka 'i'
{
FIFO<int> kolejka(n);
kolejka.wstaw(i);

#ifdef TEST
	cout << "---> Wstawiam do kolejki " << i << endl;
#endif

int s;

while(!kolejka.pusta())
 {
 kolejka.obsluz(s);	// bierzemy z kolejki pewien wierzcho³ek 's'
 V[s]=1;             // zaznaczamy wierzcho³ek 's' jako "badany"

 #ifdef TEST
  cout << "Wyjmujê z kolejki " << s << endl;
 #endif

 for(int k=0; k<n; k++)
	if(G[s][k]!=0)  	// istnieje przejœcie
			if(V[k]==0) // 'k' nie by³ jeszcze badany
			 {
			 V[k]=1;		// zaznaczamy wierzcho³ek 'k' jako "badany"
			 kolejka.wstaw(k);
			  #ifdef TEST
				  cout << "---> Wstawiam do kolejki " << k << endl;
			 #endif
			 }
 }
}

int main()
{
for(int i=0; i<n; i++)
	{
	V[i]=0;  // wierzcho³ek nie by³ jeszcze badany
	for(int j=0; j<n; j++)
	 G[i][j]=0;
	}

G[0][3]=G[3][0]=1;G[0][4]=G[4][0]=1;G[0][1]=G[1][0]=1;
G[1][4]=G[4][1]=1;G[3][4]=G[4][3]=1;G[4][5]=G[5][4]=1;
G[1][2]=G[2][1]=1;G[3][6]=G[6][3]=1;G[2][6]=G[6][2]=1;

szukaj(G,V,0);
}
