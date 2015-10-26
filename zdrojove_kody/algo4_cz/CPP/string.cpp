#include <string>
#include <iostream>
using namespace std;

int main()
{
string s1, s2="ma maso"; // deklarace + inicializace
s1 = "Ema "; // pøiøazení hodnoty
string s3 = s1 + s2 + "\n------\n"; // spojování øetìzcù
cout << "s3=" << s3;
s3.erase(); // nulování znakového øetìzce
cout << "s3=" << s3 << endl; 
for (int i=0; i < s2.length(); i++) // kontrola obsahu øetìzce s2:
cout << "s2: znak [" << i << "]=" << s2[i] << ",kód: " <<(int) s2[i] << endl;
}
