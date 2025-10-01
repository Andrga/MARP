
/*@ <authors>
 *
 * andres, garcia, navarro, marp19
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include "IndexPQ.h"

using namespace std;

/*@ <answer>

	Coste en tiempo:
	Coste en espacio:

 @ </answer> */

 //@ <answer>


bool resuelvecaso() {
	// Leer los datos de la entrada.
	int N, M, T;
	cin >> N >> M >> T;

	if (!cin)  // Fin de la entrada.
		return false;

	IndexPQ<int, int> tasks; 
	for (size_t i = 0; i < N; i++)
	{
		int ini, fin;
	}
	for (size_t i = 0; i < M; i++)
	{
		int ini, fin;
	}

	cout << "---\n";

	return true;
}

//@ </answer>
//  lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("T3/casos3.3.txt");
	if (!in.is_open())
		std::cout << "error: no se ha podido abrir el archivo de entrada." << std::endl;
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelvecaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	std::cout << "pulsa intro para salir..." << std::flush;
	std::cin.get();
#endif
	return 0;
}
