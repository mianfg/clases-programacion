/*
 *  EJERCICIO 2.4 - Pascua
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 9 agosto, 2018
 */

#include <iostream>

using namespace std;

int main() {
	int year;
	
	cout << "Inserte el año: ";
	cin >> year;
	
	int a = year % 19;
	int b = year % 4;
	int c = year % 7;
	int d = (19 * a + 24) % 30;
	int e = (2 * b + 4 * c + 6 * d + 5) % 7;
	int n = 22 + d + e;
	
	if (n <= 31) {
		cout << "Pascua caera el " << n << " de marzo";
	} else {
		n -= 31;
		if (n == 26) {
			n = 19;
		} else if (n == 25 && d == 28 && e == 6 && a > 10) {
			n = 18;
		}
		cout << "Pascua caera el " << n << " de abril";
	}
}
