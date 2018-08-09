/*
 *  EJERCICIO 2.22 - Números en rango
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 9 agosto, 2018
 */

#include <iostream>
using namespace std;

int main() {
	int N;
	double min, max;
	cout << "N, min, max: ";
	cin >> N >> min >> max;
	bool en_rango = true;
	for ( int i = 1 ; i <= N && en_rango ; i++ ) {
		double entrada;
		cout << "Introduzca valor " << i << ": "; cin >> entrada;
		if ( entrada < min || entrada > max ) {
			en_rango = false;
		}
	}
	if (!en_rango) cout << "Error. Finalización inesperada del programa: Valor fuera de rango";
	else cout << "Los " << N << " valores introducidos están en el intervalo [" << min << "," << max << "]";
}
