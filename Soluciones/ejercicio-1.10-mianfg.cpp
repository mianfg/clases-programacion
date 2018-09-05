/*
 *  EJERCICIO 1.10
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 9 agosto, 2018
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double x, y, z, avg, dvn;
	// Introducción de valores
	cout << "Introduzca tres valores separados con espacios: ";
	cin >> x >> y >> z;
	// Cálculo de la media, avg, y de la desviación típica, dvn
	avg = (x+y+z)/3;
	dvn = sqrt((pow(x-avg, 2)+pow(y-avg, 2)+pow(z-avg, 2))/3);
	cout << "La media de los tres valores: " << avg << endl << "Su desviacion tipica: " << dvn;
}
