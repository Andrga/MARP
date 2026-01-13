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
//#include "DigrafoValorado.h"
//#include "IndexPQ.h"
//
//using namespace std;
//
//
//
///*@ <answer>
//
// @ </answer> */
//
//
// //@ <answer>
//template <typename Valor>
//class Comarca {
//private:
//	const Valor INF = std::numeric_limits<Valor>::max();
//	int origen;
//	std::vector<Valor> dist;
//	IndexPQ<int, Valor> pq;
//public:
//	Comarca(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
//		dist(g.V(), INF), pq() {
//		dist[origen] = 0;
//		pq.push(origen, 0);
//		while (!pq.empty()) {
//			int v = pq.top().elem; pq.pop();
//			for (auto a : g.ady(v))
//				relajar(a);
//		}
//	}
//
//	bool hayCamino(int v) const { return dist[v] != INF; }
//	Valor distancia(int v) const { return dist[v]; }
//private:
//	void relajar(AristaDirigida<Valor> a) {
//		int v = a.desde(), w = a.hasta();
//		if (dist[w] > dist[v] + a.valor()) {
//			dist[w] = dist[v] + a.valor();
//			pq.update(w, dist[w]);
//		}
//	}
//};
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int N, C;
//	if (!(cin >> N >> C)) return false;
//	DigrafoValorado<int> g(N);
//	for (int i = 0; i < C; i++)
//	{
//		int X, Y, C; cin >> X >> Y >> C;
//		g.ponArista({ X - 1,Y - 1,C });
//	}
//	int o, P; cin >> o >> P;
//	Comarca<int> comarca(g, o-1);
//	Comarca<int> comarcaInv(g.inverso(), o-1);
//	int costTotal = 0; bool llega = true;
//	for (size_t i = 0; i < P; i++)
//	{
//		int p; cin >> p;
//		if (comarca.hayCamino(p - 1) && comarcaInv.hayCamino(p - 1)) {
//			costTotal += comarca.distancia(p - 1); costTotal += comarcaInv.distancia(p - 1);
//		}
//		else
//			llega = false;
//	}
//
//	cout << (!llega ? "IMPOSIBLE" : to_string(costTotal)) << "\n";
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
//	ifstream in("T7/casos7.L.txt");
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
