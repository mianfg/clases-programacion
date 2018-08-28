### Tema 4.  
# Modularización I: funciones

> **Clases de programación en C++** · agosto de 2018  
> Miguel Ángel Fernández Gutiérrez ([@mianfg](https://mianfg.bloomgogo.com))

- - -

## 👉 Tabla de contenidos

1. [Motivación al uso de funciones](#)
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

## 1. Motivación al uso de funciones

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

Hay, sin embargo, una sencilla solución para esto: _¡hacer uso de las **funciones**!_

- - -

## 2. Concepto de función

En programación, una **función** es una sección de un programa que realiza una tarea específica. En otras palabras, es una especie de procedimiento o rutina. En un programa, hay diversos bloques de código que pueden ser transformables en función. De este modo:

* **Reutilizamos el código, evitando errores:** basta comprobar si una función no tiene errores para asegurar que cualquier ocurrencia de esta función en el programa tampoco los tendrá.
* **Aumentamos la versatilidad de nuestro código:** llamar una función es mucho más sencillo que repetir código.

> ¡Nosotros ya hemos utilizado funciones! Ejemplos de éstas son las funciones de la biblioteca `cmath` como `sqrt()` o `pow()`, entre otras muchas.

### Definición de funciones

La estructura de una función es como sigue:

~~~ c++
<type> <nombre-función> (<parámetros>) {
    <sentencias>
    return <expresión>;  // si no es una función void
}
~~~

Las funciones se colocan (al menos así lo haremos hasta que no digamos lo contrario) entre la inclusión de bibliotecas y el `main()`. Además, en la declaración de una función hemos de distinguir los siguientes elementos:

* **Cabecera**: es la que contiene el **nombre** de la función, así como los **parámetros** y el **tipo** que devuelve:
~~~ c++
<type> <nombre-función> (<parámetros>);
~~~
*  **Cuerpo**: entre llaves, contiene las **sentencias** de la función y el **valor de retorno**.
~~~ c++
<sentencias>
return <expresión>;
~~~

- - -

## 3. Paso de parámetros a una función

Una vez vista las partes que componen una función, vamos a detallar cada una de ellas. Comenzaremos por los **parámetros**.

Cuando pasamos parámetros a una función:
* Especificamos su **tipo**: C++ debe saber qué parámetros se pasan a una función. Es posible que se realicen conversiones (pasar un `int` a un `double` y viceversa, como ejemplo).
Definimos un **nombre de variable** para cada parámetro, que es el que usaremos para hacer referencia a éstos en las sentencias.

Por tanto, la cabecera o header de la función quedaría:

~~~ c++
<type> <nombre-función> (<type_1> <param_1>, ..., <type_n> <param_n>);
~~~

Sin embargo, hay diversas formas de pasar estos parámetros:
* Paso por **copia**.
* Paso por **copia constante**.
* Paso por **referencia**.
* Paso por **referencia constante**.

- - -

### 3.1 Paso por copia

Es el paso por “defecto”. Cuando declaramos los parámetros por copia (de la forma anteriormente mencionada):

* Se crea una **nueva variable**, con una copia del valor pasado a la función. Es decir, al modificar la variable en la función, **no se modifica la variable original** (la pasada a la función).
* Esta nueva variable es **local a la función**, es decir, es **inaccesible desde fuera de la función**.
* No importa que la variable pasada sea originalmente `const` o no.

- - -

### 3.2 Paso por copia constante

Basta añadir el nombre `const` delante del tipo del parámetro que queremos que se pase de forma constante.

* Se crea una **nueva variable**, con una copia del valor pasado a la función, al igual que en el paso por copia no constante.
* Además, esta nueva variable **no es modificable**.
* Esta nueva variable es también **local a la función**.
* Tampoco importa que la variable pasada originalmente sea `const` o no.

- - -

### 3.3 Paso por referencia

Basta añadir el nombre `&` entre el tipo y el nombre de variable del parámetro que queremos que se pase por referencia.

* En este caso **no se crea** una nueva variable. Por tanto, si modificamos el valor de la variable en la función, **también se modifica el valor de la variable para todo el programa**.
* Hay que tener cuidado si pasamos variables que originalmente sean `const`, pues si en nuestra función se modifica la variable, y al pasar dicha variable al llamar a la función ésta es `const`, tendremos un error en tiempo de ejecución.

- - -

### 3.4 Paso por referencia constante

Basta añadir el nombre `const`, luego el tipo, el nombre `&` y finalmente el nombre de variable del parámetro que queremos que se pase.

* En este caso **no se crea una nueva variable**. Es decir, **no se desperdicia memoria en realizar una copia**.
* Sin embargo, la variable **no puede ser modificada dentro de la función**, independientemente de si la variable es originalmente `const` o no.
* Es ideal para funciones donde se toman datos de entrada que no son modificados: hacen nuestro programa **más eficiente**.

- - -

## 4. Devolución de valores en una función

En la cabecera de la función hay una parte fundamental: el **tipo** de la función. Cuando hacemos una función, hemos de decir qué es lo que vamos a devolver.

<type> <nombre-función> (<type_1> <param_1>, ..., <type_n> <param_n>);

Una función puede ser:
- De **tipo `void`**: no devuelve nada (sin `return`).
- De **tipo no `void`**: devuelve un dato (con `return`).

- - -

### 4.1  Funciones `void`

Son funciones que no devuelven nada. Basta declararlas de tipo `void`.

* Este tipo de funciones **no tienen `return`**.
* El paso de parámetros es exactamente igual que el explicado anteriormente.

- - -

### 4.2  Funciones no `void`

Son funciones que devuelven **un único dato**, de un **tipo específico**. Basta declarar el tipo de dato que devolverá la función en la cabecera de ésta.

* Este tipo de funciones **tienen `return`**. En él, se especifica qué se va a devolver, del tipo `return <expresión>;`.
    > **MUY IMPORTANTE:** `<expresión>` debe ser un dato del tipo especificado a devolver, o una expresión que tenga como resultado dicho tipo de dato.
* Podemos **devolver cualquier tipo de dato**: `int`, `bool`, `double`, `char`, …, incluso vectores de cualquier tipo.
