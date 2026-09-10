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
//#include "ConjuntosDisjuntos.h"
//
//using namespace std;
//
//
//
///*@ <answer>
//*
//* Complejidad en tiempo  O(N * log(N)) dond N es el numero de tipos de chorizo, y log(N) porque es el coste de push y pop
//* Complejidad en espacio O(1) no se crea memoria extra
//*
//@ </answer> */
//
//
////@ <answer>
//class Pueblos {
//private:
//	std::vector<Arista<int>> _ARM;
//	int V;
//public:
//	Pueblos(GrafoValorado<int> const& g) : V(g.V()) {
//		PriorityQueue<Arista<int>> pq(g.aristas());
//		ConjuntosDisjuntos cjtos(g.V());
//		while (!pq.empty()) {
//			auto a = pq.top(); pq.pop();
//			int v = a.uno(), w = a.otro(v);
//			if (!cjtos.unidos(v, w)) {
//				cjtos.unir(v, w);
//				_ARM.push_back(a);
//				if (_ARM.size() == g.V() - 1) break;
//			}
//		}
//	}
//	int costeMaximo() const {
//		int costeMax = 0;
//		for (Arista<int> a : _ARM)
//		{
//			if (costeMax < a.valor())
//				costeMax = a.valor();
//		}
//		return costeMax;
//	}
//	bool conectable() const {
//		return (V - _ARM.size()) == 1;
//	}
//};
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int N, M;
//	if (!(cin >> N >> M)) return false;
//	// usamos priorityQueue para ordenar
//	GrafoValorado<int> g(N);
//	for (size_t i = 0; i < M; i++)
//	{
//		int v, w, cost; cin >> v >> w >> cost;
//		g.ponArista({ v-1,w-1,cost });
//	}
//
//	Pueblos pueblos(g);
//	cout << (pueblos.conectable()? to_string(pueblos.costeMaximo()) : "IMPOSIBLE") << "\n";
//	return true;
//}
//
////@ </answer>
////  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	ifstream in("R/casosR.4.txt");
//	if (!in.is_open())
//		cout << "Error: no se ha podido abrir el archivo de entrada." << endl;
//	auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
//
//	// Resolvemos
//	int i; cin >> i;
//	while (i-- != 0)
//		resuelveCaso();
//
//	// para dejar todo como estaba al principio
//#ifndef DOMJUDGE
//	cin.rdbuf(cinbuf);
//#endif
//	return 0;
//}
