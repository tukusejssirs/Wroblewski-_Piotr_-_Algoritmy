// Program do gry w "kó³ko i krzy¿yk" z wykorzystaniem
// procedury mini-max. Jest to wersja "beta",  gdy¿ nie
// mialem czasu go w pe³ni przetestowaæ...

#include <iostream>
using namespace std;

#define GRACZ_KONTRA_KOMPUTER 1

const int GLEBOKOSC_OK=2;

const int plus_niesk  =  1000;
const int minus_niesk = -1000;

int MiniMaxUsed=0;

char ch;

enum KTO{nic,komputer,czlowiek};

struct POLE{int val; int gracz;};

struct KANDYDACI{
	int   cpt;
	int   tbl[9];
	};
// ____________________________________________________________________
KTO Nastepny_Gracz(KTO gracz)
{
if (gracz==komputer)
	return czlowiek;
else
	return komputer;
}
// ____________________________________________________________________
int WystarczajaGleboko(int p)
// Czy g³êbokoœæ MiniMax jest OK?
// (sta³a GLEBOKOSC_OK jest zdefiniowana na pocz¹tku pliku)
{
if (p==GLEBOKOSC_OK)
	return 1;
else
	return 0;
}
// ____________________________________________________________________
void WyswietlPlansze(KTO plansza[9])
{
for(int i=0;i<9;i++)
  {
  if ((i==3) || (i==6) || (i==9)) cout << endl;
  switch(plansza[i])
	{
	case nic:      cout << " *  ";break;
	case komputer: cout << " X  ";break;
	case czlowiek: cout << " O  ";break;
	}
  }
}
// ____________________________________________________________________
void Zeruj(KTO *plansza)
// zeruje teren gry
{
for (int i=0;i<9;i++) plansza[i]=nic;
}
// ____________________________________________________________________
KANDYDACI Generuj(KTO plansza[9])
// generuje mo¿liwe kandydatury nastepnego ruchu
{
KANDYDACI t;
 t.cpt=-1;
 for(int i=0;i<9;i++)
 if (plansza[i]==nic)
	  t.tbl[++t.cpt]=i; // zapamiêtanie wolnej pozycji
return t;
}
// ____________________________________________________________________
int KoniecGry(KTO plansza[9])
{
int a,b,c,d,e,f,g,h;

// sukces w linii?

a=((plansza[0]==plansza[1])&&(plansza[1]==plansza[2]) && (plansza[0]!=nic));
b=((plansza[3]==plansza[4])&&(plansza[4]==plansza[5]) && (plansza[3]!=nic));
c=((plansza[6]==plansza[7])&&(plansza[7]==plansza[8]) && (plansza[6]!=nic));

// sukces w kolumnie?

d=((plansza[0]==plansza[3])&&(plansza[3]==plansza[6]) && (plansza[0]!=nic));
e=((plansza[1]==plansza[4])&&(plansza[4]==plansza[7]) && (plansza[1]!=nic));
f=((plansza[2]==plansza[5])&&(plansza[5]==plansza[8]) && (plansza[2]!=nic));

// sukces na przek¹tnej

g=((plansza[0]==plansza[4])&&(plansza[4]==plansza[8]) && (plansza[0]!=nic));
h=((plansza[2]==plansza[4])&&(plansza[4]==plansza[6]) && (plansza[2]!=nic));

if (!(a||b||c||d||e||f||g||h)) 
	return 0;

if (a) return 1;    // robimy to aby wiedzieæ kto wygra³
if (b) return 3;
if (c) return 6;
if (d) return 3;
if (e) return 4;
if (f) return 5;
if (g) return 4;
if (h) return 4;

}
// ____________________________________________________________________
bool SprawdzCzyKoniecGry(KTO plansza[9],KTO gracz)
{
if (KoniecGry(plansza))
 {
  WyswietlPlansze(plansza);
  cout << "\n  ** KONIEC GRY ** \n";
  if (gracz==czlowiek)
		cout << "WYGRA£EŒ, GRATULACJE!\n";
  else
		cout << "WYGRA£ KOMPUTER! Naciœnij klawisz\n";
  cin.get();
  return true;
 }

KANDYDACI nastepni=Generuj(plansza);

if (nastepni.cpt==-1)
 {
	 WyswietlPlansze(plansza);
	 cout << "\n  ** KONIEC GRY ** \n";
	 cout << "Remis! Naciœnij klawisz \n";
	 cin.get();
	 return true; 
  }

return false;
}
// ____________________________________________________________________
int LiniaPusta(int Line,KTO plansza[9])
{
return ((plansza[(Line-1)*3]==nic) && (plansza[(Line-1)*3+1]==nic) && (plansza[(Line-1)*3+2]==nic));
}
// ____________________________________________________________________
int KolumnaPusta(int Col,KTO plansza[9])
{
return ((plansza[Col-1]==nic) && (plansza[(Col-1)+3]==nic) && (plansza[(Col-1)+6]==nic));
}
// ____________________________________________________________________
int LiniaPelna(int Line,KTO plansza[9])
{
return !((plansza[(Line-1)*3]==nic) || (plansza[(Line-1)*3+1]==nic) || (plansza[(Line-1)*3+2]==nic));
}
// ____________________________________________________________________
int KolumnaPelna(int Col,KTO plansza[9])
{
return !((plansza[Col-1]==nic) || (plansza[(Col-1)+3]==nic) || (plansza[(Col-1)+6]==nic));
}
// ____________________________________________________________________
int Przekatna1_Pusta(KTO plansza[9])
{
return ((plansza[0]==nic) && (plansza[4]==nic) && (plansza[8]==nic));
}
// ____________________________________________________________________
int Diag1_Full (KTO plansza[9])
{
return !((plansza[0]==nic) || (plansza[4]==nic) || (plansza[8]==nic));
}
// ____________________________________________________________________
int Diag2_Empty(KTO plansza[9])
{
return ((plansza[2]==nic) && (plansza[4]==nic) && (plansza[6]==nic));
}
// ____________________________________________________________________
int Diag2_Full (KTO plansza[9])
{
return !((plansza[2]==nic) || (plansza[4]==nic) || (plansza[6]==nic));
}
// ____________________________________________________________________
int Ewaluacja(KTO plansza[9],KTO gracz)
//
{
int val=0;
int result=KoniecGry(plansza);
if (result)
{
if (plansza[result]==Nastepny_Gracz(gracz))
	 return minus_niesk;   			// pozycja wygrywaj¹ca dla przeciwnika
else
	return  plus_niesk;    			// pozycja wygrywaj¹ca dla nas
}
for(int Line=1;Line<=3;Line++)
  if (!(LiniaPusta(Line,plansza) || LiniaPelna(Line,plansza)))
	 {
	 if ((plansza[(Line-1)*3]==Nastepny_Gracz(gracz)) || (plansza[(Line-1)*3+1]==Nastepny_Gracz(gracz)) || (plansza[(Line-1)*3+2]==Nastepny_Gracz(gracz)))
	 val-=1;
	 if ((plansza[(Line-1)*3]==gracz) || (plansza[(Line-1)*3+1]==gracz) || (plansza[(Line-1)*3+2]==gracz))
	 val+=1;
	 }
for(int Col=1;Col<=3;Col++)
  if (!(KolumnaPusta(Col,plansza) || KolumnaPelna(Col,plansza)))
	 {
	 if ((plansza[Col-1]==Nastepny_Gracz(gracz)) || (plansza[(Col-1)+3]==Nastepny_Gracz(gracz)) || (plansza[(Col-1)+6]==Nastepny_Gracz(gracz)))
	 val-=1;
	 if ((plansza[Col-1]==gracz) || (plansza[(Col-1)+3]==gracz) || (plansza[(Col-1)+6]==gracz))
	 val+=1;
	 }
if (!(Przekatna1_Pusta(plansza)||Diag1_Full(plansza)))
{
 if ((plansza[0]==Nastepny_Gracz(gracz)) || (plansza[4]==Nastepny_Gracz(gracz)) || (plansza[8]==Nastepny_Gracz(gracz)))
 val=val-1;
 if ((plansza[0]==gracz) || (plansza[4]==gracz) || (plansza[8]==gracz))
 val+=1;
};

if (!(Diag2_Empty(plansza)||Diag2_Full(plansza)))
{
 if ((plansza[2]==Nastepny_Gracz(gracz)) || (plansza[4]==Nastepny_Gracz(gracz)) || (plansza[6]==Nastepny_Gracz(gracz)))
 val-=1;
 if ((plansza[2]==gracz) || (plansza[4]==gracz) || (plansza[6]==gracz))
 val+=1;
};
return val;
}
// ____________________________________________________________________
void WykonajRuch(KTO gracz,KTO *plansza,int ruch)
{
plansza[ruch]=gracz;
}
// ____________________________________________________________________
KTO NastepnyGracz(KTO gracz, int glebokosc)
{
// dla którego gracza wykonujemy ewaluacje mini-max
if ((glebokosc % 2) == 0)
	return gracz;
else
	return Nastepny_Gracz(gracz);
}
// ____________________________________________________________________
POLE MiniMax(KTO plansza[9],int glebokosc,KTO gracz)
{
POLE res;
KANDYDACI nastepni;
if (WystarczajaGleboko(glebokosc))  // wêzel uznawany za po³o¿ony dostatecznie g³êboko
 {
 res.val=Ewaluacja(plansza,gracz);
 res.gracz=-1;
 return res;
 };

nastepni=Generuj(plansza);

if (nastepni.cpt==-1)	// wêze³ terminalny
  {
  res.val=Ewaluacja(plansza,gracz);
  res.gracz=-1;
  return res;
  }

int lepszy=minus_niesk;
int gracz_1;
for (int i=0; i<=nastepni.cpt;i++)
 {
 KTO plansza1[9];
 for (int k=0;k<9;k++) plansza1[k]=plansza[k];
 plansza1[nastepni.tbl[i]]=NastepnyGracz(gracz,glebokosc);
 POLE r;
 r=MiniMax(plansza1,glebokosc+1,gracz);
 if (-r.val>lepszy)
	{
	 lepszy=-r.val;
	 gracz_1=nastepni.tbl[i];
	}
 }
res.val=lepszy;
res.gracz=gracz_1;
return res;
}
// ____________________________________________________________________
bool Zajete(KTO plansza[9],int ruch)
// Pole wolne?
{
if (ruch==-1) 
	return true;
if (plansza[ruch] != nic)
	return false;
else
	return true;
}
// ____________________________________________________________________
void WybierzRuch(KTO gracz,KTO plansza[9],int &ruch)
// wybór ruchu zale¿y od tego, kto gra
{
if (gracz==czlowiek)
	do
	 {
#ifdef GRACZ_KONTRA_KOMPUTER // gracz vs komputer
	  cout << "\n Twój wybor(0..8):";
	  cin >> ruch;
#else                       // komputer vs komputer
	  cout << "Naciœnij klawisz...";
	  POLE wybor=MiniMax(plansza,0,gracz);
	  ruch=wybor.gracz;
	  char ch;
	  cin.get(ch);
#endif
	 } while(!Zajete(plansza,ruch));
	else {
		  cout << "\nMój ruch:\n";
		  POLE wybor=MiniMax(plansza,0,gracz);
		  ruch=wybor.gracz;
#ifndef GRACZ_KONTRA_KOMPUTER
			cout << "Naciœnij klawisz...";
		  cin.get();
#endif
  }
}

// ____________________________________________________________________

void Graj(KTO *plansza,KTO gracz)
  {
  int ruch;
  bool koniec=false;
  KTO gracz1=gracz;
  while(!koniec)
  {
  WyswietlPlansze(plansza);
  WybierzRuch(gracz1,plansza,ruch);
  WykonajRuch(gracz1,plansza,ruch);
  koniec = SprawdzCzyKoniecGry(plansza,gracz1);
  gracz1=Nastepny_Gracz(gracz1);
 }
}
// ____________________________________________________________________
int main()
{
KTO gracz;
KTO plansza[9];
Zeruj(plansza);
gracz=komputer;
Graj(plansza,gracz);
//system("PAUSE");//zatrzymanie programu do nacisniecia jakiegos przycisku

}
// ____________________________________________________________________
