# Relación 4. Modularización I: funciones

> **Clases de programación en C++** · septiembre de 2018  
> Miguel Ángel Fernández Gutiérrez ([@mianfg](https://mianfg.bloomgogo.com))

## Ejercicios orientados

### Parametrización de las funciones. Parámetros y devolución

#### Paso por copia

---

##### Ejercicio 4.1 — Divisores propios

Implemente una función que reciba un número entero positivo y que devuelva el número de divisores propios que tiene (divisores distintos del propio número). El 1 se considera divisor propio de cualquier número mayor que 1.

###### Cabecera de la función:
~~~c++
int divisoresPropios(int  num);
~~~

Implemente a continuación una función `main()` que pida valores al usuario desde la entrada estándar y que muestre cuántos divisores propios tiene cada uno. El programa finalizará cuando el usuario dé un valor menor o igual que cero como entrada.

- - -

##### Ejercicio 4.2 ¬ Conversión a minúsculas

Implemente una función que reciba un carácter y que en caso de ser una letra devuelva su correspondiente minúscula. En otro caso devolverá el mismo carácter. No se permite el uso de funciones de biblioteca (en particular `tolower()`).

###### Cabecera de la función:
~~~c++
char toMinuscula(char letra);
~~~

Implemente una función `main()` que lea una letra desde la entrada estándar y que muestre su correspondiente minúscula.

- - -

##### Ejercicio 4.3 ¬ Máximo común divisor y mínimo común múltiplo

Implemente dos funciones: una para calcular el máximo común divisor y otra para calcular el mínimo común múltiplo de dos números enteros (positivos o negativos). Los prototipos deben ser estos:

###### Cabeceras de las funciones:
~~~c++
int mcm(int num);
int mcd(int num);
~~~

A continuación implemente un main() que pregunte dos números al usuario y que muestre el resultado de ejecutar ambas
funciones. Para calcular el máximo común se sugiere la utilización del [algoritmo de Euclides](http://es.wikipedia.org/wiki/Algoritmo_de_Euclides).

- - -

##### Ejercicio 4.4 ¬ Potencia de un número

Diseñe e implemente una función que reciba dos números enteros `a` y `b` y que devuelva la potencia _a^b_. Esta función no puede utilizar ninguna función de biblioteca (en particular `pow()`).

- - -

##### Ejercicio 4.5 ¬ Evaluación de un polinomio

Escriba un programa que lea 4 números `a`, `b`, `c` y `d` que definen el polinomio _a*x^3 + b*x^2 + c*x + d_, que lo evalúe en un punto y que muestre ese valor. Para ello, defina la función `evaluar()` que recibe los cuatro valores junto con un valor `x` donde evaluarlo, y que devuelve un número resultado de la evaluación.

Para resolverlo, por un lado deberá reutilizar la función del [ejercicio 4.4](#here), y por otro, evitar declarar ninguna variable local en la función `evaluar()`.

###### Cabecera de la función:
~~~c++
double evaluar(double a, double b, double c, double d, double x);
~~~

- - -

#### Funciones tipo `void`

- - -

##### Ejercicio 4.6 ¬ Tabla de multiplicar

Implemente una función que muestre por pantalla la tabla de multiplicar del número pasado.

###### Cabecera de la función:
~~~c++
void mostrarTablaMultiplicar(int num);
~~~

Implemente también en la función `main()` las líneas de código necesarias para pedir por pantalla a un número y luego mostrarlo por pantalla haciendo uso de la función `mostrarTablaMultiplicar()`.

- - -

#### Paso por referencia

- - -

##### Ejercicio 4.7 ¬ Intercambio de valores

Escriba una función `intercambiar()` para intercambiar el valor de dos variables de tipo `double`. Es decir, en la llamada se pasarán dos variables y, al finalizar, los valores de ambas estarán intercambiados. Implemente también un `main()` para probar la función.

###### Cabecera de la función:
~~~c++
void intercambiar(double & x, double & y);
~~~

- - -

##### Ejercicio 4.8 ¬ Ordenar dos valores

Escriba una función `ordenar2()` para ordenar los valores de dos variables de tipo `double`. Es decir, en la llamada se pasarán dos variables y, al finalizar, la primera variable tendrá el menor y la segunda el mayor de los valores.

Para resolverlo, use la función `intercambiar()` del [ejercicio 4.7](#here).

Como puede comprobar en la solución del ejercicio, desde la función `ordenar2()` pasamos dos variables a la función `intercambiar()`. Realmente, estos dos objetos no están creados ahí, sino que son dos objetos que se han pasado, a su vez, desde otra función. Dicho de otra forma, son dos referencias a dos objetos que, declarados fuera de `ordenar2()`, se pasan a la función de intercambio.

- - -

##### Ejercicio 4.9 ¬ Ordenar tres valores

Escriba una función `ordenar3()` para ordenar los valores de tres variables de tipo `double`. Es decir, en la llamada se pasarán tres variables y, después de ella, la primera variable tendrá el menor, la segunda el mediano y la tercera el mayor de los valores.

###### Idea para resolver este ejercicio

> **Intenta pensar el problema primero** antes de leer lo de abajo. ¡Seguro que tú llegas a la solución!

Este problema puede resolverse haciendo uso de la función `ordenar2()` del [ejercicio 4.8](#here), teniendo en cuenta que, para ordenar tres valores, basta ordenar los dos primeros, luego los dos últimos y de nuevo los dos primeros.

- - -

### Diseño de funciones

#### Separación entre E/S y los cálculos

- - -

##### Ejercicio 4.10 ¬ Fecha con formato

Construya un programa que lea una fecha desde la entrada estándar (día, mes y
año), y que la muestre en la salida estándar con un formato que indique el día de la semana y el nombre del mes. También
se indicará si el año es bisiesto o no. A continuación se muestran un par de ejecuciones de ejemplo:

~~~
Introduzca una fecha (día, mes, año): 21 2 2011
La fecha es: lunes, 21 de febrero de 2011
~~~
~~~
Introduzca una fecha (día, mes, año): 13 8 2004
La fecha es: viernes, 13 de agosto de 2004 (bisiesto)
~~~

Los cálculos de este programa se modularizarán implementando las siguientes funciones:

* Función que reciba como entrada un año y que devuelva un booleano indicando si dicho año es o no bisiesto. Un año es bisiesto si verifica que es divisible por 4 y no por 100, excepto los divisibles por 400 que sí lo son.
* Función que reciba como entrada una fecha (día, mes y año) y que devuelva el día juliano astronómico con el que se corresponde. Use para ello la [siguiente expresión](http://www.hermetic.ch/cal_stud/jdn.htm):
    * _Día juliano_ = ( 1461 * ( _año_ + 4800 + ( _mes_ – 14 ) / 12 ) ) / 4 +  
( 367 * ( _mes_ – 2 – 12 * ( ( _mes_ – 14 ) / 12 ) ) ) / 12 -  
( 3 * ( ( _año_ + 4900 + ( _mes_ – 14 ) / 12 ) / 100 ) ) / 4 +  
_día_ – 32075
* Una función que reciba una fecha (día, mes y año) y que devuelva una letra que codifique el día de la semana (`L`=lunes, `M`=martes, `X`=miércoles, `J`=jueves, `V`=viernes, `S`=sábado, `D`=domingo). El día de la semana se calcula dividiendo el día juliano entre 7 y quedándose con el resto (operación módulo). Si el resto vale 0, el día es lunes, si vale 1 martes, y así sucesivamente hasta el 6 que se corresponde con el domingo.
* Una función que reciba una fecha (día, mes y año) y que devuelva un booleano indicando si se trata o no de una fecha válida.

La E/S de este programa será tarea exclusiva de la función `main()` junto con las dos funciones que se piden a continuación. Ninguna otra función puede leer o escribir datos en la E/S estándar.
* Función que recibe como entrada una fecha y que la escribe con el formato expresado.
* Función que lee una fecha desde la entrada estándar y que la devuelve mediante parámetros por referencia. Esta función deberá garantizar que la fecha leída es válida.

El programa comenzará pidiendo una fecha al usuario y a continuación la mostrará con el formato especificado. Puesto que el usuario puede escribir fechas sin sentido, se deberán validar los datos de entrada. En caso de que el usuario escriba una fecha incorrecta, deberá pedirla de nuevo.

Observe que ahora la función `main()` se dedica casi en exclusiva a llamar a otras funciones: una para leer la fecha con un formato y otra para escribirlo en el formato pedido.

- - -

