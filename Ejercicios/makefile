CXX = g++
CXXFLAGS = -std=c++17 -Wall
FILES = ej1 ej2 ej3 ej4

# Reglas para compilar cada archivo por separado
all: $(FILES)

ej1: ej1.cpp
 $(CXX) $(CXXFLAGS) ej1.cpp -o ejecutable1

ej2: ej2.cpp
 $(CXX) $(CXXFLAGS) ej2.cpp -o ejecutable2

ej3: ej3.cpp
 $(CXX) $(CXXFLAGS) ej3.cpp -o ejecutable3

ej4: ej4.cpp
 $(CXX) $(CXXFLAGS) ej4.cpp -o ejecutable4

# Limpieza
clean:
 rm -f ejecutable1 ejecutable2 ejecutable3 ejecutable4
