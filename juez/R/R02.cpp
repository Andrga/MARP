///*@ <authors>
// *
// * Andres Garcia Navarro, MARP19
// *
// *@ </authors> */
//
//#include <iostream>
//#include <fstream>
//#include <algorithm>
//#include <limits>
//#include <queue>
//#include <string>
//#include "ConjuntosDisjuntos.h"
//#include "Grafo.h"
//
//using namespace std;
//
//
//
///*@ <answer>
//*
//* Complejidad en tiempo  O(A*R)
//* Complejidad en espacio
//*
//@ </answer> */
//
//
////@ <answer>
//
//class Bipartito
//{
//private:
//	std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
//	vector<bool> equipo;
//	bool bipartito;
//public:
//	Bipartito(Grafo const& g): visit(g.V(), false), equipo(g.V(),false), bipartito(true) {
//		for (size_t i = 0; i < g.V(); i++)
//		{
//			if (!visit[i])
//				dfs(g, i);
//		}
//	};
//	bool getBipartito() { return bipartito; }
//private:
//	void dfs(Grafo const& G, int v) {
//		visit[v] = true;
//		for (int w : G.ady(v)) {
//			if (!bipartito) return;
//			if (!visit[w]) {
//				equipo[w] = !equipo[v];
//				dfs(G, w);
//			}
//			else if (equipo[v] == equipo[w])
//				bipartito = false;
//		}
//	}
//};
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int A, R;
//	if (!(cin >> A >> R)) return false;
//
//	// Grafo bipartito, O(A+R)
//	Grafo equipos(A);
//	for (size_t i = 0; i < R; i++)
//	{
//		int a, b; cin >> a >> b;
//		equipos.ponArista(a-1,b-1);
//	}
//	Bipartito bipartito(equipos);
//	cout << (bipartito.getBipartito() ? "SI" : "NO") << "\n";
//	return true;
//}
//
////@ </answer>
////  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	ifstream in("R/casosR.2.txt");
//	if (!in.is_open())
//		cout << "Error: no se ha podido abrir el archivo de entrada." << endl;
//	auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
//
//	// Resolvemos
//	while (resuelveCaso());
//
//	// para dejar todo como estaba al principio
//#ifndef DOMJUDGE
//	cin.rdbuf(cinbuf);
//#endif
//	return 0;
//}
