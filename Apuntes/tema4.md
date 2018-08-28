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
4. [Devolución de valores en una función](#)  
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

![Imagen 4.1](./resources/tema4-img1.png)

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

### Llamada a funciones

Llamar a una función es tan sencillo como hacer:

~~~ c++
<nombre-función>(<parámetros>);
~~~

Es posible que haya funciones que no tengan parámetros, en cuyo caso se dejan los paréntesis. Veremos más adelante un ejemplo de ello.

- - -

##### Ejemplo X. Declaración y llamada a una función: días desde fecha hasta hoy

Vamos a inventarnos una función. No la implementaremos, sencillamente la declararemos y veremos cómo se llamaría a ella.

Supongamos que creamos una función `diasHasta`, a la que pasamos una fecha y nos devuelve el número de días que han pasado desde esa fecha hasta hoy. Si la fecha es futura, devolverá un valor de días negativo.

Planteemos cómo definiríamos esta función:

~~~ c++
int diasHasta(int dia, int mes, int anio) {
    ...
}
~~~

No te preocupes si no entiendes los parámetros leyendo hasta aquí, o el tipo. En el [apartado 3](#here) y en el [apartado 4](#here) tienes toda la información al respecto. Léelos y lugo vuelve aquí para entenderlo.

Simplemente, observa cómo la declaración de esta función coincide con la "plantilla" que hemos especificado.

Si queremos ahora llamar a esta función, podríamos utilizar este código:

~~~ c++
int dia, mes, anio;
cout << "Inserte fecha: ";
cin >> dia >> mes >> anio;
cout << "Días desde esa fecha hasta hoy: " << diasHasta(dia, mes, anio) << endl;
~~~

Observa cómo es muy sencillo llamar a la función. De hecho, podemos llamar a la función todas las veces que la necesitemos: ***¡no hay límite!** (aunque recomendemos que dejes respirar a tu ordenador de vez en cuando...)*.

Como último apunte respecto a este ejemplo, es posible que te hayas dado cuenta que hemos utilizado los mismos nombres de variable que en la declaración de la función. Esto **no es obligatorio**. Puedes llamar a la función **desde las variables que quieras con los nombres que quieras, siempre que se ajusten a la plantilla de la declaración**. Por ejemplo, si hemos definido una función del tipo

~~~c++
void unaFuncionCualquiera(int a, char b, bool c);
~~~

debemos llamarla con un `int`, un `char` y un `bool`, **en ese orden**, e **independientemente del nombre de dichas variables**. Si cambiamos el orden, es posible que el compilador realice conversiones de forma nativa, o que haya errores de compilación y/o ejecución.

- - -

##### Ejemplo X. Una función que te da los buenos días (sin importar si es de noche)

Este ejemplo es un tanto indiferente, pero lo ponemos aquí para ilustrar que existen funciones sin parámetros. A continuación implementaremos la función `buenosDias`, que nos da los buenos días:

~~~ c++
void buenosDias() {
    cout << "¡¡Buenos días!! :)" << endl;
}
~~~

Para hacer uso de esta función, la llamamos del siguiente modo:

~~~ c++
buenosDias();
~~~

De este modo, se mostrará en pantalla la frase `¡¡Buenos días!! :)` seguida de un salto de línea. _¡Quién ha dicho que los programas no podían ser educados! ;)_

- - -

## 3. Paso de parámetros a una función

Una vez vista las partes que componen una función, vamos a detallar cada una de ellas. Comenzaremos por los **parámetros**.

Cuando pasamos parámetros a una función:
* Especificamos su **tipo**: C++ debe saber qué parámetros se pasan a una función. Es posible que se realicen conversiones (pasar un `int` a un `double` y viceversa, como ejemplo).
* Definimos un **nombre de variable** para cada parámetro, que es el que usaremos para hacer referencia a éstos en las sentencias.

Por tanto, la cabecera o ___header___ de la función quedaría:

![Imagen 4.2](./resources/tema4-img2.png)

Sin embargo, hay diversas formas de pasar estos parámetros:
* Paso por **copia**.
* Paso por **copia constante**.
* Paso por **referencia**.
* Paso por **referencia constante**.

### 3.1 Paso por copia

![Imagen 4.3](./resources/tema4-img3.png)

Es el paso por “defecto”. Cuando declaramos los parámetros por copia (de la forma anteriormente mencionada):

* Se crea una **nueva variable**, con una copia del valor pasado a la función. Es decir, al modificar la variable en la función, **no se modifica la variable original** (la pasada a la función).
* Esta nueva variable es **local a la función**, es decir, es **inaccesible desde fuera de la función**.
* No importa que la variable pasada sea originalmente `const` o no.

### 3.2 Paso por copia constante

![Imagen 4.4](./resources/tema4-img4.png)

Basta añadir el nombre `const` delante del tipo del parámetro que queremos que se pase de forma constante.

* Se crea una **nueva variable**, con una copia del valor pasado a la función, al igual que en el paso por copia no constante.
* Además, esta nueva variable **no es modificable**.
* Esta nueva variable es también **local a la función**.
* Tampoco importa que la variable pasada originalmente sea `const` o no.

### 3.3 Paso por referencia

![Imagen 4.5](./resources/tema4-img5.png)

Basta añadir el nombre `&` entre el tipo y el nombre de variable del parámetro que queremos que se pase por referencia.

* En este caso **no se crea** una nueva variable. Por tanto, si modificamos el valor de la variable en la función, **también se modifica el valor de la variable para todo el programa**.
* Hay que tener cuidado si pasamos variables que originalmente sean `const`, pues si en nuestra función se modifica la variable, y al pasar dicha variable al llamar a la función ésta es `const`, tendremos un error en tiempo de ejecución.

### 3.4 Paso por referencia constante

![Imagen 4.6](./resources/tema4-img6.png)

Basta añadir el nombre `const`, luego el tipo, el nombre `&` y finalmente el nombre de variable del parámetro que queremos que se pase.

* En este caso **no se crea una nueva variable**. Es decir, **no se desperdicia memoria en realizar una copia**.
* Sin embargo, la variable **no puede ser modificada dentro de la función**, independientemente de si la variable es originalmente `const` o no.
* Es ideal para funciones donde se toman datos de entrada que no son modificados: hacen nuestro programa **más eficiente**.

- - -

## 4. Devolución de valores en una función

En la cabecera de la función hay una parte fundamental: el **tipo** de la función. Cuando hacemos una función, hemos de decir qué es lo que vamos a devolver.

![Imagen 4.7](./resources/tema4-img7.png)

Una función puede ser:
- De **tipo `void`**: no devuelve nada (sin `return`).
- De **tipo no `void`**: devuelve un dato (con `return`).

### 4.1  Funciones `void`

Son funciones que no devuelven nada. Basta declararlas de tipo `void`.

* Este tipo de funciones **no tienen `return`**.
* El paso de parámetros es exactamente igual que el explicado anteriormente.

- - -

##### Ejemplo X. Función `void`: comprobación de si un número es par o impar por salida estándar

Resolveremos el problema con el que hemos motivado el uso a las funciones. Planteemos qué elementos necesita la función, y cómo la definiremos:

* **Nombre de la función**: debe ser descriptivo, diremos que es `esPar`.
* **Tipo que devuelve la función**: se trata de una función `void`.
* **Parámetros que se pasan a la función**: debemos pasar un número, que llamaremos `num`. Lo pasaremos **por copia constante**. Para decidir cómo pasarlo, hemos pensado antes en lo siguiente:
    * No queremos modificarlo, por eso será un paso **constante**.
    * Al tratarse de un `int`, es indiferente si lo pasamos por copia o no, pues ocupan muy poco espacio (si se tratase de un vector, por ejemplo, sería bastante necesario pasarlo por referencia). Por eso lo pasaremos **por copia**.

La función quedaría, de este modo, así:

~~~ c++
void esPar( const int num ) {
    if ( num % 2 == 0 )
        cout << num << " es par" << endl;
    else
        cout << num << " es impar" << endl;
}
~~~

- - -

### 4.2  Funciones no `void`

Son funciones que devuelven **un único dato**, de un **tipo específico**. Basta declarar el tipo de dato que devolverá la función en la cabecera de ésta.

* Este tipo de funciones **tienen `return`**. En él, se especifica qué se va a devolver, del tipo `return <expresión>;`.
    > **MUY IMPORTANTE:** `<expresión>` debe ser un dato del tipo especificado a devolver, o una expresión que tenga como resultado dicho tipo de dato.
* Podemos **devolver cualquier tipo de dato**: `int`, `bool`, `double`, `char`, …, incluso vectores de cualquier tipo.
* Una función no `void` **siempre debe devolver algo**.

- - -

##### Ejemplo X. Función no `void`: comprobación de si un vector está ordenado (con error)

Haremos un programa para comprobar si un vector está ordenado. Para ello, crearemos la función `estaOrdenado`, al que se le pasa un vector `v`. La función devolverá un valor `bool`, que dirá si dicho vector está o no ordenado.

Planteemos qué elementos necesita la función, y cómo la definiremos:

* **Nombre de la función**: debe ser descriptivo, diremos que es `estaOrdenado`.
* **Tipo que devuelve la función**: un valor `bool`, correspondiente a si el vector está ordenado (`true`) o no (`false`).
* **Parámetros que se pasan a la función**:
    * Debemos pasar un vector. Por tanto, sólo nos hace falta un parámetro. Haremos que el vector se pase **por referencia constante**, para no tener que crear una copia del vector (así agilizamos y optimizamos nuestro programa). Esto se hace definiendo dicho parámetro como `const vector<int> & v`.

Una posible solución es, por tanto:

~~~ c++
bool estaOrdenado( const vector<int> & v ) {
    for ( int i = 0; i < v.size() - 1; i++ )
        if ( v[i+1] < v[i] )
            return false;
}
~~~

Sin embargo, **esta solución es completamente errónea**. Recordemos que en una función no `void`, **siempre ha de devolverse algo**. En este caso, tenemos un `return false` únicamente para cuando encontremos que la función no está ordenada, por lo que en caso de que el vector esté ordenado, la función no devolvería nada. Esto es un **grave error** que solucionaremos a continuación.

- - -

##### Ejemplo X. Función no `void`: comprobación de si un vector está ordenado (arreglado)

Modificaremos el código del ejemplo anterior teniendo en cuenta estas dos consideraciones:

1. Al tratarse de una función no `void`, **siempre ha de devolver algo**. Para ello insertaremos una variable local de tipo `bool`, llamada `ordenado`. La modificaremos en nuestro código y la devolveremos al final.
2. Si encontramos al recorrer el vector dos elementos que no estén en orden, no bastará seguir recorriendo el vector. Para ello, incorporaremos una condición extra a nuestro `for`.

El código correcto, por tanto, sería:

~~~ c++
bool estaOrdenado( const vector<int> & v ) {
    bool ordenado = true;
    for ( int i = 0; i < v.size() - 1 && ordenado; i++ )
        if ( v[i+1] < v[i] )
            ordenado = false;
    return ordenado;
}
~~~

- - -

##### Ejemplo X. Función no `void`: comprobación de si un vector está ordenado (alternativo)

Finalmente, haremos una matización sobre funciones no `void`: podemos incluir en una función **tantos `return` como sea necesario**. La función dejará de ejecutarse en cuanto se encuentre el primer `return`.

Por tanto el código anterior es completamente equivalente a:

~~~ c++
bool estaOrdenado( const vector<int> & v ) {
    for ( int i = 0; i < v.size() - 1 && ordenado; i++ )
        if ( v[i+1] < v[i] )
            return false;
    return true;
}
~~~

De hecho, ten en cuenta que si encontramos dos elementos en orden no creciente, al hacer `return false` también salimos del `for`, haciendo exactamente el mismo propósito que la condición compuesta en el ejemplo anterior.

- - -

## 7. Diseño de funciones: precondiciones y documentación

Una **precondición** es toda aquella restricción que deben satisfacer los parámetros para que la función pueda ejecutarse sin problemas. Hay dos alternativas:

* Comprobar dentro de la función si se satisfacen estas precondiciones, pudiendo lanzar un mensaje de error.
* Decir al usuario que la función se comporta de forma certera si satisface ciertas precondiciones (_disclaimer_ o exención de responsabilidad), y es él mismo el que debe comprobarlo.

- - -

##### Ejemplo X. Función con precondición: factorial de un número

Vamos a programar una función que devuelve el factorial de un número. Como es usual, describiremos sus elementos antes de implementarla:

* **Nombre de la función**: `factorial`.
* **Tipo que devuelve la función**: un valor `int`, correspondiente al factorial de `num`.
* **Parámetros que se pasan a la función**:
    * `int num`: pasamos un número entero por copia, no constante.

Lo interesante de esta función es que [la definición de la operación factorial](https://es.wikipedia.org/wiki/Factorial) sólo nos permite calcular el factorial de un **número entero positivo (incluyendo el cero)**: aquí está nuestra **precondición**.

Podríamos hacer muchas cosas para lidiar con este problema. Nosotros nos reduciremos a advertir al usuario de que nuestra función calcula el factorial de números positivos (incluyendo el cero), pero... ¿y si nos da un número entero negativo? ¡Siempre tenemos que devolver algo! Tomaremos como solución una muy frecuente: devolveremos el número `-1`. Si el programador advierte este número, sabrá que algo no ha ido bien.

~~~ c++
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
~~~

> **Nota:** hay implementaciones más obvias que esta. Sin embargo, lo he hecho así para explicar un punto bastante importante, a continuación.

Un aspecto interesante de esta función es que dentro de ella hemos modificado `num`. Pero recuerda: ¡no hay problema alguno porque `num` es realmente una copia de la variable que hemos pasado! Por tanto, al devolver `num` al acabar la función, estamos copiando el valor de esta variable local en el valor de retorno de la función. ¡Y todos contentos!

- - -

En la especificación de nuestro código, una de las partes imprescindibles es la **documentación**, que describe qué tarea realiza la función.

Es muy útil para que otros programadores sepan qué es lo que hace nuestra función, qué papel cumple cada uno de los parámetros, qué es lo que se devuelve… Aquí también incluimos una descripción de las **precondiciones**.

Existe un estándar para la documentación de funciones, que es el que se utiliza para generar documentación de forma automática (utilizando programas como [Doxygen](#here)). A continuación, veremos cómo documentar nuestro [ejemplo anterior](#here).

- - -

##### Ejemplo X. Documentando la función `factorial()`

Todas las documentaciones siguen la siguiente plantilla:

~~~ c++
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
~~~

Nótese que:
* La documentación de una función es un comentario largo cualquiera (`/* ... */`), en el que la apertura del comentario tiene un asterisco extra, es decir, es un comentario largo de la forma `/** ... */`.
* En el interior del comentario de documentación se insertan:
    * **`@brief <descripción de la función>`:** describe qué hace la función. Sólo hay uno por función.
    * **`@param <var> <descripción de var>`:** describe qué cometido tiene el parámetro `var` en la función. Hay uno por cada parámetro.
    * **`@return <descripción del return>`:** describe qué devuelve la función. Sólo hay uno por función, y sólo en caso de que la función sea no `void`.
    * **`@precond <precondición>`:** describe las precondiciones de la función. Puede haber ninguna, una o varias precondiciones.

- - -
