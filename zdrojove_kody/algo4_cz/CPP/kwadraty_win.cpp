// spirala_win.cpp : hlavn� soubor projektu.

#include "kwadraty_win.h"

using namespace kwadraty_win;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
   // Aktivace vizu�ln�ch efekt� syst�mu Windows XP p�ed vytvo�en�m ovl�dac�ch prvk�
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false); 

   // Vytvo�en� hlavn�ho okna a jeho otev�en�
   Application::Run(gcnew Form1());
   return 0;
}
