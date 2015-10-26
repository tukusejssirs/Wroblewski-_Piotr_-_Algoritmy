#include <iostream>
using namespace std;

const int n=3; // stupeò mnohoèlenu

void secti_mnohocleny(int x[],int y[],int z[], int rozm)
{
for(int i=0;i<rozm;i++)
   z[i]=x[i]+y[i];         // mnohoèlen z=x+y
}

void vynasob_mnohocleny(int x[],int y[],int z[], int rozm)
{
int i,j;
for(i=0; i<2*rozm-1; i++)
   z[i]=0;                 // nulování výsledku
for(i=0;i<rozm;i++)
   for(j=0;j<rozm;j++)
       z[i+j]=z[i+j] + x[i]*y[j];
}
int main()
{
// koeficienty mnohoèlenù:
int i;
int w1[n]={1,3,2};
int w2[n]={2,0,3};
int w3[2*n];

secti_mnohocleny(w1,w2,w3,n);
cout << "w1(i)\t" << "w2(i)\t" << "w3(i)\t" << endl;
for(i=0;i<n;i++)
  cout << w1[i]   << "\t" << w2[i]  << "\t" << w3[i]  << "\t" << endl;

vynasob_mnohocleny(w1,w2,w3,n);
cout << "w1(i)\t" << "w2(i)\t" << "w3(i)\t" << endl;
for(i=0;i<2*n-1;i++)
 if(i<n)
  cout << w1[i]   << "\t" << w2[i]  << "\t" << w3[i]  << "\t" << endl;else
  cout << "\t\t" << w3[i] << endl;
}
