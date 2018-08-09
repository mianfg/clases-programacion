/*
 *  EJERCICIO 2.1 - Cálculo del sueldo
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 9 agosto, 2018
 */

#include <iostream>

using namespace std;

int main() {
	double bruto, neto;
	char tipo_trabajador;
	cout << "Inserte su sueldo bruto: ";
	cin >> bruto;
	do {
		cout << "¿Qué tipo de trabajador es? (F=fijo, T=temporal): ";
		cin >> tipo_trabajador;
	} while (!(tipo_trabajador == 'T' || tipo_trabajador == 'F'));
	
	if ( tipo_trabajador == 'F' )
		bruto += 200;
	
	neto = bruto;
	
	if ( neto > 1200 )
		neto *= 0.8;
	else
		neto *= 0.83;
	
	cout << "El sueldo bruto es: " << bruto << endl;
	cout << "El sueldo neto es: " << neto << endl;
}
