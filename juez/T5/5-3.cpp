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
//class OrdenTopologico
//{
//private:
//	vector<bool> visit;		// visit[v] = se ha visitado v?
//	vector<bool> apilado;	// apilado[v] = esta apilado?
//	deque<int> orden;		// Vector ordenado
//	bool ciclo;				// Hay un culo dirigido?
//public:
//	OrdenTopologico(Digrafo& g) : visit(g.V(), false), apilado(g.V(), false), ciclo(false)
//	{
//		for (int i = 0; i < g.V(); i++)
//			if (!visit[i])
//				dfs(g, i);
//	}
//	deque<int> const& getOrden() const { return orden; }
//	bool getCiclo() const { return ciclo; }
//
//private:
//	void dfs(Digrafo const& g, int v) {
//		apilado[v] = true;
//		visit[v] = true;
//		for (int w : g.ady(v)) {
//			if (ciclo) return; // si hay ciclo salimos
//			if (!visit[w])dfs(g, w);
//			else if (apilado[w]) ciclo = true; // hay ciclo
//		}
//		apilado[v] = false;
//		orden.push_front(v);
//	}
//};
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int N, M;
//	cin >> N >> M;
//	if (!cin) return false;
//	Digrafo g(N);
//	for (size_t i = 0; i < M; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		g.ponArista(a - 1, b - 1);
//	}
//
//	OrdenTopologico orden(g);
//
//	if (orden.getCiclo()) cout << "Imposible";
//	else {
//		deque<int> n = orden.getOrden();
//		while (!n.empty())
//		{
//			cout << n.front() +1 << " ";			
//			n.pop_front();
//		}
//	}
//	cout << "\n";
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
//	ifstream in("T5/casos5.3.txt");
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
