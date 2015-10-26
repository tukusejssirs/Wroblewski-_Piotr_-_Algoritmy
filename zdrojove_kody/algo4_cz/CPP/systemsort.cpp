// Verze pro systémy DOS a Windows (v systému Unix je nutné nahradit pøíkaz copy pøíkazem cp a upravit syntaxi pøíkazu 'sort'
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
ifstream soubor_vst1 ("input1.txt"); // vstupní soubor 1
ifstream soubor_vst2 ("input2.txt"); // vstupní soubor 2
ofstream soubor_VYS ("output.txt");// výsledný soubor
string s;
// spojení souborù pomocí jazyka C++
while (getline(soubor_vst1,s))  
   soubor_VYS << s << endl;
while (getline(soubor_vst2,s))  
   soubor_VYS << s << endl;
soubor_VYS.close(); // uvolnìní výsledného souboru

// Totéž lze samozøejmì provést i systémovým pøíkazem: 
// system("copy input1.txt+input2.txt output.txt");

system("sort output.txt /O output.txt"); // tøídìní výsledného souboru pomocí operaèního systému

   
}
