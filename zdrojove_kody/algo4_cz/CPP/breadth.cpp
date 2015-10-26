#include <iostream>
using namespace std;

const int n=7;

int G[n][n], V[n];
// G - graf n x n
// V - uchovává informaci, zda daný vrchol
//     byl již testován (1) èi nikoli (0)


#include "kolejka.h"

#define TEST


void hledej(int G[n][n],int V[n],int i)
// zaèátek ve vrcholu 'i'
{
FIFO<int> fronta(n);
fronta.vloz(i);

#ifdef TEST
   cout << "---> Vkládáme do fronty " << i << endl;
#endif

int s;

while(!fronta.prazdne())
 {
 fronta.obsluz(s);  // vyjmutí urèitého vrcholu 's' z fronty
 V[s]=1;             // oznaèení vrcholu 's' jako "otestovaného"

 #ifdef TEST
  cout << "Odstraòujeme z fronty " << s << endl;
 #endif

 for(int k=0; k<n; k++)
   if(G[s][k]!=0)    // pøechod existuje
         if(V[k]==0) // vrchol 'k' zatím nebyl testován
          {
          V[k]=1;    // oznaèení vrcholu 'k' jako "otestovaného"
          fronta.vloz(k);
           #ifdef TEST
              cout << "---> Vkládáme do fronty " << k << endl;
          #endif
          }
 }
}

int main()
{
for(int i=0; i<n; i++)
   {
   V[i]=0;  // vrchol zatím nebyl testován
   for(int j=0; j<n; j++)
    G[i][j]=0;
   }

G[0][3]=G[3][0]=1;G[0][4]=G[4][0]=1;G[0][1]=G[1][0]=1;
G[1][4]=G[4][1]=1;G[3][4]=G[4][3]=1;G[4][5]=G[5][4]=1;
G[1][2]=G[2][1]=1;G[3][6]=G[6][3]=1;G[2][6]=G[6][2]=1;

hledej(G,V,0);
}
