class Complex
 {
  public:         // za��tek ve�ejn� sekce
  Complex(double x,double y)     // konstruktor t��dy m� stejn� n�zev jako sama t��da
   {
   Re=x;
   Im=y;
   }
  void vypis(); //  hlavi�ka funkce, kter� vypisuje imagin�rn� ��slo
  double Cast_Real() { return Re; } // vrac� re�lnou ��st
  double Cast_Imag() { return Im; } // vrac� imagin�rn� ��st
  friend Complex& operator +(Complex,Complex);    // hlavi�ka funkce
  friend ostream& operator << (ostream&,Complex); // viz v��e

  private:           // za��tek soukrom� sekce
   double Re,Im;   // reprezentace jako Re+j*Im
 }; // konec deklarace (a ��ste�n� definice) t��dy Complex
