// Módulo principal del programa
#include <iostream>
#include "CampoMinas.h" // Tablero.h, fstream
using namespace std;

int main(int argc, char* argv[])
{
  // Se inicializa el campo de minas
  int filas, columnas, minas;
  CampoMinas campo;
  if (argc == 4)
  {
    filas = atoi(argv[1]);
    columnas = atoi(argv[2]);
    minas = atoi(argv[3]);
    campo = CampoMinas(filas, columnas, minas);
  }
  else if (argc == 2)
    if (!Leer(argv[1], campo))
      return 1;  // TODO: Leer desde archivo
  else
  {
    return 1;  // TODO: Instrucciones
  }

  if (filas < 4 || columnas < 4 || minas < 5 || minas*2 >= filas*columnas)
  {
    cout << "Debe haber al menos 4 filas y 4 columnas, y el número de minas debe ser mayor que 4 y menor que la mitad de las casillas" << endl;
    return 1;
  }


  bool algo_ha_pasado = true; // Almacena si ha pasado algo tras cada acción

  // Hasta que el juego termine, se pide una acción al usuario
  while (!campo.Explotado() && !campo.Ganado())
  {
    if (algo_ha_pasado)
      campo.PrettyPrint();

    char accion;
    int fila, columna;
    cout << "Acción y posición (fila y columna): ";
    cin >> accion >> fila >> columna;
    if (accion == 'a')
      algo_ha_pasado = campo.Abre(fila, columna);
    else  // (accion == 'm')
      algo_ha_pasado = campo.Marca(fila, columna);
  }

  // Se muestra si el jugador ha ganado o perdido
  campo.ImprimeTablero();
  if (campo.Explotado())
    cout << "¡Has perdido!" << endl;
  else  // (campo.Ganado())
    cout << "¡Has ganado!" << endl;
}
