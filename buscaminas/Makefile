BIN = bin
SRC = src
OBJ = obj
OBJS = $(wildcard "obj/*.o")
CXX = g++
CPPFLAGS = -Wall -g -Wextra -pedantic -std=c++03

.SECONDARY: OBJS
.PHONY: all clean mrproper

# Genera todo
all: $(BIN)/ocultar $(BIN)/revelar

# Compilación de módulos
$(OBJ)/%.o: $(SRC)/%.cpp
  $(CXX) $(CPPFLAGS) -c $< -o $@

#  Compilación del programa final
$(BIN)/BuscaMinas: $(OBJ)/BuscaMinas.o $(OBJ)/CampoMinas.o $(OBJ)/Tablero.o
  $(CXX) $(CPPFLAGS) -o $@ $^

# Limpieza
clean :
  rm  -f $(OBJ)/* $(SRC)/*~ ./*~

mrproper : clean
  rm -f $(BIN)/*
