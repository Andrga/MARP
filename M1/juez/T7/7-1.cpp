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
// @ </answer> */
//
//
// //@ <answer>
//template <typename Valor>
//class Ciudad {
//private:
//	const Valor INF = std::numeric_limits<Valor>::max();
//	Valor origen;
//	std::vector<Valor> dist;		// dist[v] es la longitud del camino mas corto conocido de s a v.
//	std::vector<Arista<Valor>> ulti;// ulti[v] es la ultima arista del camino mas corto conocido de s a v.
//	IndexPQ<Valor, int> pq;
//
//public:
//	Ciudad(GrafoValorado<Valor> const& g, int org) :
//		origen(org), dist(g.V(), INF), ulti(g.V()) {
//		Dijkstra(g);
//	}
//
//	bool hayCamino(int v) const { return dist[v] != INF; }
//	Valor distancia(int v) const { return dist[v]; }
//	vector<Valor> getCamino(int dest) {
//		std::vector<int> camino;
//		if (!hayCamino(dest)) return camino;
//		for (int v = dest; v != origen; v = ulti[v].otro(v))
//			camino.push_back(v);
//		std::reverse(camino.begin(), camino.end());
//		return camino;
//	}
//
//private:
//	void Dijkstra(GrafoValorado<Valor> const& g) {
//		dist[origen] = 0;
//		pq.push(origen, 0);
//		while (!pq.empty()) {
//			int v = pq.top().elem; pq.pop();
//			for (auto const& a : g.ady(v))
//				relajar(v, a);
//		}
//	};
//
//	void relajar(int v, Arista<Valor> const& a) {
//		int w = a.otro(v);  // obtenemos el vértice adyacente
//		Valor peso = a.valor();
//
//		// Solo relajamos si hay un camino mejor pasando por v
//		if (dist[w] > dist[v] + peso) {
//			dist[w] = dist[v] + peso;
//			ulti[w] = a;
//			pq.update(w, dist[w]);  // actualizamos prioridad del vértice w
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
//	// Construccion del grafo.
//	GrafoValorado<int> grafo(N);
//	for (size_t i = 0; i < C; i++)
//	{
//		int v, w, valor;
//		cin >> v >> w >> valor;
//		Arista<int> ar(v-1, w-1, valor);
//		grafo.ponArista(ar);
//	}
//	// Casos de prueba.
//	int K; cin >> K;
//	for (size_t i = 0; i < K; i++)
//	{
//		int v, w; cin >> v >> w;
//		Ciudad<int> ciudad(grafo, v - 1);
//		if (ciudad.hayCamino(w-1)) {
//			cout << ciudad.distancia(w-1) << ": ";
//			vector<int> camino = ciudad.getCamino(w-1);
//			cout << v;
//			for ( int t : camino)
//			{
//				cout << " -> " << t + 1;
//			}
//			cout << "\n";
//		}
//		else
//			cout << "NO LLEGA\n";
//	}
//
//
//	cout << "---\n";
//	return true;
//}
//
////@ </answer>
////  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	ifstream in("T7/casos7.1.txt");
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
