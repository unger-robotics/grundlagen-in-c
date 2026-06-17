// ju -- 17-Jun-26 -- vererbung.cpp
/*
  Vererbung: eine abgeleitete Klasse (Hund, Katze) uebernimmt Eigenschaften
  einer Basisklasse (Tier) und ergaenzt oder aendert sie -- "ist ein"-Beziehung.
  Polymorphismus: ueber einen Basiszeiger (Tier*) wird zur LAUFZEIT die passende
  Methode der echten Klasse aufgerufen. Moeglich durch "virtual" in der Basis
  und "override" in der Ableitung.
  Wichtig: hat eine Basisklasse virtuelle Methoden, braucht sie auch einen
  VIRTUELLEN Destruktor, damit "delete basiszeiger" das richtige (abgeleitete)
  Objekt vollstaendig aufraeumt.
*/
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Tier {
  protected:                          // wie private, aber auch fuer Ableitungen sichtbar
    string name_;
  public:
    Tier(string name) : name_(name) {}
    virtual ~Tier() {}                // virtueller Destruktor (siehe Kopf)
    virtual string laut() const {     // virtual -> in Ableitungen ueberschreibbar
      return "<unbestimmt>";
    }
    string name() const { return name_; }
};

class Hund : public Tier {            // Hund "ist ein" Tier
  public:
    Hund(string name) : Tier(name) {}
    string laut() const override { return "Wuff"; }  // ersetzt Tier::laut()
};

class Katze : public Tier {
  public:
    Katze(string name) : Tier(name) {}
    string laut() const override { return "Miau"; }
};

int main() {
  // Ein Basiszeiger (Tier*) zeigt auf verschiedene abgeleitete Objekte --
  // genau das ist Polymorphismus.
  Tier* tiere[] = { new Hund("Rex"), new Katze("Minka") };

  ostringstream oss;
  for (Tier* t : tiere) {
    // t->laut() ruft je nach echtem Typ Hund::laut() bzw. Katze::laut() auf,
    // obwohl t nur als Tier* bekannt ist (Aufloesung zur Laufzeit).
    oss << t->name() << " macht " << t->laut() << "\n";
  }
  cout << oss.str();   // Rex macht Wuff / Minka macht Miau

  // Aufraeumen: dank virtuellem ~Tier wird das richtige Objekt zerstoert.
  for (Tier* t : tiere) {
    delete t;
  }

  // --- Selbsttest: vergleicht die Ausgabe mit dem Erwartungswert ---
  if (oss.str() == "Rex macht Wuff\nMinka macht Miau\n") {
    cout << "ok\n";
    return 0;
  } else {
    cout << "Fehler in der Polymorphie!\n";
    return 1;  // Fehler nach aussen weiterleiten
  }
}
