#include <math.h>
#include <iostream.h>

void main()
{

cout << (int)(fmod(11732*0.61803398887,1)*30)<<endl;
}

/* Uwaga: 
         1) w systemie DOS w pliku projektowym wymusic linkowanie z
             bibliotekami matematycznymi
         2) kompilacja w systemie unix: 'c++ -o fmod fmod.cpp -lm'
*/

