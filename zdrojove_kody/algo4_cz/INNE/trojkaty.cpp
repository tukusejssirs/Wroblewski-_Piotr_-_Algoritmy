// UPOZORNÌNÍ: verze pouze pro systém DOS a kompilátory firmy Borland

#include <GRAPHICS.H>
#include <conio.h>
#include <math.h>
void trojuhelniky(double n,double lg, double x, double y)
{
// n = poèet èástí
if (n>0)
   {
   double a=lg/n;
   double h=a*sqrt(3)/2.0;
   lineto(x-a/2.0,y-h);
   trojuhelniky(n-1,lg-a,x-a/2.0,y-h);
   lineto(x+a/2.0,y-h);
   for (double i=1;i<n;i++)
   {
     lineto(x+(i-1)*a/2.0,y-(i+1)*h);
     lineto(x+(i+1)*a/2.0,y-(i+1)*h);
     }
   lineto( x,y);
   }
}
int main()
{
int Karta, Rezim;
Karta = DETECT;
initgraph(&Karta, &Rezim, "d:\\tc\\bgi\\");
setgraphmode(Rezim);
moveto(getmaxx()/2,getmaxy()-10);
trojuhelniky(6,getmaxx()/2,getx(),gety());
getch();
closegraph();
}
