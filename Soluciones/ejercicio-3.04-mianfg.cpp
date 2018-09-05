/*
 *  EJERCICIO 3.4 - Media, desviación y varianza
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
	
	cout << "Introduce el numero de elementos del vector: ";
	cin >> num;
	cout << "Vaya introduciendo los datos uno a uno: " << endl;
	
	vector<double> vec(num);
		
	for (int i=0; i<vec.size(); i++){
		cin >> vec[i] ;
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

