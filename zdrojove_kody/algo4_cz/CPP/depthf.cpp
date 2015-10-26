#include <iostream>
using namespace std;

const int n=7;
int G[n][n], V[n]; // G - graf n x n, V - uchov�v� informace, 
// zda byl dan� vrchol ji� testov�n (1) �i nikoli (0)

#define TEST

void navstiv(int G[n][n], int V[n], int i)
{
V[i]=1;  // ozna�en� vrcholu jako "otestovan�ho"
#ifdef TEST
  cout << "Zkoum�n� vrcholu " << i << endl;
#endif

for(int k=0;k<n;k++)
  if(G[i][k]!=0)  // p�echod existuje
      if(V[k]==0) navstiv(G,V,k);
}

void hledej(int G[n][n], int V[n])
{
int i;
for(i=0;i<n;i++) V[i]=0;  // vrchol zat�m nebyl testov�n
for(i=0;i<n;i++)
   if(V[i]==0) 
      navstiv(G,V,i);
}

int main()
{
for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
    G[i][j]=0;
   G[0][3]=G[3][0]=1;G[0][4]=G[4][0]=1;G[0][1]=G[1][0]=1;
   G[1][4]=G[4][1]=1;G[3][4]=G[4][3]=1;G[4][5]=G[5][4]=1;
   G[1][2]=G[2][1]=1;G[3][6]=G[6][3]=1;G[2][6]=G[6][2]=1;
hledej(G,V);
}
