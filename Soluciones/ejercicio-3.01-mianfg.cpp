/*
 *  EJERCICIO 3.1 - Mostrar elementos de un vector
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 5 sptiembre, 2018
 */

#include <iostream>
#include <vector> // Para poder usar vectores

using namespace std;

int main() {
	vector<int> v(10,1);
	cout << "El tamaño es: "<< v.size() << endl;
	for (int i=0;i<v.size();++i)
		v.at(i) = i;
	//	cin >> v.at(i); // si quisiera introducir los valores que yo quisiera

	for (int j=0; j<v.size();j++)
		cout << v.at(j);
	
	cout << "Elemento en 0: " << v.at(0) << endl;
	cout << "Elemento en 1: " << v.at(1) << endl;
	// cout << "Elemento en 10: " << v.at(10) << endl;
	// cout << "Elemento en 10000000: " << v.at(10000000) << endl;
	cout << "Elemento en size-1: " << v.at(v.size()-1) << endl;

}

