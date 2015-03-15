/*
  Calcula el área de un círculo.
*/

#include <iostream>
#include "circulo.h"

using namespace std;

int main()
{
  Circulo c1;

  cout << "Introduzca un circulo en formato radio-(x,y): ";
  c1 = LeerCirculo();

  cout << "El área del círculo es: " << Area(c1);
  cout << endl;
}
