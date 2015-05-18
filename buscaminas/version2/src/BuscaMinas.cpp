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

bool Coincide(const char* entrada, const char* largo, char corto)
{
  /* Devuelve si la entrada coincide con la salida. */
  bool un_caracter = isspace(entrada[1]);
  return (!un_caracter && !strcmp(entrada, largo)) || (un_caracter && *entrada == corto);
}

bool Avanzar(char* entrada)
{
  /* Avanza hasta el siguiente caracter y devuelve si se ha llegado al final. */
  while (!isspace(*entrada) && *entrada != '\0')
    entrada++;
  return *entrada == '\0';
}

Accion LeerAccion(char* entrada)
{
  /* Lee una acción */
  Accion accion;

  for (int x = 0; entrada[x] != ' ' && entrada[x] != '\0'; x++)
    entrada[x] = tolower(entrada[x]);

  /* Clasificación de la acción */
  if (Coincide(entrada, "abrir", 'a'))
    accion.tipo = ABRIR;
  else if (Coincide(entrada, "marcar", 'm'))
    accion.tipo = MARCAR;
  else if (Coincide(entrada, "salvar", 's'))
    accion.tipo = SALVAR;
  else
    accion.tipo = ERROR;

  if (accion.tipo == ABRIR || accion.tipo == MARCAR)
  {
    if (!Avanzar(entrada))
      accion.tipo = ERROR;
    else
      accion.fila = atoi(++entrada);

    if (!Avanzar(entrada))
      accion.tipo = ERROR;
    else
      accion.columna = atoi(++entrada);
  }
  else
    accion.fila = accion.columna = 0;

  if (accion.tipo == SALVAR)
  {
    if (!Avanzar(entrada))
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
  CampoMinas campo(20, 20, 0);
  if (argc == 4)
  {
    /* Filas columnas y minas como argumento */

    filas    = atoi(argv[1]);
    columnas = atoi(argv[2]);
    minas    = atoi(argv[3]);

    if (filas < 4 || columnas < 4 || minas < 5 || minas*2 >= filas*columnas)
    {
      cout << "Debe haber al menos 4 filas y 4 columnas." << endl;
      cout << "El número de minas debe estar entre 4 y la mitad de las casillas" << endl;
      return 1;
    }

    CampoMinas aux(filas, columnas, minas);
    campo = aux;
  }
  else if (argc == 2 && !campo.Leer(argv[1]))
  {
    cerr << "Error en la lectura de \"" << argv[1] << "\"" << endl;
    return 1;
  }
  else
  {
    cout << "Posibles usos:\n" << argv[0]
         << " [filas] [columnas] [minas]\tInicia partida con tales parámetros\n"
         << argv[0] << "[nombre de archivo]\t\tCarga una partida guardada" << endl;
    return 1;
  }

  char* entrada = new char[100];
  bool algo_ha_pasado = true; // Almacena si ha pasado algo tras cada acción

  // Hasta que el juego termine, se pide una acción al usuario
  while (!campo.Explotado() && !campo.Ganado())
  {
    if (algo_ha_pasado)
      campo.PrettyPrint();

    // Lee la entrada
    cin.getline(entrada, 100);
    Accion accion = LeerAccion(entrada);

    //
    if (accion.tipo == ABRIR)
      algo_ha_pasado = campo.Abre(accion.fila, accion.columna);
    else if (accion.tipo == MARCAR)
      algo_ha_pasado = campo.Marca(accion.fila, accion.columna);
    else if (accion.tipo == SALVAR)
    {
      if (campo.Escribir(accion.archivo))
      {
        cout << "Partida guardada correctamente" << endl;
        delete[] entrada;
        return 0;
      }
      else
        cerr << "Error al intentar guardar la partida" << endl;
    }
    else  // accion.tipo == ERROR
    {
      cerr << "Acción incorrecta" << endl;
      algo_ha_pasado = false;
    }
  }

  delete[] entrada;

  // Se muestra si el jugador ha ganado o perdido
  campo.ImprimeTablero();
  if (campo.Explotado())
    cout << "¡Has perdido!" << endl;
  else  // (campo.Ganado())
    cout << "¡Has ganado!" << endl;
}
