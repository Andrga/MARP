/*@ <authors>
 *
 * Andres, Garcia, Navarro, MARP19
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <deque>
#include "Grafo.h"

using namespace std;



/*@ <answer>

	Coste en tiempo = O(V + A),
	siendo V el numero de vertices y A el numero de aristas totales.
	En el caso peor se recorren todos los vertices y las aristas que los unen.

 @ </answer> */


 //@ <answer>

class Amigos
{
private:
	vector<bool> visit;	// visit[v] = hay camino de s a v.
	int _s;				// vertice origen.
	int maxAmigos;	// numero del grupo con mas personas.
public:
	Amigos(Grafo const& g, int s) : _s(s), visit(g.V(), false),
		maxAmigos(0)
	{
		for (int v = 0; v < g.V(); v++)
		{
			if (!visit[v]) {
				int amigos = dfs(g, v);
				maxAmigos = max(maxAmigos, amigos);
			}
		}
	}

	int getMaxAmigos() { return maxAmigos; }

private:
	int dfs(Grafo const& g, int v) {
		visit[v] = true;
		int tam = 1;
		for (int w : g.ady(v))
		{
			if (!visit[w])
			{
				tam += dfs(g, w);
			}
		}
		return tam;
	}

};

bool resuelveCaso() {

	// leemos la entrada.
	int V, A;
	cin >> V >> A;
	if (!cin) return false;

	Grafo grafo(V);

	int v, w;
	for (size_t i = 0; i < A; i++)
	{
		cin >> v >> w;
		grafo.ponArista(v - 1, w - 1);
	}

	Amigos amigos(grafo, v - 1);

	cout << amigos.getMaxAmigos() << "\n";

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	ifstream in("T4/casos4.4.txt");
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
