#include <iostream>
using namespace std;
const int N = 10;

void Scalaj(int T[], int p, int mid, int k)
// p - poczatek, k - koniec, mid - srodek
// procedura ³¹czy 2 posortowane tablice T[p...mid] i T[mid+1...k]
{
int T2[N];        // tablica pomocnicza
int p1 =  p,     k1  = mid; // podtablica 1
int p2 =  mid+1, k2  = k;   // podtablica 2
// a¿ do wyczerpania tablic dokonaj scalenia przy pomocy tablicy pomocniczej
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
// skopiuj z tablicy tymczasowej do oryginalnej
 for(i = p; i <= k; i++)
    T[i] = T2[i];
}

void MergeSort(int T[], int p, int k)
{
  if(p < k)
  {
    int mid = (p + k) / 2;  // œrodek
    MergeSort(T, p, mid);   // sortuj lew¹ po³owê
    MergeSort(T, mid+1, k); // sortuj praw¹ po³owê
    Scalaj(T, p, mid, k);   // scalaj
  }
}
int main()
{
int T[N] = {4, 6, 4, 12, -3, 6, -6, 1, 8, '2'};
cout << "Przed sortowaniem:\n";
for(int x=0; x<N; x++) cout << T[x] << " "; cout << endl;
MergeSort(T, 0, N-1);
cout << "Po sortowaniu:\n";
for(int x=0; x<N; x++)  cout << T[x] << " "; cout << endl;
}
