#include <iostream>
#include "circulo.h"    // Llama a punto.h
using namespace std;

int main()
{
    cout << "Introduzca un circulo en formato radio-(x,y): ";
    Circulo circulo = LeerCirculo();

    cout << "El area del circulo es: " << Area(circulo) << endl;
}
