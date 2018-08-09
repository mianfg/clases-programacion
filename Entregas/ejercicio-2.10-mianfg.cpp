/*
 *  EJERCICIO 2.10 - Menú y circunferencia
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 9 agosto, 2018
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int option = 0;
	double radio = 1;
	cout << "MENU Y CIRCUNFERENCIA" << endl;
	do {
		cout << endl << "- - - - - - - - - - - - - - -" << endl << endl << "Sea el siguiente menu:" << endl
			<< "    1. Cambiar el valor del radio" << endl
			<< "    2. Mostrar el valor del radio" << endl
			<< "    3. Calcular el area del circulo" << endl
			<< "    4. Calcular el perimetro de la circunferencia" << endl
			<< "    5. Finalizar el programa" << endl
			<< "Inserte la opcion que desea: ";
		cin >> option;
		
		switch (option) {
			case 1:
				cout << endl << "Inserte el nuevo valor del radio: ";
				cin >> radio;
				cout << "Valor de radio cambiado a " << radio << endl;
				break;
			case 2:
				cout << endl << "El valor actual del radio es: " << radio << endl;
				break;
			case 3:
				cout << endl << "El area de la circunferencia es: " << M_PI * radio * radio << endl;
				break;
			case 4:
				cout << endl << "El perimetro de la circunferencia es: " << M_PI * 2 * radio;
				break;
			case 5:
				cout << endl << "El programa ha finalizado" << endl;
				break;
			default:
				cout << endl << "Ha elegido una opcion no disponible. Intentelo de nuevo" << endl;
				break;
			}
	} while ( option >= 1 && option < 5);
}
