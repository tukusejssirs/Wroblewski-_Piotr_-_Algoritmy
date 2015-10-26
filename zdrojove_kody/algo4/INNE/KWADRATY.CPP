// UWAGA: wy³¹cznie wersja DOS, dla kompilatorów firmy Borland

#include <GRAPHICS.H>
#include <stdio.h>
#include <conio.h>

void kwadraty(int n,double lg, double x, double y)
{
// n = parzysta liczba kwadratów
if (n>0)
	{
	lineto(x+lg,y);
	lineto(x+lg,y+lg);
	lineto(x,y+lg);
	lineto(x,y+lg/2);
	lineto(x+lg/2,y+lg);
	lineto(x+lg,y+lg/2);
	lineto(x+lg/2,y);
	lineto(x+lg/4,y+lg/4);
		 kwadraty(n-1,lg/2,x+lg/4,y+lg/4);
	lineto(x,y+lg/2);
	lineto(x,y);
	}
}
int main()
{
int Karta, Tryb;
Karta = DETECT;
initgraph(&Karta, &Tryb, "d:\\tc\\bgi\\");
setgraphmode(Tryb);
moveto(90,50);
kwadraty(5, getmaxx()/2, getx(), gety());
getch();
closegraph();
}

