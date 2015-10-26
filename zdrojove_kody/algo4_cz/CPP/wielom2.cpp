#include <iostream>

using namespace std;

typedef struct wsp
{
int c;
int j;
struct wsp *dalsi;
}KOEFICIENTY, *KOEFICIENTY_PTR;
//-----------------------------------------------------------------------------
KOEFICIENTY_PTR vloz(KOEFICIENTY_PTR p, int c, int j)
{ // pøidání nového uzlu (koeficientu) do mnohoèlenu
if(c!=0) // pouze prvky c*(x^j), pro c!=0
  {
  KOEFICIENTY_PTR q=new KOEFICIENTY;
  q->c=c;
  q->j=j;
  q->dalsi=p;
  return q;
  }else
      return p;// seznam se nezmìnil
}
//-----------------------------------------------------------------------------
void pis(KOEFICIENTY_PTR p)
{ // výpis seznamu
if(p!=NULL)
   {
   cout << "[" << p->c <<  "," << p->j << "]  ";
   pis(p->dalsi);
   }else
        cout << endl;
}
//-----------------------------------------------------------------------------
KOEFICIENTY_PTR secti(KOEFICIENTY_PTR x, KOEFICIENTY_PTR y)
// vrácení mnohoèlenu x+y
{
KOEFICIENTY_PTR res=NULL;
while((x!=NULL) && (y!=NULL))
 if(x->j==y->j)
   {
   res=vloz(res,x->c+y->c,x->j);
   x=x->dalsi;
   y=y->dalsi;
   }
 else
    if(x->j<y->j)
      {
      res=vloz(res,x->c,x->j);
      x=x->dalsi;
      }
    else
      if(y->j<x->j)
      {
      res=vloz(res,y->c,y->j);
      y=y->dalsi;
      }
// V této fázi mùže x nebo y ještì obsahovat prvky, které
// zatím neobsloužil cyklus 'while' vzhledem ke své podmínce.
// Vkládáme tedy zbytek koeficientù (pokud existují):
while (x!=NULL)
      {
      res=vloz(res,x->c,x->j);
      x=x->dalsi;
      }
while (y!=NULL)
      {
      res=vloz(res,y->c,y->j);
      y=y->dalsi;
      }
return res;
}
//-----------------------------------------------------------------------------
int main()
{
KOEFICIENTY_PTR pw1, pw2, pw3, pwtemp;
pw1=pw2=pw3=pwtemp=NULL;
// mnohoèlen pw1(x)=
pw1=vloz(pw1,5,1700);
pw1=vloz(pw1,6,700);
pw1=vloz(pw1,10,50);
pw1=vloz(pw1,5,0);

cout << "*** SEZNAM W1: "; pis(pw1);
// mnohoèlen pw2(x)=
pw2=vloz(pw2,6,1800);
pw2=vloz(pw2,-6,700);
pw2=vloz(pw2,5,50);
pw2=vloz(pw2,15,0);

cout << "*** SEZNAM W2: "; pis(pw2);

pw3=secti(pw1,pw2);
// mnohoèlen pw3(x)=
cout << "*** SEZNAM W3=W1+W2: "; pis(pw3);

}
//-----------------------------------------------------------------------------
