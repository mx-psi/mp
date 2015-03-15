ARFLAGS = rvs
AR = ar $(ARFLAGS)
INC = include/
SRC = src/
OBJ = obj/
LIB = lib/
BIN = bin/
LDFLAGS = -L$(LIB)
LDLIBS = -lformas
CXXFLAGS = -Wall -g -I$(INC) -Wextra -pedantic -std=c++03
CXX = g++ $(CXXFLAGS)


all: $(BIN)central $(BIN)area $(BIN)rectangulo $(BIN)longitud

$(BIN)central: $(OBJ)central.o $(LIB)libformas.a
	$(CXX) -o $(BIN)central $(OBJ)central.o $(LDFLAGS) $(LDLIBS)

$(BIN)rectangulo: $(OBJ)rectangulo.o $(LIB)libformas.a
	$(CXX) -o $(BIN)rectangulo $(OBJ)rectangulo.o $(LDFLAGS) $(LDLIBS)

$(BIN)longitud: $(OBJ)longitud.o $(LIB)libformas.a
	$(CXX) -o $(BIN)longitud $(OBJ)longitud.o $(LDFLAGS) $(LDLIBS)

$(BIN)area: $(OBJ)area.o $(LIB)libformas.a
	$(CXX) -o $(BIN)area $(OBJ)area.o $(LDFLAGS) $(LDLIBS)

$(OBJ)rectangulo.o: $(INC)rectmod.h $(INC)punto.h $(SRC)rectangulo.cpp
	$(CXX) -c -o $(OBJ)rectangulo.o $(SRC)rectangulo.cpp

$(OBJ)longitud.o: $(INC)punto.h $(SRC)longitud.cpp
	$(CXX) -c -o $(OBJ)longitud.o $(SRC)longitud.cpp

$(OBJ)central.o: $(INC)circulo.h $(INC)punto.h $(SRC)central.cpp
	$(CXX) -c -o $(OBJ)central.o $(SRC)central.cpp

$(OBJ)area.o: $(INC)circulo.h $(INC)punto.h $(SRC)area.cpp
	$(CXX) -c -o $(OBJ)area.o $(SRC)area.cpp

$(LIB)libformas.a: $(OBJ)punto.o $(OBJ)circulo.o $(OBJ)rectmod.o
	$(AR) $(LIB)libformas.a $(OBJ)punto.o $(OBJ)circulo.o $(OBJ)rectmod.o

$(OBJ)rectmod.o: $(INC)rectmod.h $(SRC)rectmod.cpp
	$(CXX) -c -o $(OBJ)rectmod.o $(SRC)rectmod.cpp

$(OBJ)circulo.o: $(INC)circulo.h $(SRC)circulo.cpp
	$(CXX) -c -o $(OBJ)circulo.o $(SRC)circulo.cpp

$(OBJ)punto.o: $(INC)punto.h $(SRC)punto.cpp
	$(CXX) -c -o $(OBJ)punto.o $(SRC)punto.cpp

clean:
	rm -f $(OBJ)*.o $(LIB)*.a

mrproper: clean
	rm -f $(BIN)central $(BIN)area $(BIN)rectangulo $(BIN)longitud
