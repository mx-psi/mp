BIN = bin
SRC = src
OBJ = obj
INC = include
OBJS = $(wildcard "obj/*.o")
CXX = g++
CPPFLAGS = -Wall -g -Wextra -pedantic -std=c++03 -I$(INC)

.SECONDARY: OBJS
.PHONY: all clean mrproper

# Genera todo
all: $(BIN)/BuscaMinas

# Compilación de módulo central
$(OBJ)/BuscaMinas.o: $(SRC)/BuscaMinas.cpp $(INC)/CampoMinas.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

# Compilación de módulos
$(OBJ)/%.o: $(INC)/%.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

#  Compilación del programa final
$(BIN)/BuscaMinas: $(OBJ)/BuscaMinas.o $(OBJ)/CampoMinas.o $(OBJ)/Tablero.o
	$(CXX) $(CPPFLAGS) -o $@ $^

# Limpieza
clean :
	rm  -f $(OBJ)/* $(SRC)/*~ ./*~

mrproper : clean
	rm -f $(BIN)/*
