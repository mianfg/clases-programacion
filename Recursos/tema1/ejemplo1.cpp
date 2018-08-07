#include <iostream>
using namespace std;

int main() {
	int x;
	cout << "Inserte un número del 0 al 25: ";
	cin >> x;
	cout << "Su mayúscula correspondiente es: " << (char)(x+65) << endl;
	cout << "Su minúscula correspondiente es: " << static_cast<char>(x+97) << endl;
}
