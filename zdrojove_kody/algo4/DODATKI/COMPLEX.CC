class Complex
 {
  public:			// poczatek sekcji publicznej
  Complex(double x,double y)  	// konstruktor klasy ma tak¹ sam¹ nazwê jak klasa
	{
	Re=x;
	Im=y;
	}
  void wypisz(); //  nag³ówek funkcji która wypisuje liczbê urojona
  double Czesc_Rzecz() { return Re; } // zwraca czêœæ rzeczywista
  double Czesc_Uroj () { return Im; } // zwraca czêœæ urojona
  friend Complex& operator +(Complex,Complex);    // nag³ówek funkcji
  friend ostream& operator << (ostream&,Complex); //       j.w.

  private:          	// poczatek sekcji prywatnej
	double Re,Im;   //reprezentacja jako Re+j*Im
 };//koniec deklaracji (i czêœciowej definicji) klasy Complex
