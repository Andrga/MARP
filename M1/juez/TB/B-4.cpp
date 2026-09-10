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
//vector<vector<long long>> memo;
//
//long long resuelve(int l, int r, const vector<long long>& c) {
//	// Casos base.
//	if (l > r) return 0; // si nos salimos, pasamos.
//	if (l == r) return c[l]; // Si son iguales.
//
//	long long& res = memo[l][r];
//	if (res != -1) return res;
//
//	long long best = 0;
//
//	// --- 1. Tomo izquierda ---
//	{
//		int nl = l + 1, nr = r;
//		// Juega Devoradora
//		if (C[nl] > C[nr]) nl++;
//		else nr--;
//		best = max(best, C[l] + solve(nl, nr));
//	}
//
//	// --- 2. Tomo derecha ---
//	{
//		int nl = l, nr = r - 1;
//		// Juega Devoradora
//		if (C[nl] > C[nr]) nl++;
//		else nr--;
//		best = max(best, C[r] + solve(nl, nr));
//	}
//
//	return res = best;
//}
//
//bool resuelveCaso() {
//	int N;
//	cin >> N;
//	if (!cin) return false;
//
//	// vector de la comida
//	vector<long long> C(N);
//	for (int i = 0; i < N; i++)
//		cin >> C[i];
//
//	cout << resuelve(0, N-1, c) << "\n";
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
