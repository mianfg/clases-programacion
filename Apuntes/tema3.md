### Tema 3.  
# Vectores y matrices

> **Clases de programación en C++** · agosto de 2018  
> Miguel Ángel Fernández Gutiérrez ([@mianfg](https://mianfg.bloomgogo.com))

- - -

## 👉 Tabla de contenidos

1. [Motivación al uso de vectores](#1-motivación-al-uso-de-vectores)
2. [Concepto de vector](#2-concepto-de-vector)
3. [Operaciones básicas con vectores](#3-operaciones-básicas-con-vectores)  
    3.1 [Declaración](#31--declaración)  
    3.2 [Asignación](#32--asignación)  
    3.3 [Acceso: operador `[]`](#33--acceso-operador-)  
    3.4 [Modificación (asignación por elementos)](#34--modificación-asignación-por-elementos)  
4. [Operaciones específicas de la clase `vector`](#4-operaciones-específicas-de-la-clase-vector)  
    4.1 [Acceso y modificación: operador `at()`](#41--acceso-y-modificación-operador-at)  
    4.2 [Comprobación de tamaño: `size()`](#42--comprobación-de-tamaño-size)  
    4.3 [Variación de tamaño: `push_back()`, `pop_back()`, `clear()`](#43--variación-de-tamaño-push_back-pop_back-y-clear)  
    4.4 [Otros operadores](#44--otros-operadores)  
5. [Recorridos sobre vectores](#5-recorridos-sobre-vectores)  
    5.1 [Algoritmos de búsqueda](#51--algoritmos-de-búsqueda)  
        — 5.1.1 [Búsqueda secuencial](#511--algoritmo-de-búsqueda-secuencial)  
        — 5.1.2 [Búsqueda binaria](#512--algoritmo-de-búsqueda-binaria)  
        — 5.1.3 [Otros algoritmos de búsqueda](#513--otros-algoritmos-de-búsqueda)  
    5.2 [Modificación de elementos de un vector](#52--modificación-de-los-elementos-de-un-vector)  
        — 5.2.1 [Inserción de un valor](#521--inserción-de-un-valor)  
        — 5.2.2 [Eliminación de un valor](#522--eliminación-de-un-valor)  
    5.3 [Algoritmos de ordenación](#53--algoritmos-de-ordenación)  
        — 5.3.1 [Ordenación por selección](#531--ordenación-por-selección)  
        — 5.3.2 [Ordenación por inserción](#532--ordenación-por-inserción)  
        — 5.3.3 [Ordenación por intercambio directo (_método de la burbuja_)](#533--ordenación-por-intercambio-directo-método-de-la-burbuja)  
6. [Concepto de matriz](#6-concepto-de-matriz)
7. [Vectores vs. arrays](#7-vectores-vs-arrays)

##### Ejemplos y algoritmos

* [Ejemplo 3.1](#ejemplo-31--resolución-parcial-del-problema-de-las-notas-versión-1) — resolución parcial del problema de las notas (versión 1)
* [Ejemplo 3.2](#ejemplo-32--resolución-parcial-del-problema-de-las-notas-versión-2) — resolución parcial del problema de las notas (versión 2)
* [Ejemplo 3.3](#ejemplo-33--resolución-del-problema-de-las-notas-versión-1) — resolución del problema de las notas (versión 1)
* [Ejemplo 3.4](#ejemplo-34--resolución-del-problema-de-las-notas-versión-2) — resolución del problema de las notas (versión 2)
* [Algoritmo 3.5](#algoritmo-35--búsqueda-secuencial) — búsqueda secuencial
* [Algoritmo 3.6](#algoritmo-36--búsqueda-binaria) — búsqueda binaria
* [Algoritmo 3.7](#algoritmo-37--búsqueda-del-máximo-de-un-vector) — búsqueda del máximo de un vector
* [Algoritmo 3.8](#algoritmo-38--encontrar-un-vector-dentro-de-otro) — encontrar un vector dentro de otro

- - -

## 1. Motivación al uso de vectores

Queremos resolver el siguiente problema:

> Dado un conjunto de valores, queremos:
> * Calcular su media.
> * Decir cuántos alumnos superan la media.
> * calcular su moda.

Para contextualizar el problema, digamos que esos valores son las notas de una clase.

- - -

##### Ejemplo 3.1 — resolución parcial del problema de las notas (versión 1)

Comenzaremos resolviendo el problema usando los conocimientos del tema anterior acumulando las notas insertadas en una variable, mediante la cual calcularemos la media. Sin embargo, de este modo es imposible decir cuántos alumnos superan la media, pues no tenemos los alumnos almacenados _per se_.

~~~ c++
int contador = 0;
double media = 0, entrada;
double nota_max = 0;

cout << "Inserte las notas hasta insertar una no válida: ";
	
do {
	cin >> entrada;
	if ( entrada >= 0 && entrada <= 10 ) {
		if ( entrada > nota_max )
			nota_max = entrada;
		media += entrada;
		contador++;
	}
} while ( entrada >= 0 && entrada <= 10 );
media /= contador;
cout << "La media es: " << media << endl;
~~~

- - -

##### Ejemplo 3.2 — resolución parcial del problema de las notas (versión 2)

Podemos resolver el problema también de la siguiente forma, dejando la moda:

~~~c++
int nota_1, nota_2, nota_3;

cout << "Inserte las notas: ";
cin >> nota_1 >> nota_2 >> nota_3;

int media = (nota_1 + nota_2 + nota_3)/3, superan_media = 0;

if (nota_1 > media)
    superan_media++;
if (nota_2 > media)
    superan_media++;
if (nota_3 > media)
    superan_media++;

cout << "La media de las notas es: " << media << endl
     << "El número de notas que superan la media es: "
     << superan_media << endl;
~~~

Apreciemos cómo es necesario constatar dónde vamos a almacenar cada una de las notas, por lo que es necesario declarar una variable para cada nota. Por ello, hemos resuelto el problema para _n = 3_.

¿Qué pasa si queremos resolver el problema general, esto es, para cualquier _n_? **¡Para eso tenemos los vectores!**

- - -

## 2. Concepto de vector

Un objeto de tipo vector es una estructura de datos que cumple:

- Es **compuesto**: puede contener múltiples objetos.
- Es **homogéneo**: todos los objetos deben ser del mismo tipo.

Al declarar un vector de un cierto tamaño, estamos declarando muchas variables de un mismo tipo encadenadas en memoria.

![Imagen 3.1](./resources/tema3-img1.png)

Por ejemplo, si tuviésemos un vector de _n_ valores de tipo `double`, podríamos almacenar _n_ notas diferentes, de forma encadenada.

![Imagen 3.2](./resources/tema3-img2.png)

Esto nos permite agilizar nuestro código de forma significativa, debido a que los vectores nos permiten realizar operaciones.

> MUY IMPORTANTE  
> El tipo vector no está definido en el lenguaje, sino en una clase de C++ contenida en std. Para hacer uso de él, es **necesario incluir el fichero de cabecera `vector`**.
> ~~~c++
> #include <vector>
> ~~~

- - -

Para poder manejar cada uno de los elementos contenidos, el vector los organiza mediante un **índice**.

Tomando el mismo ejemplo anterior, los índices quedarían:

![Imagen 3.3](./resources/tema3-img3.png)

En general, podemos representar un vector con el siguiente esquema:

![Imagen 3.4](./resources/tema3-img4.png)

- - -

## 3. Operaciones básicas con vectores

### 3.1  Declaración

Para trabajar con objetos, debemos **crearlos**. Es para ello necesario especificar el tipo contenido. Opcionalmente, se puede especificar el tamaño y el valor con el que inicializarlo.

#### Vector de tipo `type` y tamaño cero

~~~ c++
vector<type> v;
~~~

![Imagen 3.5](./resources/tema3-img5.png)

De este modo, hemos creado un vector de `type` vacío.

#### Vector de tipo `type` y tamaño `n`

~~~ c++
vector<type> v(n);
~~~

![Imagen 3.6](./resources/tema3-img6.png)

De este modo, hemos creado un vector de `type` de `n` elementos. Dependiendo del tipo, se inicializarán a un valor u otro (_¡experimenta para comprobarlo!_).

#### Vector de tipo `type` y tamaño `n` inicializado a `i`

~~~ c++
vector<type> v(n, i);
~~~

![Imagen 3.7](./resources/tema3-img7.png)

De este modo, hemos creado un vector de `type` de `n` elementos, en el que todos los elementos tienen el valor `i` (inicialización), que debe ser de tipo `type`.

### 3.2  Asignación

Podemos asignar un vector a otro, o inicializarlo con un vector _raw_, es decir, un vector escrito de la forma `{...}`, siempre que todos los elementos sean del mismo tipo que el vector declarado.

~~~ c++
vector<double> notas = {9.8, 7.2, 5.6, 9.2, 8.8};
vector<double> notas_2 = notas;
~~~

### 3.3  Acceso: operador `[]`

Para acceder al valor con índice `i` del vector `v`, basta hacer **`v[i]`**.

### 3.4  Modificación (asignación por elementos)

Podemos usar los operadores anteriores para hacer uso de la asignación para cada uno de los valores individuales.

~~~ c++
notas[0] = 6;  // modifica notas a 6.0
~~~

- - -

## 4. Operaciones específicas de la clase `vector`

### 4.1  Acceso y modificación: operador `at()`

Podemos usar en lugar del operador `[]` el operador `at()`, incorporado en la clase vector.

> La diferencia entre `at()` y `[]` se encuentra explicada en la relación de ejercicios.

~~~ c++
cout << notas.at(0);  // lo mismo (casi) que cout << notas[0]
notas.at(0) = 10;     // lo mismo (casi) que notas[0] = 10
~~~

### 4.2  Comprobación de tamaño: `size()`

Esta función de la clase `vector` devuelve un dato de tipo `int`, correspondiente al número de elementos del `vector`.

~~~ c++
cout << notas.size();  // muestra 5
~~~

- - -

> ***¡Ya estamos en condiciones de resolver nuestro problema!***

##### Ejemplo 3.3 — resolución del problema de las notas (versión 1)

~~~ c++
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int num_notas;
    cout << "Inserte cuántas notas insertará: ";
    cin >> num_notas;

    vector<double> notas(num_notas);
    for ( int i = 0; i < notas.size(); i++ )
        cin >> notas[i];
    
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

### 4.3  Variación de tamaño: `push_back()`, `pop_back()` y `clear()`

| Imagen | Función | Descripción |
| --- | --- | --- |
| ![Imagen 3.8](./resources/tema3-img8.png) | `v.push_back(x)` | Inserta al vector el elemento `x` al final de éste. Debe ser del mismo tipo que el vector. |
| ![Imagen 3.9](./resources/tema3-img9.png) | `v.pop_back()` | Elimina el último elemento del vector. |
| ![Imagen 3.10](./resources/tema3-img10.png) | `v.clear()` | Vacía el vector. |

- - -

> ***¡Ahora podemos mejorar la solución a nuestro problema!***

##### Ejemplo 3.4 — resolución del problema de las notas (versión 2)

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

- - -

## 5. Recorridos sobre vectores

### 5.1  Algoritmos de búsqueda

Los **algoritmos de búsqueda** son unos de los algoritmos más utilizados para todo tipo de tareas. Su objetivo es localizar el índice de un elemento específico en un vector.

Existen diversos tipos de algoritmos, pero veremos dos:

* **Algoritmo de búsqueda secuencial o lineal:** muy sencillo pero poco eficiente.
* **Algoritmo de búsqueda binaria:** muy eficiente, requiere que el vector esté ordenado.

#### 5.1.1  Algoritmo de búsqueda secuencial

El objetivo de este algoritmo es recorrer el vector hasta encontrar el elemento buscado.

![Imagen 3.11](./resources/tema3-img11.gif)

- - -

##### Algoritmo 3.5 — búsqueda secuencial

> 😏 Este es un algoritmo muy importante: que lo entiendas es **fundamental**. Por eso, **¡intenta resolverlo tú primero!**

###### Pseudocódigo

~~~
recorrer las componentes del vector
    - hasta que se llegue al final del vector
    - hasta que encontremos el elemento a buscar
~~~

###### Código en C++. Versión 1: usando `while`

~~~ c++
vector<type> v(<tamaño>);
<type> buscado = <elemento_a_buscar>

int i = 0;
int indice_encontrado = -1;
bool encontrado = false;

while ( i < v.size() && !encontrado ) {
    if ( v[i] == buscado ) {
    	encontrado = true;
	indice_encontrado = i;
    } else
    	i++;
}
~~~

###### Código en C++. Versión 2: usando `for`

~~~ c++
vector<type> v(<tamaño>);
<type> buscado = <elemento_a_buscar>

int indice_encontrado = -1;
bool encontrado = false;

for ( int i = 0; i < v.size() && !encontrado; i++ ) {
    if ( v[i] == buscado ) {
    	encontrado = true;
	indice_encontrado = i;
    }
}
~~~

###### Casos clave a comprobar para este algoritmo

* Que el valor a buscar esté al principio.
* Que el valor a buscar esté en medio.
* Que el valor a buscar esté al final.
* Que el valor a buscar no se encuentre.
* Que el valor a buscar se encuentre varias veces.
* Que el vector esté vacío.
* Que el vector tenga un único componente.

- - -

#### 5.1.2  Algoritmo de búsqueda binaria

- - -

##### Algoritmo 3.6 — búsqueda binaria

> 😏 Este es un algoritmo muy importante: que lo entiendas es **fundamental**. Por eso, **¡intenta resolverlo tú primero!**

###### Pseudocódigo

~~~
comparamos el elemento a buscar con el elemento en el centro del vector
si coinciden, el elemento se ha encontrado
si es mayor que él, se repite el proceso con la mitad inferior
si es menor que él, se repite el proceso con la mitad superior
~~~

###### Código en C++

~~~ c++
vector<type> v(<tamaño>);
<type> buscado = <elemento_a_buscar>

int izquierda = 0;
int derecha = v.size() - 1;
int centro;
int indice_encontrado = -1;
bool encontrado = false;

while ( izquierda <= derecha && !encontrado ) {
    centro = (derecha - izquierda)/2;
    
    if ( v[centro] == buscado ) {
    	indice_encontrado = centro;
	encontrado = true;
    } else if ( buscado < v[centro] )
    	derecha = centro - 1;
    else
    	izquierda = centro + 1;
}
~~~

###### Casos clave a comprobar para este algoritmo

* Que el valor a buscar esté al principio.
* Que el valor a buscar esté en medio.
* Que el valor a buscar esté al final.
* Que el valor a buscar no se encuentre.
* Que el valor a buscar se encuentre varias veces.
* Que el vector esté vacío.
* Que el vector tenga un único componente.

- - -

#### 5.1.3  Otros algoritmos de búsqueda

- - -

##### Algoritmo 3.7 — búsqueda del máximo de un vector

> 😏 Este es un algoritmo muy importante: que lo entiendas es **fundamental**. Por eso, **¡intenta resolverlo tú primero!**

~~~ c++
vector<type> v(<tamaño>);
<type> buscado = <elemento_a_buscar>

int indice_maximo = -1;

if ( v.size() > 0 )
    indice_maximo = 0;

for ( int i = 0; i < v.size(); i++ )
    if ( v[i] >= v[indice_maximo] )
    	indice_maximo = i;
~~~

- - -

##### Algoritmo 3.8 — encontrar un vector dentro de otro

> 😏 Este es un algoritmo muy importante: que lo entiendas es **fundamental**. Por eso, **¡intenta resolverlo tú primero!**

~~~ c++
vector<type> v(<tamaño>);
<type> buscado = <elemento_a_buscar>

int indice_maximo = -1;

if ( v.size() > 0 )
    indice_maximo = 0;

for ( int i = 0; i < v.size(); i++ )
    if ( v[i] >= v[indice_maximo] )
    	indice_maximo = i;
~~~

- - -

### 5.2  Modificación de los elementos de un vector

#### 5.2.1  Inserción de un valor

- - -

##### Algoritmo 3.9 — inserción de un valor en un vector

> 😏 Este es un algoritmo muy importante: que lo entiendas es **fundamental**. Por eso, **¡intenta resolverlo tú primero!**

~~~ c++
vector<type> v(<tamaño>);
<type> buscado = <elemento_a_buscar>

<type> insertar_valor = <valor_a_insertar>;
int insertar_posicion = <posicion_a_insertar>;

vector<type> v_insertado;  // el vector a devolver

// parte izquierda del vector (antes de la posición en la que queremos insertar)
for ( int i = 0; i < insertar_posicion )
    v_insertado.push_back(v[i]);

// insertamos el elemento deseado, comprobando antes que la posición donde colocarlo es válida
if ( insertar_posicion <= v.size()
    v_insertado.push_back(insertar_valor);

// parte derecha del vector (completamos el vector)
for ( int i = insertar_posicion; i < v.size(); i++ )
    v_insertado.push_back(v[i]);

// opcionalmente podemos modificar v
v = v_insertado;
v_insertado.clear();  // para no desperdiciar memoria
~~~

- - -

#### 5.2.2  Eliminación de un valor

- - -

##### Algoritmo 3.10 — eliminación de un valor de un vector

> 😏 Este es un algoritmo muy importante: que lo entiendas es **fundamental**. Por eso, **¡intenta resolverlo tú primero!**

~~~ c++
vector<type> v(<tamaño>);
<type> buscado = <elemento_a_buscar>

<type> insertar_valor = <valor_a_insertar>;
int insertar_posicion = <posicion_a_insertar>;

vector<type> v_insertado;  // el vector a devolver

// parte izquierda del vector (antes de la posición en la que queremos insertar)
for ( int i = 0; i < insertar_posicion )
    v_insertado.push_back(v[i]);

// insertamos el elemento deseado, comprobando antes que la posición donde colocarlo es válida
if ( insertar_posicion <= v.size()
    v_insertado.push_back(insertar_valor);

// parte derecha del vector (completamos el vector)
for ( int i = insertar_posicion; i < v.size(); i++ )
    v_insertado.push_back(v[i]);

// opcionalmente podemos modificar v
v = v_insertado;
v_insertado.clear();  // para no desperdiciar memoria
~~~

- - -

### 5.3  Algoritmos de ordenación

#### 5.3.1  Ordenación por selección
#### 5.3.2  Ordenación por inserción
#### 5.3.3  Ordenación por intercambio directo (_método de la burbuja_)

- - -

## 6. Concepto de matriz
## 7. Vectores vs. arrays
