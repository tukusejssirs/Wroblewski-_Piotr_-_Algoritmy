#include <iostream>
using namespace std;

void Xor(char *s, char xor_key)
{
for (int i=0; s[i] != '\0'; i++)
      s[i]= s[i] ^ xor_key;
}

int main()
{
char s[]="ota je u auta";
cout << "P�vodn� posloupnost:\t" << s << endl;
Xor(s,12);
cout << "Za�ifrovan� posloupnost:\t" << s << endl;
Xor(s,12);
cout << "De�ifrovan� posloupnost:\t" << s << endl;
}
