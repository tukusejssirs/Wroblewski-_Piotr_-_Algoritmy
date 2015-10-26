#include <iostream>
#include <string.h>
using namespace std;

int hledej(char *w,char *t)
{
 int i=0,j=0, M=strlen(w), N=strlen(t);
 while( (j<M) && (i<N) )
    {
    if(t[i]!=w[j]) 
   {
    i-=j-1;
    j=-1;
   }
    i++;
   j++;
    }
 if(j==M) 
   return i-M; 
 else 
   return -1;
}

int main()
 {
 char *b="abrakadabra",*a="rak";
 cout <<  hledej(a,b) << endl;
 }
