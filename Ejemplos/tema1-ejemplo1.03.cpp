/*
 *  EJEMPLO 1.3 - Entrada/salida estándar con iostream
 *
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 3 septiembre, 2018
 */

#include <iostream>

using namespace std;

int main() {
    /* Variación del programa anterior:
       vamos a pedir el valor por pantalla */

    // declaración
    int valor;

    // mensaje: operador de salida
    cout << "Inserte un valor decimal: ";

    // operador de entrada
    cin >> valor;

    // mostrar valor: operador de salida
    cout << "valor" << '=' << valor << endl;
}