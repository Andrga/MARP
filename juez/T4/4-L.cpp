///*@ <authors>
// *
// * Andres, Garcia, Navarro, MARP19
// *
// *@ </authors> */
//
//#include <iostream>
//#include <fstream>
//#include <algorithm>
//#include <limits>
//#include <queue>
//#include <string>
//#include <unordered_map>
//#include "Grafo.h"
//
//using namespace std;
//
//
//
///*@ <answer>
//
//	Coste en tiempo = O(V + A),
//	siendo V el numero de vertices y A el numero de aristas totales.
//	En el caso peor, la busqueda en profundidad recorre todos los vertices y las aristas que los unen 3 veces.
//
// @ </answer> */
//
//
// //@ <answer>
//
//class camino
//{
//private:
//	vector<bool> visit;	// visit[v] = hay camino de s a v.
//	vector<int> ant;	// ant[v] = ultimo vertice para llegar a v.
//	vector<int> dist;	// dist[v] = aristas de s->v por el camino mas corto.
//	int _s;				// vertice origen.
//public:
//	camino(Grafo const& g, int inicio) : _s(inicio), visit(g.V(), false), ant(g.V()), dist(g.V())
//	{
//		bfs(g);
//	}
//
//	/// <summary>
//	/// Menor distancia hasta un punto obj.
//	/// </summary>
//	int getDistancia(int obj) { return dist[obj]; }
//	int getAnterior(int obj) { return ant[obj]; }
//
//private:
//	void bfs(Grafo const& g) {
//		queue<int> q;
//		q.push(_s);
//		visit[_s] = true;
//		dist[_s] = 0;
//
//		while (!q.empty())
//		{
//			int v = q.front(); q.pop();
//			for (int w : g.ady(v)) {
//				if (!visit[w]) {
//					ant[w] = v; dist[w] = dist[v] + 1; visit[w] = true;
//					q.push(w);
//				}
//			}
//		}
//	}
//
//};
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int I, C, A, L, T;
//	cin >> I >> C >> A >> L >> T;
//	if (!cin) return false;
//
//	Grafo g(I);
//	A--; L--; T--;
//
//	for (size_t i = 0; i < C; i++)
//	{
//		int v, w;
//		cin >> v >> w;
//		g.ponArista(v - 1, w - 1);
//	}
//
//	camino Lucas(g, A);
//	camino Alex(g, L);
//	camino Trabajo(g, T);
//
//	int distMin = I*3;
//	for (int i = 0; i < I; i++)
//	{
//		int dist = Lucas.getDistancia(i) + Alex.getDistancia(i) + Trabajo.getDistancia(i);
//		distMin = min(distMin, dist);
//	}
//
//	cout << distMin << "\n";
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
//	ifstream in("T4/casos4.L.txt");
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
