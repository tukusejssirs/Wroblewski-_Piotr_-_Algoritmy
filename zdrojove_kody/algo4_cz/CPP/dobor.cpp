#include <iostream>
using namespace std;

int dalsi[5]={-1,-1,-1,-1,-1}; // uložení poslední volby 
// úplnì na zaèátku platí dalsi[-1 + 1] =0, pozdìji dochází k posunu
// o 1 pozici dále bìhem dané fáze výbìru

int vyber[5]={-1,-1,-1,-1,-1}; // øešení úlohy

#define TEST

int vybira[5][5]={ // preference studentù
    {0,4,3,2,1},   /* A */
    {1,0,4,2,3},   /* B */
    {0,3,1,2,4},   /* C */
    {3,4,0,1,2},   /* D */
    {4,3,2,1,0}};  /* E */

// preference školitelù: rad[i][0] = èíslo A na seznamu 'i', 
// rad[i][1] = èíslo B na seznamu 'i' atd.

int rad[5][5]={ /* A B C D E */
    {3,4,0,2,1},
    {2,1,3,4,0},
    {0,1,2,4,3},
    {4,3,2,0,1},
    {2,3,4,0,1}};

int main()
{
int student,vybirajici,skolitel,odmitnuty;

for(student=0;student<5; student++)
{
vybirajici=student;
#ifdef TEST
cout << "Zaèíná vybírat student " << (char)(vybirajici +'A')<< endl;
#endif
while(vybirajici!=-1)
  {
  dalsi[vybirajici]++;
  skolitel=vybira[vybirajici][dalsi[vybirajici]];
  #ifdef TEST
  cout << "--> navrhuje téma (školitele) " << promotor << endl;
  #endif
  if(vyber[skolitel]==-1) // školitel (se svým tématem) je volný
     {
     #ifdef TEST
     cout << "Téma (školitel) " << promotor << " je volné a dostává je student " << (char)(vybirajici +'A')<< endl;
     #endif
     vyber[skolitel]=vybirajici;
     vybirajici=-1;
     }
  else
  if(rad[skolitel][vybirajici]<rad[skolitel][vyber[skolitel]])
    {
    odmitnuty=vyber[skolitel];
    #ifdef TEST
    cout << "Školitel " << promotor << "zavrhuje svùj aktuální výbìr studenta " << (char)(odmitnuty +'A');
    cout << " ve prospìch studenta " << (char)(vybirajici +'A') << endl;
    #endif
    vyber[skolitel]=vybirajici;
    vybirajici=odmitnuty;
    #ifdef TEST
    cout << "  --- Zaèíná vybírat student " << (char)(vybirajici +'A')<< endl;
    #endif
     }
  }
}

for(int i=0;i<5;i++)
cout << "(Školitel " << i << ", student " << (char)(vyber[i]+'A') << ")\n";
}
