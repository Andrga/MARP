//
///*@ <authors>
// *
// * Andrés Garcia Navarro MARP19
// *
// *@ </authors> */
//
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <queue>
//#include "Digrafo.h"
//
//using namespace std;
//
///*@ <answer>
//
//	Coste en tiempo: O((N+M) * K * 2) donde N es el numero de vertices, M el numero de aristas (solo se visita cada vertice y adyacente 1 vez),
//										K es el numero de consultas y el doble porque se realizan 2 dfs por consulta
//	Coste en espacio: O(N) donde N es el numero de vertices, N elementos en visit y amigos
//
// @ </answer> */
//
// //@ <answer>
//class Ciudad {
//private:
//	std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
//	std::vector<bool> visitInv; // visit[v] = ¿hay camino de s a v?
//	int num;
//	bool cam;
//public:
//	Ciudad(Digrafo const& g, int o, int d) : visit(g.V(), false), visitInv(g.V(), false), num(0), cam(false) {
//		dfs(g, o, visit);
//		cam = visit[d];
//		dfs(g.inverso(), d, visitInv);
//		for (int i = 0; i < g.V(); i++) {
//			if (visit[i] && visitInv[i]) num++;
//		}
//	}
//
//	int numRestaurantes() { return num; }
//	bool hayCamino() { return cam; }
//
//private:
//	void dfs(Digrafo const& G, int v, vector<bool>& vs) {
//		vs[v] = true;
//		for (int w : G.ady(v)) {
//			if (!vs[w]) {
//				dfs(G, w, vs);
//			}
//		}
//	}
//};
//
//bool resuelvecaso() {
//	// Leer los datos de la entrada.
//	int NV, NA;
//	if (!(cin >> NV >> NA))  // Fin de la entrada.
//		return false;
//	Digrafo g(NV);
//	for (size_t i = 0; i < NA; i++)
//	{
//		int v, w;
//		cin >> v >> w;
//		g.ponArista(v - 1, w - 1);
//	}
//	int Q; cin >> Q;
//	for (int i = 0; i < Q; i++)
//	{
//		int o, d; cin >> o >> d;
//		Ciudad ciudad(g, o - 1, d - 1);
//		int nres = ciudad.numRestaurantes();
//		if (ciudad.hayCamino()) 
//			cout << to_string(nres - 2) << "\n";
//		else 
//			cout << "IMPOSIBLE\n";
//
//	}
//	cout << "---\n";
//
//	return true;
//}
//
////@ </answer>
////  lo que se escriba dejado de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	std::ifstream in("T5/casos5.2.txt");
//	if (!in.is_open())
//		std::cout << "error: no se ha podido abrir el archivo de entrada." << std::endl;
//	auto cinbuf = std::cin.rdbuf(in.rdbuf());
//#endif
//
//	while (resuelvecaso());
//
//	// para dejar todo como estaba al principio
//#ifndef DOMJUDGE
//	std::cin.rdbuf(cinbuf);
//	std::cout << "pulsa intro para salir..." << std::flush;
//	std::cin.get();
//#endif
//	return 0;
//}
