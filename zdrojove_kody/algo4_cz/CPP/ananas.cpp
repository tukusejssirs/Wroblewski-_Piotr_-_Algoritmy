#include <iostream>
using namespace std;

int kmp_ananas(char *t)
{
int i=-1;
start: i++;
et0: if (t[i]!='a') 
       goto start; 
      i++;
et1: if (t[i]!='n') 
       goto et0;    
      i++;
et2: if (t[i]!='a') 
       goto et0;    
      i++;
et3: if (t[i]!='n') 
       goto et1;  i++;
     if (t[i]!='a') 
       goto et2;  i++;
     if (t[i]!='s') 
       goto et3;  i++;
return i-6;
}

int main() 
{
 char *t="v obchodì jsme mohli koupit ananasy a pomeranèe";
 cout << "Výsledek vyhledávání="<<kmp_ananas(t)<<endl;
}


