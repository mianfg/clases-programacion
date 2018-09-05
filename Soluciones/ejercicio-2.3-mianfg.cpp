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
	bool mostrar = true;
	cout << "Inserte la magnitud que desea convertir: ";
	cin >> ctd_original >> magnitud_original >> magnitud_convertida;
	if (magnitud_original == 'C') {
		if (magnitud_convertida == 'C') {
			cout << "Quiere convertir la magnitud a ella misma";
			mostrar = false;
		} else if (magnitud_convertida == 'F') {
			ctd_convertida = 9*ctd_original/5 + 32;
		} else if (magnitud_convertida == 'R') {
			ctd_convertida = 9*ctd_original/5 + 491.67;
		} else if (magnitud_convertida == 'K') {
			ctd_convertida = ctd_original = 273.15;			
		} else {
			cout << "Magnitud a convertir no reconocida";
			mostrar = false;
		}
	} else if (magnitud_original == 'F') {
		if (magnitud_convertida == 'C') {
			ctd_convertida = 5*(ctd_original - 32)/9;
		} else if (magnitud_convertida == 'F') {
			cout << "Quiere convertir la magnitud a ella misma";
			mostar = false;
		} else if (magnitud_convertida == 'R') {
			ctd_convertida = ctd_original + 459.67;
		} else if (magnitud_convertida == 'K') {
			ctd_convertida = 5*(ctd_original - 32)/9 + 273.15;
		} else {
			cout << "Magnitud a convertir no reconocida";
			mostrar = false;
		}
	} else if (magnitud_original == 'R') {
		if (magnitud_convertida == 'C') {
			ctd_convertida = 5*(ctd_original - 491.67)/9;
		} else if (magnitud_convertida == 'F') {
			ctd_convertida = ctd_original - 459.67;
		} else if (magnitud_convertida == 'R') {
			cout << "Quiere convertir la magnitud a ella misma";
			mostrar = false;
		} else if (magnitud_convertida == 'K') {
			cout << 5*(ctd_original-459.67-32)/9+273.15;
		} else {
			cout << "Magnitud a convertir no reconocida";
			mostrar = false;
		}
	} else if (magnitud_original == 'K') {
		if (magnitud_convertida == 'C') {
			ctd_convertida = ctd_original - 273.15;
		} else if (magnitud_convertida == 'F') {
			ctd_convertida = 9*(ctd_original - 273.15)/5;
		} else if (magnitud_convertida == 'R') {
			ctd_convertida = 9*(ctd_original - 273.15)/5 + 459.67 + 32;
		} else if (magnitud_convertida == 'K') {
			cout << "Quiere convertir la magnitud a ella misma";
			mostrar = false;
		} else {
			cout << "Magnitud a convertir no reconocida";
			mostrar = false;
		}
	} else {
		cout << "Magnitud inicial no reconocida";
		mostrar = false;
	}
	
	if (mostrar)
		cout << ctd_original << magnitud_original << " = " << ctd_convertida << magnitud_convertida << endl;
}
