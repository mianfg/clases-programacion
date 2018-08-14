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

### 2.1  Las estructuras `if` e `if`/`else`

#### Cuerpo básico de una estructura `if`/`else`

~~~ c++
if (<condición>) {
    <instrucciones_v>
} else {
    <instrucciones_f>
}
~~~

- - -

##### Ejemplo 2.1 — comprobar si un número es par

~~~ c++
int num;

cout << "Introduce entero: ";
cin >> num;

if ( num % 2 == 0 )
    cout << num << " es par\n";
else
    cout << num << " es impar\n";
~~~

- - -

##### Ejemplo 2.2 — comprobar si un número es par (versión modificada)

_¿Cuál es la diferencia entre este ejemplo y el anterior? ¿Qué ocurriría si intentásemos comprobar la divisibilidad por otros números?_

~~~ c++
int num;

cout << "Introduce entero: ";
cin >> num;

if ( num % 2 == 0 )
    cout << num << " es par\n";
if ( num % 2 != 0 )
    cout << num << " es impar\n";
~~~

- - -

### 2.2  Condiciones compuestas: operadores lógicos

~~~ c++
if (<condición_1>) {
    <instrucciones_1>
} else if (<condición_2>) {
    <instrucciones_2>
} ... {
    ...
} else {
    <instrucciones_f>
}
~~~

Esta estructura es similar a la anterior, pero evalúa los `if`s de la siguiente manera: si se cumple la primera condición, evalúa su cuerpo, si no, comprueba si se cumple la segunda, y así sucesivamente hasta ejecutar el cuerpo del `else` en caso de que no se cumpla ninguna de las anteriores.

En `<condición>`, debemos insertar una **expresión lógica**. Las expresiones lógicas son construcciones con **operadores lógicos** (aunque también pueden incluir otros operadores).

> Los operadores lógicos fueron vistos en el bloque anterior.

El resultado de una expresión lógica es un valor booleano (`true` o `false`). Cuando el programa encuentra un `if`, evalúa la condición y ejecuta su cuerpo si el resultado es `true`.

- - -

##### Ejemplo 2.3 — comprobaciones de divisibilidad

~~~ c++
... // código para leer num por entrada estándar

if ( num % 2 == 0 )
    cout << num << "es múltiplo de 2\n";
else if ( num % 4 == 0 )
    cout << num << "es múltiplo de 4\n";
else if ( num % 5 == 0 )
    cout << num << "es múltiplo de 5\n";
else
    cout << num << "es un número :)\n";
~~~

_¿Qué mostrará este código si..._
- _`num` es múltiplo de 2?_
- _`num` es múltiplo de 5?_
- _`num` es múltiplo de 4?_
- _`num` es múltiplo de 2 y no de 4?_
- _`num` no es múltiplo de 2, ni de 4, ni de 5?_

- - -

### 2.3  La estructura de bifurcación `switch`



| Imagen | Función | Descripción |
| --- | --- | --- |
| ![Imagen 3.8](./resources/tema3-img8.png) | `v.push_back(x)` | Inserta al vector el elemento `x` al final de éste. 
