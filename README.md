# Grundlagen in C

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

**C** – Hallo-Welt, Datentypen, Arrays & mehrdimensionale Arrays, Strings, Zeiger,
lokale/globale Variablen, `struct`, `enum`, `union`/`typedef`, Bitoperationen,
dynamischer Speicher (`malloc`/`free`/`realloc`), Datei-I/O, Funktionszeiger,
Sortier- und Suchverfahren, einfach verkettete Liste, eigene Bibliothek.

**C++** – Hallo-Welt, Klassen mit Zugriffsmethoden, Konstruktoren mit
Initialisierungsliste, Ausgabe nach Bildschirm/Datei/String (mit Selbsttest).

## Standards

C wird mit `-std=c23`, C++ mit `-std=c++23` übersetzt (im `Makefile` anpassbar).

## Git / Repository

```sh
git remote -v     # origin -> github.com/unger-robotics/grundlagen-in-c

# erstmalig veröffentlichen (Repo zuvor auf GitHub anlegen):
git push -u origin main
```
