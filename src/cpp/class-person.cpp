// ju -- 6-Jan-19 -- class-person.cpp
/*
  Eine Klasse (class) ist ein Bauplan; ein Objekt ist ein konkretes Exemplar
  davon (hier p1 und p2). Klassen buendeln Daten UND die Funktionen, die auf
  ihnen arbeiten (Member-Funktionen/Methoden).
  Kapselung ueber Zugriffsrechte:
    public  -> von aussen frei zugaenglich (hier: name, nummer)
    private -> nur INNERHALB der Klasse erreichbar (hier: anzahl_lv)
  Auf private Daten greift man von aussen kontrolliert ueber Methoden zu
  (Setter zum Schreiben, Getter zum Lesen) -- so kann die Klasse Werte pruefen
  und ihre interne Darstellung spaeter aendern, ohne den Aufrufer zu brechen.
*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
//#include "funktionen.h" // eig. Bibliothek (hier nicht genutzt)
using namespace std;
class person{// Klassenname
	public:
		char name[20];
		long int nummer;
		void anzahl(int anz){  // Setter: schreibt den privaten Wert
			anzahl_lv = anz;
		}
		int ausgabe_anzahl(){  // Getter: liefert den privaten Wert zurueck
			return anzahl_lv;
		}
  private:
		int anzahl_lv;  // nur ueber anzahl()/ausgabe_anzahl() erreichbar
};
int main(){
	class person p1, p2;  // zwei Objekte (Instanzen) derselben Klasse
	// Zugriff p1: name/nummer sind public -> direkter Zugriff erlaubt
	strcpy(p1.name,"wolf");
	p1.nummer = 123456789;
	p1.anzahl(10);  // anzahl_lv ist privat -> nur ueber den Setter setzbar
	// Zugriff p2
	strcpy(p2.name,"sussi");
	p2.nummer = 987654321;
	p2.anzahl(5);
	// Ausgabe (ausgabe_anzahl() liest den privaten Wert ueber den Getter)
	cout << fixed << setprecision(1)
			 << "Name: "   << p1.name << " - "
       << "Nummer: " << p1.nummer << " - "
			 << "Anzahl: " << p1.ausgabe_anzahl() << endl;
	cout << "Name: "   << p2.name << " - "
       << "Nummer: " << p2.nummer << " - "
			 << "Anzahl: " << p2.ausgabe_anzahl() << endl;
	return 0;
}
