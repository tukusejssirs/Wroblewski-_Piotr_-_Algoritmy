#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
ifstream plik_WEJ ("input.txt"); // stw�rz jaki� plik na dysku z kilkoma
ifstream plik_BIN ("input.txt"); // wierszami danych (ci�gi znak�w)
ofstream plik_WYJ ("output.txt");// pli wyj�ciowy
string s;

while (getline(plik_WEJ,s))
	   plik_WYJ << s << endl;
// kopiujemy linia po linii plik input.txt do output.txt
char c;
// wypisujemy znak po znaku plik wej�ciowy:
while ( plik_BIN.read(&c,1) )
  cout << "Znak:"<< c << ", dec:"<< dec << (int)c << ",  hex:" << hex << (int)c << endl;
cout << endl; 
}
