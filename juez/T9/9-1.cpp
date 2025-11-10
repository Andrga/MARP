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
struct Edificio {
	int plazo;
	int beneficio;
	int id;
};
bool operator>(Edificio a, Edificio b) {
	return a.beneficio > b.beneficio;
}

// las tareas están ordenadas de mayor a menor beneficio
int resolver(vector<Tarea> const& tareas, vector<int>& sol) {
	int N = tareas.size(); // número de tareas
	vector<int> libre(N + 1, 0);
	for (int i = 0; i <= N; ++i)
		libre[i] = i;
	vector<int> plan(N + 1); // 0 es que no está usado
	ConjuntosDisjuntos particion(N + 1);
	int beneficio = 0;
	// recorrer las tareas de mayor a menor beneficio
	for (int i = 0; i < N; ++i) {
		int c1 = particion.buscar(min(N, tareas[i].plazo));
		int m = libre[c1];
		if (m != 0) { // podemos colocar la tarea i
			plan[m] = tareas[i].id;
			beneficio += tareas[i].beneficio;
			int c2 = particion.buscar(m - 1);
			particion.unir(c1, c2);
			libre[c1] = libre[c2];
		}
	}
}


bool resuelveCaso() {

	// leemos la entrada.
	int N;
	cin >> N;
	if (!cin) return false;

	vector<Tarea> jugadores(N, 0);

	for (int i = 0; i < N; i++)
		cin >> jugadores[i];
	for (int i = 0; i < M; i++)
		cin >> equipaciones[i];

	sort(jugadores.begin(), jugadores.end());
	sort(equipaciones.begin(), equipaciones.end());

	int validas = temporada(jugadores, equipaciones);

	cout << N - validas << "\n";
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	ifstream in("T9/casos9.1.txt");
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
