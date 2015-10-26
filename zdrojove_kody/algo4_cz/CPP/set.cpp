#include <iostream>
using namespace std;
 
class Mnozina
{
private:
   unsigned char mnozina[256]; // celá tabulka ASCII
public:
Mnozina() 
  {// nulování množiny v konstruktoru
  for(int i=0;i<256;i++)
  mnozina[i]=0;
  }
Mnozina& operator +(unsigned char c) 
  { // pøidání znaku 'c' do množiny a vrácení zmìnìného objektu
  mnozina[c]=1;
  return *this;
  }
Mnozina& operator -(unsigned char c) 
  { // odstranìní znaku 'c' z množiny a vrácení zmìnìného objektu
  mnozina[c]=0;
  return *this;
  }
bool patri(unsigned char c) // patøí 'c' do množiny?
  {
  return mnozina[c]==1;
  }

Mnozina& pridej(Mnozina s2) // pøidání obsahu množiny 's2' do objektu
  {
  for(int i=0; i<256;i++)
     if(s2.patri(i))  // pokud se prvek nachází v s2,
         mnozina[i]=1;   // je pøidán do množiny
  return *this; // vrácení upraveného objektu
  }

int kolik()          // vrací poèet prvkù množiny
  {
  int n;
  for(int i=0; i<256; i++)
  if(mnozina[i]==1)  // prvek je pøítomen
     n++;
  return n;
  }

void pis()           
{// vypíše obsah množiny
  int i;
  cout << "{ ";
  for(i=0; i<256; i++)
     if(zbior[i]==1)  // vypíše pøítomný prvek
       cout << (char)i<< " ";
  if(i==0)
       cout << "Množina je prázdná!";
  cout << "}\n";;
  }
}; // konec definice tøídy Mnozina

// ---------------------------------------------
int main()
{
Mnozina s1, s2;
s1=s1+'A'; s1=s1+'A'; s1=s1+'B'; s1=s1+'C';
s2=s2+'B'; s2=s2+'B'; s2=s2+'E'; s2=s2+'F';
cout << "Mnozina S1 =";  s1.pis();
s1=s1-'C';
cout << "Mnozina S1 - 'C' =";  s1.pis();
cout << "Mnozina S2 =";  s2.pis();
      s1.pridej(s2);
cout << "Množina S1 + S2 = ";
      s1.pis();
}
