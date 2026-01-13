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
//#include "Grafo.h"
//
//using namespace std;
//
///*@ <answer>
//
//	Coste en tiempo: O(N+M) donde n es el numero de vertices y m el numero de aristas (solo se visita cada vertice y adyacente 1 vz)
//	Coste en espacio: O(N) donde N es el numero de vertices, N elementos en visit y amigos
//
// @ </answer> */
//
// //@ <answer>
//class Red {
//private:
//	vector<bool> visit;
//	vector<int> amigos;
//
//public:
//	Red(Grafo const& g, int n) : visit(n, false), amigos(n, 0) {
//		for (int i = 0; i < g.V(); i++)
//		{
//			if (visit[i]) continue;
//			vector<int> comp;
//			int tam = dfs(g, i, comp);
//			for (int v : comp) amigos[v] = tam;
//		}
//	}
//
//	int getAmigos(int v) { return amigos[v]; }
//
//private:
//	int dfs(Grafo const& g, int v, vector<int> & comp) {
//		visit[v] = true;
//		int tam = 1;
//		comp.push_back(v);
//		for (int w : g.ady(v))
//		{
//			if (visit[w]) continue;
//			tam += dfs(g, w, comp);
//		}
//		return tam;
//	}
//
//};
//
//bool resuelvecaso() {
//	// Leer los datos de la entrada.
//	int N, M;
//	if (!(cin >> N >> M))  // Fin de la entrada.
//		return false;
//	Grafo g(N);
//	for (size_t i = 0; i < M; i++)
//	{
//		int c;
//		cin >> c;
//		if (c == 0) continue;
//		int uno; cin >> uno;
//		for (size_t i = 0; i < c - 1; i++)
//		{
//			int otro; cin >> otro;
//			g.ponArista(uno - 1, otro - 1);
//			uno = otro;
//		}
//	}
//	Red red(g, N);
//	for (int i = 0; i < N; i++)
//	{
//		cout << red.getAmigos(i) << " ";
//	}
//	cout << "\n";
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
//	std::ifstream in("T4/casos4.6.txt");
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
