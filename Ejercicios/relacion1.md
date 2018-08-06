# Relación 1.  
# "Hello world". Introducción a la programación en C++

> **Clases de programación en C++** · agosto de 2018  
> Miguel Ángel Fernández Gutiérrez ([@mianfg](https://mianfg.bloomgogo.com))

## Ejercicios

### Tipos de dato `int`, `float` y `double`

La resolución de estos ejercicios no necesita de conocimientos adicionales.

##### Ejercicio 1.1. Expresiones simples

A continuación, te presentamos un programa que evalúa varias expresiones. Intenta averiguar la salida sin ejecutarlo.

~~~ c++
#include <iostream>
using namespace std;

int main() {
    cout << "3+5/4= " << 3+5/4 << endl;
    cout << "(3+5)/4= " << (3+5)/4 << endl;
    cout << "3+5.0/4= " << 3+5.0/4 << endl;
    cout << "3/4∗4.0= " << 3/4∗4.0 << endl;
    cout << "3∗4/3= " << 3∗4/3 << endl;
    cout << "3/4.0∗4.0= " << 3/4.0∗4.0 << endl;
}
~~~

##### Ejercicio 1.2. Parte entera de un número real

Escribe un programa que lea un número real y escriba la parte entera de éste.

### Biblioteca de funciones matemáticas. Errores de aproximación

Para realizar algunos de los siguientes ejercicios, deberás saber utilizar la biblioteca `cmath`. Algunas de las funciones más  interesantes son:

- `sin(x)`, que devuelve el seno de `x`, en radianes.
- `sqrt(x)`, que devuelve la raíz cuadrada de `x`.
- `pow(a, b)`, que devuelve la `b`-ésima potencia de `a`, _a^b_.

##### Ejercicio 1.3. Radio de un círculo

Escribe un programa que sea capaz de obtener el radio de un círculo a partir de la superficie que abarca.

##### Ejercicio 1.4. Cálculo de diferencia en céntimos

Consideraremos el siguiente programa para calcular el número de céntimos a devolver dados el precio y el dinero entregado en euros. Comente la razón del resultado erróneo que obtendrá.

~~~ c++
#include <iostream> // cout, cin, endl
using namespace std;

int main() {
    double precio,entregado;
    cout << "Precio y entregado en euros: ";
    cin >> precio >> entregado;
    int centimos= 100∗(entregado−precio);
    cout << "Vuelta: " << centimos << endl;
}
~~~

### Tipo `char`. Entrada/salida con `cin` y `cout`

Para realizar algunos de los siguientes ejercicios, deberás saber utilizar las siguientes funciones para tipos carácter (`char`), implementadas en `cctype`:

- `isdigit(var)`, que devuelve si `var` es o no un dígito decimal.
- `islower(var)`, que devuelve si `var` es o no minúscula.
- `toupper(var)`, que devuelve la mayúscula que le corresponde a `var`.

##### Ejercicio 1.5. Lectura de enteros y caracteres

Escriba un programa que lea un entero y escriba el valor leído. Ejecútelo con un entero de varios dígitos, como `123`. Una vez
realizado, cambie el tipo de la variable a `char` y vuelva a ejecutarlo con la misma entrada. Una vez comprobado el resultado, declare tres caracteres y lea/escriba los tres datos.

#### Caracteres ASCII

Como hemos visto, al declarar un `char` declaramos un carácter. Este carácter está codificado en **ASCII**, uno de los primeros estándares de codificación. La historia tras el ASCII es muy interesante, pero ahora nos centraremos en lo útil para C++.

El ASCII que utiliza C++ para el tipo de dato char es el llamado **ASCII extendido**, que codifica un total de 256 caracteres (8 bits, 1 byte), como vemos en la tabla siguiente:

![Tabla de caracteres ASCII extendido](https://theasciicode.com.ar/american-standard-code-information-interchange/ascii-codes-table.png)

> **Pensemos un poco:** Basados en la tabla anterior, ¿cuántos bits ocupa un `char`? ¿Y cuántos bytes?

##### Ejercicio 1.6. Caracteres y código ASCII asociado

Escriba un programa que lea un carácter —en una variable de tipo char— y escriba en una línea `cout<<` el resultado de sumar 1 a dicho carácter. Compruebe el comportamiento para varias entradas (pruebe, por ejemplo, con alguna letra, minúscula y mayúscula y algún dígito
numérico). Una vez comprobado, asegúrese de asignar el valor de esa suma a otra variable de tipo `char`, y escriba el contenido de dicha variable. ¿Qué podemos concluir?

### Conversiones explícitas
Como hemos podido comprobar, cuando mezclamos distintos tipos de datos en una expresión, el compilador se encarga de analizarla y, en el caso de combinar distintos tipos, realizar las conversiones que sean necesarias. Estas conversiones se denominan **implícitas**, ya que se sobrentienden, y por ello las realiza el compilador de forma
automática. Hasta ahora, siempre hemos considerado las conversiones como una tarea que realiza de forma automática el compilador. Sin embargo, es posible hacer una conversión explícita, es decir, indicar al compilador que queremos que convierta el valor de una expresión a un determinado tipo. En este caso, diremos que hacemos un casting (moldeado). La forma más simple de hacer un casting es escribiendo:

~~~
(TIPO) EXPRESION
~~~

donde `TIPO` es el tipo al que queremos convertir la `EXPRESION`. Por ejemplo, si deseamos escribir la parte entera de un valor real, podemos hacer:

~~~ c++
#include <iostream>
using namespace std;
int main() {
double x;
cout << “Escriba un número con decimales: ”;
cin >> x;
cout << “Parte entera: ” << (int) x << endl;
}
~~~

Compara esto con cómo realizaste el [ejercicio 1.2](#ejercicio-12-parte-entera-de-un-n%C3%BAmero-real): en él (probablemente) utilizaste el casting implícito. En este caso, lo hemos especificado.

Tenga en cuenta que el casting es otro operador y que tiene una prioridad alta, ya que está al nivel de los operadores unarios. Si tiene alguna duda, deberá poner la expresión entre paréntesis.

El operador de moldeado que hemos explicado es el que se usa en el lenguaje C, y que también está disponible en C++. Sin embargo, en C++ se incorporan nuevos operadores que son más seguros, ya que se diversifica con distintos tipos de casting de forma que el compilador conozca mejor nuestras intenciones.

Aunque hay varios, simplemente comentaremos la sintaxis del único que usaremos en esta introducción a la programación:

~~~ c++
static_cast<TIPO> (EXPRESION)
~~~

que convierte el valor resultante de la `EXPRESION` al tipo `TIPO`.

En el [ejercicio 1.7](#ejercicio-17-caracteres-y-n%C3%BAmero-ascii-asociado), trabajaremos la conversión de tipos entre `char` e `int` (bidireccional).

##### Ejercicio 1.7. Caracteres y número ASCII asociado

Escriba un programa que reciba como entrada un número del 0 al 25. Como resultado deberá escribir la letra (el 0 indica la ‘a’ y el 25 la ‘z’), su correspondiente mayúscula y los dos valores ASCII correspondientes, habiendo declarado únicamente un objeto de tipo `int`.

### Expresiones complejas

##### Ejercicio 1.8. Expresiones complejas

Evalúe el siguiente código sin ejecutarlo:

~~~ c++
#include <iostream>
using namespace std;

int a=1, b=2, c=3, d=4, e=5;
int res = 10;
res += (a++∗b)+((c=d)∗−−e);
cout << res << ’ ’ << a << ’ ’ << b << ’ ’ << c << ’ ’
     << d << ’ ’ << e << endl;
~~~

Modifique el programa para eliminar la asignación compuesta, la asignación como subexpresión, y los incrementos/decrementos, obteniendo el mismo resultado. Ejecute para comprobar que es correcto.

## Relación de ejercicios

##### Ejercicio 1.9

Escriba un programa que calcule el resultado de la división 5/0. Compruebe la ventana de errores de compilación, así como el resultado de ejecutarlo. Considere el uso de literales de tipo `int` y de tipo `double` y observe la diferencia.

##### Ejercicio 1.10

Lectura de tres valores desde el teclado y salida de dos valores: la media aritmética y la desviación estándar. Las expresiones son las siguientes:

~~~
x̅ = (x1 + x2 + x3) / 3
σ = √(((x1 − x̅)^2 + (x2 − x̅)^2 + (x3 − x̅)^2)/3)
~~~

##### Ejercicio 1.11

Escriba un programa para convertir los grados decimales a grados, minutos y segundos. Recuerde que un grado son 60 minutos y un minuto son 60 segundos.

Por ejemplo, si escribimos como entrada `34.567`, deberá obtener en la salida `34º 34’ 1.2”`.

##### Ejercicio 1.12

Compruebe algunos errores de compilación arreglándolos uno a uno y
recompilando el siguiente programa:

~~~c++
#include <ciotream> // cout, cin, endl
#include <cmath> // sqrt

int main() {
    double 1cateto;
double 2cateto;
    cout << "Introduzca el cateto 1: ";
    cin << cateto1;
    cout << "Introduzca el cateto 2:;
    cin >> cateto2;
    double hipotenusa= sqroot(cateto1 cateto1+cateto2 cateto2);
    cout << "La hipotenusa vale: " << hipotenusa << endl;
}
~~~

##### Ejercicio 1.13

Escriba un programa que lea tres valores enteros por la entrada estándar y que los almacene en tres variables `x`, `y`, `z`. A continuación el programa procederá a rotar dichos valores colocando el valor de `x` en `y`, el de `y` en `z` y el de `z` en `x`. Finalmente el programa mostrará los nuevos valores de `x`, `y`, `z`.

##### Ejercicio 1.14. Operador `? :`

Escriba un programa que lea una letra por la entrada estándar y que muestre su correspondiente mayúscula. Si lo que escribió el usuario ya era una mayúscula o no era una letra, mostrará el mismo carácter. Busque información sobre el operador ternario `? :` para resolver este ejercicio.

##### Ejercicio 1.15

Escriba un programa que lea en una variable de tipo `int` un valor entero de 3 dígitos. A continuación el programa mostrará los 3 dígitos del número: uno en cada línea.
