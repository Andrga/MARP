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
//#include "Matriz.h"
//
//using namespace std;
//
//
//
///*@ <answer>
//*
//* Complejidad en tiempo  O(N * log(N)) dond N es el numero de tipos de chorizo, y log(N) porque es el coste de push y pop
//* Complejidad en espacio O(1) no se crea memoria extra
//*
//@ </answer> */
//
//
////@ <answer>
//
//struct Receta
//{
//	int cantMasa = 0; // Cantidad de masa que lleva la receta
//	int prec = 0;	  // Precio del bollo con el chorizo
//};
//
//int mochila_rec(vector<Receta> const& obj, int i, int j, Matriz<double>& mochila) {
//	if (mochila[i][j] != -1) // subproblema ya resuelto
//		return mochila[i][j];
//	if (i == 0 || j == 0) mochila[i][j] = 0;
//	else if (obj[i - 1].cantMasa > j)
//		mochila[i][j] = mochila_rec(obj, i - 1, j, mochila);
//	else
//		mochila[i][j] = max(
//			mochila_rec(obj, i - 1, j, mochila),
//			mochila_rec(obj, i - 1, j - obj[i - 1].cantMasa, mochila) + obj[i - 1].prec);
//	return mochila[i][j];
//}
//
//int gananciaMaxima(vector<Receta> const& objetos, int M) {
//	int n = objetos.size();
//	Matriz<double> mochila(n + 1, M + 1, -1);
//	return mochila_rec(objetos, n, M, mochila);
//}
//
//// // RESOLUCION VORAZ (NO ESTA BIEN)
////int gananciaMaxima(PriorityQueue<Receta>& pq, int G) {
////	int ganancia = 0;
////	while (!pq.empty() && G > 0) {
////		// sacamos la receta con mas ganancia
////		Receta r = pq.top(); pq.pop();
////		// si hay suficiente masa o chorizo para hacer mas bollos de este tipo, continuamos.
////		if (G < r.cantMasa || r.grChor < r.cantChor) continue;
////		// restamos las cantidades usadas
////		G -= r.cantMasa;
////		r.grChor -= r.cantChor;
////		ganancia += r.prec;
////		// volvemos a insertar en la cola
////		pq.push(r);
////	}
////	return ganancia;
////}
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int N, G;
//	if (!(cin >> N >> G)) return false;
//	// usamos priorityQueue para ordenar
//	vector<Receta> recetas;
//	for (size_t i = 0; i < N; i++)
//	{
//		int cant, gc, gm, prec; cin >> cant >> gc >> gm >> prec;
//		int cantbollos = cant / gc;
//		for (size_t i = 0; i < cantbollos; i++)
//		recetas.push_back({ gm, prec});
//	}
//	cout << gananciaMaxima(recetas, G) << "\n";
//	return true;
//}
//
////@ </answer>
////  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	ifstream in("R/casosR.3.txt");
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
