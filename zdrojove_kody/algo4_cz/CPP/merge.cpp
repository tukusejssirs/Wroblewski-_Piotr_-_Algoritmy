#include <iostream>
using namespace std;
const int N = 10;

void slucuj(int T[], int p, int mid, int k)
// p - poèátek, k - konec, mid - støed
// procedura spojuje 2 setøídìná pole T[p...mid] a T[mid+1...k]
{
int T2[N];        // pomocné pole
int p1 =  p,     k1  = mid; // dílèí pole 1
int p2 =  mid+1, k2  = k;   // dílèí pole 2
// až do vyèerpání obsahu polí pokraèuje sluèování s využitím pomocného pole
int i = p1;
while((p1 <= k1) && (p2 <= k2))
{
  if(T[p1] < T[p2])
   {
    T2[i] = T[p1];
    p1++;
   }
   else
      {
      T2[i] = T[p2];
      p2++;
      }
      i++;
}

while(p1 <= k1)
{
 T2[i] = T[p1];
 p1++;
 i++;
}
while(p2 <= k2)
{
 T2[i] = T[p2];
 p2++;
 i++;
}
// kopírování z doèasného do pùvodního pole
 for(i = p; i <= k; i++)
    T[i] = T2[i];
}

void MergeSort(int T[], int p, int k)
{
  if(p < k)
  {
    int mid = (p + k) / 2;  // støed
    MergeSort(T, p, mid);   // tøídìní levé poloviny
    MergeSort(T, mid+1, k); // tøídìní pravé poloviny
    slucuj(T, p, mid, k);   // sluèování
  }
}
int main()
{
int T[N] = {4, 6, 4, 12, -3, 6, -6, 1, 8, '2'};
cout << "Pøed setøídìním:\n";
for(int x=0; x<N; x++) cout << T[x] << " "; cout << endl;
MergeSort(T, 0, N-1);
cout << "Po setøídìní:\n";
for(int x=0; x<N; x++)  cout << T[x] << " "; cout << endl;
}
