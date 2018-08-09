/*
 *  EJERCICIO 2.16 - Lectura anticipada con centinela
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 9 agosto, 2018
 */

#include <iostream>
using namespace std;

int main() {
	int entrada;
	int positivo = 0, negativo = 0;
	
	do {
		cout << "Inserte un valor entero positivo o negativo : ";
		cin >> entrada;
		if ( entrada > 0 ) {
			positivo += 1;
		} else if ( entrada < 0 ) {
			negativo += 1;
		}
	} while ( entrada != 0 );
	cout << "Ha insertado " << positivo << " numeros positivos y " << negativo << " numeros negativos";
}
