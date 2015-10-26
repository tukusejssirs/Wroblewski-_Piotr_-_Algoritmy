#include <iostream>
using namespace std;
int do_2(int a)
{
return a*a;
}
int do_4(int a)
{
return a*a*a*a;
}
int vzor(int x,int(*fun)(int))
{
return fun(x);
}
int main()
{
cout << "10 umocnìno na 2:"<< vzor(10,do_2) << endl;
cout << "10 umocnìno na 4:"<< vzor(10,do_4) << endl;
}
