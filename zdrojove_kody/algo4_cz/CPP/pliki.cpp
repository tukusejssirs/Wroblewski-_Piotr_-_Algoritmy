#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
ifstream soubor_VST ("input.txt"); // nìjaký soubor na disku s nìkolika
ifstream soubor_BIN ("input.txt"); // datovými øádky (znakovými øetìzci)
ofstream soubor_VYS ("output.txt");// výstupní soubor
string s;

while (getline(soubor_VST,s))
      soubor_VYS << s << endl;
// kopírování souboru input.txt do souboru output.txt po jednotlivých øádcích
char c;
// vypisování vstupního souboru po jednotlivých znacích:
while ( soubor_BIN.read(&c,1) )
  cout << "Znak:"<< c << ", dec:"<< dec << (int)c << ",  hex:" << hex << (int)c << endl;
cout << endl; 
}
