/*
 *  EJERCICIO 2.33 - Mostrar figuras
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 9 agosto, 2018
 */

#include <iostream>
using namespace std;

int main() {
    int N; char car;
    cout << "Inserte el numero de lineas : ";
    cin >> N;
    cout << "Inserte el caracter que desee repetir : ";
    cin >> car;
    
    cout << endl;
    
    for ( int i = 1; i <= N; i++ ) {
    	for ( int j = 1; j <= i; j++ ) {
    		cout << car;
		}
		cout << endl;
	}
    
    cout << endl;
    
    for ( int i = 1; i <= N; i++ ) {
    	if ( i == 1 || i == N ) {
    		for ( int j = 1; j <= N; j++ ) {
    			cout << car;
			}
		} else {
			for ( int j = 1; j <= N; j++ ) {
				if ( j == 1 || j == N ) {
					cout << car;
				} else {
					cout << " ";
				}
			}
		}
		cout << endl;
	}
	
	cout << endl;
	
	if ( N % 2 != 0 ) {
		// parte superior del rombo y fila central
		for ( int i = 1; i <= (N-1)/2+1; i++ ) {
			for ( int j = 1; j <= N; j++ ) {
				if ( j < ((N-1)/2+2-i) || j > ((N-1)/2+i) ) {
					cout << " ";
				} else {
					cout << car;
				}
			}
			cout << endl;
		}
		// parte inferior del rombo
		for ( int i = 1; i <= (N-1)/2; i++ ) {
			for ( int j = 1; j <= N; j++ ) {
				if ( j < (i+1) || j > (N-i) ) {
					cout << " ";
				} else {
					cout << car;
				}
			}
			cout << endl;
		}
	} else {
		cout << "Solo podemos dibujar el rombo si N es impar";
	}
}
