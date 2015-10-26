#include <iostream>
#include <string>

using namespace std;

const int K=26*2+2*2+1;// znaky ASCII + p�smena s diakritikou + mezera
int shift[K];
//-------------------------------------------------------
int index(char c)
{
switch(c)
 {
 case ' ':return 0;         // mezera=0
 case '�':return 53;
 case '�':return 54;     // �esk� p�smena
 case '�':return 55;
 case '�':return 56;     // atd. pro zb�vaj�c� �esk� p�smena
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
 char *t="Zemsk� r�j to na pohled";

 cout << t << endl;
 cout << "Zemsk� r�j to na pohled" << endl;
 cout << "012345678901234567890123456789" << endl;
 cout << "V�sledek vyhled�v�n� �et�zce \'hle\'="<<bm("hle",t)<<endl;
 cout << "V�sledek vyhled�v�n� �et�zce \'�t\'="<<bm("�t",t)<<endl;
 cout << "V�sledek vyhled�v�n� �et�zce \'sad\'="<<bm("sad",t)<<endl;
 cout << "V�sledek vyhled�v�n� cel� v�ty"<<bm("Zemsk� r�j to na pohled",t)<<endl;

  cin.get();
 }


