// Verze pro syst�my DOS a Windows (v syst�mu Unix je nutn� nahradit p��kaz copy p��kazem cp a upravit syntaxi p��kazu 'sort'
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
ifstream soubor_vst1 ("input1.txt"); // vstupn� soubor 1
ifstream soubor_vst2 ("input2.txt"); // vstupn� soubor 2
ofstream soubor_VYS ("output.txt");// v�sledn� soubor
string s;
// spojen� soubor� pomoc� jazyka C++
while (getline(soubor_vst1,s))  
   soubor_VYS << s << endl;
while (getline(soubor_vst2,s))  
   soubor_VYS << s << endl;
soubor_VYS.close(); // uvoln�n� v�sledn�ho souboru

// Tot� lze samoz�ejm� prov�st i syst�mov�m p��kazem: 
// system("copy input1.txt+input2.txt output.txt");

system("sort output.txt /O output.txt"); // t��d�n� v�sledn�ho souboru pomoc� opera�n�ho syst�mu

   
}
