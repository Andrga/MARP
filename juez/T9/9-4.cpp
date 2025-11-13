/*@ <authors>
 *
 * Andres Garcia Navarro, MARP19
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using namespace std;



/*@ <answer>
* 
 @ </answer> */


 //@ <answer>
int Sillas(vector<int> const& pesos, int pesoMaximo) {
	int sillas = 0;
	int i = 0,
		j = pesos.size()-1;

	while (i <= j)
	{
		// Queda una sola persona
		if (i == j) {
			sillas++;
			break;
		}
		// Combinacion valida
		else if (pesos[i] + pesos[j] <= pesoMaximo) {
			sillas++;
			i++; j--;
		}
		// Persona que va sola
		else {
			sillas++;
			j--;
		}
	}
	return sillas;
}


bool resuelveCaso() {

	// leemos la entrada.
	int P, N;
	cin >> P >> N;
	if (!cin) return false;

	vector<int> pesos(N);

	for (int i = 0; i < N; i++)
		cin >> pesos[i];

	sort(pesos.begin(), pesos.end());

	int sillas = Sillas(pesos, P);

	cout << sillas << "\n";
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	ifstream in("T9/casos9.4.txt");
	if (!in.is_open())
		cout << "Error: no se ha podido abrir el archivo de entrada." << endl;
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	// Resolvemos
	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
#endif
	return 0;
}
