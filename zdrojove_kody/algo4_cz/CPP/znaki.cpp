#include <string.h>
#include <iostream>
using namespace std;

int main()
{
char s[100]; // zat�m tady nic nen�, alternativn� forma: char *s=new char[100];
cout << "Zadejte slovo:";
cin >> s; // Napi�te libovoln� slovo
for (int i=0; i<=strlen(s); i++)
cout << "Znak [" << i << "]=" << s[i] << ",k�d: " <<(int) s[i] << endl;
}
