#include <iostream>
using namespace std;

void odecti(char *s)
{
for (int i=0; s[i] != '\0'; i++)
   s[i]=255-s[i];
}

int main()
{
char s[]="ota je u auta";
cout << "Pùvodní posloupnost:\t" << s << endl;
odecti(s);
cout << "Zašifrovaná posloupnost:\t" << s << endl;
odecti(s);
cout << "Dešifrovaná posloupnost:\t" << s << endl;
}
