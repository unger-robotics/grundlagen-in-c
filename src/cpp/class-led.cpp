// ju -- https://bw1.eu -- 6-Jan-19  -- class-led.cpp
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
//#include "funktionen.h" // eig. Bibliothek
using namespace std;
class Led{// Klassenname
	private:	
		int zustand;
	public:
		char name[20];		
		int color;
		bool state;
		void switch_(bool state){ 
			zustand = state; 
		}					
		int ausgabe_switch_(){ 
			return zustand; 
		}	
};
#define GREEN 1;
#define RED   2;				
int main(){				
	class Led led1;	
	// Zufriff led1
	strcpy(led1.name,"led1");	
	led1.color = GREEN;	      // GREEN o. RED
	led1.switch_(true);	      // true o. false

	// Ausgabe
	cout << fixed << setprecision(1)
			 << "Name: "   << led1.name << " - "
       << "Color: " << led1.color << " - "
			 << "State: " << led1.ausgabe_switch_() << endl;
	return 0;
}	

