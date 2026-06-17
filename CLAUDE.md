# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Was dieses Repo ist

Lern-/Übungssammlung zu C- und C++-Grundlagen ("Grundlagen in C"), entwickelt für **macOS** (Apple Clang). Es ist **keine** zusammenhängende Anwendung: Jede `.c`-/`.cpp`-Datei ist ein eigenständiges Programm mit eigener `main()` und behandelt genau ein Thema. Themen sind voneinander unabhängig — eine Änderung an einer Datei betrifft die anderen nicht.

## Struktur

```
include/funktionen.h   # gemeinsame Mini-Bibliothek (Deklarationen, extern "C"-Guard)
src/funktionen.c       # Implementierung der Bibliothek (kein eigenes main)
src/c/*.c              # C-Beispielprogramme
src/cpp/*.cpp          # C++-Beispielprogramme
bin/                   # Build-Ausgabe (erzeugt, gitignored)
```

## Build & Run

```sh
make                 # baut alle Beispiele nach bin/
make run-array       # ein Beispiel bauen und ausführen (Muster: run-<name>)
make debug-array     # Beispiel unter lldb ausführen, Auto-Backtrace bei Absturz
./bin/zeiger         # gebautes Programm direkt starten
make test            # Selbsttests bauen + ausführen (Exit != 0 = fehlgeschlagen)
make clean           # bin/ entfernen
```

```sh
make EXTRA_WARN=-Werror              # warnungsfrei bauen wie in der CI (Warnung = Fehler)
make clean && make SANITIZE=address,undefined test   # Selbsttests unter ASan/UBSan
```

- **Quellen werden automatisch erkannt** (`$(wildcard src/c/*.c)` / `src/cpp/*.cpp`) — es gibt **keine** von Hand zu pflegende `TARGETS`-Liste mehr. Neue Datei in `src/c/` oder `src/cpp/` ablegen genügt; der Binärname ist der Dateiname ohne Endung.
- C: `cc -std=c23`, C++: `c++ -std=c++23` (`cc`/`c++` sind auf macOS Apple Clang; per `CC`/`CXX` überschreibbar).
- Das Makefile ermittelt das macOS-SDK via `xcrun --show-sdk-path` und gibt es als `-isysroot` mit — nötig, falls `CC`/`CXX` auf das rohe `clang`-Binary zeigen (findet sonst `stdio.h` nicht).
- **Nur C-Programme** linken `src/funktionen.c` mit; C++-Programme sind eigenständig.
- Es gibt **kein Testframework**, aber einen einfachen `make test`-Lauf. Selbsttests sind `src/c/test-*.c` (aktuell `test-bibliothek.c` = Bibliothekslogik, `test-speicher.c` = malloc/realloc/free + Liste + Puffer, sinnvoll unter `SANITIZE`). Konvention pro Testdatei: ein `static void pruefe(name, erwartet, erhalten)`-Helfer, der Fehler zählt; `main` gibt am Ende `return fehler != 0` zurück (Exit 0 = alle bestanden). Zusätzlich prüfen sich manche Beispiele selbst (z. B. `src/cpp/class-person-v02.cpp` vergleicht seine Ausgabe mit einem Erwartungs-String, sonst `return 1`).
- **Achtung:** Die von `make test` ausgeführte Liste `TESTBINS` im `Makefile` wird — anders als die auto-erkannten Quellen — **von Hand** gepflegt. Eine neue `test-*.c` baut zwar automatisch mit, läuft aber erst bei `make test` mit, wenn sie dort eingetragen ist.

## Die "Bibliothek"

`include/funktionen.h` / `src/funktionen.c` ist die einzige gemeinsam genutzte Einheit: kleine Mathe-Hilfsfunktionen (`fac`, `quersumme`, `quadriere`, `drittePotenz`, `potenziere`). Der Header nutzt Include-Guard (`BIB_H`) und einen `extern "C"`-Block, damit er auch aus C++ verwendbar ist. Neue gemeinsame Funktionen gehören hierher (Deklaration in `.h`, Definition in `.c`).

## Laufzeit-Artefakte

Einige Beispiele schreiben Dateien ins aktuelle Verzeichnis: `class-person-v02.cpp` → `personen.txt`, `datei-io.c` → `zahlen.txt`. Beide sind in `.gitignore` und sollten nicht committet werden.

## Stil-Konventionen (durchgängig im Repo)

- Kopfzeile pro Datei: `// ju -- <Datum> -- <dateiname>`.
- Einrückung 2 Leerzeichen, **niemals Tabs**; Codierung UTF-8, Zeilenende LF.
- Formatierung ist per `.clang-format` festgelegt (LLVM-Basis, `IndentWidth: 2`, `UseTab: Never`, `ColumnLimit: 100`, `ReflowComments: false`, `SortIncludes: false`). Vor dem Commit formatieren: `clang-format -i <datei>` (oder alle: `find src include \( -name '*.c' -o -name '*.cpp' -o -name '*.h' \) -print0 | xargs -0 clang-format -i`). Die CI prüft den Stil mit `clang-format --dry-run --Werror` (clang-format 22) — Abweichungen lassen sie fehlschlagen. Kommentare werden bewusst nicht umgebrochen, daher dort auf trailing whitespace selbst achten.
- Kommentare und Bezeichner auf Deutsch. Umlaute im **Code/Kommentaren** sind ok; in neuen Beispielen werden sie der Portabilität halber teils als `ae/oe/ue` geschrieben — am Stil der umgebenden Datei orientieren. Umlaute niemals in bestehenden Texten durch ASCII ersetzen.
- Build muss warnungsfrei bleiben. Das Makefile nutzt `-Wall -Wextra -Wno-missing-field-initializers` (letzteres erlaubt bewusst partielle Struct-Initialisierung, z. B. in `struct-led.c`).
