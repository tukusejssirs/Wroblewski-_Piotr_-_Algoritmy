#include <math.h>
#include <iostream.h>

void main()
{

cout << (int)(fmod(11732*0.61803398887,1)*30)<<endl;
}

/* Upozornìní: 
         1) v systému DOS je nutné v projektovém souboru vynutit propojení
             s matematickými knihovnami
         2) kompilace v systému Unix: 'c++ -o fmod fmod.cpp -lm'
*/

