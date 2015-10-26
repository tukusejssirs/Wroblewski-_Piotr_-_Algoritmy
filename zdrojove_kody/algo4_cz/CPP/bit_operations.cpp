#include <iostream>
using namespace std;
void showbits(unsigned char s)
// funkce zobrazuje binární reprezentaci znaku
{
unsigned char vahy[8]={1,2,4,8,16,32,64,128}; // maska bitu váhy
for(int i=7; i >= 0; i--)
   {
   int bit = (vahy[i] & s);
   if (bit !=0 ) 
         cout << '1'; 
   else 
         cout << '0';
   }
}
// --Ukázkové operace s bity
int main() 
{
cout << "i\Binárnì\tPosun vlevo\tNegace\n";      
for (int i=0; i<16; i++)
   {
   cout << i << "\t";   showbits(i); cout << "\t"; // desítkovì a binárnì
    // posunutí o 1 bit vlevo:
   int j= i << 1;    showbits(j); cout << "\t";
   int k= ~i;     showbits(k); cout << endl; // bitová negace
   }
}

