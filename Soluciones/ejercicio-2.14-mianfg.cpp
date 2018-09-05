/*
 *  EJERCICIO 2.14 - Lectura anticipada con while
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 9 agosto, 2018
 */

#include <iostream>

using namespace std;

int main() {
	int entrada = 1, suma = 0;
	while ( entrada > 0 ) {
		cout << "Introduzca un numero entero positivo: ";
		cin >> entrada;
		suma += entrada;
	}
	cout << "La suma de todos los numeros insertados es: " << suma;
}
