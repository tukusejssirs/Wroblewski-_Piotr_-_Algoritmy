#include <iostream>
using namespace std;

const int n=5;

void dynam(double P[n][n])
{
int i,j;
for(i=1;i<n;i++) {P[i][0]=0;P[0][i]=1;}
for(j=1;j<n;j++)
   for(i=1;i<n;i++)
       P[i][j]=(P[i-1][j]+P[i][j-1])/2.0;
}


int main()
{
double P[n][n];
dynam(P);
for(int i=0;i<5;i++)
  for(int j=0;j<5;j++)
       cout << "P("<<i<<","<<j<<")="<<P[i][j]<<endl;

}
