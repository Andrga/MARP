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
//#include "Grafo.h"
//
//using namespace std;
//
///*@ <answer>
//
//	Coste en tiempo: O((N+M) * K) donde N es el numero de vertices, M el numero de aristas (solo se visita cada vertice y adyacente 1 vez) y K es el numero de consultas
//	Coste en espacio: O(N) donde N es el numero de vertices, N elementos en visit y amigos
//
// @ </answer> */
//
// //@ <answer>
//class Red {
//private:
//	Grafo const g;
//
//public:
//	Red(Grafo const& _g) : g(_g) {}
//
//	int inaccesibles(int v, int ttl) {
//		return g.V() - bfs(v, ttl);
//	}
//
//private:
//	int bfs(int s, int ttl) {
//		std::queue<int> q;
//		std::vector<bool> visit(g.V(), false); // visit[v] = ¿hay camino de s a v?
//		std::vector<int> dist(g.V(), 0); // visit[v] = ¿hay camino de s a v?
//		visit[s] = true; dist[s] = 0;
//		int visitados = 0;
//		q.push(s);
//		while (!q.empty()) {
//			int v = q.front(); q.pop();
//			if (dist[v] > ttl) continue;
//			visitados++;
//			for (int w : g.ady(v)) {
//				if (!visit[w]) {
//					visit[w] = true; dist[w] = dist[v] + 1;
//					q.push(w);
//				}
//			}
//		}
//		return visitados;
//	}
//
//};
//
//bool resuelvecaso() {
//	// Leer los datos de la entrada.
//	int N, C;
//	if (!(cin >> N >> C))  // Fin de la entrada.
//		return false;
//	Grafo g(N);
//	for (size_t i = 0; i < C; i++)
//	{
//		int v, w;
//		cin >> v >> w;
//		g.ponArista(v - 1, w - 1);
//	}
//	Red red(g);
//	int K; cin >> K;
//	for (int i = 0; i < K; i++)
//	{
//		int v, ttl; cin >> v >> ttl;
//		cout << red.inaccesibles(v - 1, ttl) << "\n";
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
//	std::ifstream in("T4/casos4.7.txt");
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
