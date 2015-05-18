BIN = bin
SRC = src
OBJ = obj
INC = include
OBJS = $(wildcard "obj/*.o")
INCS = $(wildcard "include/*.h")
CXX = g++
CPPFLAGS = -Wall -g -Wextra -pedantic -std=c++03 -I$(INC)

.SECONDARY: OBJS
.PHONY: all clean mrproper

# Genera todo
all: $(BIN)/BuscaMinas

# Compilación de módulo central
$(OBJ)/BuscaMinas.o: $(SRC)/BuscaMinas.cpp $(INCS)
	$(CXX) $(CPPFLAGS) -c $< -o $@

# Compilación de módulos
$(OBJ)/%.o: $(SRC)/%.cpp $(INC)/%.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

#  Compilación del programa final
$(BIN)/BuscaMinas: $(OBJ)/BuscaMinas.o $(OBJ)/CampoMinas.o $(OBJ)/Tablero.o
	$(CXX) $(CPPFLAGS) -o $@ $^

# Limpieza
clean :
	rm  -f $(OBJ)/* $(SRC)/*~ ./*~

mrproper : clean
	rm -f $(BIN)/*
