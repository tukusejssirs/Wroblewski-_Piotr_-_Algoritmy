#include <iostream>
using namespace std;
const int n=12;
int tab[n]={23,12,1,-5,34,-7,45,2,88,-3,-9,1};
//---------------------------------------------
void min_max1(int t[],int& min,int& max)
{// používat pouze pro n>=1!
 min=max=t[0];
 for(int i=1; i<n; i++)
   {
    if(max<t[i]) 
      max=t[i];
    if(min>t[i]) 
      min=t[i];
   }
 }
//---------------------------------------------
void min_max2(int left, int right, int t[], int& min, int& max)
{
if (left==right)
   min=max=t[left]; // jeden prvek
else
   if (left==right-1) // dva prvky
      if(t[left]<t[right]) 
         {
         min=t[left];
         max=t[right];
         }
      else
         {
         min=t[right];
         max=t[left];
         }
   else
   {
    int temp_min1, temp_max1, temp_min2, temp_max2, mid;
    mid=(left+right)/2;
    min_max2(left,  mid,    t, temp_min1, temp_max1);
    min_max2(mid+1, right,  t, temp_min2, temp_max2);
    // min=temp_min1<temp_min2 ? temp_min1 : temp_min2; // (1) úspornìjší forma ve stylu jazyka C
    // max=temp_max1>temp_max2 ? temp_max1 : temp_max2; // (2) úspornìjší forma ve stylu jazyka C
     if (temp_min1<temp_min2) // (1)
        min=temp_min1;
     else 
        min=temp_min2;
     if(temp_max1>temp_max2)  // (2)
        max=temp_max1;
     else 
        max=temp_max2;
    }
}
//---------------------------------------------

int main()
{
int min,max;
min_max1(tab,min,max);
cout << "Min="<< min<<",max="<<max<<endl;
min_max2(0,n-1,tab,min,max);
cout << "Min="<< min<<",max="<<max<<endl;
}
//---------------------------------------------
