// UPOZORNÌNÍ: verze pouze pro systém DOS a kompilátory firmy Borland

#include <GRAPHICS.H>
#include <stdio.h>
#include <conio.h>

void ctverce(int n,double lg, double x, double y)
{
// n = sudý poèet ètvercù
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
       ctverce(n-1,lg/2,x+lg/4,y+lg/4);
   lineto(x,y+lg/2);
   lineto(x,y);
   }
}
int main()
{
int Karta, Rezim;
Karta = DETECT;
initgraph(&Karta, &Rezim, "d:\\tc\\bgi\\");
setgraphmode(Rezim);
moveto(90,50);
ctverce(5, getmaxx()/2, getx(), gety());
getch();
closegraph();
}

