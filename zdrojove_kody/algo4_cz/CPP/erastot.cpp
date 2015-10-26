#include <iostream>
using namespace std;


#include <math.h>

// kompilace s matematickou knihovnou v systému UNIX:
// c++ -o erastot erastot.cpp -lm

inline int sqrt_int(int n) 
{ 
return (int)sqrt((double)n)/1;
}

bool prvocislo(int n)       // je n prvoèíslo?
{
int i, limes=sqrt_int(n);
for(i=2; n!=(n/i)*i && i<=limes;i++);
   if (i>limes) 
      return true;  // ano, jde o prvoèíslo
   else 
      return false;  // ne, je to „obyèejné“ èíslo
}
//-----------------------------------------------------------------------
void sito(int n) // vypsání všech prvoèísel < n
{
int cpt = 1, i, *tp=new int[n+1];

for(i=1; i<=n; i++) 
   tp[i]=i; // oznaèení všech pøirozených èísel od 1 do n

while(cpt<n)
  { // hledání prvního nenulového prvku pole tp:
  for(cpt++; (tp[cpt]==0) && (cpt!=100); cpt++);
  int k=2; /// nulování násobkù tohoto prvku (cpt) v poli tp

  while(cpt*k<=n)
  {
  tp[cpt*k]=0;
  k++;
  }
}
for(i=1;i<=n;i++)
  if (tp[i]!=0) cout << "Prvoèíslo:"<< tp[i] <<endl;
delete tp; // odstranìní pamìového pole
}

int main()
{
cout << "KLASICKÁ metoda\n";
for(int i=1; i<100; i++)
 if (prvocislo(i)==1)
  cout << "Prvoèíslo:" << i << endl;

cout << "Metoda ERATOSTHENOVA SÍTA\n";

sito(100);
}
//-----------------------------------------------------------------------
