/*
 *  EJERCICIO 2.13 - Lectura y procesamiento de datos con centinela
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 9 agosto, 2018
 */

#include <iostream>

using namespace std;

int main() {
	int entrada = 0, suma = 0;
	do {
		suma += entrada;
		cout << "Introduzca un numero entero positivo: ";
		cin >> entrada;
	} while ( entrada > 0 );
	cout << "La suma de todos los numeros insertados es: " << suma;
}
