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

### Funciones con vectores

- - -

##### Ejercicio 4.11 ¬ Media, desviación y varianza de un vector de números

Modifique el programa del [ejercicio X](#here) de forma que modularice el código mediante las siguientes funciones:

* Leer los datos. No recibe ningún parámetro y devuelve un vector con los datos leídos desde la entrada estándar. Los datos son una secuencia de números que termina en un número negativo que actúa como centinela.
* Calcular la media. Recibe un vector de números reales y devuelve la media de dichos valores.
* Calcular la desviación. Recibe un vector de datos y un valor (por ejemplo, la media) y devuelve la desviación media de los datos a dicho valor.
* Calcular la varianza. Recibe un vector de datos y devuelve la varianza.

- - -

##### Ejercicio 4.12 ¬ Matrices de Vandermonde

Una matriz de Vandermonde cuadrada de tamaño _n_ es una matriz que tiene la siguiente forma:

~~~
1  x_1  x_1^2  x_1^3  ···  x_1^(n-1)
1  x_2  x_2^2  x_2^3  ···  x_2^(n-1)
···
1  x_n  x_n^2  x_n^3  ···  x_n^(n-1)
~~~

Haga un programa que lea desde la entrada estándar un valor `n`, y una serie de valores enteros `x_1`, `x_2`, ..., `x_n` y que genere la correspondiente matriz de Vandermonde. Debe incluir, al menos, las siguientes funciones:

* Función que lee un vector de enteros desde la entrada estándar. Esta función será de tipo `void` y devolverá el vector mediante un paso por referencia.
* Función que recibe un vector de enteros y que devuelve la matriz de Vandermonde asociada. Esta función será de tipo `void` y devolverá la matriz mediante un paso por referencia.
* Función que presente adecuadamente una matriz de enteros en la salida estándar.

- - -

##### Ejercicio 4.13 ¬ Factorización de un número

Implemente un programa que lea una serie de números enteros desde la entrada estándar y que muestre al usuario su factorización. El programa estará pidiendo números y mostrando su factorización hasta que el usuario desee terminar. Dicho programa incluirá, al menos, las siguientes funciones:
* Función para calcular los primos menores que un número dado mediante el algoritmo de la Criba de Eratóstenes (que ya resolvió en el [ejercicio X](#here)).
* Función que, dado un valor entero, devuelva un vector con su descomposición en factores primos. Esta función hará uso del resultado de la criba para ir probando la divisibilidad del número.
A continuación se muestra un ejemplo de ejecución:

~~~
Escriba un valor entero: 1500
Su descomposición factorial es: 2 2 3 5 5 5
~~~

Observe que la intención es que la segunda función haga uso de los resultados de la criba por lo que tiene dos posibilidades:
* Crear el vector de números primos dentro de la segunda función. Cada vez que se descomponga un número se calculan de nuevo todos los primos menores que él.
* Crear el vector de primos fuera de la segunda función, de manera que sólo es necesario crearlo una vez. Por contra, no se sabe a priori cuál es el mayor primo que se va a necesitar.

Estudie y razone cuáles son las ventajas e inconvenientes de cada una de las propuestas e implemente la que usted crea que
es más eficiente.

- - -

##### Ejercicio 4.14 ¬ Polinomios

Implemente un programa que permita realizar las siguientes operaciones básicas sobre polinomios de cualquier grado:
* Evaluar un polinomio en un punto.
* Derivar un polinomio.
* Evaluar la derivada de un polinomio en un punto.
* Calcular el valor máximo de un polinomio en un intervalo. Este algoritmo deberá evaluar el polinomio en varios puntos del intervalo y seleccionar aquel que lo maximice. Los puntos en los que va a realizar estarán dentro del intervalo y serán equidistantes entre sí. El número de puntos para muestrear será dado por el usuario del programa.

Para trabajar con polinomios de la forma _a\_n\*x^n + a\_(n−1)\*x^(n−1) + ... + a\_2\*x^2 + a\_1\*x + a\_0_ almacenaremos sus coeficientes en vectores de números reales. Se piden, al menos, las siguientes funciones:

* Función para leer un polinomio desde la entrada estándar.
* Función para escribir un polinomio en la salida estándar.
* Función para evaluar un polinomio en un punto.
* Función para, dado un polinomio, calcular y devolver su derivada.
* Función para, dado un polinomio, un intervalo y un número de puntos a muestrear en ese intervalo, calcular y devolver su máximo de acuerdo al algoritmo indicado antes.

El programa mostrará un menú de opciones al usuario para decidir en cada momento qué operación se desea realizar. La ejecución continuará hasta que el usuario decida finalizar seleccionando una de las opciones del menú.

- - -

##### Ejercicio 4.15 ¬ Mediana de un vector

Considere de nuevo el [ejercicio X](#here) y modularícelo adecuadamente. Deberá incluir funciones al menos para:

* Leer un vector de números enteros.
* Ordenar un vector de números enteros. Puede usar el algoritmo que considere oportuno.
* Calcular la mediana de un vector de números enteros.

- - -

##### Ejercicio 4.16 ¬ Máximo de una matriz

Implemente una función que calcule el mayor elemento de una matriz de números reales.

- - -

##### Ejercicio 4.17 ¬ Medias de las filas de una matriz

Haciendo uso de una de las funciones del [ejercicio 4.11](#here) realice una función que reciba como dato una matriz de reales y que devuelva un vector con las medias de cada fila.

- - -

## Relación de ejercicios

- - -

##### Ejercicio 4.18 ¬ Número áureo

Implemente una función que calcule el [número áureo](http://es.wikipedia.org/wiki/Número_Áureo) sabiendo que puede obtenerse como la fracción entre dos términos consecutivos de la [serie de Fibonacci](http://es.wikipedia.org/wiki/Sucesión_de_Fibonacci). La función recibirá como argumento el número de términos de la serie de Fibonacci que se deben calcular. La función devolverá el valor de la aproximación para ese número de términos.

- - -

##### Ejercicio 4.19 ¬ Cálculo de π

Diseñe e implemente dos funciones para calcular el valor de π de acuerdo a los siguientes métodos iterativos:

_INSERTAR MÉTODOS ITERATIVOS <HERE>_

- - -

##### Ejercicio 4.20 ¬ Días para el cumpleaños

Haga un programa que lea dos fechas: la fecha actual y su fecha de nacimiento. A continuación mostrará cuántos días faltan para su próximo cumpleaños. Deberá reutilizar las funciones para leer fechas y para calcular el día juliano del [ejercicio 4.10](#here). A continuación tiene varios ejemplos de ejecución:

~~~
Dígame la fecha actual: 2 8 2010
Dígame su fecha de nacimiento: 4 8 2000
Faltan 2 días para su cumpleaños
~~~

~~~
Dígame la fecha actual: 4 8 2010
Dígame su fecha de nacimiento: 4 8 2000
Hoy es su cumpleaños
~~~

~~~
Dígame la fecha actual: 10 8 2010
Dígame su fecha de nacimiento: 4 8 2000
Faltan 359 días para su cumpleaños
~~~

- - -

### Ejercicios muuy interesantes (y bastante chulos je, je)

Los ejercicios que vienen a continuación son ejercicios más elaborados de los que estamos acostumbrados a hacer. Son **muy interesantes**, y cada uno de ellos aborda aspectos de programación en C++ bastante importantes.

Para hacer estos ejercicios es imprescindible tener un buen conocimiento de vectores y matrices ([tema 3](../Apuntes/tema3.md)).
- - -

##### Ejercicio 4.21 ¬ Tres en raya

Se desea implementar el juego del tres en raya para dos personas. Es un juego por turnos en el que cada jugador coloca fichas de un determinado tipo en un tablero de tamaño 3x3 (por ejemplo: un jugador coloca círculos y otro coloca equis). El primer jugador que consiga colocar tres fichas de su tipo alineadas gana. Las fichas no pueden moverse una vez colocadas y sólo es posible poner nuevas fichas en las casillas que quedan vacías. Puede ocurrir que se completen todas las casillas del tablero sin que ninguno haya logrado el tres en raya, en ese caso habrá empate.

Seguiremos una estrategia de diseño descendente: comenzaremos escribiendo la función `main()` que implementa la lógica del juego:

* Limpiar el tablero
* Mostrar el tablero
* Inicializar turno
* Repetir mientras no acabe el juego:
    * Avanzar al siguiente turno
    * Preguntar al jugador del turno en curso dónde quiere colocar su ficha
    * Poner la ficha en el tablero
    * Mostrar tablero resultante
    * Comprobar el estado del juego: "gana alguien", "empate" o "seguimos jugando"
* Mostrar el ganador (o empate si lo hubiera).

El programa, además, permitirá que juguemos tantas partidas como deseemos. La función `main()` debe ser la siguiente:

~~~c++
int main() {
    vector<vector<char> > tab(3, vector<char>(3));
    int turno = 0, estado, f, c;
    do {
        cout << "Comienza la partida" << endl;
        vaciarTablero(tab);
        visualizarTablero(tab);
        do {
            turno = (turno+1)%2;            // avanzar turno
            pedirJugada(turno, tab, f, c);  // preguntar dónde poner ficha
            ponerFicha(turno, tab, f, c);   // poner ficha en tablero
            visualizarTablero(tab);         // mostrar tablero
            estado = comprobarEstado(tab);  // comprobar estado de partida (gana, empate, nada)
        } while ( estado==3 );
        mostrarGanador(estado);
    } while ( seguir() );
}
~~~

###### Aclaraciones sobre el programa anterior:

* Se ha representado el tablero mediante una matriz de caracteres. Si una casilla está libre guardaremos un carácter blanco `' '`, si la ocupa el primer jugador colocaremos un carácter `'O'` y si la ocupa el segundo jugador colocaremos un carácter `'X'`.
* La variable `turno` toma en cada iteración, de forma alternativa, los valores 0 y 1 para saber quién tiene el turno.
* `vaciarTablero()`: pone blancos en todas las posiciones del tablero.
* `visualizarTablero()`: muestra el tablero en la salida estándar con un formato adecuado.
* `pedirJugada()`: le pregunta a un jugador en qué fila (`f`) y columna (`c`) desea poner una nueva ficha. Debe asegurarse de que es una jugada válida. No pone la ficha en el tablero.
* `ponerFicha()`: coloca la ficha de un jugador en el tablero.
* `comprobarEstado()`: analiza el tablero y determina si hay tres en raya por parte de algún jugador, se ha completado el tablero o bien se puede seguir jugando. El resultado es un entero que codifica esas situaciones. Por ejemplo, puede devolver un valor 0 si gana el primer jugador, un valor 1 si gana el segundo, un valor 2 si hay empate y un valor 3 si podemos seguir jugando.
* `mostrarGanador()`: muestra en la salida estándar quién ha ganado la partida (o si se ha producido un empate).

Debe implementar todas estas funciones y otras si las necesitas. Debe deducir la interfaz de las funciones a partir de las llamadas que puede ver en `main()`.

- - -

##### Ejercicio 4.22 ¬ El ahorcado

- - -

##### Ejercicio 4.23 ¬ Buscaminas