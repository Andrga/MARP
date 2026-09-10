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
//	Coste en tiempo = O(V + A +1),
//	siendo V el numero de instrucciones en el programa y A el numero de saltos a la siguiente instrucción
//	En el caso peor se recorren todos las instrucciones y los saltos que las unen.
//	El +1 es porque uso un vertice fantasma sin aristas indicando el final del programa.
// @ </answer> */
//
//
// //@ <answer>
//
//class ProgramaOscuro
//{
//private:
//	vector<int> visit;		// visit[v] = veces que se ha visitado v
//	vector<bool> apilado;	// apilado[v] = esta apilado?
//	bool sale;				// ha encontrado una salida?
//	bool ciclo;				// ha encontrado un ciclo?
//public:
//	ProgramaOscuro(Digrafo& g) : visit(g.V(), 0), apilado(g.V(), false), ciclo(false), sale(false)
//	{
//		dfs(g, 1);
//	}
//	bool Sale() const { return sale; }
//	bool Ciclo() const { return ciclo; }
//
//private:
//	void dfs(Digrafo const& g, int v) {
//		apilado[v] = true;
//		visit[v]++;
//		if (v == 0) sale = true; // Has llegado a nodo final.
//		for (int w : g.ady(v)) {
//			if (visit[w] < 1)dfs(g, w);
//			else if (apilado[w]) { // Has encontrado un ciclo.				
//					ciclo = true;
//			}
//		}
//		apilado[v] = false;
//	}
//};
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int L;
//	cin >> L;
//	if (!cin) return false;
//	Digrafo g(L+1);
//	for (size_t i = 1; i < L +1; i++)
//	{
//		char ins;
//		cin >> ins;
//		if (ins == 'A' || ins == 'C') {
//			if (i < L)
//				g.ponArista(i, i + 1);
//			else
//				g.ponArista(i, 0);
//		}
//		if (ins == 'J' || ins == 'C') {
//			int a;
//			cin >> a;
//			g.ponArista(i, a );
//
//		}
//	}
//
//	ProgramaOscuro programaOscuro(g);
//	if (programaOscuro.Sale() && !programaOscuro.Ciclo())
//		cout << "SIEMPRE\n";
//	if (programaOscuro.Sale() && programaOscuro.Ciclo())
//		cout << "A VECES\n";
//	if (!programaOscuro.Sale() && programaOscuro.Ciclo())
//		cout << "NUNCA\n";
//
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
//	ifstream in("T5/casos5.L.txt");
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
