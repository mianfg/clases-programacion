/*
 *  EJERCICIO 1.13
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 9 agosto, 2018
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double x, y, z, x2, y2;
	cout << "Introduzca dos valores separados con espacios del tipo x y: ";
	cin >> x >> y >> z;
	cout << "Inicialmente tenemos que: x = " << x << "; y = " << y << "; z = " << z << endl;
	x2 = x;
	y2 = y;
	x = z;
	y = x2;
	z = y2;
	cout << "Tras intercambiar los valores: x = " << x << "; y = " << y << "; z = " << z;
}
