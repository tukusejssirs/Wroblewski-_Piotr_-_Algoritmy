#include <iostream>
using namespace std;

int A(int n,int p)
{
if (n==0) 
	return 1;
if ((p==0)&&(n>=1))
	if (n==1)
		return 2;
	 else
		return n+2;

if ((p>=1)&&(n>=1))
	return A(A(n-1,p),p-1);
}
int main()
{
cout << "A(3,4)="<<A(3,4) <<endl;
}
