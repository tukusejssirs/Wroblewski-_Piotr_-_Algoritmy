#include <iostream>
using namespace std;

const int N = 8, M=12;


void scalaj(int T1[], int T2[], int T3[])
{ // T1, T2 - tablice wejœciowe o rozmiarze M i M, T3 - tablica wynikowa
	for (int i=0, j=0, k=0; k < N+M; k++)
	{
		if (i==N) // osi¹gniêto koniec zbioru T1, kopiujemy resztê
		{
			T3[k]=T2[j++]; continue;
		}
		
		if (j==M) // osi¹gniêto koniec zbioru T2, kopiujemy resztê
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

scalaj(T1, T2, T3);

cout << "Po sortowaniu:\n";
for(int i=0; i<N+M; i++)  
	cout << T3[i] << " "; 
cout << endl;
}
