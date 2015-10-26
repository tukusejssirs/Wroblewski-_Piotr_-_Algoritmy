//#include <stdlib.h>
#include <iostream>
using namespace std;

#include "stos.h"
//--------------------------------------------------------------------------------------
struct wyrazenie
{
double val;
char op;
wyrazenie *lewy,*prawy;
};
//--------------------------------------------------------------------------------------
typedef struct
{
double val;
char op;
}VAL;
//--------------------------------------------------------------------------------------
void pisz_infix(struct wyrazenie *w) // funkcja wypisuje wyra�enie w postaci wrostkowej
{
if(w->op=='0') // warto�� liczbowa...
  cout << w->val;else
     {
     cout << "(";
     pisz_infix(w->lewy);
               cout << w->op;
     pisz_infix(w->prawy);
	  cout <<")";
     }
}
//--------------------------------------------------------------------------------------
void pisz_prefix(struct wyrazenie *w)
{// funkcja wypisuje wyra�enie w postaci prefiksowej
if(w->op=='0') // warto�� liczbowa...
  cout<<w->val<<" ";
	 else
	  {
	  cout << w->op << " ";
	  pisz_prefix(w->lewy);
	  pisz_prefix(w->prawy);
	  }
}
//--------------------------------------------------------------------------------------
int poprawne(struct wyrazenie *w) 
{// czy wyra�enie jest poprawne sk�adniowo?
if(w->op=='0') 
	return 1; // OK, wg naszej konwencji jest to liczba
switch (w->op)
	{
	  case '+':
	  case '-':
	  case '*':  // to s� znane operatory
	  case ':':
	  case '/': return (poprawne(w->lewy)*poprawne(w->prawy));
	  default : return (0);  //b��d, operator nieznany!
	}
}
//--------------------------------------------------------------------------------------
double oblicz(struct wyrazenie *w)
{
if(poprawne(w)) // wyra�enie poprawne?
	if (w->op=='0') 
		return (w->val); // pojedyncza warto��
	 else
	  switch (w->op)
	  {
		case '+':return oblicz(w->lewy)+oblicz(w->prawy);
		case '-':return oblicz(w->lewy)-oblicz(w->prawy);
		case '*':return oblicz(w->lewy)*oblicz(w->prawy);
		case ':':
		case '/':if(oblicz(w->prawy)!= 0)
					return (oblicz(w->lewy)/oblicz(w->prawy));
				 else
				 {
                  cerr << "\nDzielenie przez zero!\n";
                  return -1; // u�omna sygnalizacja b��d�w...
                  }
      }
    else cerr << "B��d sk�adni...!\n";
}

//--------------------------------------------------------------------------------------
int main()
{
STOS<wyrazenie*> s;
// przyk�ad POPRAWNEJ sekwencji danych, w przypadku sekwencji b��dnej, gdy np.
// zabraknie drugiego operanda, otrzymane drzewo b�dzie r�wnie� bezsensowne
// (prosz� wykona� odpowiednie pr�by).
VAL t[9]={{2,'0'},{3,'0'},{0,'+'},{7,'0'},{9,'0'},{0,'*'},{0,'+'},{12.5,'0'},{0,'*'}};
wyrazenie *x;
for(int i=0;i<9;i++)
{
  x=new wyrazenie;
  if((t[i].op=='*')||(t[i].op=='+')||(t[i].op=='-')||(t[i].op=='/')||(t[i].op==':'))
			  x->op =t[i].op;
  else{
	   x->val=t[i].val;
	   x->op='0'; // Umowna konwencja oznaczaj�ca warto��, a nie operator
	   }
  x->lewy =NULL;
  x->prawy=NULL;
  if((t[i].op=='*')||(t[i].op=='+')||(t[i].op=='-')||(t[i].op=='/')||(t[i].op==':'))
     {
     wyrazenie *l1,*p1;
     s.pop(l1);
     s.pop(p1);
     x->lewy =l1; // "Podwi�zanie" pod w�ze� x
	 x->prawy=p1; // "Podwi�zanie" pod w�ze� x
	 }
	s.push(x);
}
pisz_infix(x); cout << "=" << oblicz(x) << endl;
pisz_prefix(x);cout << "=" << oblicz(x) << endl;
}
