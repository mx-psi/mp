BIN = bin
SRC = src
INC = include
OBJ = obj

CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -Wextra -pedantic -std=c++03


# ************ Todos y tests ******************
all: $(BIN)/ocultar $(BIN)/revelar

test: test1

test1: all
	@echo "Probando frase sin espacios..."
	$(BIN)/ocultar < tests/test1_input
	echo "imagenes/test_no_esp" | $(BIN)/revelar > tests/test1_salida
	diff -q tests/test1_salida tests/test1_correcto


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o

$(OBJ)/codificar.o: $(SRC)/codificar.cpp $(INC)/codificar.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/codificar.cpp -o $(OBJ)/codificar.o

$(OBJ)/ocultar.o: $(SRC)/ocultar.cpp $(INC)/codificar.h $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/ocultar.cpp -o $(OBJ)/ocultar.o

$(OBJ)/revelar.o: $(SRC)/revelar.cpp $(INC)/codificar.h $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/revelar.cpp -o $(OBJ)/revelar.o

# ************ Compilación de programas finales ************
$(BIN)/ocultar: $(OBJ)/ocultar.o $(OBJ)/codificar.o $(OBJ)/imagenES.o
	$(CXX) $(CPPFLAGS) -o $(BIN)/ocultar $(OBJ)/ocultar.o $(OBJ)/codificar.o $(OBJ)/imagenES.o

$(BIN)/revelar: $(OBJ)/revelar.o $(OBJ)/codificar.o $(OBJ)/imagenES.o
	$(CXX) $(CPPFLAGS) -o $(BIN)/revelar $(OBJ)/revelar.o $(OBJ)/codificar.o $(OBJ)/imagenES.o

# ************ Limpieza ************
clean :
	rm  -f $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	rm -f $(BIN)/* doc/html/* imagenes/test*
