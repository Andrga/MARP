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
//#include <deque>
//#include "Grafo.h"
//
//using namespace std;
//
//
//
///*@ <answer>
//
//	Coste en tiempo = O(V + A), 
//	siendo V el numero de vertices y A el numero de aristas
//
// @ </answer> */
//
//
// //@ <answer>
//
//class Bipartito
//{
//private:
//	vector<bool> visit;	// visit[v] = hay camino de s a v.
//	int _s;				// vertice origen.
//	vector<bool> color;	// color[v] = true o false indica cada uno un color.
//	bool bipartito;		// almacena si es un arbol libre.
//public:
//	Bipartito(Grafo const& g, int s) : _s(s), visit(g.V(), false), 
//										color(g.V()),
//										bipartito(true)
//	{
//		for (int v = 0; v < g.V() && bipartito; v++)
//		{
//			if (!visit[v]) {
//				color[v] = true;
//				dfs(g, v);
//			}
//		}
//	}
//
//	void dfs(Grafo const& g, int v) {
//		visit[v] = true;
//		for (int w : g.ady(v))
//		{	
//			if (!bipartito) return;
//			if (!visit[w])
//			{
//				color[w] = !color[v];
//				dfs(g, w);
//			}
//			else if (color[w] == color[v])
//				bipartito = false;
//		}
//	}
//
//	bool getEsBipartito() { return bipartito; }
//};
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int V, A;
//	cin >> V >> A;
//	if (!cin) return false;
//
//	Grafo grafo(V);
//
//	int v, w;
//	for (size_t i = 0; i < A; i++)
//	{
//		cin >> v >> w;
//		grafo.ponArista(v, w);
//	}
//
//	Bipartito arbol(grafo, v);
//
//	cout << (arbol.getEsBipartito() ? "SI" : "NO") << "\n";
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
//	ifstream in("T4/casos4.2.txt");
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
