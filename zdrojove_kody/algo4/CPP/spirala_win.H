#pragma once
namespace spirala_win {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	const int alpha=10; // kod dopisany

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
	
	Graphics^ g1; // kod dopisany
	Pen^ pioro;   // kod dopisany
	int origin_x, origin_y; // kod dopisany - zmienne zapamietuja biezace wspolrzedne 
	private: System::Windows::Forms::Button^  button1;
	public: 


		Form1(void)
		{
			InitializeComponent();
			//TODO: Add the constructor code here
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
			this->button1->Text = L"Rysuj";
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
			this->Text = L"Program SPIRALA";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

void lineto(int x, int y){ // kod dopisany
	Pen^ pioro_black = gcnew Pen(System::Drawing::Color::Black);
	g1->DrawLine(pioro_black, origin_x, origin_y, x, y);     
	origin_x=x;
	origin_y=y;
}

void gotoXY(int x, int y){ // kod dopisany
	Pen^ pioro_white = gcnew Pen(System::Drawing::Color::White);
	g1->DrawLine(pioro_white, 0, 0, x, y);     
	origin_x=x;
	origin_y=y;

}

void SPIRALA(int lg,int x, int y){ // kod dopisany
   if (lg>0){
   lineto(x+lg,y);
   lineto(x+lg,y+lg);
   lineto(x+alpha,y+lg);
   lineto(x+alpha,y+alpha);
   SPIRALA(lg-2*alpha,x+alpha,y+alpha);
   }
}

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		g1=this->CreateGraphics(); // kod dopisany
 		pioro=gcnew Pen(System::Drawing::Color::Black); // kod dopisany
		origin_x=0; // kod dopisany
		origin_y=0; // kod dopisany
		 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		gotoXY(90, 50); // kod dopisany
		this->SPIRALA(300, 90, 50); // kod dopisany
			 }
};
}

