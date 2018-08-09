/*
 *  EJERCICIO 2.15 - Lectura anticipada para mostrar mensajes de entrada diferentes
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 9 agosto, 2018
 */

#include <iostream>
using namespace std;

int main() {
    int entrada;
    cout << "Inserte un valor entero en el rango [0, 100] : ";
    cin >> entrada;
    while ( entrada < 0 || entrada > 100 ) {
    	cout << "Valor fuera del rango. Intentelo de nuevo : ";
    	cin >> entrada;
	}
	cout << "Valor insertado : " << entrada;
}
