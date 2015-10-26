#include <iostream>
using namespace std;

#include <string.h>

void palindrom(char *s)
{
int dl=strlen(s), cpt=0;
bool test=true; //  's' je (zatím) palindrom
while( (cpt<=dl/2) && (test==true) )
   if(s[cpt]==s[dl-cpt-1]) 
      cpt++; 
   else 
      test=false;
cout << s;
if(test==true) 
   cout << " ...je palindrom\n"; 
else 
   cout << " ...je obyèejné slovo...\n";
}

int main()
{
palindrom("ab");
palindrom("a");
palindrom("abba");
palindrom("abkba");
palindrom("abkca");
}
