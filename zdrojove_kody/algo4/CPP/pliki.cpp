#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
ifstream plik_WEJ ("input.txt"); // stwórz jakiœ plik na dysku z kilkoma
ifstream plik_BIN ("input.txt"); // wierszami danych (ci¹gi znaków)
ofstream plik_WYJ ("output.txt");// pli wyjœciowy
string s;

while (getline(plik_WEJ,s))
	   plik_WYJ << s << endl;
// kopiujemy linia po linii plik input.txt do output.txt
char c;
// wypisujemy znak po znaku plik wejœciowy:
while ( plik_BIN.read(&c,1) )
  cout << "Znak:"<< c << ", dec:"<< dec << (int)c << ",  hex:" << hex << (int)c << endl;
cout << endl; 
}
