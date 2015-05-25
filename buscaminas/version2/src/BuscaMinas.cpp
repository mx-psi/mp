#include <iostream>
#include "CampoMinas.h" // Tablero.h, fstream, cstream
using namespace std;

/* Módulo principal del programa */

enum TipoAccion { ABRIR, MARCAR, SALVAR, ERROR };

struct Accion
{
  TipoAccion tipo;
  int fila, columna;
  char* archivo;
};

// Devuelve si una cadena es igual a la primera palabra de otra cadena
bool PrimeraPalabra(const char* una, const char* otra)
{
  int l = -1;
  while(una[++l] != '\0')
    if (una[l] != otra[l])
      return false;

  return otra[l] == ' ';
}

// Devuelve si la entrada coincide con la salida
bool Coincide(const char* entrada, const char* largo, char corto)
{
  bool un_caracter = isspace(entrada[1]);
  return (!un_caracter && PrimeraPalabra(largo, entrada)) || (un_caracter && *entrada == corto);
}

// Avanza hasta el siguiente grupo de caracteres y devuelve si se ha llegado al final
bool Avanzar(char* &entrada)
{
  while (!isspace(*entrada) && *entrada != '\0')
    entrada++;
  while (isspace(*entrada) && *entrada != '\0')
    entrada++;
  return *entrada != '\0';
}

// Lee una acción
Accion LeerAccion(char* entrada)
{
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
      accion.fila = atoi(entrada);

    if (!Avanzar(entrada))
      accion.tipo = ERROR;
    else
      accion.columna = atoi(entrada);
  }
  else
    accion.fila = accion.columna = 0;

  if (accion.tipo == SALVAR)
  {
    if (!Avanzar(entrada))
      accion.tipo = ERROR;
    else
      accion.archivo = entrada;
  }
  else
    accion.archivo = 0;

  return accion;
}

int main(int argc, char* argv[])
{
  // Se inicializa el campo de minas
  CampoMinas campo;
  if (argc == 4)
  {
    /* Filas columnas y minas como argumento */

    int filas    = atoi(argv[1]);
    int columnas = atoi(argv[2]);
    int minas    = atoi(argv[3]);

    if (filas < 4 || columnas < 4 || minas < 5 || minas*2 >= filas*columnas)
    {
      cout << "Debe haber al menos 4 filas y 4 columnas." << endl;
      cout << "El número de minas debe estar entre 5 y la mitad de las casillas" << endl;
      return 1;
    }

    CampoMinas aux(filas, columnas, minas);
    campo = aux;
  }
  else if (argc == 2)
  {
    /* Lectura de archivo */
    if (!campo.Leer(argv[1]))
    {
      cerr << "Error en la lectura de \"" << argv[1] << "\"" << endl;
      return 1;
    }
  }
  else
  {
    /* Uso incorrecto */
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
    cout << "Acción: ";
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
