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
cout << "P�vodn� posloupnost:\t" << s << endl;
odecti(s);
cout << "Za�ifrovan� posloupnost:\t" << s << endl;
odecti(s);
cout << "De�ifrovan� posloupnost:\t" << s << endl;
}
