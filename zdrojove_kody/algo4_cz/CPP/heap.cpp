#include <iostream>
using namespace std;

void obnov(int T[], int k, int n)
{
int i,j; 
   
i = T[k-1];
while (k <= n/2) 
   {
   j=2*k;
   if((j<n) && ( T[j-1]<T[j]) ) j++;
   if (i >= T[j-1]) 
      break;
    else 
    {
      T[k-1] = T[j-1];
      k=j;
    }
   }
T[k-1]=i;
}


// tøídìní pole T

void heapsort(int T[], int n) 
{
int k, swap; 
   for(k=n/2; k>0; k--) obnov(T, k, n); 
do 
 {
  swap=T[0];
  T[0]=T[n-1];
  T[n-1]=swap;
  n--;
  obnov(T, 1, n);
 } while (n > 1);
}

int main()
{
int i, T[14]={12,3,-12,9,34,23,1,81,45,17,9,23,11,4};
for (i=0;i<14;i++)
   cout << "  " << T[i];
   
cout << endl;

heapsort(T,14);

for (i=0;i<14;i++)
   cout << "  " << T[i];
}
