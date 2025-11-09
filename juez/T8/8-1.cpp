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
//* El coste en tiempo de esta funcion es de O(N) donde N es el ncumero de agujeros que tiene la manguera
//* Esto es asi porque el vector de agujeros esta ordenado de menor a mayor, y se recorre de forma lineal.
// @ </answer> */
//
//
// //@ <answer>
//
///// <param name="D">Vector de distancias</param>
///// <param name="K">Distancia que ocupa un parche</param>
///// <param name="p">Posiciones de parches</param>
//int parches(vector<int> const& D, int K, vector<bool>& p) {
//	// Primer agujero tiene un parche.
//	p[0] = true;
//	int parches = 1;
//	int d = D[0]; // Distancia desde el ultimo parche.
//	for (int i = 1; i < D.size(); i++)
//	{
//		// si la distancia al siguiente agujero + la distancia desde que empieza el parche
//		// es menor al espacio que ocupa un parche, no hace falta parar.
//		if (D[i] - d <= K) {
//			p[i] = false; // No hace falta poner parche.
//		}
//		else {
//			p[i] = true;
//			parches++;
//			d = D[i];
//		}
//		// Sumamos a la distancia desde que empieza el parche la distancia hasta el siguiente agujero.
//	}
//	return parches;
//}
//
//
//bool resuelveCaso() {
//
//	// leemos la entrada.
//	int N, L;
//	cin >> N >> L;
//	if (!cin) return false;
//
//	vector<int> agujeros(N,0); 
//	vector<bool> p(N, false);
//
//	for (int i = 0; i < N; i++)
//		cin >> agujeros[i];
//	cout << parches(agujeros, L, p) << "\n";
//	return true;
//}
//
////@ </answer>
////  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
//
//int main() {
//	// ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//	ifstream in("T8/casos8.1.txt");
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
