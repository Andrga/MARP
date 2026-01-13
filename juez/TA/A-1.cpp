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
//
//using namespace std;
//
//
//
///*@ <answer>
//*
// @ </answer> */
//
//
// //@ <answer>
//
//
//const long long INF = numeric_limits<long long>::max();
//
//bool resuelveCaso() {
//	int N, L;
//	cin >> N >> L;
//	if (!cin) return false;
//
//	vector<int> len(N), cost(N);
//	for (int i = 0; i < N; i++)
//		cin >> len[i] >> cost[i];
//
//	// vectores con las 3 soluciones.
//	vector<long long> ways(L + 1, 0);
//	vector<long long> minRopes(L + 1, INF);
//	vector<long long> minCost(L + 1, INF);
//
//	// inicializacion del primer valor
//	ways[0] = 1;
//	minRopes[0] = 0;
//	minCost[0] = 0;
//
//	// Procesamos cada cordel
//	for (int i = 0; i < N; i++) {
//		int w = len[i], c = cost[i];
//		for (int x = L; x >= w; x--) {
//
//			ways[x] = min(ways[x] + ways[x - w], INF);
//
//			// Si la distancia minima del cordel actual que comprobamos es valido.
//			if (minRopes[x - w] != INF)
//				// escogemos la cantidad minima si x o la que estamos comprobando.
//				minRopes[x] = min(minRopes[x], minRopes[x - w] + 1);
//			// Si el coste minimo del cordel actual que comprobamos con el resto es valido.
//			if (minCost[x - w] != INF)
//				// Escogemos el coste minimo.
//				minCost[x] = min(minCost[x], minCost[x - w] + c);
//		}
//	}
//	
//	if (ways[L] == 0)
//		cout << "NO\n";
//	else
//		cout << "SI " << ways[L] << " " << minRopes[L] << " " << minCost[L] << "\n";
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
//	ifstream in("TA/casosA.1.txt");
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
