SRC = src
OBJ = obj
LIB = lib
BIN = bin
INC = include
AR = ar
CXX = g++
CXXFLAGS = -Wall -g -I$(INC) -Wextra -pedantic -std=c++03
LDFLAGS = -L$(LIB)
LDLIBS = -lformas


all: $(BIN)/central $(BIN)/area $(BIN)/longitud

$(BIN)/longitud: $(OBJ)/longitud.o $(LIB)/libformas.a
	$(CXX) $(CXXFLAGS) -o $(BIN)/longitud $(OBJ)/longitud.o $(LDFLAGS) $(LDLIBS)

$(BIN)/area: $(OBJ)/area.o $(LIB)/libformas.a
	$(CXX) $(CXXFLAGS) -o $(BIN)/area $(OBJ)/area.o $(LDFLAGS) $(LDLIBS)

$(BIN)/central: $(OBJ)/central.o $(LIB)/libformas.a
	$(CXX) $(CXXFLAGS) -o $(BIN)/central $(OBJ)/central.o $(LDFLAGS) $(LDLIBS)

$(OBJ)/longitud.o: $(INC)/punto.h $(SRC)/longitud.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/longitud.o $(SRC)/longitud.cpp

$(OBJ)/area.o: $(INC)/punto.h $(INC)/circulo.h $(SRC)/area.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/area.o $(SRC)/area.cpp

$(OBJ)/central.o: $(INC)/punto.h $(INC)/circulo.h $(SRC)/central.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/central.o $(SRC)/central.cpp

$(OBJ)/punto.o: $(INC)/punto.h $(SRC)/punto.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/punto.o $(SRC)/punto.cpp

$(OBJ)/circulo.o: $(INC)/circulo.h $(SRC)/circulo.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/circulo.o $(SRC)/circulo.cpp

$(LIB)/libformas.a: $(OBJ)/punto.o $(OBJ)/circulo.o
	$(AR) rvs $(LIB)/libformas.a $(OBJ)/punto.o $(OBJ)/circulo.o

clean:
	@echo "Limpiando ..."
	rm -f $(OBJ)/*.o $(LIB)/lib*.a

mrproper: clean
	rm -f $(BIN)/*

