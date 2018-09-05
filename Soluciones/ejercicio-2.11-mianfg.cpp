/*
 *  EJERCICIO 2.11 - Forzar la primera iteración del bucle while
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 9 agosto, 2018
 */

#include <iostream>

using namespace std;

int main() {
	int numero = 0;
	while (numero <= 0) {
		cout << "Introduzca un numero entero positivo: ";
		cin >> numero;
	}
	cout << numero << " es un numero entero positivo" << endl;
}
