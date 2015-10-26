#include <iostream>
using namespace std;
const int N = 10;

void slucuj(int T[], int p, int mid, int k)
// p - po��tek, k - konec, mid - st�ed
// procedura spojuje 2 set��d�n� pole T[p...mid] a T[mid+1...k]
{
int T2[N];        // pomocn� pole
int p1 =  p,     k1  = mid; // d�l�� pole 1
int p2 =  mid+1, k2  = k;   // d�l�� pole 2
// a� do vy�erp�n� obsahu pol� pokra�uje slu�ov�n� s vyu�it�m pomocn�ho pole
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
// kop�rov�n� z do�asn�ho do p�vodn�ho pole
 for(i = p; i <= k; i++)
    T[i] = T2[i];
}

void MergeSort(int T[], int p, int k)
{
  if(p < k)
  {
    int mid = (p + k) / 2;  // st�ed
    MergeSort(T, p, mid);   // t��d�n� lev� poloviny
    MergeSort(T, mid+1, k); // t��d�n� prav� poloviny
    slucuj(T, p, mid, k);   // slu�ov�n�
  }
}
int main()
{
int T[N] = {4, 6, 4, 12, -3, 6, -6, 1, 8, '2'};
cout << "P�ed set��d�n�m:\n";
for(int x=0; x<N; x++) cout << T[x] << " "; cout << endl;
MergeSort(T, 0, N-1);
cout << "Po set��d�n�:\n";
for(int x=0; x<N; x++)  cout << T[x] << " "; cout << endl;
}
