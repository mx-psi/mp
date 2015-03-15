#include <iostream>
#include <fstream>
#include "rectmod.h"    // Llama a punto.h
using namespace std;

// Salta los espacios y los comentarios en la lectura
void Avanza(istream &is)
{
  while (isspace(is.peek()) || is.peek() == '#')
    if (is.peek() == '#')
        is.ignore(8192, '\n');
    else
        is.ignore();
}

// Lee un punto saltando los espacios y comentarios previos
bool LeerConSaltos(istream &is, Punto &p)
{
    Avanza(is);
    return Leer(is, p);
}

// Expande el rectángulo para que abarque el punto, si no lo abarca ya
void Actualiza(const Punto &p, Rectangulo &r)
{
  if (p.x < r.vert1.x)
      r.vert1.x = p.x;
  else if (p.x > r.vert2.x)
      r.vert2.x = p.x;

  if (p.y < r.vert1.y)
      r.vert1.y = p.y;
  else if (p.y > r.vert2.y)
      r.vert2.y = p.y;
}

// Obtiene el rectángulo que abarca el punto dado y los leídos hasta fin de fichero. Devuelve si se lee con éxito
bool Abarcador(istream &is, Punto p, Rectangulo &r)
{
  InicializarRectangulo(r, p, p);

  while(!is.eof() && LeerConSaltos(is, p))
      Actualiza(p, r);

  return is.eof();
}


int main(int argc, char* argv[])
{
  Punto p;
  Rectangulo r;
  bool todo_correcto = false;

  if (argc == 1)
  {
    todo_correcto = LeerConSaltos(cin, p);
    if (todo_correcto)
      todo_correcto = Abarcador(cin, p, r);
  }
  else
  {
    ifstream f(argv[1]);
    if (!f)
        return 1;

    todo_correcto = LeerConSaltos(f, p);
    if (todo_correcto)
        todo_correcto = Abarcador(f, p, r);
  }

  if (!todo_correcto)
  {
    cerr << "Error inesperado. No se ha leído toda la entrada" << endl;
    return 1;
  }

  cout << "El rectangulo que contiene todos los puntos es: ";
  Escribir(cout, r);
  cout << endl;
}
