#include <iostream>
#include "CampoMinas.h"
using namespace std;

int main()
{
  int filas, columnas, minas;

  cout << "Dimensiones del tablero (filas y columnas): ";
  cin >> filas >> columnas;
  cout << "Número de minas (no debe ser menor que 5 ni mayor que la mitad que el número de casillas): ";
  do
  {
    cin >> minas;
  }while (minas < 5 || minas > filas*columnas/2);

  CampoMinas campo(filas, columnas, minas);

  while (!campo.Explotado() && !campo.Ganado())
  {
    campo.PrettyPrint();
    char accion;
    int fila, columna;
    cout << "Acción y posición (fila y columna): ";
    cin >> accion >> fila >> columna;
    if (accion == 'a')
      campo.Abre(fila, columna);
    else  // (accion == 'm')
      campo.Marca(fila, columna);
  }

  campo.ImprimeTablero();
  if (campo.Explotado())
    cout << "¡Has perdido!";
  else
    cout << "¡Has ganado!";
}
