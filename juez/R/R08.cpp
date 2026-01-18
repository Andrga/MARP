/*@ <authors>
 *
 * Andres Garcia Navarro, MARP19
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "PriorityQueue.h"

using namespace std;



/*@ <answer>
*
* Complejidad en tiempo O(N*M) doble bucle del metodo combinaciones
* Complejidad en espacio O(N*M) Matriz dp
*
@ </answer> */



//@ <answer>

struct Evento {
	long ini, fin;

	bool operator<(Evento const& other) const {
		return ini < other.ini;
	}
};

int solapamiento(PriorityQueue<Evento>& eventos) {
	PriorityQueue<int> companyeros;

	while (!eventos.empty())
	{
		Evento ev = eventos.top(); eventos.pop();
		if (companyeros.empty())
		{
			companyeros.push( ev.fin );
			continue;
		}
		int c = companyeros.top();
		if (c > ev.ini) { // todos los companyeros ocupados
			companyeros.push( ev.fin );
		}
		else {
			companyeros.pop();
			companyeros.push(ev.fin);
		}
	}
	return companyeros.size() - 1;
}

bool resuelveCaso() {

	// leemos la entrada.
	int n;
	cin >> n;
	if (n == 0) return false;
	PriorityQueue<Evento> eventos;
	for (size_t i = 0; i < n; i++)
	{
		long ini, fin; cin >> ini >> fin;
		eventos.push({ ini, fin });
	}

	cout << solapamiento(eventos)<< "\n";
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	ifstream in("R/casosR.8.txt");
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
