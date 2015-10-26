#include <iostream>
using namespace std;

const int n=3;

void greedy(double M, double W[n], double C[n], double X[n])
{
int i;
double Z=M; // zbývá zaplnit
for(i=0; i<n; i++)
   {
   if(W[i]>Z) 
      break;
   X[i]=1;
   Z=Z-W[i];
    }
if(i<n)
   X[i]=Z/W[i];
}

int main()
{
double W[n]={10,12,16}, C[n]={60,70,80}, X[n]={0,0,0};
greedy(20,W,C,X);
double p=0;
for(int i=0; i<n; p+=X[i]*C[i],i++)
   cout << i << "\t" << W[i] <<"\t" << C[i] << "\t" << X[i] << endl;
cout << "Dohromady:"<<p<<endl;
}
