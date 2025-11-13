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
//#include <vector>
//#include <string>
//#include "ConjuntosDisjuntos.h"
//
//using namespace std;
//
//
//
///*@ <answer>
//*
//* El coste es O(N*Log(N))
//*
// @ </answer> */
//
//
// //@ <answer>
//
//struct Pila
//{
//	int c, f;
//};
//
//
//// las tareas estan ordenadas de mayor a menor beneficio
//int resolver(vector<int> const& pilas, int voltios) {
//	int cont = 0;	// Cantidad de trabajos.
//	int n = pilas.size();
//	int i = 0,
//		j = n-1;
//	while (i < j) {
//		int actV = pilas[i] + pilas[j];
//		if (actV >= voltios) {
//			cont++;
//			i++; j--;
//		}
//		else
//			i++;
//	}
//	return cont;
//}
//
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int N, V;
//	cin >> N >> V;
//
//	vector<int> pilas(N);
//
//	for (int i = 0; i < N; i++) {
//		int p;
//		cin >> p;
//		pilas[i] = p;
//	}
//
//	// Ordenar por extremo izquierdo.
//	sort(pilas.begin(), pilas.end());
//	int s = resolver(pilas, V);
//	cout << s << "\n";
//	return true;
//}
//
////@ </answer>
////  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	ifstream in("T9/casos9.3.txt");
//	if (!in.is_open())
//		cout << "Error: no se ha podido abrir el archivo de entrada." << endl;
//	auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
//	int n;
//	cin >> n;
//	// Resolvemos
//	while (n > 0) {
//		resuelveCaso();
//		--n;
//	}
//
//	// para dejar todo como estaba al principio
//#ifndef DOMJUDGE
//	cin.rdbuf(cinbuf);
//#endif
//	return 0;
//}
