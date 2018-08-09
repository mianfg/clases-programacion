/*
 *  EJERCICIO 2.3 - Conversión de escalas
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 9 agosto, 2018
 */

#include <iostream>
using namespace std;

int main() {
	double ctd_original; char magnitud_original, magnitud_convertida;
	double ctd_convertida;
	cout << "Inserte la magnitud que desea convertir: ";
	cin >> ctd_original >> magnitud_original >> magnitud_convertida;
	if (magnitud_original == 'C') {
		if (magnitud_convertida == 'C') {
			cout << "Quiere convertir la magnitud a ella misma";
		} else if (magnitud_convertida == 'F') {
			ctd_convertida = 9*ctd_original/5 + 32;
		} else if (magnitud_convertida == 'R') {
			ctd_convertida = 9*ctd_original/5 + 491.67;
		} else {
			cout << "Magnitud a convertir no reconocida";
		}
	} else if (magnitud_original == 'F') {
		if (magnitud_convertida == 'C') {
			ctd_convertida = 5*(ctd_original - 32)/9;
		} else if (magnitud_convertida == 'F') {
			cout << "Quiere convertir la magnitud a ella misma";
		} else if (magnitud_convertida == 'R') {
			ctd_convertida = ctd_original + 459.67;
		} else {
			cout << "Magnitud a convertir no reconocida";
		}
	} else if (magnitud_original == 'R') {
		if (magnitud_convertida == 'C') {
			ctd_convertida = 5*(ctd_original - 491.67)/9;
		} else if (magnitud_convertida == 'F') {
			ctd_convertida = ctd_original - 459.67;
		} else if (magnitud_convertida == 'R') {
			cout << "Quiere convertir la magnitud a ella misma";
		} else {
			cout << "Magnitud a convertir no reconocida";
		}
	} else {
		cout << "Magnitud inicial no reconocida";
	}
}
