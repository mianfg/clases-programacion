/*
 *  EJEMPLO 4.3 - esPar()
 *  Función void: comprobación de si un número es par o impar por salida estándar
 *
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 3 septiembre, 2018
 */

#include <iostream>

using namespace std;

void esPar( const int num ) {
    if ( num % 2 == 0 )
        cout << num << " es par" << endl;
    else
        cout << num << " es impar" << endl;
}

int main() {
    cout << "Inserte un número positivo, y le diremos si es par o no.\nInserte un número negativo para terminar" << endl;
    int entrada = 0;
    while ( entrada > 0 ) {
        cout << "Inserte el número: ";
        cin >> entrada;
        if ( entrada > 0 )
            esPar(entrada);
    }
}