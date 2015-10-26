// definicje typ�w danych
enum szukanie {PORAZKA=0, SUKCES=1};
typedef struct rob
{
int wartosc;
struct rob *nastepny; // wska�nik do
}ELEMENT;             // nast�pnego elementu

// pocz�tek deklaracji klasy LISTA

class LISTA
{
public:
  // nag��wki:	
	friend LISTA& operator +(LISTA&,LISTA&); // sumuje dwie listy
	friend void fuzja(LISTA &x,LISTA &y);
	void wypisz();         		// wypisuje zawarto�� listy
	int szukaj(int x);   	   		// szuka elementu x na li�cie
	void dorzuc1(int x); 	   		// dorzuca bez sortowania
	void dorzuc2(int x); 	   		// dorzuca z sortowaniem
	LISTA& operator --(int); 		// usuwa ostatni element listy, parametr 'int'
	// jest sztuczny, informuje kompilator o tym, �e jest to operator "przyrostkowy"
	// kilka prostych metod:
	bool  pusta()             					// czy lista co� zawiera?
	{
	return (inf.glowa==NULL);
	}
	void zeruj()								// zeruje list� bez wykonywania "delete"
	{
	inf.glowa=inf.ogon=NULL;
	}
	LISTA()	// konstruktor
	{
	inf.glowa=inf.ogon=NULL;
	}	
	~LISTA()	// destruktor, kt�ry u�ywa przedefiniowanego operatora --
	{			     	
	while (!pusta()) (*this)--;
	}
private:
	typedef struct        // struktura informacyjna zapewni dost�p do listy
	{
	ELEMENT *glowa;
	ELEMENT *ogon;
	}INFO;

	INFO inf;
}; //koniec deklaracji klasy LISTA
