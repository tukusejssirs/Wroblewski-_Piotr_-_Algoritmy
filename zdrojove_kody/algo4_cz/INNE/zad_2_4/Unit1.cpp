//---------------------------------------------------------------------------
#include <vcl.h>
#include <math.h>

#pragma hdrstop

#include "Unit1.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
  : TForm(Owner)
{
}

//---------------------------------------------------------------------------

void __fastcall TForm1::PaintBox1Paint(TObject *Sender)
{
TRect Rect = PaintBox1->ClientRect;
int Sirka, Vyska;
Sirka = Rect.Right - Rect.Left;
Vyska = Rect.Bottom - Rect.Top;

// PaintBox1->Canvas->MoveTo(Sirka/2,Vyska);

PaintBox1->Canvas->MoveTo(Sirka/2,Vyska);


trojuhelniky(6,Sirka/2,Sirka/2,Vyska);
}
//---------------------------------------------------------------------------

TForm1::trojuhelniky(int n, int lg, int x, int y)
{
// n = poèet èástí
if (n>0)
   {
   int a=lg/n;
   int h=a*sqrt(3)/2;
   PaintBox1->Canvas->LineTo(x-a/2,y-h);
   trojuhelniky(n-1,lg-a,x-a/2,y-h);
   PaintBox1->Canvas->LineTo(x+a/2,y-h);
   for (double i=1;i<n;i++)
   {
     PaintBox1->Canvas->LineTo(x+(i-1)*a/2,y-(i+1)*h);
     PaintBox1->Canvas->LineTo(x+(i+1)*a/2,y-(i+1)*h);
     }
   PaintBox1->Canvas->LineTo( x,y);
   }
}


