BIN = bin
SRC = src
INC = include
OBJ = obj

CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -Wextra -pedantic -std=c++03


# Genera todo
all: $(BIN)/ocultar $(BIN)/revelar

# Comprueba que todo va bien
test: all
	@echo "Probando frase sin espacios..."
	$(BIN)/ocultar < tests/test1_input
	echo "imagenes/test_no_esp.pgm" | $(BIN)/revelar > tests/test1_salida
	diff -q tests/test1_salida tests/test1_correcto

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
