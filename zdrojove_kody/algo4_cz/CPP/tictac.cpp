// Program hry "pi�kvorky" s vyu�it�m
// procedury mini-max. Jedn� se "betaverzi",  kter�
// nebyla kompletn� otestov�na...

#include <iostream>
using namespace std;

#define HRAC_VERSUS_POCITAC 1

const int HLOUBKA_OK=2;

const int plus_nekonecno  =  1000;
const int minus_nekonecno = -1000;

int MiniMaxUsed=0;

char ch;

enum KDO{nic,pocitac,clovek};

struct POLICKO{int val; int hrac;};

struct KANDIDATI{
   int   cpt;
   int   tbl[9];
   };
// ____________________________________________________________________
KDO Dalsi_Hrac(KDO hrac)
{
if (hrac==pocitac)
   return clovek;
else
   return pocitac;
}
// ____________________________________________________________________
int DostatecnaHloubka(int p)
// Je hloubka MiniMax dostate�n�?
// (konstanta HLOUBKA_OK je definov�na na za��tku souboru)
{
if (p==HLOUBKA_OK)
   return 1;
else
   return 0;
}
// ____________________________________________________________________
void ZobrazMrizku(KDO mrizka[9])
{
for(int i=0;i<9;i++)
  {
  if ((i==3) || (i==6) || (i==9)) cout << endl;
  switch(mrizka[i])
   {
   case nic:      cout << " *  ";break;
   case pocitac: cout << " X  ";break;
   case clovek: cout << " O  ";break;
   }
  }
}
// ____________________________________________________________________
void Nuluj(KDO *mrizka)
// nulov�n� hrac� plochy
{
for (int i=0;i<9;i++) mrizka[i]=nic;
}
// ____________________________________________________________________
KANDIDATI Generuj(KDO mrizka[9])
// generov�n� mo�n�ch kandid�t� na dal�� tah
{
KANDIDATI t;
 t.cpt=-1;
 for(int i=0;i<9;i++)
 if (mrizka[i]==nic)
     t.tbl[++t.cpt]=i; // zapamatov�n� voln� pozice
return t;
}
// ____________________________________________________________________
int KonecHry(KDO mrizka[9])
{
int a,b,c,d,e,f,g,h;

// �sp�ch v �ad�?

a=((mrizka[0]==mrizka[1])&&(mrizka[1]==mrizka[2]) && (mrizka[0]!=nic));
b=((mrizka[3]==mrizka[4])&&(mrizka[4]==mrizka[5]) && (mrizka[3]!=nic));
c=((mrizka[6]==mrizka[7])&&(mrizka[7]==mrizka[8]) && (mrizka[6]!=nic));

// �sp�ch ve sloupci?

d=((mrizka[0]==mrizka[3])&&(mrizka[3]==mrizka[6]) && (mrizka[0]!=nic));
e=((mrizka[1]==mrizka[4])&&(mrizka[4]==mrizka[7]) && (mrizka[1]!=nic));
f=((mrizka[2]==mrizka[5])&&(mrizka[5]==mrizka[8]) && (mrizka[2]!=nic));

// �sp�ch na �hlop���ce?

g=((mrizka[0]==mrizka[4])&&(mrizka[4]==mrizka[8]) && (mrizka[0]!=nic));
h=((mrizka[2]==mrizka[4])&&(mrizka[4]==mrizka[6]) && (mrizka[2]!=nic));

if (!(a||b||c||d||e||f||g||h)) 
   return 0;

if (a) return 1;    // chceme zjistit, kdo vyhr�l
if (b) return 3;
if (c) return 6;
if (d) return 3;
if (e) return 4;
if (f) return 5;
if (g) return 4;
if (h) return 4;

}
// ____________________________________________________________________
bool KontrolujKonecHry(KDO mrizka[9],KDO hrac)
{
if (KonecHry(mrizka))
 {
  ZobrazMrizku(mrizka);
  cout << "\n  ** KONEC HRY ** \n";
  if (hrac==clovek)
      cout << "GRATULUJI K V�H�E!\n";
  else
      cout << "VYHR�L PO��TA�! Stiskn�te libovolnou kl�vesu\n";
  cin.get();
  return true;
 }

KANDIDATI dalsi=Generuj(mrizka);

if (dalsi.cpt==-1)
 {
    ZobrazMrizku(mrizka);
    cout << "\n  ** KONEC HRY ** \n";
    cout << "Rem�za! Stiskn�te libovolnou kl�vesu\n";
    cin.get();
    return true; 
  }

return false;
}
// ____________________________________________________________________
int RadekPrazdny(int Radek,KDO mrizka[9])
{
return ((mrizka[(Radek-1)*3]==nic) && (mrizka[(Radek-1)*3+1]==nic) && (mrizka[(Radek-1)*3+2]==nic));
}
// ____________________________________________________________________
int SloupecPrazdny(int Sloupec,KDO mrizka[9])
{
return ((mrizka[Sloupec-1]==nic) && (mrizka[(Sloupec-1)+3]==nic) && (mrizka[(Sloupec-1)+6]==nic));
}
// ____________________________________________________________________
int RadekPlny(int Radek,KDO mrizka[9])
{
return !((mrizka[(Radek-1)*3]==nic) || (mrizka[(Radek-1)*3+1]==nic) || (mrizka[(Radek-1)*3+2]==nic));
}
// ____________________________________________________________________
int SloupecPlny(int Sloupec,KDO mrizka[9])
{
return !((mrizka[Sloupec-1]==nic) || (mrizka[(Sloupec-1)+3]==nic) || (mrizka[(Sloupec-1)+6]==nic));
}
// ____________________________________________________________________
int Uhlopricka1_Prazdna(KDO mrizka[9])
{
return ((mrizka[0]==nic) && (mrizka[4]==nic) && (mrizka[8]==nic));
}
// ____________________________________________________________________
int Uhlopricka1_Plna(KDO mrizka[9])
{
return !((mrizka[0]==nic) || (mrizka[4]==nic) || (mrizka[8]==nic));
}
// ____________________________________________________________________
int Uhlopricka2_Prazdna(KDO mrizka[9])
{
return ((mrizka[2]==nic) && (mrizka[4]==nic) && (mrizka[6]==nic));
}
// ____________________________________________________________________
int Uhlopricka2_Plna(KDO mrizka[9])
{
return !((mrizka[2]==nic) || (mrizka[4]==nic) || (mrizka[6]==nic));
}
// ____________________________________________________________________
int Hodnoceni(KDO mrizka[9],KDO hrac)
//
{
int val=0;
int result=KonecHry(mrizka);
if (result)
{
if (mrizka[result]==Dalsi_Hrac(hrac))
    return minus_nekonecno;          // v�hern� pozice pro protivn�ka
else
   return  plus_nekonecno;           // v�hern� pozice pro n�s
}
for(int Radek=1;Radek<=3;Radek++)
  if (!(RadekPrazdny(Radek,mrizka) || RadekPlny(Radek,mrizka)))
    {
    if ((mrizka[(Radek-1)*3]==Dalsi_Hrac(hrac)) || (mrizka[(Radek-1)*3+1]==Dalsi_Hrac(hrac)) || (mrizka[(Radek-1)*3+2]==Dalsi_Hrac(hrac)))
    val-=1;
    if ((mrizka[(Radek-1)*3]==hrac) || (mrizka[(Radek-1)*3+1]==hrac) || (mrizka[(Radek-1)*3+2]==hrac))
    val+=1;
    }
for(int Sloupec=1;Sloupec<=3;Sloupec++)
  if (!(SloupecPrazdny(Sloupec,mrizka) || SloupecPlny(Sloupec,mrizka)))
    {
    if ((mrizka[Sloupec-1]==Dalsi_Hrac(hrac)) || (mrizka[(Sloupec-1)+3]==Dalsi_Hrac(hrac)) || (mrizka[(Sloupec-1)+6]==Dalsi_Hrac(hrac)))
    val-=1;
    if ((mrizka[Sloupec-1]==hrac) || (mrizka[(Sloupec-1)+3]==hrac) || (mrizka[(Sloupec-1)+6]==hrac))
    val+=1;
    }
if (!(Uhlopricka1_Prazdna(mrizka)||Uhlopricka1_Plna(mrizka)))
{
 if ((mrizka[0]==Dalsi_Hrac(hrac)) || (mrizka[4]==Dalsi_Hrac(hrac)) || (mrizka[8]==Dalsi_Hrac(hrac)))
 val=val-1;
 if ((mrizka[0]==hrac) || (mrizka[4]==hrac) || (mrizka[8]==hrac))
 val+=1;
};

if (!(Uhlopricka2_Prazdna(mrizka)||Uhlopricka2_Plna(mrizka)))
{
 if ((mrizka[2]==Dalsi_Hrac(hrac)) || (mrizka[4]==Dalsi_Hrac(hrac)) || (mrizka[6]==Dalsi_Hrac(hrac)))
 val-=1;
 if ((mrizka[2]==hrac) || (mrizka[4]==hrac) || (mrizka[6]==hrac))
 val+=1;
};
return val;
}
// ____________________________________________________________________
void ProvedTah(KDO hrac,KDO *mrizka,int tah)
{
mrizka[tah]=hrac;
}
// ____________________________________________________________________
KDO Dalsi_Hrac(KDO hrac, int hloubka)
{
// pro kter�ho hr��e se po��t� hodnocen� mini-max
if ((hloubka % 2) == 0)
   return hrac;
else
   return Dalsi_Hrac(hrac);
}
// ____________________________________________________________________
POLICKO MiniMax(KDO mrizka[9],int hloubka,KDO hrac)
{
POLICKO res;
KANDIDATI dalsi;
if (DostatecnaHloubka(hloubka))  // uzel je polo�en dostate�n� hluboko
 {
 res.val=Hodnoceni(mrizka,hrac);
 res.hrac=-1;
 return res;
 };

dalsi=Generuj(mrizka);

if (dalsi.cpt==-1)   // termin�ln� uzel
  {
  res.val=Hodnoceni(mrizka,hrac);
  res.hrac=-1;
  return res;
  }

int lepsi=minus_nekonecno;
int hrac_1;
for (int i=0; i<=dalsi.cpt;i++)
 {
 KDO mrizka1[9];
 for (int k=0;k<9;k++) mrizka1[k]=mrizka[k];
 mrizka1[dalsi.tbl[i]]=Dalsi_Hrac(hrac,hloubka);
 POLICKO r;
 r=MiniMax(mrizka1,hloubka+1,hrac);
 if (-r.val>lepsi)
   {
    lepsi=-r.val;
    hrac_1=dalsi.tbl[i];
   }
 }
res.val=lepsi;
res.hrac=hrac_1;
return res;
}
// ____________________________________________________________________
bool Obsazeno(KDO mrizka[9],int tah)
// Je pol��ko voln�?
{
if (tah==-1) 
   return true;
if (mrizka[tah] != nic)
   return false;

else
   return true;
}
// ____________________________________________________________________
void VyberTah(KDO hrac,KDO mrizka[9],int &tah)
// v�b�r tahu z�vis� na tom, kdo hraje
{
if (hrac==clovek)
   do
    {
#ifdef HRAC_VERSUS_POCITAC // hr�� proti po��ta�i
     cout << "\n V� v�b�r(0..8):";
     cin >> tah;
#else                       // po��ta� proti po��ta�i
     cout << "Stiskn�te kl�vesu...";
     POLICKO vyber=MiniMax(mrizka,0,hrac);
     tah=vyber.hrac;
     char ch;
     cin.get(ch);
#endif
    } while(!Obsazeno(mrizka,tah));
   else {
        cout << "\nM�j tah:\n";
        POLICKO vyber=MiniMax(mrizka,0,hrac);
        tah=vyber.hrac;
#ifndef HRAC_VERSUS_POCITAC
         cout << "Stiskn�te kl�vesu...";
        cin.get();
#endif
  }
}

// ____________________________________________________________________

void Hraj(KDO *mrizka,KDO hrac)
  {
  int tah;
  bool konec=false;
  KDO hrac1=hrac;
  while(!konec)
  {
  ZobrazMrizku(mrizka);
  VyberTah(hrac1,mrizka,tah);
  ProvedTah(hrac1,mrizka,tah);
  koniec = KontrolujKonecHry(mrizka,hrac1);
  hrac1=Dalsi_Hrac(hrac1);
 }
}
// ____________________________________________________________________
int main()
{
KDO hrac;
KDO mrizka[9];
Nuluj(mrizka);
hrac=pocitac;
Hraj(mrizka,hrac);
//system("PAUSE");// pozastaven� programu do stisknut� libovoln� kl�vesy

}
// ____________________________________________________________________
