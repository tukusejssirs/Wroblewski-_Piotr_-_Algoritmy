//#include <stdlib.h>
#include <iostream>
using namespace std;

#include "stos.h"
//--------------------------------------------------------------------------------------
struct vyraz
{
double val;
char op;
vyraz *levy,*pravy;
};
//--------------------------------------------------------------------------------------
typedef struct
{
double val;
char op;
}VAL;
//--------------------------------------------------------------------------------------
void pis_infix(struct vyraz *v) // funkce vypisuje v�raz v infixov� form�
{
if(v->op=='0') // ��seln� hodnota...
  cout << v->val;else
     {
     cout << "(";
     pis_infix(v->levy);
               cout << v->op;
     pis_infix(v->pravy);
     cout <<")";
     }
}
//--------------------------------------------------------------------------------------
void pis_prefix(struct vyraz *v)
{// funkce vypisuje v�raz v prefixov� form�
if(v->op=='0') // ��seln� hodnota...
  cout<<v->val<<" ";
    else
     {
     cout << v->op << " ";
     pis_prefix(v->levy);
     pis_prefix(v->pravy);
     }
}
//--------------------------------------------------------------------------------------
int spravne(struct vyraz *v) 
{// m� v�raz spr�vnou syntaxi?
if(v->op=='0') 
   return 1; // OK, podle na�� konvence se jedn� o ��slo
switch (v->op)
   {
     case '+':
     case '-':
     case '*':  // jsou to zn�m� oper�tory
     case ':':
     case '/': return (spravne(v->levy)*spravne(v->pravy));
     default : return (0);  // chyba, nezn�m� oper�tor!
   }
}
//--------------------------------------------------------------------------------------
double vypocitej(struct vyraz *v)
{
if(spravne(v)) // je v�raz spr�vn�?
   if (v->op=='0') 
      return (v->val); // samotn� hodnota
    else
     switch (v->op)
     {
      case '+':return vypocitej(v->levy)+vypocitej(v->pravy);
      case '-':return vypocitej(v->levy)-vypocitej(v->pravy);
      case '*':return vypocitej(v->levy)*vypocitej(v->pravy);
      case ':':
      case '/':if(vypocitej(v->pravy)!= 0)
               return (vypocitej(v->levy)/vypocitej(v->pravy));
             else
             {
                  cerr << "\nD�len� nulou!\n";
                  return -1; // primitivn� kontrola chyb...
                  }
      }
    else cerr << "Syntaktick� chyba!\n";
}

//--------------------------------------------------------------------------------------
int main()
{
ZASOBNIK<vyraz*> s;
// p��klad SPR�VN� posloupnosti dat � v p��pad� chybn� sekvence, kdy nap�.
// chyb� druh� oper�tor, nebude m�t smysl ani z�skan� strom
// (jak se m��eme sami p�esv�d�it).
VAL t[9]={{2,'0'},{3,'0'},{0,'+'},{7,'0'},{9,'0'},{0,'*'},{0,'+'},{12.5,'0'},{0,'*'}};
vyraz *x;
for(int i=0;i<9;i++)
{
  x=new vyraz;
  if((t[i].op=='*')||(t[i].op=='+')||(t[i].op=='-')||(t[i].op=='/')||(t[i].op==':'))
           x->op =t[i].op;
  else{
      x->val=t[i].val;
      x->op='0'; // dohodnut� konvence k ozna�en� hodnoty, nikoli oper�toru
      }
  x->levy =NULL;
  x->pravy=NULL;
  if((t[i].op=='*')||(t[i].op=='+')||(t[i].op=='-')||(t[i].op=='/')||(t[i].op==':'))
     {
     vyraz *l1,*p1;
     s.pop(l1);
     s.pop(p1);
     x->levy =l1; // P�ipojen� pod uzel x
    x->pravy=p1; // P�ipojen� pod uzel x
    }
   s.push(x);
}
pis_infix(x); cout << "=" << vypocitej(x) << endl;
pis_prefix(x);cout << "=" << vypocitej(x) << endl;
}
