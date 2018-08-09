/*
 *  EJERCICIO 2.9 - Lectura con do-while
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 9 agosto, 2018
 */

#include <iostream>

using namespace std;

int main() {
	int numero;
	do {
		cout << "Introduzca un numero entero positivo: ";
		cin >> numero;
	} while ( numero < 0 );
		cout << numero << " es un numero entero positivo" << endl;
}
