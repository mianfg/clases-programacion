/*
 *  EJEMPLO 1.2 - Acceso a variables
 *
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 3 septiembre, 2018
 */

#include <iostream>

using namespace std;

int main() {
    // declaración
    int valor;

    // acceso: ¿qué valor tiene?
    cout << valor << endl;

    // asignación
    valor = 7;

    // declaración con inicialización
    bool valor2 = true;

    // acceso
    cout << valor << ' ' << valor2 << '\n';
}