#include <iostream>
using namespace std;

#include <string.h>

void palindrom(char *s)
{
int dl=strlen(s), cpt=0;
bool test=true; //  's' jest (na razie) palindromem
while( (cpt<=dl/2) && (test==true) )
	if(s[cpt]==s[dl-cpt-1]) 
		cpt++; 
	else 
		test=false;
cout << s;
if(test==true) 
	cout << " ...jest palindromem\n"; 
else 
	cout << " ...jest zwyk³ym s³owem...\n";
}

int main()
{
palindrom("ab");
palindrom("a");
palindrom("abba");
palindrom("abkba");
palindrom("abkca");
}
