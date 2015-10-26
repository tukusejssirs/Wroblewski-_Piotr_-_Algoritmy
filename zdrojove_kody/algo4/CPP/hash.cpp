#include <iostream>
using namespace std;

// first reported by Dan Bernstein in comp.lang.c
unsigned long H1(unsigned char *str)
{
unsigned long hash = 5381;
int c;
while (c = *str++)
       hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
return hash;
}

int H2(char *s, int Rmax)
{
int tmp;
for(tmp=0; *s != '\0'; s++)
     tmp = (64*tmp+(*s)) % Rmax;
return tmp;
}

// sdbm database library
static unsigned long H3(unsigned char *str)
{
unsigned long hash = 0;
int c;

while (c = *str++)
      hash = c + (hash << 6) + (hash << 16) - hash;
return hash;
}

// Kernigham & Ritchie
unsigned long H4(unsigned char *str)
{
unsigned int hash = 0;
int c;
while (c = *str++)
	    hash += c;
return hash;
}

int main()
{
}
