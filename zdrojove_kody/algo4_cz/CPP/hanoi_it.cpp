#include <iostream>
using namespace std;

int a,b,n;

void hanoi()
{
if (n!=1)
   {
     n--; b=3-a-b;
     hanoi();
     n++; b=3-a-b;
     cout << "Pøesuò disk èíslo "<< n << " z " << a << " na "<< b <<endl;
     n--; a=3-a-b;
     hanoi();
     n++; a=3-a-b;
   }else
   cout << "Pøesuò disk èíslo "<< n << " z " << a << " na "<< b <<endl;
}

void hanoi_iter()
{
int M=1;
do
{
 while (n!=1) 
 { 
   n--;
   b=3-a-b; 
   M*=2;
 }
 cout << "Pøesuò disk èíslo "<< n << " z " << a << " na "<< b <<endl;

 while ((M!=1) && (M%2)) {M=M/2; n=n+1; a=3-a-b;}

 if(M==1) goto KONEC;

 M++;
 n++; b=3-a-b;
 cout << "Pøesuò disk èíslo "<< n << " z " << a << " na "<< b <<endl;
 n--; a=3-a-b;
} while (M!=1);

KONEC:
;
}


int main()
{
cout << "Klasicky:\n";
n=4;a=0;b=1;
hanoi();
cout << "Iterativnì\n";
n=4;a=0;b=1;
hanoi_iter();
}
