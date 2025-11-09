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
// @ </answer> */
//
//
// //@ <answer>
//template <typename Valor>
//class Web {
//private:
//	const Valor INF = std::numeric_limits<Valor>::max();
//	Valor origen;
//	std::vector<Valor> dist;		// dist[v] es la longitud del camino mas corto conocido de s a v.
//	std::vector<AristaDirigida<Valor>> ulti;// ulti[v] es la ultima arista del camino mas corto conocido de s a v.
//	IndexPQ<int, Valor> pq;
//
//public:
//	Web(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
//		dist(g.V(), INF), ulti(g.V()) {
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
//
//	void relajar(AristaDirigida<Valor> a) {
//		int v = a.desde(), w = a.hasta();
//		if (dist[w] > dist[v] + a.valor()) {
//			dist[w] = dist[v] + a.valor(); ulti[w] = a;
//			pq.update(w, dist[w]);
//		}
//	}
//};
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int N;
//	cin >> N;
//	if (N == 0) return false;
//	// Tiempos de carga.
//	vector<int> tiempos(N);
//	for (int i = 0; i < N; i++) {
//		cin >> tiempos[i];
//	}
//	// Construccion del grafo.
//	DigrafoValorado<int> grafo(N);
//	int M; cin >> M;
//	for (size_t i = 0; i < M; i++)
//	{
//		int v, w, valor;
//		cin >> v >> w >> valor; 
//		AristaDirigida<int> ar(v-1, w-1, tiempos[w-1] + valor);
//		grafo.ponArista(ar);
//	}
//	// Casos de prueba.
//	Web<int> web(grafo, 0);
//
//	cout << (web.hayCamino(N - 1) ? to_string(web.distancia(N - 1) + tiempos[0]) : "IMPOSIBLE") << "\n";
//	return true;
//}
//
////@ </answer>
////  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	ifstream in("T7/casos7.2.txt");
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
