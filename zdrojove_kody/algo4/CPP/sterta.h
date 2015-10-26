#include <iostream>
using namespace std;

class Sterta
{
public:
  Sterta(int nMax)
	 {
	 t=new int[nMax+1];
	 L=0;
	 }
	void wstaw(int x);
	int  obsluz();
	void DoGory();
	void NaDol();
	void pisz();
private:
  int *t;
  int L;	// liczba elementów
}; // koniec definicji klasy Sterta

//------------------------------------------------------------
void Sterta::wstaw(int x)
{
t[++L]=x;
DoGory();
}
//------------------------------------------------------------
void Sterta::DoGory()
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
int Sterta::obsluz()
{
int x=t[1];
t[1]=t[L--];   //brak kontroli b³êdów!!!
NaDol();
return x;
}
//------------------------------------------------------------
void Sterta::NaDol()
{
int i=1;
while(1)
 {
  int p=2*i;    	 // lewy potomek wêz³a 'i' to (p), prawy to (p+1)
  if(p>L)break;
  if(p+1<=L)             // prawy potomek niekoniecznie musi istnieæ!
	 if(t[p]<t[p+1]) p++; //przesuwamy siê do nastêpnego
  if(t[i]>=t[p]) break;
  int temp=t[p]; 	 // zamiana
			  t[p]=t[i];
			  t[i]=temp;

  i=p;
 }
}
//------------------------------------------------------------
void Sterta::pisz()
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


