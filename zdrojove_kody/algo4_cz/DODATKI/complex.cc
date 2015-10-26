class Complex
 {
  public:         // zaèátek veøejné sekce
  Complex(double x,double y)     // konstruktor tøídy má stejná název jako sama tøída
   {
   Re=x;
   Im=y;
   }
  void vypis(); //  hlavièka funkce, která vypisuje imaginární èíslo
  double Cast_Real() { return Re; } // vrací reálnou èást
  double Cast_Imag() { return Im; } // vrací imaginární èást
  friend Complex& operator +(Complex,Complex);    // hlavièka funkce
  friend ostream& operator << (ostream&,Complex); // viz vıše

  private:           // zaèátek soukromé sekce
   double Re,Im;   // reprezentace jako Re+j*Im
 }; // konec deklarace (a èásteèné definice) tøídy Complex
