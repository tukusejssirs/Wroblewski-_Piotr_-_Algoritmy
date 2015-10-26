#include <iostream>
using namespace std;


#include <math.h>

// kompilace s matematickou knihovnou v syst�mu UNIX:
// c++ -o erastot erastot.cpp -lm

inline int sqrt_int(int n) 
{ 
return (int)sqrt((double)n)/1;
}

bool prvocislo(int n)       // je n prvo��slo?
{
int i, limes=sqrt_int(n);
for(i=2; n!=(n/i)*i && i<=limes;i++);
   if (i>limes) 
      return true;  // ano, jde o prvo��slo
   else 
      return false;  // ne, je to �oby�ejn� ��slo
}
//-----------------------------------------------------------------------
void sito(int n) // vyps�n� v�ech prvo��sel < n
{
int cpt = 1, i, *tp=new int[n+1];

for(i=1; i<=n; i++) 
   tp[i]=i; // ozna�en� v�ech p�irozen�ch ��sel od 1 do n

while(cpt<n)
  { // hled�n� prvn�ho nenulov�ho prvku pole tp:
  for(cpt++; (tp[cpt]==0) && (cpt!=100); cpt++);
  int k=2; /// nulov�n� n�sobk� tohoto prvku (cpt) v poli tp

  while(cpt*k<=n)
  {
  tp[cpt*k]=0;
  k++;
  }
}
for(i=1;i<=n;i++)
  if (tp[i]!=0) cout << "Prvo��slo:"<< tp[i] <<endl;
delete tp; // odstran�n� pam�ov�ho pole
}

int main()
{
cout << "KLASICK� metoda\n";
for(int i=1; i<100; i++)
 if (prvocislo(i)==1)
  cout << "Prvo��slo:" << i << endl;

cout << "Metoda ERATOSTHENOVA S�TA\n";

sito(100);
}
//-----------------------------------------------------------------------
