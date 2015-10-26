#include <iostream>
using namespace std;

int nastepny[5]={-1,-1,-1,-1,-1}; // zapami�tuje ostatni wyb�r, 
// na samym pocz�tku nast�pny[-1 + 1] =0, p�niej posuwamy si�
// o 1 pozycj� dalej podczas danego etapu wyboru

int dobor[5]={-1,-1,-1,-1,-1}; // rozwi�zanie zadania

#define TEST

int wybiera[5][5]={ // preferencje student�w
	 {0,4,3,2,1},   /* A */
	 {1,0,4,2,3},   /* B */
	 {0,3,1,2,4},   /* C */
	 {3,4,0,1,2},   /* D */
	 {4,3,2,1,0}};  /* E */

// preferencje promotor�w: lubi[i][0] = nr A na li�cie 'i', 
// lubi[i][1] = nr B na li�cie 'i' itd.

int lubi[5][5]={ /* A B C D E */
	 {3,4,0,2,1},
	 {2,1,3,4,0},
	 {0,1,2,4,3},
	 {4,3,2,0,1},
	 {2,3,4,0,1}};

int main()
{
int student,wybierajacy,promotor,odrzucony;

for(student=0;student<5; student++)
{
wybierajacy=student;
#ifdef TEST
cout << "Wybieraj�cym staje si� " << (char)(wybierajacy +'A')<< endl;
#endif
while(wybierajacy!=-1)
  {
  nastepny[wybierajacy]++;
  promotor=wybiera[wybierajacy][nastepny[wybierajacy]];
  #ifdef TEST
  cout << "-->pr�buje on temat (promotora) " << promotor << endl;
  #endif
  if(dobor[promotor]==-1) // promotor (i jego temat) jest wolny
	  {
	  #ifdef TEST
	  cout << "Temat (promotor) " << promotor << " by� wolny i zostaje on przyznany studentowi " << (char)(wybierajacy +'A')<< endl;
	  #endif
	  dobor[promotor]=wybierajacy;
	  wybierajacy=-1;
	  }
  else
  if(lubi[promotor][wybierajacy]<lubi[promotor][dobor[promotor]])
    {
	 odrzucony=dobor[promotor];
	 #ifdef TEST
	 cout << "Promotor " << promotor << "porzuca sw�j aktualny wyb�r " << (char)(odrzucony +'A');
	 cout << " na rzecz " << (char)(wybierajacy +'A') << endl;
	 #endif
	 dobor[promotor]=wybierajacy;
	 wybierajacy=odrzucony;
	 #ifdef TEST
	 cout << "  --- Wybieraj�cym staje si� " << (char)(wybierajacy +'A')<< endl;
	 #endif
     }
  }
}

for(int i=0;i<5;i++)
cout << "(Promotor " << i << ", student " << (char)(dobor[i]+'A') << ")\n";
}
