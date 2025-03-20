CXX = g++
CXXFLAGS = -std=c++17 -Wall

TARGET_EJ1 = ejecutable1
TARGET_EJ2 = ejecutable2
TARGET_EJ3 = ejecutable3
TARGET_EJ4 = ejecutable4

# Reglas para compilar cada archivo por separado
all: ej1 ej2 ej3 ej4

ej1: ej1.cpp ej1.hpp
	$(CXX) $(CXXFLAGS) -o $(TARGET_EJ1) ej1.cpp
	./$(TARGET_EJ1)

ej2: ej2.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET_EJ2) ej2.cpp
	./$(TARGET_EJ2)

ej3: ej3.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET_EJ3) ej3.cpp
	./$(TARGET_EJ3)

ej4: ej4.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET_EJ4) ej4.cpp
	./$(TARGET_EJ4)

# Limpieza
clean:
	rm -f ej1 ejecutable2 ejecutable3 ejecutable4
