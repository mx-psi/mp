// Módulo principal del programa
#include <iostream>
#include "CampoMinas.h" // Tablero.h, fstream, cstream
using namespace std;

enum TipoAccion { ABRIR, MARCAR, SALVAR, ERROR };

struct Accion
{
  TipoAccion tipo;
  int fila, columna;
  char* archivo;
};

Accion LeerAccion(char* entrada)
{
  Accion accion;

  for (int x = 0; entrada[x] != ' ' && entrada[x] != '\0'; x++)
    entrada[x] = tolower(entrada[x]);

  /* Clasificación de la acción */
  bool un_caracter = isspace(entrada[1]);
  if ((!un_caracter && !strcmp(entrada, "abrir")) || (un_caracter && entrada[0] == 'a'))
    accion.tipo = ABRIR;
  else if ((!un_caracter && !strcmp(entrada, "marcar")) || (un_caracter && entrada[0] == 'm'))
    accion.tipo = MARCAR;
  else if ((!un_caracter && !strcmp(entrada, "salvar")) || (un_caracter && entrada[0] == 's'))
    accion.tipo = SALVAR;
  else
    accion.tipo = ERROR;

  if (accion.tipo == ABRIR || accion.tipo == MARCAR)
  {
    while (!isspace(entrada[0]) && entrada[0] != '\0')
      entrada++;

    if (entrada[0] == '\0')
      accion.tipo = ERROR;
    else
      accion.fila = atoi(++entrada);

    while (!isspace(entrada[0]) && entrada[0] != '\0')
      entrada++;

    if (entrada[0] == '\0')
      accion.tipo = ERROR;
    else
      accion.columna = atoi(++entrada);
  }
  else
    accion.fila = accion.columna = 0;

  if (accion.tipo == SALVAR)
  {
    while (!isspace(entrada[0]) && entrada[0] != '\0')
      entrada++;

    if (entrada[0] == '\0')
      accion.tipo = ERROR;
    else
      accion.archivo = ++entrada;
  }
  else
    accion.archivo = 0;

  return accion;
}

int main(int argc, char* argv[])
{
  // Se inicializa el campo de minas
  int filas, columnas, minas;
  CampoMinas campo(0, 0, 0);
  if (argc == 4)
  {
    filas    = atoi(argv[1]);
    columnas = atoi(argv[2]);
    minas    = atoi(argv[3]);
    campo    = CampoMinas(filas, columnas, minas);
  }
  else if (argc == 2)
  {
    if (!campo.Leer(argv[1]))
      return 1;
  }
  else
  {
    cout << "Posibles usos:\n" << argv[0] << " [filas] [columnas] [minas]\tInicia partida con tales parámetros\n"
         << argv[0] << "[nombre de archivo]\t\tCarga una partida guardada" << endl;
    return 1;
  }

  if (filas < 4 || columnas < 4 || minas < 5 || minas*2 >= filas*columnas)
  {
    cout << "Debe haber al menos 4 filas y 4 columnas." << endl;
    cout << "El número de minas debe estar entre 4 y la mitad de las casillas" << endl;
    return 1;
  }


  bool algo_ha_pasado = true; // Almacena si ha pasado algo tras cada acción

  // Hasta que el juego termine, se pide una acción al usuario
  while (!campo.Explotado() && !campo.Ganado())
  {
    if (algo_ha_pasado)
      campo.PrettyPrint();

    char* entrada;
    cin.getline(entrada, 100);
    Accion accion = LeerAccion(entrada);

    if (accion.tipo == ABRIR)
      algo_ha_pasado = campo.Abre(accion.fila, accion.columna);
    else if (accion.tipo == MARCAR)
      algo_ha_pasado = campo.Marca(accion.fila, accion.columna);
    else if (accion.tipo == SALVAR)
    {
      if (campo.Escribir(accion.archivo))
      {
        cout << "Partida guardada correctamente" << endl;
        return 0;
      }
      else
        cout << "Error al intentar guardar la partida" << endl;
    }
    else  // accion.tipo == ERROR
    {
      cout << "Acción incorrecta" << endl;
      algo_ha_pasado = false;
    }
  }

  // Se muestra si el jugador ha ganado o perdido
  campo.ImprimeTablero();
  if (campo.Explotado())
    cout << "¡Has perdido!" << endl;
  else  // (campo.Ganado())
    cout << "¡Has ganado!" << endl;
}
