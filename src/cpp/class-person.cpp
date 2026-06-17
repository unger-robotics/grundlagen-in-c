// ju -- https://bw1.eu -- 6-Jan-19  -- class-person.cpp
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
//#include "funktionen.h" // eig. Bibliothek
using namespace std;
class person{// Klassenname
	public:
		char name[20];		
		long int nummer;
		void anzahl(int anz){ 
			anzahl_lv = anz; 
		}					
		int ausgabe_anzahl(){ 
			return anzahl_lv; 
		}	
  private:	
		int anzahl_lv;	
};				
int main(){				
	class person p1, p2;	
	// Zufriff p1
	strcpy(p1.name,"wolf");	
	p1.nummer = 123456789;	
	p1.anzahl(10);	
	// Zugriff p2
	strcpy(p2.name,"sussi");	
	p2.nummer = 987654321;	
	p2.anzahl(5);
	// Ausgabe
	cout << fixed << setprecision(1)
			 << "Name: "   << p1.name << " - "
       << "Nummer: " << p1.nummer << " - "
			 << "Anzahl: " << p1.ausgabe_anzahl() << endl;	
	cout << "Name: "   << p2.name << " - "
       << "Nummer: " << p2.nummer << " - "
			 << "Anzahl: " << p2.ausgabe_anzahl() << endl;
	return 0;
}	

