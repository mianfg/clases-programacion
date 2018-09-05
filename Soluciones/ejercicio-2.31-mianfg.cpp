/*
 *  EJERCICIO 2.31 - Número perfecto
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 9 agosto, 2018
 */

#include <iostream>
using namespace std;

int main() {
	// comprobar si es un número perfecto
	int numero_tope;
	int suma = 0;
	int mayor_perfecto = 0;
	cout << "Inserte un entero: "; cin >> numero_tope;
	for ( int numero = 1 ; numero <= numero_tope ; numero++ ) {
		suma = 0;
		for ( int i = numero; i >= 1; i-- ) {
			if ( numero % i == 0 && numero != i ) {
				// cout << "Divisor de " << numero << ": " << i << endl;
				suma += i;
			}
		}
		// cout << suma << endl;
		if ( suma == numero ) {
			// se trata de un número perfecto
			mayor_perfecto = numero;
		}
	}
	
	if ( mayor_perfecto != 0 ) {
		cout << "El mayor numero perfecto hasta " << numero_tope << " es " << mayor_perfecto;
	} else {
		cout << "No hay ningun numero perfecto menor o igual que " << numero_tope;
	}
}
