#include <iostream>
using namespace std;

int dalsi[5]={-1,-1,-1,-1,-1}; // ulo�en� posledn� volby 
// �pln� na za��tku plat� dalsi[-1 + 1] =0, pozd�ji doch�z� k posunu
// o 1 pozici d�le b�hem dan� f�ze v�b�ru

int vyber[5]={-1,-1,-1,-1,-1}; // �e�en� �lohy

#define TEST

int vybira[5][5]={ // preference student�
    {0,4,3,2,1},   /* A */
    {1,0,4,2,3},   /* B */
    {0,3,1,2,4},   /* C */
    {3,4,0,1,2},   /* D */
    {4,3,2,1,0}};  /* E */

// preference �kolitel�: rad[i][0] = ��slo A na seznamu 'i', 
// rad[i][1] = ��slo B na seznamu 'i' atd.

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
cout << "Za��n� vyb�rat student " << (char)(vybirajici +'A')<< endl;
#endif
while(vybirajici!=-1)
  {
  dalsi[vybirajici]++;
  skolitel=vybira[vybirajici][dalsi[vybirajici]];
  #ifdef TEST
  cout << "--> navrhuje t�ma (�kolitele) " << promotor << endl;
  #endif
  if(vyber[skolitel]==-1) // �kolitel (se sv�m t�matem) je voln�
     {
     #ifdef TEST
     cout << "T�ma (�kolitel) " << promotor << " je voln� a dost�v� je student " << (char)(vybirajici +'A')<< endl;
     #endif
     vyber[skolitel]=vybirajici;
     vybirajici=-1;
     }
  else
  if(rad[skolitel][vybirajici]<rad[skolitel][vyber[skolitel]])
    {
    odmitnuty=vyber[skolitel];
    #ifdef TEST
    cout << "�kolitel " << promotor << "zavrhuje sv�j aktu�ln� v�b�r studenta " << (char)(odmitnuty +'A');
    cout << " ve prosp�ch studenta " << (char)(vybirajici +'A') << endl;
    #endif
    vyber[skolitel]=vybirajici;
    vybirajici=odmitnuty;
    #ifdef TEST
    cout << "  --- Za��n� vyb�rat student " << (char)(vybirajici +'A')<< endl;
    #endif
     }
  }
}

for(int i=0;i<5;i++)
cout << "(�kolitel " << i << ", student " << (char)(vyber[i]+'A') << ")\n";
}
