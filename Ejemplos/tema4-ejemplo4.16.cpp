/*
 *  EJEMPLO 4.16 - cubo()
 *  Función recursiva: cálculo de cubos (alternativo)
 *
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 4 septiembre, 2018
 */

#include <iostream>

using namespace std;

int cubo( int num ) {
    int resultado;
    if ( num >= 0 )
        resultado = num*num*num;
    else
        resultado = cubo(-num);
    return resultado;
}

int main() {
    int num;
    cout << "Inserte un número: ";
    cin >> num;
    cout << num << "^3=" << cubo(num) << endl;
}
