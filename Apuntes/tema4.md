### Tema 4.  
# Modularización I: funciones

> **Clases de programación en C++** · agosto de 2018  
> Miguel Ángel Fernández Gutiérrez ([@mianfg](https://mianfg.bloomgogo.com))

- - -

## 👉 Tabla de contenidos

1. [Motivación al uso de funciones. Concepto de modularización y reutilización de código](#)
2. [Concepto de función](#)
3. [Paso de parámetros a una función](#)  
    3.1 [Paso de parámetros por copia](#)  
    3.2 [Paso de parámetros por copia constante](#)  
    3.3 [Paso de parámetros por referencia](#)  
    3.4 [Paso de parámetros por referencia constante](#)  
4. [Devolución de valores de una función](#)  
    4.1 [Funciones `void`](#)  
    4.2 [Funciones no `void`](#)  
5. [Valores por defecto y sobrecarga](#)  
6. [Diseño de funciones: los _disclaimer_](#)  
7. [Funciones recursivas](#)  
    7.1 [Caso general y caso base](#)  
    7.2 [Funciones recursivas con varios puntos de salida](#)  
    7.3 [Múltiples casos base y/o generales](#)

##### Ejemplos

...

- - -

## 1. Motivación al uso de funciones. Concepto de modularización y reutilización de código

Retomemos uno de los primeros problemas que nos planteamos al comenzar este curso: comprobar si un número es par o impar. Crearemos un programa que nos muestre por salida estándar si el número es par o impar.

El programa, recordemos, es bastante sencillo. Si el número es `num`, bastaría hacer:

~~~ c++
if ( num % 2 == 0 )
    cout << num << " es par" << endl;
else
    cout << num << " es impar" << endl;
~~~

- - -

Pongamos que queremos comprobar si los elementos de un vector `v` de tipo `int` son pares o impares. Podríamos hacer esto:

~~~ c++
for ( int i = 0; i < v.size(); i++ )
    if ( v[i] % 2 == 0 )
        cout << v[i] << " es par" << endl;
    else
        cout << v[i] << " es impar" << endl;
~~~

Nótese cómo:

* Hemos repetido el código anterior: si quisiésemos utilizar de nuevo este "programita", deberíamos escribirlo completamente. Además, esto puede inducir a error.
* Hemos tenido que modificar el nombre de la variable de `num` a `v[i]`, para recontextualizarlo.

Hay, sin embargo, una sencilla solución para esto: hacer uso de las **funciones**.

- - -

## 2. Concepto de función

En programación, una **función** es una sección de un programa que realiza una tarea específica. En otras palabras, es una especie de procedimiento o rutina. En un programa, hay diversos bloques de código que pueden ser transformables en función. De este modo:

* Reutilizamos el código, evitando errores: basta comprobar si una función no tiene errores para asegurar que cualquier ocurrencia de esta función en el programa tampoco los tendrá.
* Son versátiles: llamar una función es mucho más sencillo que repetir código.

> ¡Nosotros ya hemos utilizado funciones! Ejemplos de éstas son las funciones de la biblioteca `cmath` como `sqrt()` o `pow()`, entre otras muchas.

### Definición de funciones

La estructura de una función es como sigue:

~~~ c++
<type> <nombre-función> (<parámetros>) {
    <sentencias>
    return <expresión>;  // si no es una función void
}
~~~


Queremos crear un programa que compruebe si un vector está ordenado o no.

La solución es bastante sencilla: queremos comprobar si el vector `v`, de tipo `type` (con relación de orden) está ordenado.

~~~ c++
bool ordenado = true;
for ( int i = 0; i < v.size() - 1 && ordenado; i++ )
    if ( v[i] > v[i+1] )
        ordenado = false;
~~~

Tras ejecutar este código, `ordenado` tendrá el valor `true` si el vector `v` está ordenado, y `false` en caso contrario.

- - -

Supongamos ahora que tenemos un vector de vectores `vv`, del mismo tipo que `v`, y queremos comprobar si los vectores que se encuentran dentro están orde
