#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
ifstream soubor_VST ("input.txt"); // n�jak� soubor na disku s n�kolika
ifstream soubor_BIN ("input.txt"); // datov�mi ��dky (znakov�mi �et�zci)
ofstream soubor_VYS ("output.txt");// v�stupn� soubor
string s;

while (getline(soubor_VST,s))
      soubor_VYS << s << endl;
// kop�rov�n� souboru input.txt do souboru output.txt po jednotliv�ch ��dc�ch
char c;
// vypisov�n� vstupn�ho souboru po jednotliv�ch znac�ch:
while ( soubor_BIN.read(&c,1) )
  cout << "Znak:"<< c << ", dec:"<< dec << (int)c << ",  hex:" << hex << (int)c << endl;
cout << endl; 
}
