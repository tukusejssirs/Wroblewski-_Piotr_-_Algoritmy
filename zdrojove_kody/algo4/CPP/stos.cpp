#include <iostream>
using namespace std;
#include "stos.h"
// dane przyk³adowe
char* tab1[3]={"Ala", "ma", "kota"};
double tab2[3]={3.14, 2.12, 100};



template <class TypPodst> int STOS<TypPodst>::StanStosu()
{// wypisuje i zwraca informacje o stanie stosu
 switch(szczyt)
 {
  case 0          	 : return (STOS_PUSTY);
  case DLUGOSC_MAX	 : return (STOS_PELNY);
  default         	 : return (OK);  
  }
}


int main()
{
int i;
STOS<char*>   s1; // stos do przechowywania tekstów
STOS<double>  s2; // stos do przechowywania liczb
cout << "Odk³adam na stos s1: ";

for(i=0; i<3;i++)
{
if (s1.StanStosu() != STOS_PELNY)
{
	cout << "Próbujê w³o¿yæ:" << tab1[i] << ",";
	s1.push(tab1[i]);
}
else
	{
	cout << "Stos pe³ny, stop!\n"; 
	break;
	}
}

cout << "\nOdk³adam na stos s2: ";

for(i=0; i<3;i++)
{
if (s2.StanStosu() != STOS_PELNY)
{
	cout << "Próbujê w³o¿yæ:" << tab2[i] << ",";
	s2.push(tab2[i]);
}
else
	{
		cout << "Stos pe³ny, stop!\n"; 
		break;
	}
}

for(i=0; i<3;i++)
{
char *z;
if (s1.pop(z)==OK)
	cout << "\nZdejmujê ze stosu s1: "<< z << endl;
else
	{
		cout << "Stos pusty, koniec!\n";
		break;
	}
}

}
