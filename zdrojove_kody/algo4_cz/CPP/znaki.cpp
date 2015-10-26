#include <string.h>
#include <iostream>
using namespace std;

int main()
{
char s[100]; // zatím tady nic není, alternativní forma: char *s=new char[100];
cout << "Zadejte slovo:";
cin >> s; // Napište libovolné slovo
for (int i=0; i<=strlen(s); i++)
cout << "Znak [" << i << "]=" << s[i] << ",kód: " <<(int) s[i] << endl;
}
