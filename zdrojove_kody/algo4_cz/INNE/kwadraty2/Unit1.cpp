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
int Sirka;
Sirka = Rect.Right - Rect.Left;
PaintBox1->Canvas->MoveTo(90,50);
ctverce(2, Sirka/2,90,50);
}
//---------------------------------------------------------------------------

TForm1::ctverce(int n, int lg, int x, int y)
{
// n   - sudý poèet ètvercù
// x,y - souøadnice poèáteèního bodu
if (n>0)
  {
  PaintBox1->Canvas->LineTo(x+lg,y);
  PaintBox1->Canvas->LineTo(x+lg,y+lg);
  PaintBox1->Canvas->LineTo(x,y+lg);
  PaintBox1->Canvas->LineTo(x,y+lg/2);
  PaintBox1->Canvas->LineTo(x+lg/2,y+lg);
  PaintBox1->Canvas->LineTo(x+lg,y+lg/2);
  PaintBox1->Canvas->LineTo(x+lg/2,y);
  PaintBox1->Canvas->LineTo(x+lg/4,y+lg/4);
    ctverce(n-1,lg/2,x+lg/4,y+lg/4);
  PaintBox1->Canvas->LineTo(x,y+lg/2);
  PaintBox1->Canvas->LineTo(x,y);
  }
}


