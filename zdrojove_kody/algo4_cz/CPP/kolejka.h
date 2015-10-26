enum stav {OK, CHYBA};

template <class ZaklTyp>  class FIFO
{
private:
   ZaklTyp *t;
   int hlava,ocas,MaxElt;
public:
  FIFO(int n)
    {
    MaxElt=n;
    hlava=ocas=0;
    t=new ZaklTyp[MaxElt+1];
    }

  void vloz(ZaklTyp x)
    {
    t[ocas++]=x;
    if(ocas>MaxElt) ocas=0;
    }

  int obsluz(ZaklTyp &w)
    {
    if (hlava==ocas) 
      return CHYBA; // informace o chyb� p�i operaci
    w=t[hlava++];
    if(hlava>MaxElt) hlava=0;
    return OK;
    }

  bool prazdne()
    {// je fronta pr�zdn�?
    if (hlava==ocas)
      return true; // fronta je pr�zdn�
    else
    return  false;
    }
};
