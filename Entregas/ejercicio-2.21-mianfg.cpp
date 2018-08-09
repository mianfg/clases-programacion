/*
 *  EJERCICIO 2.21 - Media de medias
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 9 agosto, 2018
 */

#include <iostream>

using namespace std;

int main() {
	int ciudades;
	double num;
	double acumulado=0;
	double media;
	int contador=0;
	double max=0;
	int ciudadmax;
	
	cout << "Introduzca el numero de ciudades que va a introducir:";
	cin >> ciudades;
	
	cout << "Vaya introduciendo los valores uno a uno, y para terminar cada ciudad introduzca -100" << endl;
	
	for (int i=1; i<=ciudades ; i++){
		// cout << "Ciudad " << i << endl; 
		do {
			cin >> num;
			acumulado=acumulado+num;
			contador++;
		} while (num != -100);
		media=(acumulado+100)/(contador-1);
		// cout << "Media: " << media << endl;
		if (max<media){
			max=media;
			ciudadmax=i;
		}
		media=0;
		acumulado=0	;
		contador=0;
	}
	cout << "La media maxima es: " << max << "2 de la ciudad: " << ciudadmax;	
}

