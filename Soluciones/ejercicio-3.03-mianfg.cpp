/*
 *  EJERCICIO 3.3 - Acceso con corchetes
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 5 septiembre, 2018
 */

#include <iostream>
#include <vector> // Para poder usar vectores

using namespace std;

int main() {
	vector<int> v(10,1);
	cout << "El tamaño es: "<< v.size() << endl;
	for (int i=0;i<v.size();++i)
		v[i] = i;

	for (int j=0; j<v.size();j++)
		cout << v[j];
	
	cout << "Elemento en 0: " << v[0] << endl;
	cout << "Elemento en 1: " << v[1] << endl;
	cout << "Elemento en 10: " << v[10] << endl;
	cout << "Elemento en 10000000: " << v[10000000] << endl;  // error en ejecución
	cout << "Elemento en size-1: " << v[v.size()-1] << endl;

}

