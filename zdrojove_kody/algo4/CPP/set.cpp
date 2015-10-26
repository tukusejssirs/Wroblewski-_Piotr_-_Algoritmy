#include <iostream>
using namespace std;
 
class Zbior
{
private:
	unsigned char zbior[256]; // ca³a tablica ASCII
public:
Zbior() 
  {//zerowaie zbioru w konstruktorze
  for(int i=0;i<256;i++)
  zbior[i]=0;
  }
Zbior& operator +(unsigned char c) 
  { // dodaj znak 'c' do zbioru i zwróæ zmieniony obiekt
  zbior[c]=1;
  return *this;
  }
Zbior& operator -(unsigned char c) 
  {// usuñ znak 'c' ze zbioru zwróæ zmieniony obiekt
  zbior[c]=0;
  return *this;
  }
bool nalezy(unsigned char c) // czy 'c' nale¿y do zbioru?
  {
  return zbior[c]==1;
  }

Zbior& dodaj(Zbior s2) // dodaj zawartoœæ zbioru 's2' do obiektu
  {
  for(int i=0; i<256;i++)
	  if(s2.nalezy(i))  // jeœli element obecny w s2
			zbior[i]=1;   // dodaj go do zbioru
  return *this; // zwraca zmodyfikowany obiekt
  }

int ile()          // zwraca liczbê elementów w zbiorze
  {
  int n;
  for(int i=0; i<256; i++)
  if(zbior[i]==1)  // element obecny
	  n++;
  return n;
  }

void pisz()           
{// wypisuje zawartoœæ zbioru
  int i;
  cout << "{ ";
  for(i=0; i<256; i++)
	  if(zbior[i]==1)  // wypisz obecne element
		 cout << (char)i<< " ";
  if(i==0)
		 cout << "Zbiór pusty!";
  cout << "}\n";;
  }
}; // koniec definicji klasy Zbior

// ---------------------------------------------
int main()
{
Zbior s1, s2;
s1=s1+'A'; s1=s1+'A'; s1=s1+'B'; s1=s1+'C';
s2=s2+'B'; s2=s2+'B'; s2=s2+'E'; s2=s2+'F';
cout << "Zbior S1 =";  s1.pisz();
s1=s1-'C';
cout << "Zbior S1 - 'C' =";  s1.pisz();
cout << "Zbior S2 =";  s2.pisz();
		s1.dodaj(s2);
cout << "Zbior S1 + S2 = ";
		s1.pisz();
}
