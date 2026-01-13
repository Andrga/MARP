/*@ <authors>
 *
 * Andres Garcia Navarro, MARP19
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;



/*@ <answer>
*
* Esta sin hacer
*
@ </answer> */



//@ <answer>

bool resuelveCaso() {

	// leemos la entrada.
	int K, S;
	if (!(cin >> K >> S)) return false;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	ifstream in("R/casosR.5.txt");
	if (!in.is_open())
		cout << "Error: no se ha podido abrir el archivo de entrada." << endl;
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	// Resolvemos
	int i; cin >> i;
	while (i-- != 0)
		resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
#endif
	return 0;
}
