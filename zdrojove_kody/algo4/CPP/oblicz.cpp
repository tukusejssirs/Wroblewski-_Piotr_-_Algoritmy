#include <iostream>
using namespace std;

#include <stdlib.h>
#include <math.h>
#include <string.h>

double transl(char *s)
// zamienia ci¹gi znaków typu 1+1 na 2, 1+1+2*5 na 12 etc.
// uwaga funkcja nie analizuje dzielenia i badania przypadku
// dzielenia przez zero!
{
int i,n;
char *s1;
n=strlen(s);
s1= new char[n+1]; // kopia robocza tekstu wejœciowego
strcpy(s1,s);      // kopia ci¹gu wejœciowego

for(i=0;i<n;i++)// szukamy znaków + i *
 if(s[i]=='+'||s[i]=='*')
	{
	 s1[i]='\0';
	 if(s[i]=='+')
		return transl(s1)+transl(s+i+1);
	 else
		return transl(s1)*transl(s+i+1);
	 }
// przypadek elementarny:
delete s1;
return atof(s); //  atof= "ascii to float"
}


int main()
{
cout << "1+1="<< transl("1+1") << endl;         // 2   OK
cout << "2*2*3="<< transl("2*2*3") << endl;     // 12  OK
cout << "2+2*3="<< transl("2+2*3") << endl;     // 8   OK
cout << "2+2+3="<< transl("2+2+3") << endl;     // 7   OK
cout << "2+2*0="<< transl("2+2*0") << endl;     // 2   OK
cout << "2*3+4*5="<< transl("2*3+4*5") << endl; // 46 Ÿle!
}
