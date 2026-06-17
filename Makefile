# ju -- 17-Jun-26 -- Makefile
# macOS (Apple Clang) -- Build der C/C++-Grundlagenbeispiele
#
# Verwendung:
#   make              alle Beispiele bauen (Ausgabe nach bin/)
#   make run-array    Beispiel bauen und ausfuehren (z. B. bin/array)
#   make clean        bin/ entfernen
#
# Quellen werden automatisch erkannt (src/c/*.c, src/cpp/*.cpp) --
# neue Dateien einfach dort ablegen, keine Liste pflegen.

CC       ?= cc          # Apple Clang (gcc ist hierauf nur ein Alias)
CXX      ?= c++         # Apple Clang++ (g++ ist hierauf nur ein Alias)
WARN     := -Wall -Wextra -Wno-missing-field-initializers
CFLAGS   := -std=c23   $(WARN) -g -O0
CXXFLAGS := -std=c++23 $(WARN) -g -O0
CPPFLAGS := -Iinclude
LIB      := src/funktionen.c

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

clean:
	rm -rf bin

.PHONY: all clean
