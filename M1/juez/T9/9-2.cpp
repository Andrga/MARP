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
//struct Trabajo
//{
//	int c , f;
//};
//class compare{
//public:
//	bool operator() (Trabajo a, Trabajo b) {
//		return a.c > b.c;
//	}
//};
//
//
//// las tareas estan ordenadas de mayor a menor beneficio
//int resolver(vector<Trabajo> const& trabajos, int C, int F) {
//	int cont = 0;	// Cantidad de trabajos.
//	int c = C;		// Ultimo fin de trabajo.
//	int i = 0;
//
//	while (c < F) {
//		int bestf = c; // Final del trabajo que llega mas lejos.
//		// Vamos pasando trabajos hasta llegar al que supera a c.
//		while (i < trabajos.size() && trabajos[i].c <= c) {
//			// Guardamos el final del trabajo que llega mas lejos.
//			bestf = max(bestf, trabajos[i].f);
//			++i;
//		}
//		// Si el mejor final es el propio c, es porque no hay trabajos que cubran todo el intervalo,ç.
//		if (bestf == c) return -1;
//		cont++;
//		// Asignamos nueva c
//		c = bestf;
//	}
//	return cont;
//}
//
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int C, F, N;
//	cin >> C >> F >> N;
//	if (C == 0 && F == 0 && N == 0) return false;
//
//	vector<Trabajo> trabajos(N);
//
//	for (int i = 0; i < N; i++) {
//		int c, f;
//		cin >> c >> f;
//		trabajos[i] = { c, f };
//	}
//
//	// Ordenar por extremo izquierdo.
//	sort(trabajos.begin(), trabajos.end(),
//		[](const Trabajo a, const Trabajo& b) {
//			return a.c < b.c;
//		});
//	int s = resolver(trabajos, C, F);
//	cout << ((s == -1) ? "Imposible" : to_string(s)) << "\n";
//	return true;
//}
//
////@ </answer>
////  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	ifstream in("T9/casos9.2.txt");
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
