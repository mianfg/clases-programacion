### Relación 3.  
# Vectores y matrices

> **Clases de programación en C++** · agosto de 2018  
> Miguel Ángel Fernández Gutiérrez ([@mianfg](https://mianfg.bloomgogo.com))

## Ejercicios orientados

### Operaciones con vectores

Para realizar estos ejercicios basta con saber usar las operaciones básicas con vectores (apartado 2 de las transparencias y las funciones `size()` y `at()`).

---

##### Ejercicio 3.1 — Mostrar elementos de un vector

> 🌟 Este es un ejercicio **muy recomendado**.  

Tengamos el siguiente programa, que muestra la funcionalidad básica de un objeto tipo `vector`:

~~~c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v(10,1);

    // Mostramos el tamaño del vector
    cout << "El tamaño del vector es: " << v.size() << endl;

    // Asignamos valores a las celdas del vector
    for ( int i = 0; i < v.size(); i++ )
        v.at(i) = i;
}
~~~

Complételo añadiendo al final un bucle que muestre en la salida estándar todos los elementos del vector.

---

Es muy importante tener en cuenta que la operación `at()` no se puede aplicar con un índice que esté fuera del rango válido. Por ejemplo, si un vector tiene 10 elementos, no podemos acceder al elemento 20.

- - -

##### Ejercicio 3.2 — Acceso a los elementos

> 🌟 Este es un ejercicio **muy recomendado**.

Considere el programa del [ejercicio anterior](#ejercicio-31--mostrar-elementos-de-un-vector) y añada las siguientes líneas para ver tres elementos concretos:

~~~c++
cout << "Elemento en 0: " << v.at(0) << endl;
cout << "Elemento en 1: " << v.at(1) << endl;
cout << "Elemento en 10: " << v.at(10) << endl;
cout << "Elemento en 10000000: " << v.at(10000000) << endl;
cout << "Elemento en size−1: " << v.at(v.size()−1) << endl;
~~~

Antes de ejecutar este código piense qué valores son los que se mostrarían. A continuación ejecútelo y verifique sus suposiciones.

- - -

Además de la operación `at()`, podemos usar los corchetes para poder referirnos a un elemento de un vector. En lugar de escribir `v.at(i)`, usamos la sintaxis `v[i]`. La diferencia fundamental está en que:

* En la operación `at()` se comprueba que el índice está en el rango correcto. Si no lo está, directamente obtenemos un resultado como el que ha visto en el [ejercicio 3.2](#ejercicio-32--acceso-a-los-elementos).
* En la operación `[]` no se hacen comprobaciones. Por tanto, se intenta realizar la operación aunque estemos en un índice
incorrecto. Esto hace que sea muy peligroso, pues accedemos a posiciones de memoria incorrectas, aunque permite que el código no pierda tiempo en las comprobaciones si estamos seguros de que son correctas.

En la práctica, la sintaxis de corchetes es más simple y más eficiente, y además, es la misma que se usa para los vectores en C,
por lo que es la más habitual. Por supuesto, su uso obliga a tener mucho cuidado, pues tenemos que garantizar que no nos salimos del rango válido.

- - -

##### Ejercicio 3.3 — Acceso con corchetes

> 🌟 Este es un ejercicio **muy recomendado**.  

Considere el [ejercicio 3.2](#ejercicio-32--acceso-a-los-elementos) y cambie el operador `at()` por el operador `[]`. Es decir, añada estas líneas:

~~~c++
cout << "Elemento en 0: " << v[0] << endl;
cout << "Elemento en 1: " << v[1] << endl;
cout << "Elemento en 10: " << v[10] << endl;
cout << "Elemento en 10000000: " << v[10000000] << endl;
cout << "Elemento en size−1: " << v[v.size()−1] << endl;
~~~

¿Qué diferencias observa en la ejecución con respecto a la versión que usa `at()`?

- - -

##### Ejercicio 3.4 — Media, desviación y varianza

> ⭐ Este es un ejercicio recomendado.  

Escriba un programa que lea un número entero que indica el número de datos a analizar y a continuación tantos números reales como indique dicho entero. Como resultado, escribirá la media, la desviación media y la varianza de dichos datos (véase la relación de problemas del tema anterior [aquí](#here)).

Para ello, pida un número entero positivo, declare un vector con dicho tamaño, y luego lea todos los elementos en el vector antes de realizar los cálculos.

- - -

##### Ejercicio 3.5 — Criba de Eratóstenes

> ⭐ Este es un ejercicio recomendado.  
> 🤔 Este ejercicio es de dificultad **alta**.

Escriba un programa que calcule todos los números primos menores que un número `N` dado (este número será leído desde la entrada estándar). Para ello, use la [**criba de Eratóstenes**](http://es.wikipedia.org/wiki/Criba_de_Eratóstenes).

La idea de este algoritmo consiste en escribir todos los números hasta el n, y recorrerlos de uno en uno. Si un número no se ha tachado, se tacharán todos sus múltiplos. Cuando hemos recorrido todos los números, aquellos no tachados son los números primos.

Para resolverlo puede optar por dos opciones:

1. Declarar un vector de booleanos de tamaño `N`. En dicho vector, el valor de una posición `i` (`true` o `false`) indicará si el valor `i` de la serie de números está o no tachado.

2. En lugar de un vector de booleanos se puede crear un vector de enteros inicializado con los números del `2` en adelante. En dicho vector se tacharán los números cambiándolos por un valor especial (por ejemplo `-1`).

Como resultado, el programa escribirá todos los primos resultantes.

- - -

##### Ejercicio 3.6 — Criba de Eratóstenes (versión 2)

> 🤔 Este ejercicio es de dificultad **alta**.

Modifique el [ejercicio 3.5](#ejercicio-35--criba-de-eratóstenes) para que, como resultado del algoritmo de la criba, tengamos un vector sólo con los números primos y sin los números tachados.

- - -

### Vectores de tamaño variable

Para resolver estos ejercicios, debe saber utilizar las funciones de modificación de tamaño de la clase `vector` (`push_back()`, `pop_back()` y `clear()`).

- - -

##### Ejercicio 3.7 — Media, desviación y varianza de números positivos

> 🌟 Este es un ejercicio **muy recomendado**.  

Escriba un programa similar al del [ejercicio 3.4](#ejercicio-34--media-desviación-y-varianza), pero teniendo en cuenta que los valores que se analizarán serán no negativos. La entrada de datos se realizará leyendo valores hasta que se lea un valor negativo. En ese momento, se obtendrán en la salida estándar los valores de la media, desviación y varianza de los datos introducidos.

- - -

##### Ejercicio 3.8 — Eliminar pares

> ⭐ Este es un ejercicio recomendado.  

Escriba un programa que lea números positivos y los almacene en un vector (la lectura será similar a la que ha hecho en el [ejercicio 3.7](#ejercicio-37--media-desviación-y-varianza-de-números-positivos)). A continuación, el programa eliminará del vector todos los números que sean pares. Para ello, deberá recorrer el vector y cada vez que encuentre un número par, lo intercambiará con el último y a continuación lo eliminará con la operación `pop_back()`. Observe que el vector resultante no mantiene el orden original de los elementos impares.

- - -

### Vectores y lectura adelantada

En la relación anterior se estudió un esquema de procesamiento de datos denominado **lectura adelantada** que se usaba
cuando había que procesar series de datos leídas desde la entrada estándar hasta que se cumpliese una determinada condición.

Este esquema también se usa con cierta frecuencia al tratar datos almacenados en vectores. La idea es la misma con la diferencia de que ahora los datos se van cogiendo del vector en lugar de cogerlos desde la entrada estándar.

- - -

##### Ejercicio 3.9 — Media, desviación y varianza de números positivos con lectura adelantada

Revise el [ejercicio 3.7](#ejercicio-37--media-desviación-y-varianza-de-números-positivos) y asegúrese de que en la lectura de datos está utilizando un esquema de lectura adelantada. Con este esquema únicamente debería hacer inserciones con `push_back()` y no debería hacer ningún borrado con `pop_back()`.

- - -

##### Ejercicio 3.10 — Parejas de producto par

Haga un programa que lea una serie de números enteros –positivos y negativos– desde la entrada estándar hasta que el usuario introduzca un valor cero. El número total de números introducidos ha de ser par y al menos debería haber dos números. Si cuando el usuario introduce un cero el número total de números fuese impar, se descartaría el cero y se seguirían leyendo datos. La serie de datos se almacenará en un vector que incluirá como último dato el valor cero.

A continuación deberá recorrer el vector e indicar si existe al menos una pareja de números enteros consecutivos cuyo producto sea par. Observe que este bucle deberá detenerse en el momento en que encuentre una pareja que cumpla la condición o bien cuando se llegue al final del vector. Para ello se recomienda el uso de un bucle de tipo `while`.

El cero no se considera para los cálculos. Las parejas que deben considerarse son las de las posiciones 0-1, 1-2, 2-3, ...

- - -

### Vectores de vectores

- - -

##### Ejercicio 3.11 — Control de ventas

Una empresa de ventas recibe una secuencia de enteros para controlar el número de ventas de cada uno de sus vendedores. Las ventas de un vendedor consisten en una secuencia de números enteros no negativos terminada con un valor `-1` que indica final de secuencia. El conjunto de ventas total se compone de una secuencia de ventas de vendedores terminada con un número `-2` para indicar final de vendedores. Por ejemplo, en la siguiente secuencia se muestran las ventas de 4 vendedores:

~~~
3 5 0 2 -1 4 11 2 -1 7 1 -1 8 9 5 10 2 -1 -2
~~~

donde vemos que han vendido `10`, `17`, `8` y `34` unidades cada uno.

Escriba un programa que lea una secuencia como la anterior, calcule el número de ventas de cada vendedor, y escriba
el número de vendedor con mayores ventas así como su secuencia correspondiente.

Observe que en este ejercicio hay que implementar dos esquemas de lectura adelantada anidados. Se necesita hacer
una lectura adelantada de “secuencias” acabadas con el valor especial `-2`. Cada una de estas “secuencias” es, a su vez, un esquema de lectura anticipada de series de datos acabadas en el valor especial `-1`.

- - -

### Matrices

- - -

##### Ejercicio 3.12 — Traza de una matriz

Implemente un programa que lea una matriz cuadrada desde la entrada estándar de tamaño arbitrario y que calcule y muestre su traza.

- - -

##### Ejercicio 3.13 — Suma de matrices

Implemente un programa que lea dos matrices rectangulares de igual tamaño y que calcule y muestre su suma (elemento a elemento).

- - -

##### Ejercicio 3.14 — Máximos de cada fila

Implemente un programa que lea los datos de una matriz de tamaño arbitrario (también leído desde la entrada estándar). El programa calculará y mostrará el elemento mayor de cada fila.

- - -

### Ordenación y búsqueda

Los algoritmos de ordenación y búsqueda son fundamentales. En principio, es interesante practicar con ellos intentado no copiar anteriores implementaciones, sino reescribiéndolas sabiendo cómo funcionan.

- - -

##### Ejercicio 3.15 — Frecuencias de los datos

Escriba un programa para obtener la frecuencia de los datos de entrada.

El programa recibe un entero que indica el número de datos, seguido de los datos. La salida será el conjunto de datos
introducidos junto con su frecuencia. Un ejemplo de ejecución podría ser este:

~~~
¿Cuántos datos hay? 14
Introduzca datos: 1 5 5 17 4 1 2 17 1 5 4 5 2 1
Resultado:
1 : 4 veces
2 : 2 veces
4 : 2 veces
5 : 4 veces
17 : 2 veces
~~~

Para resolverlo se recomienda:
* Ordenar los datos introducidos.
* A partir del vector de datos ordenados, obtener dos nuevos vectores, uno con los datos sin repetir y otro con las
frecuencias.

- - -

Los algoritmos de ordenación son básicos para resolver otros problemas. Por ejemplo, se puede obtener la mediana de un
conjunto de valores si ordenamos los datos y seleccionamos el valor central.

- - -

##### Ejercicio 3.16 — Mediana

Escriba un programa que reciba un entero indicando el número de datos que se van a introducir, seguido de tantos datos como indique dicho número, y obtenga como salida la mediana de los datos.

La mediana es el valor que deja por debajo a la mitad de los datos y por encima a la otra mitad. Si el número de datos
es impar, la mediana corresponde al valor central, y si es par, se puede obtener como la media de los dos centrales.

- - -

##### Ejercicio 3.17 — Mezcla de vectores ordenados

Escriba un programa que recibe dos secuencias de elementos ordenadas y escribe el resultado como una secuencia mezcla de las dos anteriores. Cada secuencia se introduce como un entero que indica el número de elementos seguido de dichos elementos.

El programa debe asegurar que si cualquiera de las secuencias no está ordenada, se ordena antes de la mezcla.

- - -

El algoritmo de búsqueda binaria es especialmente potente gracias a la eficiencia cuando el número de elementos es
muy alto. Así, si disponemos de un conjunto de datos ordenado, resulta especialmente recomendable que optemos por este
algoritmo. Incluso si no estuvieran ordenados, pero vamos a realizar múltiples búsquedas, podría ser recomendable que
dediquemos un coste a la ordenación para hacer que las siguientes búsquedas sean muy rápidas.

- - -

##### Ejercicio 3.18 — Frecuencias de los datos (2)

Considere el programa del [ejercicio 3.15](#), donde se calculan las frecuencias asociadas a una serie de datos. Se desea mejorar el programa para los casos en los que existen pocos datos y altas frecuencias. Para ello, se propone que no se ordenen los datos de entrada, sino que se creen los dos vectores solución (datos y frecuencias) y se vayan modificando con cada uno de los datos de entrada. El algoritmo, básicamente, consiste en coger un nuevo dato y, si ya se ha obtenido previamente, incrementar su frecuencia, y si no, insertarlo en la solución con frecuencia uno.

- - -

## Relación de ejercicios

- - -

##### Ejercicio 3.19 — Letras más usadas

Se desea realizar un programa para calcular la frecuencia de las letras en un documento. Para ello, se analizarán las apariciones de cada una de las letras de la parte básica de la tabla ASCII (los caracteres del cero al 127).

Escriba un programa que lea los caracteres de un texto hasta encontrar el carácter `#`. Para cada uno de los caracteres
leídos, calculará la frecuencia de aparición. Como resultado, escribirá en la salida estándar cada uno de los pares
carácter/frecuencia de mayor a menor frecuencia. Sólo se imprimirán los caracteres que hayan aparecido, al menos, una
vez.

- - -

##### Ejercicio 3.20 — Descomposición en números primos

Escriba un programa que lea un número positivo y escriba su descomposición en números primos. El programa almacenará la descomposición en un vector.

- - -

##### Ejercicio 3.21 — Columnas únicas

Escriba un programa que lea una matriz bidimensional desde la entrada estándar y que indique cuántas de sus columnas son únicas. Una columna se considera única si no se repite, es decir, si no hay otra igual a ella.

- - -

##### Ejercicio 3.22 — Traspuesta de una matriz

Implemente un programa que lea una matriz por la entrada estándar y que calcule y muestre su correspondiente traspuesta.

- - -

##### Ejercicio 3.23 — Punto de silla

Implemente un programa que lea los datos de una matriz de tamaño arbitrario (también leído desde la entrada estándar). El programa nos dirá si existe o no algún elemento que sea a la vez máximo de su fila y mínimo de su columna.

- - -

##### Ejercicio 3.24 — Transformaciones de una matriz

Implemente un programa que lea una matriz cuadrada y que, a elección del usuario, permita realizar:

* Una rotación de 90 grados a la derecha.
* Una rotación de 90 grados a la izquierda.
* Una rotación de 180 grados.
* Una simetría respecto al eje central vertical.
* Una simetría respecto al eje central horizontal.

- - -
