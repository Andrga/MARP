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
* Complejidad en tiempo  
* Complejidad en espacio 
*
@ </answer> */



//@ <answer>
int combinaciones(int K, int S) {
	vector<int> combinaciones(S + 1, 0);
	combinaciones[0] = 1;
	// calcular la matriz sobre el propio vector
	for (int i = 1; i <= K; ++i) {
		for (int j = i; j <= S; ++j) {
			combinaciones[j] += combinaciones[j - i];
		}
	}
	return combinaciones[S];
}

bool resuelveCaso() {

	// leemos la entrada.
	int K, S;
	if (!(cin >> K >> S)) return false;
	int comb = combinaciones(K, S);
	cout << (comb > 0 ? to_string(comb) : "IMPOSIBLE") << "\n";
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
