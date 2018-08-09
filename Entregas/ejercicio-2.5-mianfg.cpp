/*
 *  EJERCICIO 2.5 - Rectángulo
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 9 agosto, 2018
 */

#include <iostream>

using namespace std;

int main() {
	/*
	 *  Las variables son:
	 *     A(x1, x2) y B(y1, y2) definen el rectángulo
	 *     P(Px, Py) es el punto que queremos comprobar si está en su interior
	 */
	
	double x1, x2, y1, y2, Px, Py;
	cout << "Inserte las coordenadas de los puntos siguientes en el mismo orden:" << endl
		<< "    x1 x2 y1 y2 son las coordenadas de los puntos que definen el rectangulo" << endl
		<< "    Px y Py son las coordenadas de P y queremos comprobar si esta en el" << endl;
	cin >> x1 >> x2 >> y1 >> y2 >> Px >> Py;
	
	double aux;
	// reordenamos para que las coordenadas de A sean menores que las coordenadas de B
	if (x1 > y1) {
		aux = x1;
		x1 = y1;
		y1 = aux;
	}
	if (x2 > y2) {
		aux = x2;
		x2 = y2;
		y2 = aux;
	}

	if (((x1 < Px) && (Px < y1))  &&  ((x2 < Py) && (Py < y2))) {
		cout << "El punto esta contenido en el rectangulo";
	} else if (((Px < x1) || (Py < y1))  ||  ((Px > x2) || (Py > y2))) {
		cout << "El punto esta fuera del rectangulo";
	} else {
		cout << "El punto esta en el borde del rectangulo";
	}
}
		
/*
	if ((   ((x1 <= Px) && (Px <= y1)) || ((x1 >= Px) && (Px >= y1)))  &&  
	        (((x2 < Py) && (Py < y2)) || ((x2 > Py) && (Py > y2)))) {
		cout << "El punto C esta en el rectangulo";
	} else {
		cout << "El punto C no esta en el rectangulo";
	}
if (contenido o borde if (contenido) else (borde)) else (no esta en el rectangulo)

if (
}
*/
