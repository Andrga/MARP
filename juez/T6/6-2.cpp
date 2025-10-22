/*@ <authors>
 *
 * Andres Garcia Navarro, MARP19
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
#include <string>
#include "GrafoValorado.h"

using namespace std;



/*@ <answer>

	Coste en tiempo: O(V + E) donde V es el numero de intersecciones de la ciudad y E el numero de calles que las unen.
	Esto es asi porque el coste en el caso peor de realizar un dfs de este estilo es O(V+E).
 @ </answer> */


 //@ <answer>

class ciudad {
private:
	GrafoValorado<int> const& _g; // Grafo valorado

public:
	ciudad(GrafoValorado<int> const& grafo) : _g(grafo) {}

	bool consulta(int ini, int fin, int ancho) {
		vector<bool> visit(_g.V(), false);
		return dfs(visit, ini, fin, ancho);
	}

private:
	bool dfs(vector<bool>& visit, int v, int fin, int anchoMin) {
		visit[v] = true;
		if (v == fin) return true;

		for (auto const& arista : _g.ady(v)) {
			int w = arista.otro(v);
			if (!visit[w] && arista.valor() >= anchoMin)
				if (dfs(visit, w, fin, anchoMin)) return true;
		}
		return false;
	}
};



bool resuelveCaso() {

	// leemos la entrada.
	int V, E;
	cin >> V >> E;
	if (!cin) return false;

	GrafoValorado<int> grafo(V);
	for (int i = 0; i < E; i++)
	{
		int v, w, valor;
		cin >> v >> w >> valor;
		Arista<int> a(v - 1, w - 1, valor);
		grafo.ponArista(a);
	}
	ciudad ciudad(grafo);
	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int org, dest, anch;
		cin >> org >> dest >> anch;
		cout << (ciudad.consulta(org - 1, dest - 1, anch) ? "SI" : "NO") << "\n";
	}

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	ifstream in("T6/casos6.2.txt");
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
