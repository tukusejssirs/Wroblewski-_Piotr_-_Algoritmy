#include <iostream>
using namespace std;
void showbits(unsigned char s)
// funkce zobrazuje bin�rn� reprezentaci znaku
{
unsigned char vahy[8]={1,2,4,8,16,32,64,128}; // maska bitu v�hy
for(int i=7; i >= 0; i--)
   {
   int bit = (vahy[i] & s);
   if (bit !=0 ) 
         cout << '1'; 
   else 
         cout << '0';
   }
}
// --Uk�zkov� operace s bity
int main() 
{
cout << "i\Bin�rn�\tPosun vlevo\tNegace\n";      
for (int i=0; i<16; i++)
   {
   cout << i << "\t";   showbits(i); cout << "\t"; // des�tkov� a bin�rn�
    // posunut� o 1 bit vlevo:
   int j= i << 1;    showbits(j); cout << "\t";
   int k= ~i;     showbits(k); cout << endl; // bitov� negace
   }
}

