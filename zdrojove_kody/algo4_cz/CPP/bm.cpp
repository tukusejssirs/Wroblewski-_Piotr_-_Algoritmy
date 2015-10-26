#include <iostream>
#include <string>

using namespace std;

const int K=26*2+2*2+1;// znaky ASCII + písmena s diakritikou + mezera
int shift[K];
//-------------------------------------------------------
int index(char c)
{
switch(c)
 {
 case ' ':return 0;         // mezera=0
 case 'á':return 53;
 case 'Á':return 54;     // èeská písmena
 case 'è':return 55;
 case 'È':return 56;     // atd. pro zbývající èeská písmena
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
   shift[index(w[i])]=M-i-1;
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
 char *t="Zemský ráj to na pohled";

 cout << t << endl;
 cout << "Zemský ráj to na pohled" << endl;
 cout << "012345678901234567890123456789" << endl;
 cout << "Výsledek vyhledávání øetìzce \'hle\'="<<bm("hle",t)<<endl;
 cout << "Výsledek vyhledávání øetìzce \'ìt\'="<<bm("ìt",t)<<endl;
 cout << "Výsledek vyhledávání øetìzce \'sad\'="<<bm("sad",t)<<endl;
 cout << "Výsledek vyhledávání celé vìty"<<bm("Zemský ráj to na pohled",t)<<endl;

  cin.get();
 }


