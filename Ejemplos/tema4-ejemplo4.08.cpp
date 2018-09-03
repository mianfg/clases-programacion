/*
 *  EJEMPLO 4.8 - Sobrecarga de funciones
 *
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 3 septiembre, 2018
 */

#include <iostream>

using namespace std;

// vamos a insertar en las funciones mensajes por salida estándar para
// poder distinguir en cada caso qué función usaría C++
void funcion(double x) {
    cout << "Hemos usado funcion(double x) (función no. 1)" << endl;
}
void funcion(char x) {
    cout << "Hemos usado funcion(char x) (función no. 2)" << endl;
}
void funcion(int x, double y) {
    cout << "Hemos usado funcion(int x, double y) (función no. 3)" << endl;
}

int main() {
    funcion(3.4);       // función no. 1
    funcion(7);         // función no. 1 con conversión implícita de int a double
    funcion('a');       // función no. 2
    funcion(4, 9.2);    // función no. 3
    funcion(4, 9);      // función no. 3 con conversión implícita de int a double (en el segundo parámetro)
}