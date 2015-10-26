// definice datov�ch typ�
enum hledani {NEUSPECH=0, USPECH=1};
typedef struct rob
{
int hodnota;
struct rob *dalsi; // ukazatel na
}PRVEK;             // n�sleduj�c� prvek

// za��tek deklarace t��dy SEZNAM

class SEZNAM
{
public:
  // hlavi�ky:   
   friend SEZNAM& operator +(SEZNAM&,SEZNAM&); // s��t� dva seznamy
   friend void slouceni(SEZNAM &x,SEZNAM &y);
   void vypis();             // vyp�e obsah seznamu
   int hledej(int x);               // hled� v seznamu prvek x
   void vloz(int x);             // p�id� prvek bez t��d�n�
   void vloz2(int x);             // p�id� prvek s t��d�n�m
   SEZNAM& operator --(int);      // odstran� posledn� prvek seznamu, parametr 'int'
   // je um�l� a informuje kompil�tor o tom, �e se jedn� o "p��r�stkov�" oper�tor
   // n�kolik jednoduch�ch metod:
   bool  prazdne()                          // je seznam pr�zdn�?
   {
   return (inf.hlava==NULL);
   }
   void nuluj()                        // nuluje seznam bez odstran�n�
   {
   inf.hlava=inf.ocas=NULL;
   }
   SEZNAM()  // konstruktor
   {
   inf.hlava=inf.ocas=NULL;
   }   
   ~SEZNAM() // destruktor, kter� pou��v� p�edefinovan� oper�tor --
   {                 
   while (!prazdne()) (*this)--;
   }
private:
   typedef struct        // informa�n� struktura zajist� p��stup k seznamu
   {
   PRVEK *hlava;
   PRVEK *ocas;
   }INFO;

   INFO inf;
}; // konec deklarace t��dy SEZNAM
