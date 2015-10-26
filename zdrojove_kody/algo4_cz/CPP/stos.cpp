#include <iostream>
using namespace std;
#include "stos.h"
// uk�zkov� data
char* tab1[3]={"Ema", "m�", "maso"};
double tab2[3]={3.14, 2.12, 100};



template <class ZaklTyp> int ZASOBNIK<ZaklTyp>::StavZasobniku()
{// vypisuje a vrac� informace o stavu z�sobn�ku
 switch(vrchol)
 {
  case 0              : return (ZASOBNIK_PRAZDNY);
  case DELKA_MAX    : return (ZASOBNIK_PLNY);
  default             : return (OK);  
  }
}


int main()
{
int i;
ZASOBNIK<char*>   s1; // z�sobn�k na ukl�d�n� text�
ZASOBNIK<double>  s2; // z�sobn�k na ukl�d�n� ��sel
cout << "Vlo�en� do z�sobn�ku s1: ";

for(i=0; i<3;i++)
{
if (s1.StavZasobniku() != ZASOBNIK_PLNY)
{
   cout << "Pokus o vlo�en� prvku:" << tab1[i] << ",";
   s1.push(tab1[i]);
}
else
   {
   cout << "Z�sobn�k je pln�, stop!\n"; 
   break;
   }
}

cout << "\nVlo�en� do z�sobn�ku s2: ";

for(i=0; i<3;i++)
{
if (s2.StavZasobniku() != ZASOBNIK_PLNY)
{
   cout << "Pokus o vlo�en� prvku:" << tab2[i] << ",";
   s2.push(tab2[i]);
}
else
   {
      cout << "Z�sobn�k je pln�, stop!\n"; 
      break;
   }
}

for(i=0; i<3;i++)
{
char *z;
if (s1.pop(z)==OK)
   cout << "\nVyjmut� ze z�sobn�ku s1: "<< z << endl;
else
   {
      cout << "Z�sobn�k je pr�zdn�, konec!\n";
      break;
   }
}

}
