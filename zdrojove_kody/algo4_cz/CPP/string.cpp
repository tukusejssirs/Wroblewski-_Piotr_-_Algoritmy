#include <string>
#include <iostream>
using namespace std;

int main()
{
string s1, s2="ma maso"; // deklarace + inicializace
s1 = "Ema "; // p�i�azen� hodnoty
string s3 = s1 + s2 + "\n------\n"; // spojov�n� �et�zc�
cout << "s3=" << s3;
s3.erase(); // nulov�n� znakov�ho �et�zce
cout << "s3=" << s3 << endl; 
for (int i=0; i < s2.length(); i++) // kontrola obsahu �et�zce s2:
cout << "s2: znak [" << i << "]=" << s2[i] << ",k�d: " <<(int) s2[i] << endl;
}
