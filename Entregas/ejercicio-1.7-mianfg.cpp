/*
 *  EJERCICIO 1.7 - Caracteres y número ASCII asociado
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 7 agosto, 2018
 */

#include <iostream>
using namespace std;

int main() {
	int x;
	cout << "Inserte un número del 0 al 25: ";
	// El 0 corresponde a 'a', el 25 a 'z'
	cin >> x;
	// Sumamos 65 porque 'A' tiene código ASCII 65
	cout << "Su mayúscula correspondiente es: " << (char)(x+65) << endl;
	// Sumamos 97 porque 'a' tiene código ASCII 97
	cout << "Su minúscula correspondiente es: " << static_cast<char>(x+97) << endl;  // lo mismo que (char)
}
