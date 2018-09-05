/*
 *  JUEGO DEL AHORCADO - El clásico juego del ahorcado, en C++
 *  
 *  Clases particulares de programación en C++
 *  Autor: Miguel Ángel Fernández Gutiérrez (@mianfg)
 *  Fecha: 5 septiembre, 2018
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief comprueba si un elemento se encuentra en un vector de char
 * @param vect vector en el que se realiza la búsqueda
 * @param elemento elemento a buscar
 * @return si el elemento se encuentra en el vector
 */
bool ocurre( const vector<char> & vect, const char elemento ) {
	for ( int i = 0; i < vect.size(); i++ )
		if ( vect[i] == elemento )
			return true;
	return false;
}

/**
 * @brief comprueba si una letra se encuentra en la palabra, modificando el vector comprobador
 * @param palabra palabra a adivinar
 * @param comprobador vector comprobador
 * @param elemento letra a comprobar
 * @return si se encuentra la letra en la palabra
 */
bool comprobar( const string & palabra, vector<bool> & comprobador, const char elemento ) {
	bool encontrado = false;
	for ( int i = 0; i < palabra.size(); i++ )
		if ( palabra[i] == elemento ) {
			encontrado = true;
			comprobador[i] = true;
		}
	return encontrado;
}

/**
 * @brief comprueba si el usuario ha ganado el juego
 * @param comprobador vector comprobador
 * @return si el usuario ha ganado el juego
 */
bool comprobar_ganado( const vector<bool> & comprobador ) {
	for ( int i = 0; i < comprobador.size(); i++ )
		if ( !comprobador[i] )
			return false;
	return true;
}

/**
 * @brief pide una letra por pantalla
 * @param palabra palabra a adivinar
 * @param comprobador vector comprobador
 * @param usadas vector de letras usadas
 * @param num_intentos número de intentos
 */
void pedirLetra( const string & palabra, vector<bool> & comprobador, vector<char> & usadas, int & num_intentos ) {
	char letra;
	cout << "[Jugador 2] Inserte una letra -> ";
	cin >> letra;
	
	if ( ocurre(usadas, letra) )
		cout << "¡Ya ha insertado esa letra! Inténtelo de nuevo" << endl;
	else {
		usadas.push_back(letra);
		if ( comprobar(palabra, comprobador, letra) )
			cout << "¡Genial, ha encontrado una letra!" << endl;
		else {
			cout << "Lo siento, se ha equivocado :(" << endl;
			num_intentos--;
		}
	}
}

/**
 * @brief muestra la palabra por pantalla, con huecos en los lugares no acertados
 * @param palabra palabra a adivinar
 * @param comprobador vector comprobador
 */
void mostrarPalabra( const string & palabra, const vector<bool> & comprobador ) {
	for ( int i = 0; i < palabra.size(); i++ )
		if (comprobador[i])
			cout << palabra[i];
		else
			cout << '_';
}

/**
 * @brief muestra un vector por pantalla
 * @param vect vector a mostrar
 */
void mostrarVector( const vector<char> & vect ) {
	for ( int i = 0; i < vect.size(); i++ )
		cout << vect[i] << ' ';
}

/**
 * @brief mostrar dibujo de ahorcado, número de intentos, palabra y letras usadas
 * @param palabra palabra a adivinar
 * @param comprobador vector comprobador
 * @param usadas vector de letras usadas
 * @param num_intentos número de intentos
 */
void mostrar( const string & palabra, const vector<bool> & comprobador, const vector<char> & usadas, const int num_intentos ) {
	// inicio
	cout << "   ____     " << endl << "  |    |    " << endl;
	
	// cabeza
	cout << "  |    ";
	if ( num_intentos >= 1 )
		cout << 'o';
	else
		cout << ' ';
	cout << "    ";
	
	// mostrar número de intentos
	cout << "  Número de intentos: " << num_intentos << endl;
	
	// brazo izquierdo, central, derecho
	cout << "  |   ";
	if ( num_intentos >= 4 )
		cout << "/|\\   ";
	else if ( num_intentos >= 3 )
		cout << "/|    ";
	else if ( num_intentos >= 2 )
		cout << "/     ";
	else
		cout << "      ";
	
	// mostrar palabra
	cout << "  Palabra: ";
	mostrarPalabra(palabra, comprobador);
	cout << endl;
	
	// tórax
	if ( num_intentos >= 5 )
		cout << "  |    |    ";
	else
		cout << "  |         ";
	
	// mostrar letras usadas
	cout << "  Letras usadas: ";
	mostrarVector(usadas);
	cout << endl;
	
	// pierna izquierda, derecha
	if ( num_intentos >= 7 )
		cout << "  |   / \\   ";
	else if ( num_intentos >= 6 )
		cout << "  |   /     ";
	else
		cout << "  |         ";
	cout << endl;
	
	// final
	cout << " _|_        " << endl << "|   |______ " << endl << "|          |" << endl << "|__________|" << endl;
}

/**
 * @brief bucle para adivinar la palabra
 * @param palabra palabra a adivinar
 */
void adivinar ( const string & palabra ) {
	int num_intentos = 7;
	vector<bool> comprobador(palabra.size(), false);
	vector<char> usadas;
	bool ganado = false;
	while ( num_intentos > 0 && !ganado ) {
		mostrar( palabra, comprobador, usadas, num_intentos );
		pedirLetra(palabra, comprobador, usadas, num_intentos);
		if ( comprobar_ganado(comprobador) )
			ganado = true;
	}
	
	mostrar( palabra, comprobador, usadas, num_intentos );
	
	if ( ganado )
		cout << "¡Felicidades, jugador 2, ha ganado el juego con " << num_intentos << " intentos restantes!" << endl;
	else
		cout << "Lo sentimos, jugador 2... ha perdido. La palabra era " << palabra << endl;
}

/**
 * @brief juego del ahorcado
 */
void hangman() {
	string palabra;
	
	// pedimos palabra
	cout << "[Jugador 1] Introduce la palabra. ¡No mires, jugador 2! -> ";
	cin >> palabra;
	
	// "borrar" la pantalla, insertando muchos saltos de línea
	for ( int i = 0; i < 50; i++ )
		cout << endl;
	
	adivinar(palabra);
}

int main() {
	hangman();
}
