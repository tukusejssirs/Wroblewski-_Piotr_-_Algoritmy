const int DELKA_MAX=2;
enum stav {OK=0, ZASOBNIK_PLNY=1, ZASOBNIK_PRAZDNY=2};

template <class ZaklTyp>  class ZASOBNIK
{
public:                       // vrchol = prvn� VOLN� bu�ka
  ZASOBNIK() { vrchol=0;}            // konstruktor
  void clear() { vrchol=0;}      // nulov�n� z�sobn�ku
  int push(ZaklTyp x);
  int pop (ZaklTyp &w);
  int StavZasobniku();
private:
  ZaklTyp t[DELKA_MAX];    // zasobnik=t[0]...t[DELKA_MAX-1]
  int vrchol;
}; // konec definice t��dy ZASOBNIK

template <class ZaklTyp> int ZASOBNIK<ZaklTyp>::push(ZaklTyp x)
{
    if(vrchol<DELKA_MAX)
    {
   t[vrchol++]=x;
   return (OK);
   }else
      return (ZASOBNIK_PLNY);
}
template <class ZaklTyp> int ZASOBNIK<ZaklTyp>::pop(ZaklTyp &w)
 // do prom�nn� "w" bude ulo�ena hodnota vyzvednut� ze z�sobn�ku
{
if (vrchol>0)
   {
   w=t[--vrchol];
   return (OK);
   }else
   return (ZASOBNIK_PRAZDNY);
}
