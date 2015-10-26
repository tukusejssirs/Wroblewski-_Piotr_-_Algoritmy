#include <iostream>
using namespace std;
void showbits(unsigned char s)
// funkcja pokazuje reprezentacj� binarn� znaku
{
unsigned char wagi[8]={1,2,4,8,16,32,64,128}; // maska bitu wagi
for(int i=7; i >= 0; i--)
	{
	int bit = (wagi[i] & s);
	if (bit !=0 ) 
			cout << '1'; 
	else 
			cout << '0';
	}
}
// --Przyk�adowe operacje na bitach
int main() 
{
cout << "i\tbinarnie\tprzes.w lewo\tnegacja\n";      
for (int i=0; i<16; i++)
	{
	cout << i << "\t"; 	showbits(i); cout << "\t";	// dec oraz binarnie
    // przesuni�cie o 1 bit w lewo:
	int j= i << 1; 	showbits(j); cout << "\t";
	int k= ~i; 		showbits(k); cout << endl;	// negacja bitowa
	}
}

