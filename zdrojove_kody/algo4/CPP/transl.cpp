#include <iostream>
using namespace std;


#include <math.h>
#include <string.h>
#include <stdlib.h>

double transl(char *s)
// zamienia ci¹gi znaków typu 1+1 na 2, 1+1+2x50% na 2 etc.
// transl("1+1")       = 2.0
// transl("1+2+3")     = 6.0
// transl("1+2+3x30%") = 1.8
// transl("1+1+2x50%") = 2.0
// transl("1+1+2*50%") = 2.0
{
int n;
char s1[10];
register int i;
n=strlen(s);
strcpy(s1,s);
for(i=0;i<n;i++)
 if(s[i]=='x' || s[i]=='*')
	{
	 s1[i]='\0';
	 return transl(s1)*atof(s+i+1)/100.0;
	 }
for(i=0;i<n;i++)
 if(s[i]=='+')
	 {
	 s1[i]='\0';
	 return transl(s1)+transl(s+i+1);
	 break;
	 }
// przypadek elementarny:
return atof(s);
}


int main()
{
cout << "1+1="<< transl("1+1") << endl;
cout << "1+2+3="<< transl("1+2+3") << endl;
cout << "1+2+3x30%="<< transl("1+2+3x30%") << endl;
cout << "1+1+2x50%="<< transl("1+1+2x50%") << endl;
cout << "1+1+2x50%="<< transl("1+1+2*50%") << endl;
}
