// definice datových typù
enum hledani {NEUSPECH=0, USPECH=1};
typedef struct rob
{
int hodnota;
struct rob *dalsi; // ukazatel na
}PRVEK;             // následující prvek

// zaèátek deklarace tøídy SEZNAM

class SEZNAM
{
public:
  // hlavièky:   
   friend SEZNAM& operator +(SEZNAM&,SEZNAM&); // sèítá dva seznamy
   friend void slouceni(SEZNAM &x,SEZNAM &y);
   void vypis();             // vypíše obsah seznamu
   int hledej(int x);               // hledá v seznamu prvek x
   void vloz(int x);             // pøidá prvek bez tøídìní
   void vloz2(int x);             // pøidá prvek s tøídìním
   SEZNAM& operator --(int);      // odstraní poslední prvek seznamu, parametr 'int'
   // je umìlý a informuje kompilátor o tom, že se jedná o "pøírùstkový" operátor
   // nìkolik jednoduchých metod:
   bool  prazdne()                          // je seznam prázdný?
   {
   return (inf.hlava==NULL);
   }
   void nuluj()                        // nuluje seznam bez odstranìní
   {
   inf.hlava=inf.ocas=NULL;
   }
   SEZNAM()  // konstruktor
   {
   inf.hlava=inf.ocas=NULL;
   }   
   ~SEZNAM() // destruktor, který používá pøedefinovaný operátor --
   {                 
   while (!prazdne()) (*this)--;
   }
private:
   typedef struct        // informaèní struktura zajistí pøístup k seznamu
   {
   PRVEK *hlava;
   PRVEK *ocas;
   }INFO;

   INFO inf;
}; // konec deklarace tøídy SEZNAM
