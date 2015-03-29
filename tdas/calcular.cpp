#include <iostream>
#include "matriz_operaciones.h"
using namespace std;

const int N_ARGS = 4; // Número de argumentos
const char* ARGS[N_ARGS] = {"NOT", "OR", "AND", "TRS"}; // Argumentos posibles

// Comprueba si dos cadenas son iguales.
bool Iguales(const char cad1[], const char cad2[])
{
  bool iguales = true;
  for (int i = 0; iguales && (cad1[i] != '\0' || cad2[i] != '\0'); i++)
    iguales = cad2[i] == cad1[i];

  return iguales;
}

// Comprueba que una cadena dada es uno de los argumentos posibles
bool Valido(const char arg[])
{
  for(int i = 0; i < N_ARGS; i++)
    if(Iguales(arg, ARGS[i]))
      return true;

  return false;
}

// Comprueba que dos matrices tienen las mismas dimensiones
bool CoincidenDimensiones(MatrizBit m1, MatrizBit m2)
{
  return Filas(m1) == Filas(m2) && Columnas(m1) == Columnas(m2); 
}

int main(int argc, char* argv[])
{
  MatrizBit salida, matriz1;
  bool todo_correcto;

  if (argc == 1 || argc > 4 || !Valido(argv[1]))
  {
    cerr << "calcular: Llamada incorrecta a la función" << endl;
    return 1;
  }

  // Lectura de la (primera) matriz
  if (argc == 2)
    todo_correcto = Leer(cin, matriz1);
  else
    todo_correcto = Leer(argv[2], matriz1);

  if (!todo_correcto)
  {
    cerr << "calcular: No se pudo leer la" << (Iguales(argv[1], "AND") || Iguales(argv[1], "OR")
            ? " primera " : " ") << "matriz" << endl;
    return 1;
  }

  if (Iguales(argv[1], "NOT"))
    Not(salida, matriz1);
  else if (Iguales(argv[1], "TRS"))
    Traspuesta(salida, matriz1);
  else
  {
    // Lectura de la segunda matriz
    MatrizBit matriz2;

    if (argc <= 3)
      todo_correcto = Leer(cin, matriz2);
    else
      todo_correcto = Leer(argv[3], matriz2);

    if (!todo_correcto)
    {
      cerr << "calcular: No se pudo leer la segunda matriz" << endl;
      return 1;
    }

    if (!CoincidenDimensiones(matriz1, matriz2))
    {
      cerr << "calcular: Las dimensiones de las matrices no coinciden" << endl;
      return -1;
    }
    if (Iguales(argv[1], "AND"))
      And(salida, matriz1, matriz2);
    else
      Or(salida, matriz1, matriz2);
  }

  Escribir(cout, salida);
  cout << endl;
}
