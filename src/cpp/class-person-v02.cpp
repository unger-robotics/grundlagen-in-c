// ju -- https://bw1.eu -- 6-Jan-19  -- class-person-v02.cpp
#include <string>
#include <iostream>
#include <sstream> 
#include <fstream> 
using namespace std;

class Person{
  private:
    string name_;
    int alter_;
    string ort_;
  public:
    Person(string n = "kein Name", int a = -1, string o = "kein Ort")// Standardwerte
      : name_(n), alter_(a), ort_(o) { }
    ostream& print(ostream& os) {// Ausgabe: Bildschirm, Datei, String (auto. Test)
      return os << "Name: " << name_ 
                << " - Alter: " << alter_ 
                << " - Ort: " << ort_ << "\n";
    };  
};
int main(){
  // Zugriff
  Person p1 {};
  Person p2 {"Willi", 72, "Wuppertal"};

  // Ausgabe: Bildschirm
  p1.print(cout); 
  p2.print(cout); 

  // Ausgabe: Datei
  ofstream datei {"personen.txt"};
  p1.print(datei); 
  p2.print(datei);
  cout << "file personen.txt wurde angelegt." << "\n";

  // Ausgabe: String (auto. Test)
  ostringstream oss{}; 
  p1.print(oss);
  //p2.print(oss);
  if(oss.str() == "Name: kein Name - Alter: -1 - Ort: kein Ort\n"){
    cout << "ok\n";
  }else{
    cout << "Fehler in Person::print!\n";
    cout << oss.str();
    return 1; // Fehler nach außen weiterleiten
  }
}