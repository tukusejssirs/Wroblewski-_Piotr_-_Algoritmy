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
void pis_infix(struct vyraz *v) // funkce vypisuje výraz v infixové formì
{
if(v->op=='0') // èíselná hodnota...
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
{// funkce vypisuje výraz v prefixové formì
if(v->op=='0') // èíselná hodnota...
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
{// má výraz správnou syntaxi?
if(v->op=='0') 
   return 1; // OK, podle naší konvence se jedná o èíslo
switch (v->op)
   {
     case '+':
     case '-':
     case '*':  // jsou to známé operátory
     case ':':
     case '/': return (spravne(v->levy)*spravne(v->pravy));
     default : return (0);  // chyba, neznámý operátor!
   }
}
//--------------------------------------------------------------------------------------
double vypocitej(struct vyraz *v)
{
if(spravne(v)) // je výraz správný?
   if (v->op=='0') 
      return (v->val); // samotná hodnota
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
                  cerr << "\nDìlení nulou!\n";
                  return -1; // primitivní kontrola chyb...
                  }
      }
    else cerr << "Syntaktická chyba!\n";
}

//--------------------------------------------------------------------------------------
int main()
{
ZASOBNIK<vyraz*> s;
// pøíklad SPRÁVNÉ posloupnosti dat – v pøípadì chybné sekvence, kdy napø.
// chybí druhý operátor, nebude mít smysl ani získaný strom
// (jak se mùžeme sami pøesvìdèit).
VAL t[9]={{2,'0'},{3,'0'},{0,'+'},{7,'0'},{9,'0'},{0,'*'},{0,'+'},{12.5,'0'},{0,'*'}};
vyraz *x;
for(int i=0;i<9;i++)
{
  x=new vyraz;
  if((t[i].op=='*')||(t[i].op=='+')||(t[i].op=='-')||(t[i].op=='/')||(t[i].op==':'))
           x->op =t[i].op;
  else{
      x->val=t[i].val;
      x->op='0'; // dohodnutá konvence k oznaèení hodnoty, nikoli operátoru
      }
  x->levy =NULL;
  x->pravy=NULL;
  if((t[i].op=='*')||(t[i].op=='+')||(t[i].op=='-')||(t[i].op=='/')||(t[i].op==':'))
     {
     vyraz *l1,*p1;
     s.pop(l1);
     s.pop(p1);
     x->levy =l1; // Pøipojení pod uzel x
    x->pravy=p1; // Pøipojení pod uzel x
    }
   s.push(x);
}
pis_infix(x); cout << "=" << vypocitej(x) << endl;
pis_prefix(x);cout << "=" << vypocitej(x) << endl;
}
