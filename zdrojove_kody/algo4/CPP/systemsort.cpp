// Wersja dla systemu DOS/WIndows (dla Unix zast¹p copy prze cp i dostosuj sk³adniê komendy 'sort'
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
ifstream plik_W1 ("input1.txt"); // plik wejœciowy 1
ifstream plik_W2 ("input2.txt"); // plik wejœciowy 2
ofstream plik_WYJ ("output.txt");// plik wynikowy
string s;
// z³¹czamy pliki ze sob¹, u¿ywaj¹c C++
while (getline(plik_W1,s))  
	plik_WYJ << s << endl;
while (getline(plik_W2,s))  
	plik_WYJ << s << endl;
plik_WYJ.close(); // zwalniamy plik wynikowy

// To samo mo¿na ewentualnie wykonaæ przez polecenie systemowe: 
// system("copy input1.txt+input2.txt output.txt");

system("sort output.txt /O output.txt"); // sortujemy plik wynikowy przy pomocy systemu operacyjnego

	
}
