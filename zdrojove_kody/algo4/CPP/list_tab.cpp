#include <iostream>
using namespace std;
const int MaxTab=200;

class ListaTab
{
public:
	ListaTab() { tab[0]=0; }	// konstruktor klasy
								// metody zdefiniowane nieco dalej:
	void UsunElement(int k);
	void WstawElement(int x);
	void WstawElement(int x,int k);
	void WypiszListe();
private:
	int tab[MaxTab];		// tab[0] zarezerwowane!
};
//------------------------------------------------
void ListaTab::UsunElement(int k)
{ //usuwamy k-ty element listy, k>=1
if((k>=1) && (k<=tab[0]))
	{
	for(int i=k;i<tab[0];i++)
		tab[i]=tab[i+1];
	tab[0]--;
	}
}
//------------------------------------------------
void ListaTab::WstawElement(int x)
{//wstawiamy na koniec listy
if(tab[0]<MaxTab-1)
	tab[++tab[0]]=x;
}
//------------------------------------------------
void ListaTab::WstawElement(int x,int k)
{//wstawiamy na k-t¹ pozycjê listy
if((k>=1) && (k<=tab[0]+1) && (tab[0]<MaxTab-1))
	{
	for(int i=tab[0];i>=k;i--)
		tab[i+1]=tab[i];// robimy miejsce
	tab[k]=x;
	tab[0]++;
	}
}
//------------------------------------------------
void ListaTab::WypiszListe()
{
for (int i=1;i<=tab[0];i++)
	cout << tab[i] << "  ";
cout << endl;
}
//------------------------------------------------
int main()
{
int t[10]={2,5,-11,4,77,12,13,13,3,8};
ListaTab lst;
lst.WypiszListe();
for (int i=0;i<10;i++) lst.WstawElement(t[i]);
lst.WstawElement(0,4);
lst.WypiszListe();
}
// -------------------------------------------------------
