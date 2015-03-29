BIN = bin
SRC = src
INC = include
OBJ = obj

CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -Wextra -pedantic -std=c++03

.SECONDARY: $(wildcard "obj/*.o")
.PHONY: all documentacion clean mrproper

# Genera todo
all: $(BIN)/ocultar $(BIN)/revelar

# Compilación de módulos
$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

#  Compilación de programas finales
$(BIN)/%: $(OBJ)/%.o $(OBJ)/codificar.o $(OBJ)/imagenES.o
	$(CXX) $(CPPFLAGS) -o $@ $^

# Documentación
documentacion:
	doxygen doc/doxys/Doxyfile

# Limpieza
clean :
	rm  -f $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	rm -f $(BIN)/* doc/html/* imagenes/test* tests/*salida
