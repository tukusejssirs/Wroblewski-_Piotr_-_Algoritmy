#include <iostream>
using namespace std;
const int n=5; // stupeò mnohoèlenu
// -----------------------------------------
int vypocitej_mnohoclen(int a, int w[], int rozm)
{ // klasická metoda
int res=0,pot=1;
for(int j=rozm-1;j>=0;j--)
    {
    res+=pot*w[j];      // èásteèné souèty
    pot*=a;             // další mocnina a
    }
return res;
}
// -----------------------------------------
int vypocitej_mnohoclen_H(int a,int w[],int rozm)
// Hornerovo schéma
{
int res=w[0];
for(int j=1; j<rozm; res=res*a+w[j++]);
return res;
}
// -----------------------------------------
int main()
{
int w[n]={1,4,-2,0,7};  // koeficienty mnohoèlenu
cout << vypocitej_mnohoclen(2,w,n) << endl;
cout << vypocitej_mnohoclen_H(2,w,n) << endl;
}
