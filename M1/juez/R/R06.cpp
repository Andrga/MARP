///*@ <authors>
// *
// * Andres Garcia Navarro, MARP19
// *
// *@ </authors> */
//
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <string>
//#include <limits>
//#include "Grafo.h"
//
//using namespace std;
//
//
//
///*@ <answer>
//*
//* Complejidad en tiempo
//* Complejidad en espacio
//*
//@ </answer> */
//
//
//
////@ <answer>
//class Juego
//{
//private:
//	vector<bool> visit; // visit[v] = ¿hay camino de s a v?
//	int total;
//	vector<int> const& costes;
//	int s; // vértice origen
//public:
//	Juego(Grafo const& g, vector<int> const& costs) : visit(g.V(), false), total( 0), costes(costs) {
//		for (int i = 0; i < g.V(); i++)
//		{
//			if (!visit[i])
//				total += dfs(g, i);
//		}
//	}
//
//	int costemin() {
//		return total;
//	}
//
//private:
//	int dfs(Grafo const& G, int v) {
//		visit[v] = true;
//		int costemin = costes[v];
//		for (int w : G.ady(v)) {
//			if (!visit[w]) {
//				if (costemin > costes[w])
//					costemin = costes[w];
//				int c = dfs(G, w);
//				costemin = c < costemin ? c : costemin;
//			}
//		}
//		return costemin;
//	}
//};
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int N, M;
//	if (!(cin >> N >> M)) return false;
//	Grafo g(N);
//	vector<int> costes(N);
//	for (size_t i = 0; i < N; i++)
//	{
//		int c; cin >> c;
//		costes[i] = c;
//	}
//	for (size_t i = 0; i < M; i++)
//	{
//		int v, w; cin >> v >> w;
//		g.ponArista(v-1, w-1);
//	}
//	Juego juego(g, costes);
//	cout << juego.costemin() << "\n";
//	return true;
//}
//
////@ </answer>
////  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	ifstream in("R/casosR.6.txt");
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
