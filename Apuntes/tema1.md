### Tema 2.  
# Estructuras de iteración y selección

> **Clases de programación en C++** · agosto de 2018  
> Miguel Ángel Fernández Gutiérrez ([@mianfg](https://mianfg.bloomgogo.com))

## 1. Estructuras de control de flujo

El interés del diseño de algoritmo radica en poder ejecutar instrucciones dependiendo de condiciones.

Un ejemplo de un programa que no se podría realizar con las instrucciones que conocemos: detectar si un número es par o no.

Necesitamos una forma de controlar cuándo queremos ejecutar una instrucción u otra: **control de flujo**.

En un lenguaje de programación, las **estructuras de control** permiten modificar el **flujo de ejecución** de las instrucciones de un programa. Es uno de los componentes esenciales del **paradigma de programación estructurada**.

Podemos clasificarlas en:
- **Estructuras selectivas:** ejecutan según condiciones lógicas.
- **Estructuras iterativas:** repiten un bloque según condiciones.

- - -

## 2. La estructura de selección

Las **estructuras de control de selección** ejecutan un bloque de instrucciones u otro, o saltan a un subprograma o subrutina según se cumpla o no una condición.

En C++ tenemos las siguientes:
- `if` (estructura de selección simple)
- `if ... else` (estructura de selección simple)
- `if ... else if ... else` (estructura de selección compuesta)
- `switch`/`case` (estructura de selección compuesta)




| Imagen | Función | Descripción |
| --- | --- | --- |
| ![Imagen 3.8](./resources/tema3-img8.png) | `v.push_back(x)` | Inserta al vector el elemento `x` al final de éste. Debe ser del mismo tipo que el vector. |
| ![Imagen 3.9](./resources/tema3-img9.png) | `v.pop_back()` | Elimina el último elemento del vector. |
| ![Imagen 3.10](./resources/tema3-img10.png) | `v.clear()` | Vacía el vector. |

- - -

##### ¡Ahora podemos mejorar la solución a nuestro problema!

~~~ c++
#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<double> notas;
    double entrada;

    cout << "Inserte todas las notas que quiera,
            finalice con una nota no válida: ";
    
    do {
        cin >> entrada;
        if ( entrada >= 0 && entrada <= 10 )
            notas.push_back(entrada);
    } while ( entrada >= 0 && entrada <= 10 );

    double media = 0;
    for ( int i = 0; i < notas.size(); i++ )
        media += notas[i];
    media /= notas.size();
    double moda = 0;

    int superan_media = 0;
    for ( int i = 0; i < notas.size(); i++ )
        if ( notas[i] > media )
            superan_media++;

    for ( int i = 0; i < notas.size(); i++ )
        if ( notas[i] > moda )
        moda = notas[i];

    cout << "Media: " << media << endl
         << "Superan la media: " << superan_media << endl
         << "Moda: " << moda << endl;
}
~~~

- - -

### 4.4  Otros operadores

La clase `vector` tiene definida multitud de operadores. Sin embargo, con los anteriores, podemos resolver todos los problemas que hagan falta con vectores.

En la relación de ejercicios se introducen otros operadores. La lista completa la puedes ver en la referencia de C++:

<http://www.cplusplus.com/reference/vector/vector/>
