// ju -- 17-Jun-26 -- stl-vector.cpp
/*
  std::vector ist ein dynamisches Array aus der C++-Standardbibliothek (STL):
  es waechst zur Laufzeit (anders als ein festes C-Array) und kennt seine eigene
  Groesse. Mit Algorithmen aus <algorithm> (z.B. sort, find) laesst es sich
  bequem bearbeiten. Die range-based for-Schleife laeuft ueber alle Elemente,
  ohne dass man mit Indizes hantieren muss.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<int> zahlen = {42, 7, 19}; // mit drei Werten starten

  zahlen.push_back(3); // hinten anfuegen -> der vector waechst
  zahlen.push_back(25);

  cout << "Groesse: " << zahlen.size() << "\n"; // 5

  // --- sortieren (aufsteigend) ---
  sort(zahlen.begin(), zahlen.end());

  // --- range-based for: ueber alle Elemente iterieren ---
  cout << "sortiert:";
  for (int z : zahlen) {
    cout << " " << z; // Ausgabe: 3 7 19 25 42
  }
  cout << "\n";

  // --- suchen mit find: liefert einen Iterator (Position) ---
  int gesucht = 19;
  auto it = find(zahlen.begin(), zahlen.end(), gesucht);
  if (it != zahlen.end()) {
    // it - begin() ist der Index des gefundenen Elements
    cout << gesucht << " gefunden an Index " << (it - zahlen.begin()) << "\n";
  } else {
    cout << gesucht << " nicht gefunden\n";
  }
  return 0;
}
