#include <string>
#include <iostream>
using namespace std;

int main()
{
string s1, s2="ma kota"; // deklaracja + inicjalizacja
s1 = "ala "; // przypisanie warto�ci
string s3 = s1 + s2 + "\n------\n"; // sklejanie �a�cuch�w
cout << "s3=" << s3;
s3.erase(); // zerujemy ci�g znak�w
cout << "s3=" << s3 << endl; 
for (int i=0; i < s2.length(); i++) // sprawd�my, co jest w �rodku s2:
cout << "s2: znak [" << i << "]=" << s2[i] << ",kod: " <<(int) s2[i] << endl;
}
