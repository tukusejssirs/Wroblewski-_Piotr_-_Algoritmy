#include <iostream>
using namespace std;
 
class Mnozina
{
private:
   unsigned char mnozina[256]; // cel� tabulka ASCII
public:
Mnozina() 
  {// nulov�n� mno�iny v konstruktoru
  for(int i=0;i<256;i++)
  mnozina[i]=0;
  }
Mnozina& operator +(unsigned char c) 
  { // p�id�n� znaku 'c' do mno�iny a vr�cen� zm�n�n�ho objektu
  mnozina[c]=1;
  return *this;
  }
Mnozina& operator -(unsigned char c) 
  { // odstran�n� znaku 'c' z mno�iny a vr�cen� zm�n�n�ho objektu
  mnozina[c]=0;
  return *this;
  }
bool patri(unsigned char c) // pat�� 'c' do mno�iny?
  {
  return mnozina[c]==1;
  }

Mnozina& pridej(Mnozina s2) // p�id�n� obsahu mno�iny 's2' do objektu
  {
  for(int i=0; i<256;i++)
     if(s2.patri(i))  // pokud se prvek nach�z� v s2,
         mnozina[i]=1;   // je p�id�n do mno�iny
  return *this; // vr�cen� upraven�ho objektu
  }

int kolik()          // vrac� po�et prvk� mno�iny
  {
  int n;
  for(int i=0; i<256; i++)
  if(mnozina[i]==1)  // prvek je p��tomen
     n++;
  return n;
  }

void pis()           
{// vyp�e obsah mno�iny
  int i;
  cout << "{ ";
  for(i=0; i<256; i++)
     if(zbior[i]==1)  // vyp�e p��tomn� prvek
       cout << (char)i<< " ";
  if(i==0)
       cout << "Mno�ina je pr�zdn�!";
  cout << "}\n";;
  }
}; // konec definice t��dy Mnozina

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
cout << "Mno�ina S1 + S2 = ";
      s1.pis();
}
