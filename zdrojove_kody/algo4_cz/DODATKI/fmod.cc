#include <math.h>
#include <iostream.h>

void main()
{

cout << (int)(fmod(11732*0.61803398887,1)*30)<<endl;
}

/* Upozorn�n�: 
         1) v syst�mu DOS je nutn� v projektov�m souboru vynutit propojen�
             s matematick�mi knihovnami
         2) kompilace v syst�mu Unix: 'c++ -o fmod fmod.cpp -lm'
*/

