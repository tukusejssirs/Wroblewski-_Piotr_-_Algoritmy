#include <iostream>

using namespace std;

typedef struct wsp
{
int c;
int j;
struct wsp *nastepny;
}WSPOLCZYNNIKI, *WSPOLCZYNNIKI_PTR;
//-----------------------------------------------------------------------------
WSPOLCZYNNIKI_PTR wstaw(WSPOLCZYNNIKI_PTR p, int c, int j)
{ // dodaje nowy wêze³ (wspó³czynnik) do wielomianu
if(c!=0)	// tylko elementy c*(x^j), dla c!=0
  {
  WSPOLCZYNNIKI_PTR q=new WSPOLCZYNNIKI;
  q->c=c;
  q->j=j;
  q->nastepny=p;
  return q;
  }else
		return p;// lista nie zosta³a zmieniona
}
//-----------------------------------------------------------------------------
void pisz(WSPOLCZYNNIKI_PTR p)
{ // wypisuje listê
if(p!=NULL)
	{
	cout << "[" << p->c <<  "," << p->j << "]  ";
	pisz(p->nastepny);
	}else
		  cout << endl;
}
//-----------------------------------------------------------------------------
WSPOLCZYNNIKI_PTR dodaj(WSPOLCZYNNIKI_PTR x, WSPOLCZYNNIKI_PTR y)
// zwraca wielomian x+y
{
WSPOLCZYNNIKI_PTR res=NULL;
while((x!=NULL) && (y!=NULL))
 if(x->j==y->j)
	{
	res=wstaw(res,x->c+y->c,x->j);
	x=x->nastepny;
	y=y->nastepny;
	}
 else
	 if(x->j<y->j)
		{
		res=wstaw(res,x->c,x->j);
		x=x->nastepny;
		}
	 else
		if(y->j<x->j)
		{
		res=wstaw(res,y->c,y->j);
		y=y->nastepny;
		}
// W tym momencie x lub y moze jeszcze zawierac elementy, które
// nie zosta³y obs³u¿one w pêtli 'while' z uwagi na jej warunek.
// Wstawiamy zatem resztê czynników (jeœli istniej¹):
while (x!=NULL)
		{
		res=wstaw(res,x->c,x->j);
		x=x->nastepny;
		}
while (y!=NULL)
		{
		res=wstaw(res,y->c,y->j);
		y=y->nastepny;
		}
return res;
}
//-----------------------------------------------------------------------------
int main()
{
WSPOLCZYNNIKI_PTR pw1, pw2, pw3, pwtemp;
pw1=pw2=pw3=pwtemp=NULL;
// wielomian pw1(x)=
pw1=wstaw(pw1,5,1700);
pw1=wstaw(pw1,6,700);
pw1=wstaw(pw1,10,50);
pw1=wstaw(pw1,5,0);

cout << "*** LISTA W1: "; pisz(pw1);
// wielomian pw2(x)=
pw2=wstaw(pw2,6,1800);
pw2=wstaw(pw2,-6,700);
pw2=wstaw(pw2,5,50);
pw2=wstaw(pw2,15,0);

cout << "*** LISTA W2: "; pisz(pw2);

pw3=dodaj(pw1,pw2);
// wielomian pw3(x)=
cout << "*** LISTA W3=W1+W2: "; pisz(pw3);

}
//-----------------------------------------------------------------------------
