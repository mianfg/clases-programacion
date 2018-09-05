# Relación 4. Modularización I: funciones

> **Clases de programación en C++** · septiembre de 2018  
> Miguel Ángel Fernández Gutiérrez ([@mianfg](https://mianfg.bloomgogo.com))

- - -

:pencil: Encuentra los **apuntes** de este tema [aquí](../Apuntes/tema4.md).

- - -

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

##### Ejercicio 4.2 — Conversión a minúsculas

Implemente una función que reciba un carácter y que en caso de ser una letra devuelva su correspondiente minúscula. En otro caso devolverá el mismo carácter. No se permite el uso de funciones de biblioteca (en particular `tolower()`).

###### Cabecera de la función:
~~~c++
char toMinuscula(char letra);
~~~

Implemente una función `main()` que lea una letra desde la entrada estándar y que muestre su correspondiente minúscula.

- - -

##### Ejercicio 4.3 — Máximo común divisor y mínimo común múltiplo

Implemente dos funciones: una para calcular el máximo común divisor y otra para calcular el mínimo común múltiplo de dos números enteros (positivos o negativos). Los prototipos deben ser estos:

###### Cabeceras de las funciones:
~~~c++
int mcm(int num);
int mcd(int num);
~~~

A continuación implemente un main() que pregunte dos números al usuario y que muestre el resultado de ejecutar ambas
funciones. Para calcular el máximo común se sugiere la utilización del [algoritmo de Euclides](http://es.wikipedia.org/wiki/Algoritmo_de_Euclides).

- - -

##### Ejercicio 4.4 — Potencia de un número

Diseñe e implemente una función que reciba dos números enteros `a` y `b` y que devuelva la potencia _a^b_. Esta función no puede utilizar ninguna función de biblioteca (en particular `pow()`).

- - -

##### Ejercicio 4.5 — Evaluación de un polinomio

Escriba un programa que lea 4 números `a`, `b`, `c` y `d` que definen el polinomio _a*x^3 + b*x^2 + c*x + d_, que lo evalúe en un punto y que muestre ese valor. Para ello, defina la función `evaluar()` que recibe los cuatro valores junto con un valor `x` donde evaluarlo, y que devuelve un número resultado de la evaluación.

Para resolverlo, por un lado deberá reutilizar la función del [ejercicio 4.4](#ejercicio-44--potencia-de-un-número), y por otro, evitar declarar ninguna variable local en la función `evaluar()`.

###### Cabecera de la función:
~~~c++
double evaluar(double a, double b, double c, double d, double x);
~~~

- - -

#### Funciones tipo `void`

- - -

##### Ejercicio 4.6 — Tabla de multiplicar

Implemente una función que muestre por pantalla la tabla de multiplicar del número pasado.

###### Cabecera de la función:
~~~c++
void mostrarTablaMultiplicar(int num);
~~~

Implemente también en la función `main()` las líneas de código necesarias para pedir por pantalla a un número y luego mostrarlo por pantalla haciendo uso de la función `mostrarTablaMultiplicar()`.

- - -

#### Paso por referencia

- - -

##### Ejercicio 4.7 — Intercambio de valores

Escriba una función `intercambiar()` para intercambiar el valor de dos variables de tipo `double`. Es decir, en la llamada se pasarán dos variables y, al finalizar, los valores de ambas estarán intercambiados. Implemente también un `main()` para probar la función.

###### Cabecera de la función:
~~~c++
void intercambiar(double & x, double & y);
~~~

- - -

##### Ejercicio 4.8 — Ordenar dos valores

Escriba una función `ordenar2()` para ordenar los valores de dos variables de tipo `double`. Es decir, en la llamada se pasarán dos variables y, al finalizar, la primera variable tendrá el menor y la segunda el mayor de los valores.

Para resolverlo, use la función `intercambiar()` del [ejercicio 4.7](#ejercicio-47--intercambio-de-valores).

Como puede comprobar en la solución del ejercicio, desde la función `ordenar2()` pasamos dos variables a la función `intercambiar()`. Realmente, estos dos objetos no están creados ahí, sino que son dos objetos que se han pasado, a su vez, desde otra función. Dicho de otra forma, son dos referencias a dos objetos que, declarados fuera de `ordenar2()`, se pasan a la función de intercambio.

- - -

##### Ejercicio 4.9 — Ordenar tres valores

Escriba una función `ordenar3()` para ordenar los valores de tres variables de tipo `double`. Es decir, en la llamada se pasarán tres variables y, después de ella, la primera variable tendrá el menor, la segunda el mediano y la tercera el mayor de los valores.

###### Idea para resolver este ejercicio

> **Intenta pensar el problema primero** antes de leer lo de abajo. ¡Seguro que tú llegas a la solución!

Este problema puede resolverse haciendo uso de la función `ordenar2()` del [ejercicio 4.8](#ejercicio-48--ordenar-dos-valores), teniendo en cuenta que, para ordenar tres valores, basta ordenar los dos primeros, luego los dos últimos y de nuevo los dos primeros.

- - -

### Diseño de funciones

#### Separación entre E/S y los cálculos

- - -

##### Ejercicio 4.10 — Fecha con formato

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

##### Ejercicio 4.11 — Media, desviación y varianza de un vector de números

Modifique el programa del [ejercicio 3.4](../Ejercicios/relacion3.md#ejercicio-34--media-desviación-y-varianza) de forma que modularice el código mediante las siguientes funciones:

* Leer los datos. No recibe ningún parámetro y devuelve un vector con los datos leídos desde la entrada estándar. Los datos son una secuencia de números que termina en un número negativo que actúa como centinela.
* Calcular la media. Recibe un vector de números reales y devuelve la media de dichos valores.
* Calcular la desviación. Recibe un vector de datos y un valor (por ejemplo, la media) y devuelve la desviación media de los datos a dicho valor.
* Calcular la varianza. Recibe un vector de datos y devuelve la varianza.

- - -

##### Ejercicio 4.12 — Matrices de Vandermonde

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

##### Ejercicio 4.13 — Factorización de un número

Implemente un programa que lea una serie de números enteros desde la entrada estándar y que muestre al usuario su factorización. El programa estará pidiendo números y mostrando su factorización hasta que el usuario desee terminar. Dicho programa incluirá, al menos, las siguientes funciones:
* Función para calcular los primos menores que un número dado mediante el algoritmo de la Criba de Eratóstenes (que ya resolvió en el [ejercicio 3.5](../Ejercicios/relacion3.md#ejercicio-35--criba-de-eratóstenes)).
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

##### Ejercicio 4.14 — Polinomios

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

##### Ejercicio 4.15 — Mediana de un vector

Considere de nuevo el [ejercicio 3.16](../Ejercicios/relacion3.md#ejercicio-316--mediana) y modularícelo adecuadamente. Deberá incluir funciones al menos para:

* Leer un vector de números enteros.
* Ordenar un vector de números enteros. Puede usar el algoritmo que considere oportuno.
* Calcular la mediana de un vector de números enteros.

- - -

##### Ejercicio 4.16 — Máximo de una matriz

Implemente una función que calcule el mayor elemento de una matriz de números reales.

- - -

##### Ejercicio 4.17 — Medias de las filas de una matriz

Haciendo uso de una de las funciones del [ejercicio 4.11](#ejercicio-411--media-desviación-y-varianza-de-un-vector-de-números) realice una función que reciba como dato una matriz de reales y que devuelva un vector con las medias de cada fila.

- - -

## Relación de ejercicios

- - -

##### Ejercicio 4.18 — Número áureo

Implemente una función que calcule el [número áureo](http://es.wikipedia.org/wiki/Número_Áureo) sabiendo que puede obtenerse como la fracción entre dos términos consecutivos de la [serie de Fibonacci](http://es.wikipedia.org/wiki/Sucesión_de_Fibonacci). La función recibirá como argumento el número de términos de la serie de Fibonacci que se deben calcular. La función devolverá el valor de la aproximación para ese número de términos.

- - -

##### Ejercicio 4.19 — Cálculo de π

Diseñe e implemente dos funciones para calcular el valor de π de acuerdo a los siguientes métodos iterativos:

* Haciendo uso de la [serie de Leibniz](https://es.wikipedia.org/wiki/Serie_de_Leibniz).
* Haciendo uso del [producto de Wallis](https://es.wikipedia.org/wiki/Producto_de_Wallis).

- - -

##### Ejercicio 4.20 — Días para el cumpleaños

Haga un programa que lea dos fechas: la fecha actual y su fecha de nacimiento. A continuación mostrará cuántos días faltan para su próximo cumpleaños. Deberá reutilizar las funciones para leer fechas y para calcular el día juliano del [ejercicio 4.10](#ejercicio-410--fecha-con-formato). A continuación tiene varios ejemplos de ejecución:

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

##### Ejercicio 4.21 — Tres en raya

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

##### Ejercicio 4.22 — El ahorcado

Implemente el juego del ahorcado en C++ . Este es un juego para dos personas (_jugador1_ y _jugador2_) y la dinámica es la siguiente:

* El _jugador1_ se inventa una palabra y el _jugador2_ debe acertarla en un número máximo de intentos.
* En cada intento, el _jugador2_ dice una letra y el _jugador1_ le dice si está o no presente en la palabra que se inventó. Además, si está, debe mostrarle en qué posiciones está.
* No se permite que el _jugador2_ repita letras.

Más concretamente, el programa debe realizar estas tareas:
1. Al comienzo, el programa le pide al _jugador1_ que le diga la palabra que se ha inventado. El _jugador2_ no debería verla. El _jugador1_ también podrá indicar el límite de intentos para adivinar.  
    Para almacenar la palabra usaremos un objeto de tipo `string`. Observe que debe tener cuidado con que el usuario escriba palabras válidas (sin caracteres que no sean alfabéticos). Tenga presente también que se distinguen mayúsculas y minúsculas.  
    Por ejemplo, si la palabra que se ha inventado es “ballena” y queremos tener un máximo de 4 intentos, el comienzo de la ejecución del programa podría ser este:  
    ~~~
    Hay dos jugadores:
    1.- El que se inventa la palabra
    2.- El que adivina la palabra
    Jugador 1: escribe una palabra
    Jugador 2: ¡No mires!
    La palabra debe tener al menos una letra: ballena
    Jugador 1: ¿de cuántos intentos disponemos? 4
    ~~~
2. Comenzamos el juego mostrando al _jugador2_ las letras que tiene la palabra que debe adivinar y otra información relevante (número de intentos que le quedan, letras que ha dicho...).
3. Ahora el _jugador2_ irá diciendo letras y el programa le irá indicando si están o no mostrando, en cada intento, información sobre la evolución del juego.
    * Si el jugador acierta se mostrarán las letras en la posición correspondiente.
    * Si el jugador falla se descontará un intento y se guardará la letra que ha dicho para que lo tenga presente.
    * También se informará cuando el _jugador2_ repita letras sin penalizar dichos intentos.

A continuación vemos una posible ejecución para averiguar la palabra “ballena” introducida previamente:

~~~
La palabra es: -------
Letras usadas:
Intentos: 4
Dime una letra: u
Mal, la letra no está

La palabra es: -------
Letras usadas: u
Intentos: 3
Dime una letra: a
Bien, la letra está en la palabra oculta

La palabra es: -a----a
Letras usadas: u a
Intentos: 3
Dime una letra: a
¡ Esa letra ya la dijiste !

La palabra es: -a----a
Letras usadas: u a
Intentos: 3
Dime una letra: n
Bien, la letra está en la palabra oculta

La palabra es: -a---na
Letras usadas: u a n
Intentos: 3
Dime una letra:
~~~

Debe modularizar convenientemente este programa.

###### Ampliación

Puede hacer más interesante este juego si consigue que, en lugar de que sea el usuario el que escribe la palabra a buscar, sea el propio ordenador el que se la invente. Para ello puede disponer de un listado de palabras almacenado en un vector de cadenas de caracteres. El programa comenzará eligiendo una de ellas al azar: bastaría con inventarse un número entero entre 0 y el número de palabras almacenadas menos uno, que haría referencia a la posición del vector –la palabra– que vamos a elegir para jugar.

Dicho vector de palabras puede codificarse en el propio programa o bien se puede disponer de un fichero de texto plano con las palabras que se leerá (mediante la técnica de copiar y pegar) al comienzo de la ejecución. Igualmente el número de intentos podría generarse aleatoriamente, o incluso generarse en función del tamaño de la palabra a buscar o el número de letras distintas que tiene.

- - -

##### Ejercicio 4.23 — Buscaminas

El juego del buscaminas comienza con un tablero de F filas y C columnas, donde se ocultan N minas. Inicialmente no se sabe nada sobre lo que hay debajo de cada casilla, pudiendo ser una casilla sin mina o con mina.

El problema consiste en localizar las minas sin detonar ninguna de ellas. En cada paso, el jugador escoge entre:

1. Destapar una casilla. Si es una mina, habrá detonado y el juego ha terminado sin éxito. Si no lo es, se abrirá la casilla y el resto de casillas del entorno.
2. Marcar una casilla como posición probable de una mina. Es decir, el jugador determina que esta casilla nunca se abrirá, ya que piensa que tiene una mina.

Si el juego continúa y llega el momento en que todas las casillas se han abierto (excepto las que contienen una mina), no quedarán casillas por abrir y, por tanto, se habrá ganado el juego.

Para poder guiar al jugador de forma que pueda averiguar dónde se encuentran las minas, el juego ofrece pistas sobre dónde podrían estar las minas. En concreto, cuando se abre una casilla sin mina existen dos posibilidades:

1. Está vacía, sin mina, y no hay ninguna mina al lado. En este caso, el juego explora automáticamente las 8 casillas que hay a su alrededor, abriendo aquellas que no tengan mina.
2. Está vacía, sin mina, pero tiene una o más minas al lado. En este caso el juego se limita a mostrar al jugador la casilla como vacía, pero mostrando un número que indica el número de minas que están en su entorno.

El jugador deberá analizar los números que se van mostrando para deducir dónde se sitúan las N minas que sabemos oculta el tablero.

###### La dinámica de juego

Se pretende obtener un programa sencillo que pueda usarse con la consola. Por tanto, las entradas y salidas deberán realizarse con `cin>>` y `cout<<`. Se propone la siguiente interfaz:

* Inicialmente comienza el juego pidiendo los parámetros de dificultad. Estos parámetros están compuestos por el número de filas, el número de columnas, y el número de minas ocultas. Observe que el número de minas no puede ser demasiado grande. Por ejemplo, podemos obligar a que siempre haya un número mínimo de 5 minas y un número máximo que corresponde al 50 % de casillas en el tablero.
* En cada iteración, el juego muestra el tablero actual y pregunta por una acción a realizar. La acción puede ser:
    * Abrir una posición: el usuario escribe tres datos, el primero será una palabra “a” o “abrir” (con cualquier combinación mayúsculas/minúsculas), y los dos siguientes la fila y columna correspondientes. En este caso, el programa abre la casilla indicada modificando el tablero según corresponda. Observe que esta acción no hace nada si la casilla ya está abierta o tiene una marca.
    * Marcar/desmarcar una posición: el usuario escribe tres datos, el primero una palabra “m” o “marcar” (con cualquier combinación mayúsculas/minúsculas), y los dos siguientes la fila y columna correspondiente. Si la casilla está sin marcar la pone como marcada, y en caso de que ya esté marcada elimina la marca.
* El juego termina con éxito cuando todas las casillas sin mina están abiertas. Por otro lado, el juego termina sin éxito si se realiza una acción de apertura sobre una casilla que contiene una mina.

###### Diseño propuesto

Existen distintas alternativas para almacenar el tablero del juego. En principio, la más sencilla es almacenar la información en un vector de vectores de enteros, y codificar con distintos enteros la situación de cada casilla, incluyendo información sobre el contenido, el estado (abierta o no) y si está marcada.

Para simplificar el problema, proponemos una forma de codificar dicha información, aunque pueden establecerse otras. En nuestra solución, proponemos que se guarde toda la información posible en el tablero, de forma que sea más sencillo y eficiente visualizarlo o procesarlo. En concreto, proponemos que el tablero contenga un entero con la siguiente codificación:

* Si contiene un número del 0 al 9, es una casilla oculta. Además, el entero indica el número de minas que hay alrededor (del 0 al 8), o indica que es una mina (el 9).
* Si contiene un número del 10 al 19, es una casilla que se ha abierto. Contiene la misma información que los números del 0 al 9, aunque como abiertas. Así, por ejemplo, el número 3 indica que está oculta y hay 3 minas alrededor, y el número 3+10 también indica que hay 3 minas alrededor, aunque es una casilla abierta.
* Si contiene un número del 20 al 29, es una casilla marcada. Contiene la misma información que los números del 0 al 9, aunque como marcada. Por ejemplo, el número 3+20 indica que hay 3 minas alrededor y que el usuario la tiene como marcada.

Con esta codificación, podemos deducir que una partida se ha perdido cuando hemos abierto una casilla 9.

Algunas de las funciones o módulos que puede contener la solución son:
* Generar el tablero.
* Imprimir el tablero. Esta función debería facilitar al usuario observar el estado actual del tablero para poder tomar una decisión.
* Solicitar una jugada. Deberá pedir una terna (acción, fila, columna) para procesar la jugada. Recuerde que la acción se especifica con una palabra, y que dicha palabra puede estar en minúscula o mayúscula.
* Comprobar si se ha resuelto el tablero. Será necesario comprobar que no quedan casillas por abrir y que las marcas son correctas.
* Abrir casilla. Corresponde al procesamiento de la acción de abrir sobre una determinada casilla (se explica más adelante).

Lógicamente, se puede decidir el conjunto de funciones que considere más conveniente, incluyendo éstas, parte de éstas, y otras que probablemente necesitará.

###### Generación del tablero

La generación del tablero consiste en crear una estructura bidimensional con tantas filas y columnas como se desee, y generar aleatoriamente la posición de las minas.

Se debe tener especial cuidado en la generación de minas ya que, al generar la posición de las minas de forma aleatoria, podría ocurrir que se intente colocar más de una vez una mina en una misma casilla. Lógicamente, sólo es posible tener una mina en una casilla, y por tanto, si ya existe una mina, deberá repetirse la generación en una casilla distinta.

Una vez generadas las minas, se deberá recorrer el tablero para asignar, a cada una de las restantes casillas, el valor entero que corresponde al número de minas en su entorno.

###### Algoritmo para "abrir" una casilla

La parte más complicada, desde el punto de vista algorítmico, es probablemente la apertura de una posición o casilla.

Esta dificultad se debe a que abrir una casilla puede provocar la apertura de algunas de su entorno y éstas, a su vez, otras adicionales, de forma que se pueden encadenar un número muy alto de aperturas.

La idea es que la apertura de una casilla que no tiene mina en ella ni en su entorno (codificada como cero) dispara la apertura de cualquier casilla de su alrededor. Un algoritmo sencillo para resolver el problema a partir de una casilla ( _f\_i_ , _c\_i_ ) es el siguiente:
1. Añadir la casilla ( _f\_i_ , _c\_i_ ) al conjunto C de casillas por abrir.
2. Mientras queden casillas por procesar en C:
    * Extraer una casilla ( _f_, _c_ ) del conjunto C de pendientes.
    * Si la casilla ( _f_ , _c_ ) tiene un número entre 1 y 8, modificar como abierta.
    * Si la casilla ( _f_ , _c_ ) tiene un número cero (vacía, oculta y sin minas vecinas), ponerla como abierta e insertar todas sus vecinas al conjunto C de pendientes.

Una vez que el conjunto C queda vacío, todas las casillas vacías conectadas con la original ( _f\_i_ , _c\_i_ ) se habrán visitado, es decir, se habrán abierto. Observe que cualquier casilla con un valor distinto de cero que se abra no propagará el efecto de apertura a sus vecinas. Además, las casillas que estén marcadas por el usuario (tienen un valor entre 20 y 29) ni se abrirán ni propagarán la apertura.

- - -
