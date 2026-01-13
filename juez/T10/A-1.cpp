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
#include "GrafoValorado.h"
#include "IndexPQ.h"

using namespace std;



/*@ <answer>
*
 @ </answer> */


 //@ <answer>
class Dijkstra {
private:
	const int INF = std::numeric_limits<int>::max();
	int origen;
	vector<long long> dist;		// dist[v] es la longitud del camino mas corto conocido de s a v.
	IndexPQ<int, int> pq;

public:
	Dijkstra(GrafoValorado<int> const& g, int org) :
		origen(org), dist(g.V(), INF) {
		dist[origen] = 0;
		pq.push(origen, 0);
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto const& a : g.ady(v))
				relajar(v, a);
		}
	}

	vector<long long> getDistancias() const { return dist; }

private:
	void relajar(int v, Arista<int> const& a) {
		int w = a.otro(v);  // Obtenemos el vertice adyacente.
		int peso = a.valor();

		// Solo relajamos si hay un camino mejor pasando por v.
		if (dist[w] > dist[v] + peso) {
			dist[w] = dist[v] + peso;
			pq.update(w, dist[w]);  // Actualizamos prioridad del vertice w.
		}
	}
};

int resuelve(vector<long long> const& norte, vector<long long> const& sur, int N) {
	int coste = 0;
	int i = 1,
		j = 0,
		t = 0;
	while (i < N - 1 && j < N / 2 && t < N / 2)
	{
		if (norte[i] > sur[i]) {
			coste += sur[i];
			t++;
		}
		else {
			coste += norte[i];
			j++;
		}
		i++;
	}
	// si no se ha asignado todo, se asigna lo que falta.
	if (i < N - 1) {
		if (j < N / 2)
			while (i < N - 1)
			{
				coste += norte[i];
				i++;
			}
		else
			while (i < N - 1)
			{
				coste += sur[i];
				i++;
			}
	}
	return coste * 2;
}

bool resuelveCaso() {

	// leemos la entrada.
	int N, M;
	cin >> N >> M;
	if (!cin) return false;

	GrafoValorado<int> carreteras(N);

	for (int i = 0; i < M; i++) {
		int v, w, valor;
		cin >> v >> w >> valor;
		carreteras.ponArista(Arista<int>(v - 1, w - 1, valor));
	}

	Dijkstra djkNorte(carreteras, 0);
	Dijkstra djkSur(carreteras, N - 1);

	cout << resuelve(djkNorte.getDistancias(), djkSur.getDistancias(), N) << "\n";
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	ifstream in("T9/casos9.L.txt");
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
