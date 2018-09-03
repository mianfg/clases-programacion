/*
 *  EJEMPLO 4.10 - factorial()
 *  Documentando la función factorial()
 *
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 3 septiembre, 2018
 */

#include <iostream>

using namespace std;

/**
  * @brief Devuelve el factorial de un número
  * @param num Número del que queremos devolver su factorial
  * @return El factorial de num
  * @precond num >= 0
  */
int factorial(int num) {
    if ( num > 0 ) {
        int multiplicar_por = num - 1;
        while ( multiplicar_por > 1 ) {
            num *= multiplicar_por;
            multiplicar_por--;
        }
    } else if (num == 0)
        num = 1;  // pues factorial(0) debe ser igual a 1
    else
        num = -1;  // hemos dicho que si num es negativo, devolvemos -1
    
    return num;
}

int main() {
    int num;
    cout << "Inserte un número entero: ";
    cin >> num;
    cout << num << "!=" << factorial(num) << endl;
}