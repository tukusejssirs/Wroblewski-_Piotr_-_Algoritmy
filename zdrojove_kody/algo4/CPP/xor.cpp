#include <iostream>
using namespace std;

void Xor(char *s, char xor_key)
{
for (int i=0; s[i] != '\0'; i++)
		s[i]= s[i] ^ xor_key;
}

int main()
{
char s[]="ala ma kota";
cout << "Oryginalny ci�g znak�w:\t" << s << endl;
Xor(s,12);
cout << "Ci�g zakodowany:\t" << s << endl;
Xor(s,12);
cout << "Ci�g odkodowany:\t" << s << endl;
}
