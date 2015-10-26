enum stan {OK, BLAD};

template <class TypPodst>  class FIFO
{
private:
	TypPodst *t;
	int glowa,ogon,MaxElt;
public:
  FIFO(int n)
	 {
	 MaxElt=n;
	 glowa=ogon=0;
	 t=new TypPodst[MaxElt+1];
	 }

  void wstaw(TypPodst x)
	 {
	 t[ogon++]=x;
	 if(ogon>MaxElt) ogon=0;
	 }

  int obsluz(TypPodst &w)
	 {
	 if (glowa==ogon) 
		return BLAD; // informacja o b³êdzie operacji
	 w=t[glowa++];
	 if(glowa>MaxElt) glowa=0;
	 return OK;
	 }

  bool pusta()
	 {// czy kolejka jest pusta?
	 if (glowa==ogon)
		return true; // kolejka pusta
	 else
	 return	false;
	 }
};
