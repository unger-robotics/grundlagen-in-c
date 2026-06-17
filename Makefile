# ju -- 17-Jun-26 -- Makefile
# macOS (Apple Clang) -- Build der C/C++-Grundlagenbeispiele
#
# Verwendung:
#   make              alle Beispiele bauen (Ausgabe nach bin/)
#   make run-array    Beispiel bauen und ausfuehren (z. B. bin/array)
#   make debug-array  Beispiel unter lldb ausfuehren (Auto-Backtrace bei Absturz)
#   make clean        bin/ entfernen
#
# Quellen werden automatisch erkannt (src/c/*.c, src/cpp/*.cpp) --
# neue Dateien einfach dort ablegen, keine Liste pflegen.

CC       ?= cc          # Apple Clang (gcc ist hierauf nur ein Alias)
CXX      ?= c++         # Apple Clang++ (g++ ist hierauf nur ein Alias)
EXTRA_WARN ?=          # zusaetzliche Warn-Flags, z. B. in der CI: make EXTRA_WARN=-Werror
WARN     := -Wall -Wextra -Wno-missing-field-initializers $(EXTRA_WARN)
CFLAGS   := -std=c23   $(WARN) -g -O0
CXXFLAGS := -std=c++23 $(WARN) -g -O0
CPPFLAGS := -Iinclude
LIB      := src/funktionen.c

# Optionaler Sanitizer, standardmaessig aus.
#   make SANITIZE=address,undefined   -> Speicher-/UB-Checks (z. B. fuer make test)
# -fsanitize in den (C|CXX)FLAGS wirkt bei diesen Ein-Schritt-Builds zugleich beim Linken.
SANITIZE ?=
ifneq ($(SANITIZE),)
SAN      := -fsanitize=$(SANITIZE) -fno-omit-frame-pointer
CFLAGS   += $(SAN)
CXXFLAGS += $(SAN)
endif

# macOS-SDK ermitteln und mitgeben -- robust, falls CC/CXX das Sysroot
# nicht selbst setzen (z. B. wenn CC auf das rohe clang-Binary zeigt).
SDKROOT  := $(shell xcrun --show-sdk-path 2>/dev/null)
ifneq ($(SDKROOT),)
CPPFLAGS += -isysroot $(SDKROOT)
endif

C_SRCS   := $(wildcard src/c/*.c)
CPP_SRCS := $(wildcard src/cpp/*.cpp)
BINS     := $(patsubst src/c/%.c,bin/%,$(C_SRCS)) \
            $(patsubst src/cpp/%.cpp,bin/%,$(CPP_SRCS))

all: $(BINS)

bin:
	mkdir -p bin

# C-Programme: gemeinsame Bibliothek mitlinken
bin/%: src/c/%.c $(LIB) include/funktionen.h | bin
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $< $(LIB)

# C++-Programme: eigenstaendig (nutzen die Bibliothek nicht)
bin/%: src/cpp/%.cpp | bin
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

# Komfort: bauen und ausfuehren, z. B. `make run-zeiger`
run-%: bin/%
	./$<

# Komfort: unter lldb ausfuehren; bei Absturz automatisch Backtrace,
# z. B. `make debug-zeiger`. --batch laeuft ohne manuelle Eingabe; bei sauberem
# Lauf wie run-%, sonst gibt -k 'bt all' (nur im Crash-Fall) den Backtrace aus.
# Nutzt die vorhandenen -g -O0-Binaries. Hinweis: lldb liefert auch nach einem
# Absturz Exit 0 -- ein Crash schlaegt make also nicht fehl (anders als bei test).
debug-%: bin/%
	lldb --batch -o run -k 'bt all' -k quit ./$<

# Selbsttests bauen und ausfuehren (Exit != 0 = Test fehlgeschlagen).
# Fuer echte Speicherpruefung: make clean && make SANITIZE=address,undefined test
TESTBINS := bin/test-bibliothek bin/test-speicher
test: $(TESTBINS)
	@for t in $(TESTBINS); do echo "== $$t =="; "./$$t" || exit 1; done
	@echo "Alle Selbsttests bestanden."

clean:
	rm -rf bin

.PHONY: all clean test
