/*
 *  EJERCICIO 3.6 - Criba de Erastótenes (versión 2)
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 5 septiembre, 2018
 */

#include<iostream>
#include<vector>

using namespace std;

int main(){
	int num;
	cout << "Introduzca numero"; cin >> num;
	vector <bool> criba(num);
	vector <int> vec;
	
	for (int i = 0 ; i < criba.size() ; i++ ){
		criba[i] = true;
	}
	
	for ( int j=2 ; j < criba.size() ; j++ ){
		for (int k=2 ; j*k < criba.size() ; k++ ){
			criba[k*j] = false;
		}
	}

	for (int l=1 ; l < criba.size() ; l++){
		if (criba[l]) {
			cout << l << endl;
			vec.push_back(l);
		}
	}
	
	cout << "vec = "; 
	
	for (int k=0 ; k < vec.size() ; k++){
		cout << vec[k] << " ";
	}
	
}
