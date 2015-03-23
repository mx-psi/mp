#include <iostream>
#include "matriz_operaciones.h"
using namespace std;

int main(int argc, char* argv[])
{
  if (argc > 1 && (argv[1] == "NOT" || argv[1] == "TRS"))
  {
    MatrizBit matriz;
    if ((argc == 2 && !Leer(cin, matriz)) || !Leer(argv[2], matriz))  // TODO: Si no te gusta esto así de agrupado, puede toquetearse
    {
      cerr << "calcular: No se pudo leer la matriz" << endl;
      return 1;
    }
    MatrizBit salida;
    if (argv[1] == "NOT")
      Not(salida, matriz);
    else  // argv[1] == "TRS"
      Traspuesta(salida, matriz); 

    Escribir(cout, salida);
  }
  else if (argc > 1 && (argv[1] == "AND" || argv[1] == "OR"))
  {
    MatrizBit matriz1, matriz2;
    if ((argc == 2 && !Leer(cin, matriz1)) || !Leer(argv[2], matriz1))  // TODO: Si no te gusta esto así de agrupado, puede toquetearse
    {
      cerr << "calcular: No se pudo leer la primera matriz" << endl;
      return 1;
    }
    if ((argc <= 3 && !Leer(cin, matriz2)) || !Leer(argv[3], matriz2))  // TODO: Si no te gusta esto así de agrupado, puede toquetearse
    {
      cerr << "calcular: No se pudo leer la segunda matriz" << endl;
      return 1;
    }
    MatrizBit salida;
    if (argv[1] == "AND")
      And(salida, matriz1, matriz2);
    else  // argv[1] == "OR"
      Or(salida, matriz1, matriz2); 

    Escribir(cout, salida);
  }
  else
    return 1; // TODO: Una parrafada indicando el uso del programa molaría.
}

