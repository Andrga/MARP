///*@ <authors>
// *
// * Andres Garcia Navarro, MARP19
// *
// *@ </authors> */
//
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <string>
//#include "Matriz.h"
//
//using namespace std;
//
//
//
///*@ <answer>
//*
//* Complejidad en tiempo O(N*M) doble bucle del metodo combinaciones
//* Complejidad en espacio O(N*M) Matriz dp
//*
//@ </answer> */
//
//
//
////@ <answer>
//int combinaciones(Matriz<int> const& a, int n, int m) {
//	Matriz<int> dp(n, m, 0);
//	dp[0][0] = 1;
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (dp[i][j] == 0) continue;
//
//			int salto = a[i][j];
//			if (i + salto < n)
//				dp[i + salto][j] += dp[i][j];
//			if (j + salto < m)
//				dp[i][j + salto] += dp[i][j];
//		}
//	}
//	return dp[n-1][m-1];
//}
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int n, m;
//	if (!(cin >> n >> m)) return false;
//	Matriz<int> a(n, m);
//	for (size_t i = 0; i < n; i++)
//	{
//		for (size_t j = 0; j < m; j++)
//		{
//			int c; cin >> c;
//			a[i][j] = c;
//		}
//	}
//
//	cout << combinaciones(a, n, m) << "\n";
//	return true;
//}
//
////@ </answer>
////  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	ifstream in("R/casosR.7.txt");
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
