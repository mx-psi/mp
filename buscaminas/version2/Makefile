BIN = bin
SRC = src
OBJ = obj
INC = include
CXX = g++
CPPFLAGS = -Wall -g -Wextra -pedantic -I$(INC)

.PHONY: all clean mrproper

# Genera todo
all: $(BIN)/BuscaMinas

#  Compilación del programa final
$(BIN)/BuscaMinas: $(OBJ)/BuscaMinas.o $(OBJ)/Tablero.o $(OBJ)/CampoMinas.o
	$(CXX) $(CPPFLAGS) -o $@ $^

# Compilación de módulos
$(OBJ)/BuscaMinas.o: $(SRC)/BuscaMinas.cpp $(INC)/CampoMinas.h $(INC)/Tablero.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ)/Tablero.o: $(SRC)/Tablero.cpp $(INC)/Tablero.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ)/CampoMinas.o: $(SRC)/CampoMinas.cpp $(INC)/CampoMinas.h $(INC)/Tablero.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

# Limpieza
clean :
	rm  -f $(OBJ)/* $(SRC)/*~ ./*~

mrproper : clean
	rm -f $(BIN)/*
