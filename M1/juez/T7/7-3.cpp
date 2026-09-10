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
//#include <unordered_map>
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
//*	El coste en tiempo de esta funcion es de O((N+C)log(N)) donde N es el numero de intersecciones y C el numero de calles.
//*	O(N log(N)) viene de las operaciones de manejar elementos de la cola en la constructora de Ciudad.
//*	O(C log(N)) viene del update de relajar.
// @ </answer> */
//
//
// //@ <answer>
//template <typename Valor>
//class Ciudad {
//private:
//	const Valor INF = std::numeric_limits<Valor>::max();
//	int origen;
//	std::vector<Valor> dist;
//	std::vector<AristaDirigida<Valor>> ulti;
//	vector<long long> numCaminos;
//	IndexPQ<int, Valor> pq;
//
//public:
//	Ciudad(DigrafoValorado<Valor> const& g) : origen(0),
//		dist(g.V(), INF), ulti(g.V()), numCaminos(g.V(), 0) {
//		dist[origen] = 0;
//		numCaminos[origen] = 1;
//		pq.push(origen, 0);
//		while (!pq.empty()) {
//			int v = pq.top().elem; pq.pop();
//			for (auto a : g.ady(v))
//				relajar(a);
//		}
//	}
//
//	bool hayCamino(int v) const { return dist[v] != INF; }
//	long long numeroCaminos(int v) { return numCaminos[v]; }
//
//private:
//	void relajar(AristaDirigida<Valor> a) {
//		int v = a.desde(), w = a.hasta();
//		if (dist[w] > dist[v] + a.valor()) {
//			dist[w] = dist[v] + a.valor(); ulti[w] = a;
//			numCaminos[w] = numCaminos[v];
//			pq.update(w, dist[w]);
//		}
//		else if (dist[w] == dist[v] + a.valor()) {
//			numCaminos[w] += numCaminos[v];
//		}
//	}
//};
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int N, C;
//	cin >> N >> C;
//	if (!cin) return false;
//	DigrafoValorado<int> grafo(N);
//
//	for (size_t i = 0; i < C; i++)
//	{
//		int v, w, valor;
//		cin >> v >> w >> valor;
//		AristaDirigida<int> ar1(v-1, w-1, valor);
//		AristaDirigida<int> ar2(w-1, v-1, valor);
//		grafo.ponArista(ar1);
//		grafo.ponArista(ar2);
//	}
//
//	Ciudad<int> ciudad(grafo);
//	cout << ciudad.numeroCaminos(N - 1) << "\n";
//	return true;
//}
//
////@ </answer>
////  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	ifstream in("T7/casos7.3.txt");
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
