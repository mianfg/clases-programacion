/*
 *  EJEMPLO 4.11 - volumenCaja()
 *  Función con parámetros con valor por defecto: volumen de una caja
 *
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 3 septiembre, 2018
 */

#include <iostream>

using namespace std;

double volumenCaja(double largo=1.0, double ancho=1.0, double alto=1.0) {
    return largo*ancho*alto;
}

int main() {
    cout << "Volumen por defecto: " << volumenCaja() << endl;   // caja 1x1x1
    cout << "Volumen caja 10x1x1: " << volumenCaja(10) << endl;
    cout << "Volumen caja 10x5x1: " << volumenCaja(10, 5) << endl;
    cout << "Volumen caja 10x5x2: " << volumenCaja(10, 5, 2) << endl;
}
