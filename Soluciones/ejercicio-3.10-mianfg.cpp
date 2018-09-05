/*
 *  EJERCICIO 3.10 - Parejas de producto par
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 5 septiembre, 2018
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> vec;
	int num;
	int tamano = 1;
	
	cout << "Introduzca los valores uno a uno, para parar introduzca el 0" << endl;
	cin >> num;
	vec.push_back(num);
	
	while (num !=0){
		cin >> num;
		vec.push_back(num);
		tamano++;
	}
	
	while (tamano % 2 != 0){
		cout << "El tamaño del vector tiene que ser par, siga introduciendo numeros" << endl;
		vec.pop_back();
		tamano--;
		
		cin >> num;
		vec.push_back(num);
		
		while (num !=0){
			cin >> num;
			vec.push_back(num);
			tamano++;
		}
	}
	
	
	for (int i=0 ; i < vec.size() -1 ; i++){
		// cout << vec[i];
		if ((vec[i]*vec[i+1]) % 2 == 0) {
			cout << vec[i] << " x " << vec[i+1] << " = " << vec[i]*vec[i+1] << " es multiplo de dos"; // FALTA EL CASO DE QUE NO HAYA NINGUN PRODUCTO PAR
			break;
		}
		
	}

}

