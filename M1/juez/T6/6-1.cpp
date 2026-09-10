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
//#include "ConjuntosDisjuntos.h"
//
//using namespace std;
//
//
//
///*@ <answer>
//
//	Coste en tiempo:
//	En la lectura O(F * C)  siendo F el numero de filas y C el numero de columnas.
//	En el procesado de nuevas manchas O(N + Mln*(N)) ~= O(N) donde N es el numero de elementos y M el numero de llamadas a unir y buscar.
// @ </answer> */
//
//
// //@ <answer>
//
//const vector<pair<int, int>> dirs = {
//									{-1,-1},{-1,0},{-1,1},
//									{0,-1}		 ,{0,1},
//									{1,-1},{1,0},{1,1} };
//
//
//
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int F, C;
//	cin >> F >> C;
//	if (!cin) return false;
//
//	vector<string> map(F);
//
//	for (int i = 0; i < F; i++)
//	{
//		string f;
//		cin >> f;
//		map[i] = f;
//	}
//
//	ConjuntosDisjuntos cd(F * C);
//	int maxMancha = 0;
//	for (int i = 0; i < F; i++)
//	{
//		for (int j = 0; j < C; j++)
//		{
//			if (map[i][j] != '#') continue;
//			int id = i * C + j;
//			for (pair<int, int> p : dirs)
//			{
//				int i2 = i + p.first,
//					j2 = j + p.second;
//				if (i2 < 0 || j2 < 0 || i2 >= F || j2 >= C) continue;
//				if (map[i2][j2] == '#')	cd.unir(id, i2 * C + j2);
//			}
//			maxMancha = max(maxMancha, cd.cardinal(id));
//		}
//	}
//	cout << maxMancha;
//
//	int N;
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		int f, c;
//		cin >> f >> c;
//		f--; c--;
//		map[f][c] = '#';
//		int id = f * C + c;
//		for (pair<int, int> p : dirs)
//		{
//			int i2 = f + p.first,
//				j2 = c + p.second;
//			if (i2 < 0 || j2 < 0 || i2 >= F || j2 >= C) continue;
//			if (map[i2][j2] == '#')	cd.unir(id, i2 * C + j2);
//		}
//		maxMancha = max(maxMancha, cd.cardinal(id));
//		cout << " " << maxMancha;
//	}
//
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
//	ifstream in("T6/casos6.1.txt");
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
