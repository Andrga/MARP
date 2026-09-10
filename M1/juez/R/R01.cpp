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
//#include "GrafoValorado.h"
//#include "IndexPQ.h"
//
//using namespace std;
//
//
//
///*@ <answer>
//*
//* Complejidad en tiempo O((N + M) log N)
//*
//@ </answer> */
//
//
////@ <answer>
//template <typename Valor>
//class Cuevas {
//private:
//	const Valor INF = std::numeric_limits<Valor>::max();
//	int origen;
//	std::vector<Valor> dist;
//	std::vector<Arista<Valor>> ulti;
//	IndexPQ<int,Valor> pq;
//public:
//	Cuevas(GrafoValorado<Valor> const& g, int orig) : origen(orig),
//		dist(g.V(), INF), ulti(g.V()) {
//		dist[origen] = 0;
//		pq.push(origen, 0);
//		while (!pq.empty()) {
//			int v = pq.top().elem; pq.pop();
//			for (auto a : g.ady(v))
//				relajar(a, v);
//		}
//	}
//	bool hayCamino(int v) const { return dist[v] != INF; }
//	Valor distanciaMax(int v) const {
//		return dist[v];
//	}
//private:
//	void relajar(Arista<Valor> a, int v) {
//		int w = a.otro(v);
//		Valor nuevo = max(dist[v], a.valor());
//		if (nuevo < dist[w]) {
//			dist[w] = nuevo;
//			pq.update(w, dist[w]);
//		}
//	}
//};
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int N, M;
//	if (!(cin >> N >> M)) return false;
//	GrafoValorado<int> g(N);
//	for (int i = 0; i < M; i++)
//	{
//		int X, Y, C; cin >> X >> Y >> C;
//		g.ponArista({ X - 1,Y - 1,C });
//	}
//	int ini, fin; cin >> ini >> fin;
//	Cuevas<int> cuevas(g, ini - 1);
//	cout << (!cuevas.hayCamino(fin - 1) ? "IMPOSIBLE" : to_string(cuevas.distanciaMax(fin - 1))) << "\n";
//
//	return true;
//}
//
////@ </answer>
////  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	ifstream in("R/casosR.1.txt");
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
