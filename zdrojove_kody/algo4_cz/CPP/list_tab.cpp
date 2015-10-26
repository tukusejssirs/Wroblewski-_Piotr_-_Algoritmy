#include <iostream>
using namespace std;
const int MaxPole=200;

class SeznamPole
{
public:
   SeznamPole() { tab[0]=0; }   // konstruktor t��dy
                        // metody jsou definov�ny d�le:
   void OdstranPrvek(int k);
   void VlozPrvek(int x);
   void VlozPrvek(int x,int k);
   void VypisSeznam();
private:
   int tab[MaxPole];     // tab[0] rezervov�no!
};
//------------------------------------------------
void SeznamPole::OdstranPrvek(int k)
{ // odstran�n� k-t�ho prvku seznamu, k>=1
if((k>=1) && (k<=tab[0]))
   {
   for(int i=k;i<tab[0];i++)
      tab[i]=tab[i+1];
   tab[0]--;
   }
}
//------------------------------------------------
void SeznamPole::VlozPrvek(int x)
{// vlo�en� na konec seznamu
if(tab[0]<MaxPole-1)
   tab[++tab[0]]=x;
}
//------------------------------------------------
void SeznamPole::VlozPrvek(int x,int k)
{// vlo�en� na k-tou pozici seznamu
if((k>=1) && (k<=tab[0]+1) && (tab[0]<MaxPole-1))
   {
   for(int i=tab[0];i>=k;i--)
      tab[i+1]=tab[i];// uvoln�n� m�sta
   tab[k]=x;
   tab[0]++;
   }
}
//------------------------------------------------
void SeznamPole::VypisSeznam()
{
for (int i=1;i<=tab[0];i++)
   cout << tab[i] << "  ";
cout << endl;
}
//------------------------------------------------
int main()
{
int t[10]={2,5,-11,4,77,12,13,13,3,8};
SeznamPole lst;
lst.VypisSeznam();
for (int i=0;i<10;i++) lst.VlozPrvek(t[i]);
lst.VlozPrvek(0,4);
lst.VypisSeznam();
}
// -------------------------------------------------------
