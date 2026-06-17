# Grundlagen in C

[![build](https://github.com/unger-robotics/grundlagen-in-c/actions/workflows/build.yml/badge.svg)](https://github.com/unger-robotics/grundlagen-in-c/actions/workflows/build.yml)

Eine Lernsammlung kleiner, eigenständiger **C- und C++-Beispielprogramme** zu den
Grundlagen beider Sprachen. Jede Datei ist ein in sich geschlossenes Programm mit
eigener `main()` und behandelt genau ein Thema.

> Entwickelt und getestet unter **macOS** (Apple Clang). Frühere Windows-/MinGW-
> und PowerShell-Teile wurden entfernt.

## Voraussetzungen

- **Xcode Command Line Tools** (liefern `clang`/`clang++` und `make`):
  ```sh
  xcode-select --install
  ```
- Optional [Homebrew](https://brew.sh/) für zusätzliche Werkzeuge (z. B. `git`, `gh`).

Prüfen:
```sh
cc --version     # Apple Clang
make --version
```

## Bauen & Ausführen

Der Build erkennt alle Quellen unter `src/c/` und `src/cpp/` automatisch – es muss
keine Liste gepflegt werden. Binärdateien landen in `bin/`.

```sh
make                 # alle Beispiele bauen
make run-array       # ein Beispiel bauen und sofort ausführen
./bin/zeiger         # gebautes Programm direkt starten
make clean           # bin/ wieder entfernen
```

## Projektstruktur

```
grundlagen-in-c/
├── include/funktionen.h   # gemeinsame Mini-Bibliothek (Deklarationen)
├── src/
│   ├── funktionen.c       # Implementierung der Bibliothek
│   ├── c/                 # C-Beispielprogramme
│   └── cpp/               # C++-Beispielprogramme
├── bin/                   # Build-Ausgabe (wird erzeugt, nicht versioniert)
└── Makefile
```

Die kleine Bibliothek `funktionen` (Fakultät, Quersumme, Potenzen) wird in jedes
**C**-Programm gelinkt; der Header ist per `extern "C"` auch aus C++ nutzbar.

## Themenübersicht

Jedes Programm ist eigenständig und behandelt genau ein Thema. Mit
`make run-<name>` (z. B. `make run-zeiger`) lässt sich ein Beispiel direkt starten.

### C (`src/c/`)

| Programm | Thema |
| --- | --- |
| `hallo-in-c.c`, `halloC-v02.c` | Erstes Programm, Konsolenausgabe |
| `datentypen.c` | Datentypen und Wertebereiche |
| `schleifen.c` | `for` / `while` / `do-while`, `break` & `continue` |
| `rekursion.c` | Rekursion vs. Iteration (Fakultät) |
| `zeiger.c` | Zeiger und Adressen |
| `lokal-global-var.c` | Lokale vs. globale Variablen (Gültigkeitsbereich) |
| `dynamischer-speicher.c` | Heap: `malloc` / `free` / `realloc` |
| `array.c`, `mehrdim-array.c` | Arrays und mehrdimensionale Arrays |
| `string.c`, `string-funktionen.c` | Zeichenketten und `<string.h>`-Funktionen |
| `struct-led.c` | Strukturen (`struct`) |
| `enum.c` | Aufzählungstypen (`enum`) |
| `union-typedef.c` | `union` und `typedef` |
| `bitoperationen.c` | Bitoperatoren und Bitmasken |
| `funktionszeiger.c` | Funktionszeiger |
| `sortieren.c`, `suchen.c` | Sortier- und Suchverfahren |
| `verkettete-liste.c` | Einfach verkettete Liste |
| `datei-io.c` | Datei-Ein-/Ausgabe (schreibt `zahlen.txt`) |
| `test-bibliothek.c` | Nutzt die gemeinsame `funktionen`-Bibliothek |

### C++ (`src/cpp/`)

| Programm | Thema |
| --- | --- |
| `hallo-in-c++.cpp`, `halloC++-v02.cpp` | Erstes C++-Programm (`std::cout`) |
| `class-person.cpp` | Klasse mit Zugriffsmethoden |
| `class-person-v02.cpp` | Konstruktor mit Initialisierungsliste; Ausgabe nach Bildschirm/Datei/String (mit Selbsttest) |
| `class-led.cpp` | Klasse mit privaten/öffentlichen Membern |
| `vererbung.cpp` | Vererbung & Polymorphismus (`virtual` / `override`) |
| `stl-vector.cpp` | `std::vector`, `<algorithm>` (`sort`/`find`), range-based `for` |

## Standards

C wird mit `-std=c23`, C++ mit `-std=c++23` übersetzt (im `Makefile` anpassbar).

## CI / Automatische Prüfungen

Bei jedem Push und Pull Request auf `main` läuft der Workflow
[`.github/workflows/build.yml`](.github/workflows/build.yml) auf einem **macOS**-Runner
(Apple Clang). Den Status zeigt das Badge oben. Geprüft werden zwei Dinge:

1. **Warnungsfreier Build** – alle Beispiele werden mit `-Werror` übersetzt; jede
   Compiler-Warnung (und natürlich jeder Syntax-/Typfehler) lässt die CI fehlschlagen.
2. **Ausführung** – jedes gebaute Programm wird gestartet; ein Exit-Code ≠ 0 (Absturz
   oder fehlgeschlagener Selbsttest, z. B. `class-person-v02`) lässt die CI fehlschlagen.

Lokal identisch nachstellbar:

```sh
make EXTRA_WARN=-Werror                                          # warnungsfrei bauen (wie in der CI)
for p in bin/*; do [ -f "$p" ] && [ -x "$p" ] && "$p" </dev/null; done   # alle ausführen
```

Geprüft werden damit Übersetzbarkeit, Warnungsfreiheit und Absturzfreiheit. **Logik-**
**fehler** in Programmen *ohne* Selbsttest erkennt die CI nicht – dafür müsste ein Programm
seine Ausgabe gegen einen Erwartungswert prüfen (wie `class-person-v02`).

## Git / Repository

```sh
git remote -v     # origin -> github.com/unger-robotics/grundlagen-in-c

# erstmalig veröffentlichen (Repo zuvor auf GitHub anlegen):
git push -u origin main
```

## Lizenz

Veröffentlicht unter der [MIT-Lizenz](LICENSE) – frei nutzbar, auch zu Lernzwecken.
