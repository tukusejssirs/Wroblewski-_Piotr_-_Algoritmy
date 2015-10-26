#include <iostream>
using namespace std;
#include "stos.h"
// ukázková data
char* tab1[3]={"Ema", "má", "maso"};
double tab2[3]={3.14, 2.12, 100};



template <class ZaklTyp> int ZASOBNIK<ZaklTyp>::StavZasobniku()
{// vypisuje a vrací informace o stavu zásobníku
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
ZASOBNIK<char*>   s1; // zásobník na ukládání textù
ZASOBNIK<double>  s2; // zásobník na ukládání èísel
cout << "Vložení do zásobníku s1: ";

for(i=0; i<3;i++)
{
if (s1.StavZasobniku() != ZASOBNIK_PLNY)
{
   cout << "Pokus o vložení prvku:" << tab1[i] << ",";
   s1.push(tab1[i]);
}
else
   {
   cout << "Zásobník je plný, stop!\n"; 
   break;
   }
}

cout << "\nVložení do zásobníku s2: ";

for(i=0; i<3;i++)
{
if (s2.StavZasobniku() != ZASOBNIK_PLNY)
{
   cout << "Pokus o vložení prvku:" << tab2[i] << ",";
   s2.push(tab2[i]);
}
else
   {
      cout << "Zásobník je plný, stop!\n"; 
      break;
   }
}

for(i=0; i<3;i++)
{
char *z;
if (s1.pop(z)==OK)
   cout << "\nVyjmutí ze zásobníku s1: "<< z << endl;
else
   {
      cout << "Zásobník je prázdný, konec!\n";
      break;
   }
}

}
