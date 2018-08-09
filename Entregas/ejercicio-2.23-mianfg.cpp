/*
 *  EJERCICIO 2.23 - Cotización de las acciones
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 9 agosto, 2018
 */

#include <iostream>
using namespace std;

int main() {
	double max, min, bajada_max = 0, subida_max = 0;
	double diferencia;
	double entrada = 0;
	double entrada_anterior = 0;
	int contador = 0;
	while ( entrada != -1 ) {
		if ( contador > 1 ) {
			diferencia = entrada - entrada_anterior;
			if ( diferencia > 0 ) {
				if ( diferencia > subida_max ) subida_max = diferencia;
			} else if ( diferencia < 0 ) {
				if ( -1*diferencia > bajada_max ) bajada_max = -1*diferencia;
			}
		}
		entrada_anterior = entrada;
		cout << "Introduzca un valor : ";
		cin >> entrada;
		if ( entrada != -1 && entrada > max ) {
			max = entrada;
		}
		if ( entrada != -1 && entrada < min ){
			min = entrada;
		}
		if ( contador == 0 ) {
			min = entrada; max = entrada;
		}
		contador++;
	}
	
	cout << endl << "Resultados a partir de los valores obtenidos:" << endl;
	cout << " Valor maximo: " << max << endl;
	cout << " Valor minimo: " << min << endl;
	cout << " Subida maxima: " << subida_max << endl;
	cout << " Bajada maxima: " << bajada_max << endl;
}
