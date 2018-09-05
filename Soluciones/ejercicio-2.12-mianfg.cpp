/*
 *  EJERCICIO 2.12 - Procesamiento de datos con while
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
	
	int digitos = 0;
	while (numero > 0) {
		numero /= 10;
		digitos++;
	}
	cout << "Ademas, el numero tiene " << digitos << " digitos";
}
