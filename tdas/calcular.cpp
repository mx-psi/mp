#include "matriz_operaciones.h" // Llama a iostream
using namespace std;

int main(int argc, char* argv[])
{
  if (argc > 0 && (argv[0] == "NOT" || argv[0] == "TRS"))
  {
    MatrizBit matriz;
    if (argc == 1 && !Leer(cin, matriz) || !Leer(argv[1], matriz))  // TODO: Si no te gusta esto así de agrupado, puede toquetearse
    {
      cerr << "calcular: No se pudo leer la matriz" << endl;
      return 1;
    }
    MatrizBit salida;
    if (argv[0] == "NOT")
      Not(salida, matriz);
    else  // argv[0] == "TRS"
      Traspuesta(salida, matriz); 

    Escribir(cout, salida);
  }
  else if (argc > 0 && (argv[0] == "AND" || argv[0] == "OR"))
  {
    MatrizBit matriz1, matriz2;
    if (argc == 1 && !Leer(cin, matriz1) || !Leer(argv[1], matriz1))  // TODO: Si no te gusta esto así de agrupado, puede toquetearse
    {
      cerr << "calcular: No se pudo leer la primera matriz" << endl;
      return 1;
    }
    if (argc <= 2 && !Leer(cin, matriz2) || !Leer(argv[2], matriz2))  // TODO: Si no te gusta esto así de agrupado, puede toquetearse
    {
      cerr << "calcular: No se pudo leer la segunda matriz" << endl;
      return 1;
    }
    MatrizBit salida;
    if (argv[0] == "AND")
      And(salida, matriz1, matriz2);
    else  // argv[0] == "OR"
      Or(salida, matriz1, matriz2); 

    Escribir(cout, salida);
  }
  else
    return 1; // TODO: Una parrafada indicando el uso del programa molaría.
}
