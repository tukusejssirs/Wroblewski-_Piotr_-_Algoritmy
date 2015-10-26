const int DLUGOSC_MAX=2;
enum stan {OK=0, STOS_PELNY=1, STOS_PUSTY=2};

template <class TypPodst>  class STOS
{
public:              	    	// szczyt = pierwsza WOLNA komórka
  STOS() { szczyt=0;}         	// konstruktor
  void clear() { szczyt=0;}   	// zerowanie stosu
  int push(TypPodst x);
  int pop (TypPodst &w);
  int StanStosu();
private:
  TypPodst t[DLUGOSC_MAX]; 	// stos=t[0]...t[DLUGOSC_MAX-1]
  int szczyt;
}; // koniec definicji klasy STOS

template <class TypPodst> int STOS<TypPodst>::push(TypPodst x)
{
    if(szczyt<DLUGOSC_MAX)
    {
	t[szczyt++]=x;
	return (OK);
	}else
		return (STOS_PELNY);
}
template <class TypPodst> int STOS<TypPodst>::pop(TypPodst &w)
 // "w" zostanie "za³adowane" wartoœci¹ zdjêt¹ ze stosu
{
if (szczyt>0)
	{
	w=t[--szczyt];
	return (OK);
	}else
	return (STOS_PUSTY);
}
