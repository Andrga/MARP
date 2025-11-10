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
#include "ConjuntosDisjuntos.h"

using namespace std;



/*@ <answer>
*
 @ </answer> */


 //@ <answer>

struct Edificio
{
	int W;
	int E;
	int id;
};

// las tareas estan ordenadas de mayor a menor beneficio
int resolver(vector<Edificio> const& edificios) {
	int cont = 0; // Cantidad de pasadizos.5
	int last = -1; // Distancia desde el ultimo tunel

	for (auto& e : edificios) {
		if (last <= e.W) {   // El edificio no esta cubierto
			last = e.E;     // Colocamos un tunel en el extremo derecho
			cont++;
		}
	}

	return cont;
}


bool resuelveCaso() {

	// leemos la entrada.
	int N;
	cin >> N;
	if (N == 0) return false;

	vector<Edificio> edificios(N);

	for (int i = 0; i < N; i++) {
		int w, e;
		cin >> w >> e;
		edificios[i] = { w,e,i };
	}

	// Ordenar por extremo derecho asc.
	sort(edificios.begin(), edificios.end(),
		[](const Edificio a, const Edificio& b) {
			if (a.E != b.E) return a.E < b.E;
			return a.W < b.W;
		});

	cout << resolver(edificios) << "\n";
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	ifstream in("T9/casos9.2.txt");
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
