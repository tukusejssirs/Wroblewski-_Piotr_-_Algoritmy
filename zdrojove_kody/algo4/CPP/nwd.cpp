// najwiekszy wspolny dzielnik

#include <iostream>
using namespace std;

// wersja 1

int nwd1 (int a, int b)
  {
  if (b>a) 
	return nwd1 (a, b-a);
  if (b<a) 
	return nwd1 (a-b, b);
  if (a==b) 
	return b;
}

// wersja 2;

int nwd2 (int a, int b)
  {
  if (b==0) 
	  return a;
  else
	   return nwd2(b, a % b); // modulo
}


int main()
{

cout << " Metoda 1\n";

cout << " nwd(12,3)=" << nwd1(12,3) << ",";
cout << " nwd(24,30)=" << nwd1(24,30) << ",";
cout << " nwd(5,7)=" << nwd1(5,7) << ",";
cout << " nwd(54,69)=" << nwd1(54,69) << endl;

cout << " Metoda 2\n";

cout << " nwd(12,3)=" << nwd2(12,3) << ",";
cout << " nwd(24,30)=" << nwd2(24,30) << ",";
cout << " nwd(5,7)=" << nwd2(5,7) << ",";
cout << " nwd(54,69)=" << nwd2(54,69) << endl;

}
//-----------------------------------------------------------------------
