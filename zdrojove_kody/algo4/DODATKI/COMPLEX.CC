class Complex
 {
  public:			// poczatek sekcji publicznej
  Complex(double x,double y)  	// konstruktor klasy ma tak� sam� nazw� jak klasa
	{
	Re=x;
	Im=y;
	}
  void wypisz(); //  nag��wek funkcji kt�ra wypisuje liczb� urojona
  double Czesc_Rzecz() { return Re; } // zwraca cz�� rzeczywista
  double Czesc_Uroj () { return Im; } // zwraca cz�� urojona
  friend Complex& operator +(Complex,Complex);    // nag��wek funkcji
  friend ostream& operator << (ostream&,Complex); //       j.w.

  private:          	// poczatek sekcji prywatnej
	double Re,Im;   //reprezentacja jako Re+j*Im
 };//koniec deklaracji (i cz�ciowej definicji) klasy Complex
