// UWAGA: wyłącznie wersja DOS, dla kompilatorów firmy Borland

#include <GRAPHICS.H>
#include <conio.h>

const double alpha=10;

void spirala(double lg,double x,double y)
{
if (lg>0)
   {
   lineto(x+lg,y);
   lineto(x+lg,y+lg);
   lineto(x+alpha,y+lg);
   lineto(x+alpha,y+alpha);
   spirala(lg-2*alpha,x+alpha,y+alpha);
   }
}
int main()
{
int Karta, Tryb;
Karta = DETECT;
initgraph(&Karta, &Tryb, "d:\\tc\\bgi\\");
setgraphmode(Tryb);
moveto(90,50);
spirala(getmaxx()/2,getx(),gety());
getch();
closegraph();
}

