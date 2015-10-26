#include <iostream>
#include <string.h>
using namespace std;

const int M=4;
int shift[M]; // tablica przesunięć

//--------------------------------------------
void init_shifts(char *w)
{
 int i,j;
 shift[0]=-1;
 for(i=0,j=-1;i<M-1;i++,j++,shift[i]=j)
	while((j>=0)&&(w[i]!=w[j])) 
		j=shift[j];
}
//--------------------------------------------
int kmp(char *w, char *t)
{
 int i,j, N=strlen(t);
 for(i=0,j=0; (i<N) && (j<M); i++,j++)
	while( (j>=0) && (t[i]!=w[j]) ) 
		j=shift[j];
 if (j==M) 
	return i-M; 
 else 
	 return -1;
}
//--------------------------------------------
int main()
{
 char *w="1010";
 init_shifts(w);
 char *t="abcd1010def";
 cout << "Wynik poszukiwań="<<kmp(w,t)<<endl;
}

