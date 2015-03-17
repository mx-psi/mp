BIN = bin
SRC = src
INC = include
OBJ = obj

CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c -Wextra -pedantic -std=c++03


all: $(BIN)/ocultar $(BIN)/revelar

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o

$(OBJ)/codificar.o: $(SRC)/codificar.cpp $(INC)/codificar.h
	$(CXX) $(CPPFLAGS) $(SRC)/codificar.cpp -o $(OBJ)/codificar.o

$(OBJ)/ocultar.o: $(SRC)/ocultar.cpp $(INC)/codificar.h $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/ocultar.cpp -o $(OBJ)/ocultar.o

$(OBJ)/revelar.o: $(SRC)/revelar.cpp $(INC)/codificar.h $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/revelar.cpp -o $(OBJ)/revelar.o

# ************ Compilación de programas finales ************
$(BIN)/ocultar: $(OBJ)/ocultar.o
	$(CXX) $(CPPFLAGS) -o $(BIN)/ocultar $(OBJ)/ocultar.o

$(BIN)/revelar: $(OBJ)/revelar.o
	$(CXX) $(CPPFLAGS) -o $(BIN)/revelar $(OBJ)/revelar.o

# ************ Limpieza ************
clean :
	rm  -f $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	rm -f $(BIN)/* doc/html/*
