/*
 *  EJERCICIO 3.8 - Eliminar pares
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 5 septiembre, 2018
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	int num;	
	vector<int> vec;
	vector<int> v;

	cout << "Introduzca los valores positivos del vector, para finalizar de introducir datos introduzca un valor negativo: " << endl;
	
	do {
		cin >> num;
		vec.push_back(num);		
	}while (num >= 0);
	
	vec.pop_back();
	
	for (int i=0 ; i < vec.size() ; i++){
		if ( vec[i] % 2 != 0 ){
			//vec[i] = vec[vec.size()-1];
			//vec.pop_back();
			v.push_back(vec[i]);
		} // else cout << " pra " << vec[i] << endl; 
	}
	
	cout << "vec = ";
	for (int j=0 ; j < v.size() ; j++){
		cout << v[j] << " ";
	}

	
	
}
