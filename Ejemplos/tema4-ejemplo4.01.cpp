/*
 *  EJEMPLO 4.1 - diasHasta()
 *  Declaración y llamada a una función: días desde fecha hasta hoy
 *
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 3 septiembre, 2018
 */

#include <iostream>

using namespace std;

int diasHasta(int dia, int mes, int anio) {
    // ¡intenta implementar tú esta función!
    return 7; // siempre devolverá esto, es simplemente para usarlo como ejemplo
}

int main() {
    int dia, mes, anio;
    cout << "Inserte fecha: ";
    cin >> dia >> mes >> anio;
    cout << "Días desde esa fecha hasta hoy: " << diasHasta(dia, mes, anio) << endl;
}