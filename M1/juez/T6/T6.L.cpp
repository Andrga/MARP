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
//class Carreteras {
//private:
//	std::vector<Arista<Valor>> _ARM;
//	int V;
//	Valor coste;
//public:
//	Carreteras(GrafoValorado<Valor> const& g, int A) : coste(0) {
//		V = g.V();
//		PriorityQueue<Arista<Valor>> pq(g.aristas());
//		ConjuntosDisjuntos cjtos(g.V());
//		while (!pq.empty()) {
//			auto a = pq.top(); pq.pop();
//
//			// si el coste es mayor que A entonces el resto van a ser conectados por aeropuertos en lugar de carreteras
//			// dejamos de buscar un ARM, porque el resto no van a entrar
//			if (a.valor() >= A)
//				break;
//
//			int v = a.uno(), w = a.otro(v);
//			if (!cjtos.unidos(v, w)) {
//				cjtos.unir(v, w);
//				_ARM.push_back(a); coste += a.valor();
//				if (_ARM.size() == g.V() - 1) break;
//			}
//		}
//	}
//	// numero de conjuntos es V del grafo - tamaño del _arm porque para 1 arbol _arm.size = g.V()-1
//	int getNConjuntos() { return V - _ARM.size(); }
//	int getCoste() { return coste; }
//};
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int N, M, A;
//	cin >> N >> M >> A;
//	if (!cin) return false;
//	GrafoValorado<int> g(N);
//	for (int i = 0; i < M; i++)
//	{
//		int X, Y, C; cin >> X >> Y >> C;
//		g.ponArista({ X-1,Y-1,C });
//	}
//	Carreteras<int> carreteras(g, A);
//	int costeTot = carreteras.getCoste() + (carreteras.getNConjuntos() * A);
//	cout << costeTot << " " << carreteras.getNConjuntos() << "\n";
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
