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
//#include <unordered_map>
//#include "Digrafo.h"
//
//using namespace std;
//
//
//
///*@ <answer>
//
//	Coste en tiempo = O(V + A),
//	siendo V el numero de restaurantes y A el numero de calles totales que los unen.
//	En el caso peor se recorren todos los restaurantes y las calles que los unen.
//
// @ </answer> */
//
//
// //@ <answer>
//
//class Paella
//{
//private:
//	Digrafo& grafo;
//public:
//	Paella(Digrafo& g) : grafo(g)
//	{
//	}
//
//	int restaurantes(int ini, int fin) {
//		vector<bool> visitIni(grafo.V(), false);
//		vector<bool> visitFin(grafo.V(), false);
//		dfs(grafo, ini, visitIni);				// Marcamos los nodos a los que se puede llegar desde ini.
//		dfs(grafo.inverso(), fin, visitFin);	// Marcamos los nodos que se pueden llegar a fin.
//
//		int cuenta = 0;
//		for (int i = 0; i < grafo.V(); i++)
//		{
//			// Si ha sido visitado por los dos y no es ni ini ni fin, es un restaurante posible.
//			if (i != ini && i != fin && visitIni[i] && visitFin[i])
//				cuenta++;
//		}
//
//		return cuenta;
//	}
//
//private:
//	void dfs(Digrafo const& g, int v, vector<bool> & visit) {
//		visit[v] = true;
//		for (int w : g.ady(v))
//			if (!visit[w])dfs(g, w, visit);
//	}
//};
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int NV, NA;
//	cin >> NV >> NA;
//	if (!cin) return false;
//	Digrafo g(NV);
//	for (size_t i = 0; i < NA; i++)
//	{
//		int v, w;
//		cin >> v >> w;
//		g.ponArista(v - 1, w - 1);
//	}
//
//	Paella paella(g);
//	int Q;
//	cin >> Q;
//	for (size_t i = 0; i < Q; i++)
//	{
//		int ini, fin;
//		cin >> ini >> fin;
//		int n = paella.restaurantes(ini - 1, fin - 1);
//		cout << (n > 0 ? to_string(n) : "IMPOSIBLE") << "\n";
//	}
//	cout << "---\n";
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
//	ifstream in("T5/casos5.2.txt");
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
