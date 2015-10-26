#include <iostream>
using namespace std;

class C1
 {
protected:
 int x;
public:
 C1(int n) { x = n; }
void pis() { cout << "** Stará verze metody 'pis': x="<<x<<" **\n";}
};

class C2
 {
private:
 int y;
public:
 C2(int n) { y = n; }
 int ret_y() { return y;}
};

