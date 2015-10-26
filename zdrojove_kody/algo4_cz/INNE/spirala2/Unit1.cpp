//---------------------------------------------------------------------------
#include <vcl.h>
#include <math.h>

#pragma hdrstop

#include "Unit1.h"

const int alpha=10;

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
int Sirka;
Sirka = Rect.Right - Rect.Left;
PaintBox1->Canvas->MoveTo(90,50);
spirala(Sirka/2,90,50);
}
//---------------------------------------------------------------------------

TForm1::spirala(int lg, int x, int y)
{
if (lg>0)
  {
  PaintBox1->Canvas->LineTo(x+lg,y);
  PaintBox1->Canvas->LineTo(x+lg,y+lg);
  PaintBox1->Canvas->LineTo(x+alpha,y+lg);
  PaintBox1->Canvas->LineTo(x+alpha,y+alpha);
  spirala(lg-2*alpha,x+alpha,y+alpha);
 }
}


