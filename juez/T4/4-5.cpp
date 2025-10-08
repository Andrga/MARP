/*@ <authors>
 *
 * Andres, Garcia, Navarro, MARP19
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
#include <string>
#include <unordered_map>
#include "Grafo.h"

using namespace std;



/*@ <answer>

	Coste en tiempo = O(V + A),
	siendo V el numero de vertices y A el numero de aristas totales.
	En el caso peor se recorren todos los vertices y las aristas que los unen.

 @ </answer> */


 //@ <answer>

class Bacon
{
private:
	vector<bool> visit;	// visit[v] = hay camino de s a v..
	vector<int> ant;	// ant[v] = ultimo vertice para llegar a v.
	vector<int> dist;	// dist[v] = aristas de s->v por el camino mas corto.
	int _s;				// vertice origen.
public:
	Bacon(Grafo const& g, int bacon) : _s(bacon), visit(g.V(), false), ant(g.V()), dist(g.V())
	{
		bfs(g);
		for (size_t i = 0; i < visit.size(); i++)
		{
			if (!visit[i])
				dist[i] = -1;
		}
	}

	int getNBacon(int actor) { return dist[actor]; }

private:
	void bfs(Grafo const& g) {
		queue<int> q;
		q.push(_s);
		visit[_s] = true;
		dist[_s] = 0;

		while (!q.empty())
		{
			int v = q.front(); q.pop();
			for (int w : g.ady(v)) {
				if (!visit[w]) {
					ant[w] = v; dist[w] = dist[v] + 1; visit[w] = true;
					q.push(w);
				}
			}
		}
	}

};

bool resuelveCaso() {

	// leemos la entrada.
	int nPelis;
	cin >> nPelis;
	if (!cin) return false;

	unordered_map<string, int> nombNodo; // Mapa que asigna un nombre de peli o actor a un nodo.
	vector<pair<string, string>> relaciones; // Conexion de actores con peliculas.

	for (size_t i = 0; i < nPelis; i++)
	{
		string peli;
		int nActors;
		cin >> peli >> nActors;
		nombNodo[peli] = nombNodo.size();
		for (size_t j = 0; j < nActors; j++)
		{
			string actor;
			cin >> actor;
			if (!nombNodo.count(actor))
				nombNodo[actor] = nombNodo.size();
			relaciones.push_back({ peli, actor }); // Guarda la relacion.
		}
	}

	if (!nombNodo.count("KevinBacon")) {
		int n;
		cin >> n;
		for (size_t i = 0; i < n; i++)
		{
			string actor;
			cin >> actor;
			cout << actor << " INF\n";
		}
		cout << "---\n";
		return true;
	}

	Grafo grafo(nombNodo.size());
	for (pair<string, string> AP : relaciones)
	{
		int v = nombNodo[AP.first], w = nombNodo[AP.second];
		grafo.ponArista(v, w);
	}


	Bacon bacon(grafo, nombNodo["KevinBacon"]);

	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		string actor;
		cin >> actor;
		int nBacon = bacon.getNBacon(nombNodo[actor])/2;
		cout << actor << " " << (nBacon == -1 ? "INF" : to_string(nBacon)) << "\n";
	}
	cout << "---\n";
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	ifstream in("T4/casos4.5.txt");
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
