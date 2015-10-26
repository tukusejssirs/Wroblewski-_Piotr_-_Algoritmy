#include <iostream>
using namespace std;

#include <stdlib.h>
#include <math.h>
#include <string.h>

double transl(char *s)
// nahrazuje posloupnosti znakù typu 1+1 èi 2+1+1*5 hodnotou (zde 2, resp. 12)
// pozor: funkce neanalyzuje dìlení a nekontroluje pøípad
// dìlení nulou!
{
int i,n;
char *s1;
n=strlen(s);
s1= new char[n+1]; // pracovní kopie vstupního textu
strcpy(s1,s);      // kopie vstupní posloupnosti

for(i=0;i<n;i++)// hledání znakù + a *
 if(s[i]=='+'||s[i]=='*')
   {
    s1[i]='\0';
    if(s[i]=='+')
      return transl(s1)+transl(s+i+1);
    else
      return transl(s1)*transl(s+i+1);
    }
// elementární pøípad:
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
cout << "2*3+4*5="<< transl("2*3+4*5") << endl; // 46 špatnì!
}
