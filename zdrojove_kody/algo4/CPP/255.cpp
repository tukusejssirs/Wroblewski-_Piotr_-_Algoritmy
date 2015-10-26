#include <iostream>
using namespace std;

void odejmij(char *s)
{
for (int i=0; s[i] != '\0'; i++)
	s[i]=255-s[i];
}

int main()
{
char s[]="ala ma kota";
cout << "Oryginalny ciąg znaków:\t" << s << endl;
odejmij(s);
cout << "Ciąg zakodowany:\t" << s << endl;
odejmij(s);
cout << "Ciąg odkodowany:\t" << s << endl;
}
