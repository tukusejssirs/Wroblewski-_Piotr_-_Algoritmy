// spirala_win.cpp : hlavní soubor projektu.

#include "kwadraty_win.h"

using namespace kwadraty_win;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
   // Aktivace vizuálních efektù systému Windows XP pøed vytvoøením ovládacích prvkù
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false); 

   // Vytvoøení hlavního okna a jeho otevøení
   Application::Run(gcnew Form1());
   return 0;
}
