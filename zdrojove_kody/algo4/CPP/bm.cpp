#include <iostream>
#include <string>

using namespace std;

const int K=26*2+2*2+1;// znaki ASCII + polskie litery + odstêp
int shift[K];
//-------------------------------------------------------
int indeks(char c)
{
switch(c)
 {
 case ' ':return 0;         // odstêp=0
 case 'ê':return 53;
 case 'Ê':return 54;     // polskie litery
 case '³':return 55;
 case '£':return 56;     // itd. dla pozosta³ych polskich liter
 default:
		if(islower(c))
			return c-'a'+1;
		else 
			return c-'A'+27;
 }
}
//-------------------------------------------------------
void init_shifts(char *w)
{
int M=strlen(w);
for(int i=0;i<K;i++) 
	shift[i]=M;
for(int i=0;i<M;i++)
	shift[indeks(w[i])]=M-i-1;
}
//-------------------------------------------------------
int bm(char *w, char *t)
{
init_shifts(w);
int i, j,N=strlen(t),M=strlen(w);
for(i=M-1,j=M-1; j>=0; i--,j--)
  while(t[i]!=w[j])
	{
	int x=shift[indeks(t[i])];
	if(M-j>x) 
		i+=M-j;
	else
		  i+=x;
	if (i>=N) 
		return -1;
	j=M-1;
	}
return i+1;
}
//-------------------------------------------------------
int main()
 {
 char *t="Z pamiêtnika m³odej lekarki";

 cout << t << endl;
 cout << "Z pamiêtnika m³odej lekarki" << endl;
 cout << "012345678901234567890123456789" << endl;
 cout << "Wynik poszukiwañ s³owa 'lek'="<<bm("lek",t)<<endl;
 cout << "Wynik poszukiwañ s³owa \'er\'="<<bm("er",t)<<endl;
 cout << "Wynik poszukiwañ s³owa \'kir\'="<<bm("kir",t)<<endl;
 cout << "Wynik poszukiwañ ca³ego zdania"<<bm("Z pamiêtnika m³odej lekarki",t)<<endl;

  cin.get();
 }


