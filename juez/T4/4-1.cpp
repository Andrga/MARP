///*@ <authors>
// *
// * MARP19 Andres Garcia Navarro
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
///*@ <answer>
//
// @ </answer> */
//
//
// // ================================================================
// // Escribe el código completo de tu solución aquí debajo (después de la marca)
// //@ <answer>
//
//class ArbolLibre
//{
//private:
//	vector<bool> visit;	// visit[v] = hay camino de s a v.
//	vector<int> ant;	// ant[v] = nodo anterior a v.
//	int _s;				// vertice origen.
//	bool esArbol;		// almacena si es un arbol libre.
//public:
//	ArbolLibre(Grafo const& g, int s) : _s(s), visit(g.V(), false), ant(g.V())
//	{
//		esArbol = true;
//		dfs(g, 0);
//	}
//
//	void dfs(Grafo const& g, int v) {
//		visit[v] = true;
//		vector<int> adys;
//		for (int w : g.ady(v))
//		{	
//			if (!visit[w]) 
//			{
//				ant[w] = v;
//				dfs(g, w);
//			}
//			else if (ant[v] != w && w != _s) {
//				esArbol = false;
//			}
//		}
//	}
//	bool esConexo() {
//		bool conexo = true;
//		for (bool v : visit)
//		{
//			if (!v) {
//				conexo = false;
//			}
//		}
//		return conexo;
//	}
//
//	bool getEsArbol() { return esArbol; }
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
//	ArbolLibre arbol(grafo, v);
//
//	cout << ((arbol.getEsArbol()&& arbol.esConexo()) ? "SI" : "NO") << "\n";
//
//	return true;
//}
//
////@ </answer>
////  Lo que se escriba debajo de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	ifstream in("T4/casos4.1.txt");
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
