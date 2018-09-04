/*
 *  EJEMPLO 4.8 - estaOrdenado()
 *  Función no void: comprobación de si un vector está ordenado (con error)
 *
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 3 septiembre, 2018
 */

#include <iostream>
#include <vector>

using namespace std;

bool estaOrdenado( const vector<int> & v ) {
    for ( int i = 0; i < v.size() - 1; i++ )
        if ( v[i+1] < v[i] )
            return false;
}

// estas son funciones extra (¡de regalo!) para hacer y mostrar vectores
// de hecho, aquí probamos cómo podemos hacer uso del anidamiento de funciones
void mostrarVector( const vector<int> & v ) {
    for ( int i = 0; i < v.size(); i++ )
        cout << v[i] << ' ';
    cout << endl;
}
void crearVectorPositivos( vector<int> & v ) {
    v.clear();
    cout << "Vamos a crear un vector. Inserte números enteros positivos. Inserte un número negativo para finalizar." << endl;
    int entrada = 0;
    while ( entrada > 0 ) {
        cout << "Inserte un número: ";
        cin >> entrada;
        if ( entrada > 0 ) {
            v.push_back(entrada);
            cout << "    Elemento insertado: " << entrada << endl;
        } else {
            cout << "Vector finalizado. Vector guardado: " << endl;
        }
    }
    mostrarVector();
}

int main() {
    vector<int> vect;
    crearVectorPositivos(vect);
    if ( estaOrdenado(vect) )
        cout << "¡Genial! El vector está ordenado" << endl;
    else
        cout << "Oops... parece que el vector está desordenado" << endl;
}
