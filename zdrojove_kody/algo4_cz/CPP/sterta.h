#include <iostream>
using namespace std;

class Halda
{
public:
  Halda(int nMax)
    {
    t=new int[nMax+1];
    L=0;
    }
   void vloz(int x);
   int  obsluz();
   void Nahoru();
   void Dolu();
   void pis();
private:
  int *t;
  int L; // po�et prvk�
}; // konec definice t��dy Halda

//------------------------------------------------------------
void Halda::vloz(int x)
{
t[++L]=x;
Nahoru();
}
//------------------------------------------------------------
void Halda::Nahoru()
{
int temp=t[L];
int n=L;
while((n!=1)&&(t[n/2]<=temp))
 {
  t[n]=t[n/2];
  n=n/2;
 }
t[n]=temp;
}
//------------------------------------------------------------
int Halda::obsluz()
{
int x=t[1];
t[1]=t[L--];   // nekontroluj� se chyby!
Dolu();
return x;
}
//------------------------------------------------------------
void Halda::Dolu()
{
int i=1;
while(1)
 {
  int p=2*i;       // lev� potomek uzlu 'i' je (p), prav� potomek je (p+1)
  if(p>L)break;
  if(p+1<=L)             // prav� potomek nemus� nutn� existovat!
    if(t[p]<t[p+1]) p++; // p�echod na n�sleduj�c�
  if(t[i]>=t[p]) break;
  int temp=t[p];   // v�m�na
           t[p]=t[i];
           t[i]=temp;

  i=p;
 }
}
//------------------------------------------------------------
void Halda::pis()
{
int i=1;
while(i<=L)
  {
  
  for(int j=i;(j<=L)&&(j<2*i);j++)
  cout<<t[j]<<",";
  
  i*=2;
  cout<<endl;
  }
}
//------------------------------------------------------------


