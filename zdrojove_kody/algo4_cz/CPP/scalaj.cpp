#include <iostream>
using namespace std;

const int N = 8, M=12;


void slucuj(int T1[], int T2[], int T3[])
{ // T1, T2 - vstupn� pole velikosti M a M, T3 - v�sledn� pole
   for (int i=0, j=0, k=0; k < N+M; k++)
   {
      if (i==N) // dosa�en konec mno�iny T1, kop�rov�n� zbytku
      {
         T3[k]=T2[j++]; continue;
      }
      
      if (j==M) // dosa�en konec mno�iny T2, kop�rov�n� zbytku
      {
         T3[k]=T1[i++]; continue;
      }
      if (T1[i]<T2[j])
         T3[k]=T1[i++];
      else
         T3[k]=T2[j++];
   }
}
int main()
{
int T1[N] = {-4, -2, 0, 4, 6, 8, 9, 11};
int T2[M] = {2, 3, 4, 5, 5, 6, 7, 12, 13, 14, 16, 19};
int T3[N+M];

slucuj(T1, T2, T3);

cout << "Po set��d�n�:\n";
for(int i=0; i<N+M; i++)  
   cout << T3[i] << " "; 
cout << endl;
}
