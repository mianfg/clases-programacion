/*
 *  EJERCICIO 3.7 - Media, desviación y varianza de números positivos
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 5 septiembre, 2018
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	int num;
	double suma = 0, suma2 = 0, suma3 = 0;
	double media = 0, desviacion, varianza;
	
	int i = 0; 
	vector<double> vec;

	cout << "Introduzca los valores positivos del vector, para finalizar de introducir datos introduzca un valor negativo: " << endl;
	
	do {
		cin >> num;
		vec.push_back(num);		
	}while (num >= 0);
	
	vec.pop_back();	// Para eliminar el ultimo elemento que es negativo
		
	for (int i=0; i<vec.size(); i++){
		cout << vec[i] ;
		suma += vec[i];
	} 
	
	for (int k=0; k<vec.size(); k++){
		suma2 += (vec.at(k)-media);
		suma3 += (suma2*suma2);
	}
	
	media = suma / vec.size();
	cout << "La media es: " << media << endl;

	desviacion = suma2 / vec.size();
	cout << "La desviacion es: " << desviacion << endl;
	
	varianza = suma3 / vec.size();
	cout << "La varianza es: " << varianza << endl;
	
}

