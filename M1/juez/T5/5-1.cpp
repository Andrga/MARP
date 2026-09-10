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
//	siendo V el numero de vertices y A el numero de aristas totales.
//	En el caso peor se recorren todos los vertices y las aristas que los unen.
//
// @ </answer> */
//
//
// //@ <answer>
//
//class Calculadora
//{
//private:
//public:
//	Calculadora()
//	{	}
//
//	int bfs(int origen, int destino) {
//		if (origen == destino) return 0;
//		vector<int> distancia(MAX, INF);
//		distancia[origen] = 0;
//		queue<int> cola; cola.push(origen);
//		while (!cola.empty()) {
//			int v = cola.front(); cola.pop();
//			for (int i = 0; i < 3; i++){
//				int w = adyacente(v, i);
//				if (distancia[w] == INF) { // no ha sido visitado
//					distancia[w] = distancia[v] +1;
//					if (w == destino) return distancia[w];
//					cola.push(w);
//				}
//			}
//		}
//	}
//
//private:
//	const int MAX = 10000;
//	const int INF = 1000000000;
//
//	int adyacente(int v, int i) {
//		switch (i)
//		{
//		case 0: return (v + 1) % MAX;
//		case 1: return (v * 2) % MAX;
//		case 2: return v / 3;
//		}
//	}
//
//};
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int ini, fin;
//	cin >> ini >> fin;
//	if (!cin) return false;
//
//
//	Calculadora calculadora;
//
//	cout << calculadora.bfs(ini, fin) << "\n";
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
//	ifstream in("T5/casos5.1.txt");
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
