#pragma once
namespace kwadraty_win {

   using namespace System;
   using namespace System::ComponentModel;
   using namespace System::Collections;
   using namespace System::Windows::Forms;
   using namespace System::Data;
   using namespace System::Drawing;

   const int alpha=10; // doplnìný kód

   public ref class Form1 : public System::Windows::Forms::Form
   {
   public:
   
   Graphics^ g1; // doplnìný kód
   Pen^ pero;   // doplnìný kód
   int origin_x, origin_y; // doplnìný kód - promìnné uchovávají aktuální souøadnice 
   private: System::Windows::Forms::Button^  button1;
   public: 


      Form1(void)
      {
         InitializeComponent();
         //TODO: Sem pøidejte kód konstruktoru
      }
   protected:
      ~Form1()
      {
         if (components)
         {
            delete components;
         }
      }

   private:
      System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
      void InitializeComponent(void)
      {
         this->button1 = (gcnew System::Windows::Forms::Button());
         this->SuspendLayout();
         this->button1->Location = System::Drawing::Point(2, 12);
         this->button1->Name = L"button1";
         this->button1->Size = System::Drawing::Size(75, 23);
         this->button1->TabIndex = 0;
         this->button1->Text = L"Kresli";
         this->button1->UseVisualStyleBackColor = true;
         this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
         // 
         // Form1
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(453, 368);
         this->Controls->Add(this->button1);
         this->Name = L"Form1";
         this->Text = L"Program CTVERCE";
         this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
         this->ResumeLayout(false);

      }
#pragma endregion

void lineto(int x, int y){ // doplnìný kód
   Pen^ pero_black = gcnew Pen(System::Drawing::Color::Black);
   g1->DrawLine(pero_black, origin_x, origin_y, x, y);     
   origin_x=x;
   origin_y=y;
}

void gotoXY(int x, int y){ // doplnìný kód
   Pen^ pero_white = gcnew Pen(System::Drawing::Color::White);
   g1->DrawLine(pero_white, 0, 0, x, y);     
   origin_x=x;
   origin_y=y;

}

void CTVERCE (int n, double lg,  double x,  double y){ // doplnìný kód
// n = sudý poèet ètvercù
if (n>0)
   {
   lineto(x+lg,y);
   lineto(x+lg,y+lg);
   lineto(x,y+lg);
   lineto(x,y+lg/2);
   lineto(x+lg/2,y+lg);
   lineto(x+lg,y+lg/2);
   lineto(x+lg/2,y);
   lineto(x+lg/4,y+lg/4);
       CTVERCE(n-1,lg/2,x+lg/4,y+lg/4);
   lineto(x,y+lg/2);
   lineto(x,y);
   }
}

   private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
      g1=this->CreateGraphics(); // doplnìný kód
      pero=gcnew Pen(System::Drawing::Color::Black); // doplnìný kód
      origin_x=0; // doplnìný kód
      origin_y=0; // doplnìný kód
       }
   private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
      gotoXY(90, 50); // doplnìný kód
      this->CTVERCE(3, 200, 90, 50); // doplnìný kód
         // ctverce(5, getmaxx()/2, getx(), gety());




          }
};
}

