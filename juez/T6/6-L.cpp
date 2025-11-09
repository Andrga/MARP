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
//#include "PriorityQueue.h"
//
//using namespace std;
//
//
//
///*@ <answer>
//
//	Coste en tiempo: O(N + M) donde N es el numero de ciudades y M el numero de carreteras que las unen (recorrido de un dfs en el algoritmo de Prim implementado).
//	Buscamos el camino de coste minimo, en este caso implementando un algoritmo de Prim.
//	En Prim se visitan los vertices cuyo camino hacia ellos tiene un coste menor que un aeropuerto.
//	Por cada grupo de vertices se crea un aeropuerto.
// @ </answer> */
//
//
// //@ <answer>
//template <typename Valor>
//class carreteras {
//private:
//	vector<bool> visit;
//	int nConjuntos;
//	Valor coste;
//public:
//	carreteras(GrafoValorado<int> const& g, int costAeropuerto) : visit(g.V(), false), nConjuntos(0), coste(0) {
//		for (int i = 0; i < g.V(); i++)
//		{
//			if (!visit[i]) {
//				nConjuntos++;
//				Prim(g, i, costAeropuerto);
//			}
//		}
//	}
//	Valor getCoste() const {
//		return coste;
//	}
//	int getNAeropuertos() const {
//		return nConjuntos;
//	}
//private:
//	void Prim(GrafoValorado<int> const& g, int ini, int costMax) {
//		visit[ini] = true;
//		// Cogemos los adyacentes de v.
//		PriorityQueue<Arista<Valor>> pq(g.ady(ini));
//		// Procesamos las aristas no visitadas.
//		int v = ini;
//		while (!pq.empty()) {
//			Arista<Valor> a = pq.top();
//			pq.pop();
//			v = a.uno();
//			int w = a.otro(v);
//			// Si no ha sido visitado y el valor es menor que el coste de un aeropuerto.
//			if (!visit[a.otro(v)] && a.valor() < costMax) {
//				coste += a.valor();
//				visit[v] = true;
//				for (Arista<Valor> const& a : g.ady(a.otro(v)))
//					if (!visit[a.uno()])
//						pq.push(a);
//			}
//			if (!visit[a.uno()] && a.valor() < costMax) {
//				coste += a.valor();
//				visit[v] = true;
//				for (Arista<Valor> const& a : g.ady(a.uno()))
//					if (!visit[a.otro(v)])
//						pq.push(a);
//			}
//		}
//	}
//};
//
//
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int N, M, A;
//	cin >> N >> M >> A;
//	if (!cin) return false;
//
//	GrafoValorado<int> grafo(N);
//	for (int i = 0; i < M; i++)
//	{
//		int x, y, c;
//		cin >> x >> y >> c;
//		Arista<int> a(x - 1, y - 1, c);
//		grafo.ponArista(a);
//	}
//	carreteras<int> carreteras(grafo, A);
//	cout << carreteras.getNAeropuertos() * A + carreteras.getCoste() << " " << carreteras.getNAeropuertos() << "\n";
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
//	ifstream in("T6/casos6.L.txt");
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
